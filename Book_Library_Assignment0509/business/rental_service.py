'''
Created on Nov 26, 2018

@author: Korina
'''
from model.book import Book
from model.client import Client
from model.rental import  Rental
from errors.error import LibraryError
from extra_help import date_to_str_format
from business.dto import BookRentalDays, ClientRentalDays, AuthorRentalDays
from business.undo_service import UndoService, FunctionCall, Operations, CascadeOperations
from GnomeSort_and_Filter import k_filter, GnomeSort


class RentalService:
    def __init__(self, rental_repo, rental_valid, book_repo, client_repo, undo_ser):
        self.__rental_repo = rental_repo
        self.__rental_valid = rental_valid
        self.__book_repo = book_repo
        self.__client_repo = client_repo
        self.__undo_ser = undo_ser
        
    def __can_rent(self, bid, cid):
        """
        Verifies if the book and the client exist so that the rent makes sense
        Input: bid  - positive integer
               cid - positive integer
        Output: True if the book which identifies with bid and the client which identifies with cid exist
                False otherwise
        """
        book = Book(bid, None, None, None)
        client = Client(cid, None)
        if self.__book_repo.exists_book(book) and self.__client_repo.exists_client(client):
            return True
        return False
    
    def list_rentals(self):
        """
        Returns a list containing the rentals from repository
        """
        return self.__rental_repo.get_rentals()
    
    
    def remove_rental(self, rental_id):
        """
        Removes the rental with the given id, from repository
        """
        for r in self.__rental_repo.get_rentals():
            if r.get_id() == rental_id:
                self.__rental_repo.remove(r)
                return
            
    def filter_rentals(self, bid, cid):
        """
        Filters the rentals by the given book and the given client (or by one of them if the other is None)
        Input: client - an object of the class Client
               book - an object of the class Book
        Output: a list with the rentals regarding only the book and the client
        """
        if bid != None:
            return k_filter(self.__rental_repo, lambda x: x.get_b_id() == bid)
        else:
            return k_filter(self.__rental_repo, lambda x: x.get_c_id() == cid)
        
#         filter_result = []
#         for r in self.__rental_repo.get_rentals():
#             if r.get_b_id() == bid or r.get_c_id() == cid:
#                 filter_result.append(r)
#         return filter_result
        
        
        
    def rent(self, rid, bid, cid, rentdate, duedate, returdate=None):
        """
        Adds the rent, created using the given attributes, in the repository
        Input: rid, bid, cid - positive integer
               rentdate, duedate, returdate - string representing dates in format = "dd.mm.YYYY"
               the default value for returdate is None
        Exceptions: LibraryError - if the rent is not possible
        """
        if not self.__can_rent(bid, cid):
            raise LibraryError("!!! The book or the client does not exist!")
        rent = Rental(rid, bid, cid, rentdate, duedate, returdate)
        self.__rental_valid.valid_rent(rent)
        self.__rental_repo.available_rent(rent)
        self.__rental_repo.add(rent)
        
        
        redo = FunctionCall(self.rent, rid, bid, cid, rentdate, duedate, returdate)
        undo = FunctionCall(self.remove_rental, rid)
        oper = Operations(undo, redo)
        self.__undo_ser.add(oper)
        
        
    def retur(self,rid, returdate):
        """
        Sets the returdate of the rent with bid and cid corresponding to the given ones
        Input: bid, cid - positive integer
               returdate - strings representing dates in format = "dd.mm.YYYY"
        Output:
        Exceptions: LibraryError - if the book has been returned already
        
        """
        
        rentals = self.__rental_repo.get_rentals()
        for i in range(0,len(rentals)):
            if rentals[i].get_id() == rid :
                if rentals[i].get_returned_date() == None:
                    r = rentals[i]
                    r.set_returned_date(returdate)
                    self.__rental_repo.update(r)
                elif rentals[i].get_returned_date() != None:
                    raise LibraryError("! This book has already been returned by this client")
       
            
        redo = FunctionCall(self.retur, rid, returdate)
        undo = FunctionCall(self.undo_retur, rid)
        oper = Operations(undo, redo)
        self.__undo_ser.add(oper)

    def undo_retur(self, rid):
        """
        Created only for setting the retur date back to None
        """
        rentals = self.__rental_repo.get_rentals()
        for i in range(0,len(rentals)):
            if rentals[i].get_id() == rid :
                r = rentals[i]
                r.set_returned_date(None)
                self.__rental_repo.update(r)
               
    
    def most_rented_books(self):
        """
        Returns a sorted list
        which contains the books and the number of days 
        each book has been rented for.
        """
        aux ={}
        for r in self.__rental_repo.get_rentals():
            if r.get_b_id() not in aux.keys():
                aux[r.get_b_id()] = r.days()
            else:
                aux[r.get_b_id()] += r.days()
                
        for b in self.__book_repo.get_books():
            if b.get_id() not in  aux.keys():
                aux[b.get_id()] = 0
        
        solution = []
        for k in aux.keys():
            solution.append(BookRentalDays(self.__book_repo.find(k), aux[k]))
            
        GnomeSort(solution, lambda x, y: x.days > y. days)
        return solution
    
    def most_active_clients(self):
        """
        Most active clients. 
        This will provide the list of clients, 
        sorted in ascending order of the number of book rental days they have.
        """
        aux = {}
        for r in self.__rental_repo.get_rentals():
            if r.get_c_id() not in aux.keys():
                aux[r.get_c_id()] = r.days()
            else:
                aux[r.get_c_id()] += r.days()
        for c in self.__client_repo.get_clients():
            if c.get_id() not in aux.keys():
                aux[c.get_id()] = 0
        solution = []
        for k in aux.keys():
            solution.append(ClientRentalDays(self.__client_repo.find(k), aux[k]))
        GnomeSort(solution, lambda x, y: x.days > y. days)
        return solution
        
    def most_rented_author(self):
        """
        Most rented author. 
        This provides the list of book authored, 
        sorted in ascending order of 
        the total number of rentals their books have.
        """
        mrb = self.most_rented_books() # mrb =most rented books
        aux = {}
        for b in range(len(mrb)):
            if mrb[b].get_book().get_author() not in aux.keys():
                aux[mrb[b].get_book().get_author()] = mrb[b].get_days()
            else:
                aux[mrb[b].get_book().get_author()] += mrb[b].get_days()
                
        for b in self.__book_repo.get_books():
            if b.get_author() not in aux.keys():
                aux[b.get_author()] = 0
        sol = []
        for k in aux.keys():
            sol.append(AuthorRentalDays(k, aux[k]))            
        GnomeSort(sol, lambda x, y: x.days > y. days)
        
        return sol
        
    def late_rentals(self):
        """
        Late rentals. 
        All the books that are currently rented, 
        for which the due date for return has passed,
        sorted in ascending order of the number of days of delay.
        """
        aux = {}
        for r in self.__rental_repo.get_rentals():
            if r.is_late():
                if (r.get_b_id() not in aux.keys()):
                    aux[r.get_b_id()] = r.how_late()
                else:
                    aux[r.get_b_id()] += r.how_late()
        for  b in self.__book_repo.get_books():
            if b.get_id() not in aux.keys():
                aux[b.get_id()] = 0
                
        sol = []
        for k in aux.keys():
            sol.append(BookRentalDays(self.__book_repo.find(k), aux[k]))
            
        GnomeSort(sol, lambda x, y: x.days > y. days)
        return sol
        
    
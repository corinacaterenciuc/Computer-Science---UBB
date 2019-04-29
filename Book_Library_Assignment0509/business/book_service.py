'''
Created on Nov 26, 2018

@author: Korina
'''

from model.book import Book
from errors.error import LibraryError
from extra_help import date_to_str_format
from business.undo_service import UndoService, FunctionCall, Operations, CascadeOperations
from GnomeSort_and_Filter import k_filter


class BookService:
    def __init__(self, book_repo, book_valid,undo_ser, rental_service):
        self.__book_repo = book_repo
        self.__book_valid = book_valid
        self.__undoService= undo_ser
        self.__rental_service = rental_service
        
    def add_book(self, bid, title, author, description = None):
        """
        Creates a book with the given attributes and adds it in the repository
        Input: bid -  positive integer 
               title, author - string
               description - string (default value the empty string)
        
        """
        book = Book(bid, title, author, description)
        self.__book_valid.valid_book(book)
        self.__book_repo.add(book)
        
        """
        If everything works fine, we try to implement undo and redo command
        """
        redo = FunctionCall(self.add_book, bid, title, author, description)
        undo = FunctionCall(self.remove_book, bid)
        oper = Operations(undo, redo)
        self.__undoService.add(oper)
        
        
    def remove_book(self, bid ):
        """
        Removes the book with the given id from the repository
        Input: bid - positive integer
        """
        book = Book(bid, None, None, None)
        b = self.__book_repo.remove(book)
        
        """
        delete the rentals\
        """
        rentals = self.__rental_service.filter_rentals(bid, None)
        
        for r in rentals:
            self.__rental_service.remove_rental(r.get_id())
        
        
        undo = FunctionCall(self.add_book,b.get_id(), b.get_title(), b.get_author(), b.get_description())
        redo = FunctionCall(self.remove_book, bid)
        oper1 = Operations(undo, redo)
        
        co = CascadeOperations()
        co.add(oper1)
        
        if len(rentals)!= 0 :
            for r in rentals:
                rdate = date_to_str_format(r.get_rent_date())
                ddate = date_to_str_format( r.get_due_date())
                if r.get_returned_date() != None:
                    retdate = date_to_str_format(r.get_returned_date())
                    undo = FunctionCall(self.__rental_service.rent,r.get_id(),r.get_b_id(), r.get_c_id(), rdate, ddate, retdate)
                else:
                    undo = FunctionCall(self.__rental_service.rent,r.get_id(),r.get_b_id(), r.get_c_id(), rdate, ddate)
                redo = FunctionCall(self.__rental_service.remove_rental, r.get_id())
                oper = Operations(undo, redo)
                co.add(oper)
        
        self.__undoService.add(co)
        
                
    def update_book (self, bid, title, author,  description = None):
        """
        Creates a book with the given attributes and updates the book with the same id, 
        already existing in the repository 
        Input: bid -  positive integer (already existing in one of the books from the repository)
               title, author - string
               description - string (default value the empty string)
        
        """
        book = Book(bid, title, author, description)
        self.__book_valid.valid_book(book)
        b = self.__book_repo.update(book)
        
        redo = FunctionCall(self.update_book, bid, title, author, description)
        undo = FunctionCall(self.update_book, bid, b.get_title(), b.get_author(), b.get_description())
        oper = Operations(undo, redo)
        self.__undoService.add(oper)
        
    def list_books(self):
        """
        Returns a list containing the books in the repository
        """
        return self.__book_repo.list()
    
    def search_books_id(self, Id):
        """
        Returns a list containing the books which have the given id
        """
        return self.__book_repo.search_id(Id)
    
    def search_books_title(self, title):
        """
        Returns a list containing the books which have a title that includes the given title
        """
        return self.__book_repo.search_title(title)
    
    def search_books_author(self, author):
        """
        Returns a list containing the books which have an author that includes the given author
        """
        return self.__book_repo.search_author(author)
    
    def search_books_description(self, description):
        """
        Returns a list containing the books which have a description that includes the given description
        """
        return self.__book_repo.search_description(description) 
    
    
    
    
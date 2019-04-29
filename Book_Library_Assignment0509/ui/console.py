'''
Created on Nov 22, 2018

@author: Korina
'''
from errors.error import RepoError, LibraryError, ValidError


"""
15.11.2018
-You need to create atributes for each service. 
- 

"""



class Console:
    
    def __init__(self, book_service, client_service, rental_service, undo_service):
        self.__book_service = book_service
        self.__client_service = client_service
        self.__rental_service = rental_service
        self.__undo_service = undo_service
    
       
    def __print_Menu(self):
        print("\nYour options are: ")
        print("\t 1 Operations on Books and  Clients.")
        print("\t 2 Operations regarding rentals.")
        print("\t 3 Operations of searching for clients")
        print("\t 4 Operations for statistics ")
        print("\t 5 Undo")
        print("\t 6 Redo")
        print("\t 0 stop")


    def __print_op_1(self):
        print("\nOperations on Books and  Clients: ")
        print("\t 11 add  book")
        print("\t 12 remove book")
        print("\t 13 update book")
        print("\t 14 list books")
        print("\t 15 add client")
        print("\t 16 remove client")
        print("\t 17 update client")
        print("\t 18 list clients")
        
    def __print_op_2(self):
        print("\nOperations regarding rentals: ")
        print("\t 21 rent a book")
        print("\t 22 return a book")
        print("\t 23 list rentals")
        
    def __print_op_3(self):
        print("\nOperations of searching for clients: ")
        print("\t 31 Search books using id")
        print("\t 32 Search books using title")
        print("\t 33 Search books using author")
        print("\t 34 Search books using description")
        print("\t 35 Search clients using id")
        print("\t 36 Search clients using name")
        
    def __print_op_4(self):
        print("\nOperations for statistics: ")
        print("\t 41 Most rented books.")
        print("\t 42 Most active clients.")
        print("\t 43 Most rented author.")
        print("\t 44 Late rentals")
        
    def __add_bookUI(self):
        bid = input("give the id: ")
        title = input("give the title: ")
        author = input("give the author: ")
        description = input("give the description: ")
        bid = int(bid)
        
        if description == "":
            self.__book_service.add_book(bid, title, author)
        else:
            self.__book_service.add_book(bid, title, author, description)
            
    def __remove_bookUI(self):
        bid  = int(input("give the id of the book you want to remove: "))
        self.__book_service.remove_book(bid)
        
    def __update_bookUI(self):
        bid  = int(input("give the id of the book you want to update: "))
        title = input("give the new title: ")
        author = input("give the new author: ")
        description = input("give the new description: ")
        self.__book_service.update_book(bid, title, author, description)
        
    def __list_booksUI(self):
        print(self.__book_service.list_books())
        
    def __add_clientUI(self):
        cid = int(input("give the id: "))
        name = input("give the name : ")
        self.__client_service.add_client(cid, name)
    
    def __remove_clientUI(self):
        cid = int(input("give the id of the client you want to remove: "))
        self.__client_service.remove_client(cid)
        
    def __update_clientUI(self):
        cid = int(input("give the id of the client you want to update: "))
        name = input("give the new name: ")
        self.__client_service.update_client(cid, name)
        
    def __list_clientsUI(self):
        print(self.__client_service.list_clients())
        
    
    def __add_rentalUI(self):
        rid = int(input("give rental id: "))
        bid = int(input("give the id of the book: "))
        cid = int(input("give the id of the client: "))
        rdate = input("give the rent date: ")
        ddate = input("give the due date: ")
            
        self.__rental_service.rent(rid, bid, cid, rdate, ddate)

    def __return__bookUI(self):
        rid = int(input("give the id of the rental: "))
        returdate = input("give the retur date: ")
        self.__rental_service.retur(rid, returdate)
        
    def __list_rentalsUI(self):
        for r in self.__rental_service.list_rentals():
            print(r)
            
    def show_books(self, books):
        result_str ="ID \t Title \t Author \t Description \t\t\t\n"
        for b in books:
            result_str += str(b)+"\n"
        print(result_str)
    
    def show_clients(self, clients):
        
        result_str = "ID \t Name \n"
        for c in clients:
            result_str += str(c)+"\n"
        print(result_str)
            
    def __search_book_idUI(self):
        id = input("give the id you are searching for: ")
        rez_search = self.__book_service.search_books_id(id)
        if len(rez_search) == 0:
            print("There are no books with that id! sorry")
        else:
            self.show_books(rez_search)
            
    def __search_book_titleUI(self):
        title = input("give the title you are searching by: ")
        rez_search = self.__book_service.search_books_title(title)
        if len(rez_search) == 0:
            print("There are no books with the given title! sorry")
        else:
            self.show_books(rez_search)
            
    def __search_book_authorUI(self):
        author = input("give the author you are searching by: ")
        rez_search = self.__book_service.search_books_author(author)
        if len(rez_search) == 0:
            print("There are no books with the given author! sorry")
        else:
            self.show_books(rez_search)
            
    def __search_book_descriptionUI(self):
        description = input("give the description you are searching by: ")
        rez_search = self.__book_service.search_books_description(description)
        if len(rez_search) == 0:
            print("There are no books with the given description! sorry")
        else:
            self.show_books(rez_search)
            
    def __search_client_idUI(self):
        Id = input("give the id you are searching for: ")
        rez_search = self.__client_service.search_client_id(Id)
        if len(rez_search) == 0:
            print("There are no clients with the given id! sorry")
        else:
            self.show_clients(rez_search)
        
    
    def __search_client_nameUI(self):
        name = input("give the name you are searching for: ")
        result_search = self.__client_service.search_client_name(name)
        if len(result_search) == 0: 
            print("There are no clients that have what you are searching for! sorry")
        else:
            self.show_clients(result_search)
            
    def __most_rented_booksUI(self):
        print("Most rented books. This will provide the list of books, sorted in descending order of the of days they were rented. ")
        print("Days".ljust(9) + "Book".ljust(40))
        for i in range(0,len(self.__rental_service.most_rented_books())):
            print(self.__rental_service.most_rented_books()[i])
        print("-"*70)
        
    def __most_active_clientsUI(self):
        print("Most active clients. This will provide the list of clients, sorted in descending order of the number of book rental days they have. ")
        print("Days".ljust(9) + "Client".ljust(40))
        for i in range(0,len( self.__rental_service.most_active_clients())):
            print(self.__rental_service.most_active_clients()[i])
        print("-"*70)
        
        
    def __most_rented_authorsUI(self):
        print("Most rented authors. ")
        for i in range(0,len(self.__rental_service.most_rented_author())):
            print (str(self.__rental_service.most_rented_author()[i].days) +"       "+str(self.__rental_service.most_rented_author()[-i].author))
        print("-"*70)
        
    def __late_rentalsUI(self):
        print("Late rentals.")
        print("Days of delay".ljust(2)+"Book".ljust(40))
        for i in range(0,len(self.__rental_service.late_rentals())):
            print(self.__rental_service.late_rentals()[i])
        print("-"*70)
        
    def run_console(self):
        while True:
            self.__print_Menu()
            
            try:
                option = int(input("-> What is your option: "))
                if option == 0:
                    return
                elif option == 1:
                    self.__print_op_1()
                elif option == 2:
                    self.__print_op_2()
                elif option == 3:
                    self.__print_op_3()
                elif option == 4:
                    self.__print_op_4()
                elif option == 11:
                    self.__add_bookUI()
                elif option == 12:
                    self.__remove_bookUI()
                elif option == 13:
                    self.__update_bookUI()
                elif option == 14:
                    self.__list_booksUI()
                elif option == 15:
                    self.__add_clientUI()
                elif option == 16:
                    self.__remove_clientUI()
                elif option == 17:
                    self.__update_clientUI()
                elif option == 18:
                    self.__list_clientsUI()
                elif option == 21:
                    self.__add_rentalUI()
                elif option == 22:
                    self.__return__bookUI()
                elif option == 23:
                    self.__list_rentalsUI()
                elif option == 31:
                    self.__search_book_idUI()
                elif option == 32:
                    self.__search_book_titleUI()
                elif option == 33:
                    self.__search_book_authorUI()
                elif option == 34:
                    self.__search_book_descriptionUI()
                elif option == 35:
                    self.__search_client_idUI()
                elif option == 36:
                    self.__search_client_nameUI()
                elif option == 41:
                    self.__most_rented_booksUI()
                    
                elif option == 42:
                    self.__most_active_clientsUI()
                elif option == 43:
                    self.__most_rented_authorsUI()
                elif option == 44:
                    self.__late_rentalsUI()
                    
                elif option == 5:
                    undo = self.__undo_service.undo()
                    if not undo:
                        print("No more Undo's!")
                elif option == 6:
                    redo = self.__undo_service.redo()
                    if not redo:
                        print("No more Redo's!")
                
                else:
                    print("! invalid option")
            except ValueError:
                print("! invalid values given")
            except RepoError as re:
                print("Repository error: ")
                print(re)
            except ValidError as ve:
                print("Validation error: ")
                print(ve)
            except LibraryError as le:
                print("Library error: ")
                print(le)
            except IOError as ie:
                print(" File exception: "+str(ie))
            
        



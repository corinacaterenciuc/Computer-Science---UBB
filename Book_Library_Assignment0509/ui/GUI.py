'''
Created on Dec 1, 2018

@author: Korina
'''
from tkinter import *
from tkinter import messagebox
from builtins import int


class GUI:
    def __init__(self, book_service, client_service, rental_service, undo_service):
        self.__book_service = book_service
        self.__client_service = client_service
        self.__rental_service = rental_service
        self.__undo_service = undo_service
        self.__during_listing = False
    

    def _addClient(self):
        try:
            self.__client_service.add_client(int(self.cid_entr.get()), self.name_entr.get())
            messagebox.showinfo("Added", "{} has been added.".format(self.name_entr.get()))
        except Exception as e:
            messagebox.showerror("Error", "Error adding the client: "+str(e))
    
    
    def _removeClient(self):
        try:
            self.__client_service.remove_client(int(self.cid_entr.get()))
            messagebox.showwarning("Removed", "The client with the id {} has been removed.".format(int(self.cid_entr.get())))
        except Exception as e:
            messagebox.showerror("Error", "Error removing the client: "+str(e))
    
    
    def _updateClient(self):
        try:
            self.__client_service.update_client(int(self.cid_entr.get()), self.name_entr.get())
            messagebox.showinfo("Updated", "The client with the id: {} has been updated.".format(self.cid_entr.get()))
        except Exception as e:
            messagebox.showerror("Error", "Error updating the client: "+str(e))
    
    
    def _listClients(self):
        
        clients = self.__client_service.list_clients().split("\n")
        if len(clients) == 0:
            messagebox.showerror("Error", "Nothing to list")
        else:
            self.list_objects(clients)
        
    def _rent(self):
        try:
            if self.retdate_entr.get() == "":
                self.__rental_service.rent(int(self.rid_entr.get()), int(self.bid_entr_rental.get()), int(self.cid_entr_rental.get()), self.rdate_entr.get(), self.ddate_entr.get())
            else:
                self.__rental_service.rent(int(self.rid_entr.get()), int(self.bid_entr_rental.get()), int(self.cid_entr_rental.get()), self.rdate_entr.get(), self.ddate_entr.get(), self.retdate_entr.get())
            messagebox.showinfo("Added", "The rent has been added.")
        except Exception as e:
            messagebox.showerror("Error", "Error saving the rent: "+str(e))
    
    
    
    def _return(self):
        try:
            self.__rental_service.retur(int(self.rid_entr.get()), self.retdate_entr.get())
            messagebox.showinfo("Returned", "The book has been returned.")
        except Exception as e:
            messagebox.showerror("Error", "Error returning the book: "+str(e))
    
    
    def _listRentals(self):
        
        rentals = self.__rental_service.list_rentals()
        if len(rentals) == 0:
            messagebox.showerror("Error", "Nothing to list")
        else:
            self.list_objects(rentals)
    
    
    def search_id_Book(self):
        try:
            rez_search = self.__book_service.search_books_id(int(self.bid_entr.get()))
            if len(rez_search) == 0:
                messagebox.showerror("Error", "Nothing to list")
            else:
                self.list_objects(rez_search)
        except Exception as e:
            messagebox.showerror("Error", "Error when searching by id: "+str(e))
        
    
    
    def search_title_Book(self):
        
        rez_search = self.__book_service.search_books_title(self.title_entr.get())
        if len(rez_search) == 0:
            messagebox.showerror("Error", "Nothing to list")
        else:
            self.list_objects(rez_search)
    
    
    def search_author_Book(self):
        
        rez_search = self.__book_service.search_books_author(self.author_entr.get())
        if len(rez_search) == 0:
            messagebox.showerror("Error", "Nothing to list")
        else:
            self.list_objects(rez_search)
    
    
    def search_description_Book(self):
        
        rez_search = self.__book_service.search_books_description(self.description_entr.get())
        if len(rez_search) == 0:
            messagebox.showerror("Error", "Nothing to list")
        else:
            self.list_objects(rez_search)
    
    
    def search_id_client(self):
        
        try:
            rez_search = self.__client_service.search_client_id(int(self.cid_entr.get()))
            if len(rez_search) == 0:
                messagebox.showerror("Error", "Nothing to list")
            else:
                self.list_objects(rez_search)
        except Exception as e:
            messagebox.showerror("Error", "Error when searching by id: "+str(e))
        
    
    def search_name_client(self):
        
        rez_search = self.__client_service.search_client_name(self.name_entr.get())
        if len(rez_search) == 0:
            messagebox.showerror("Error", "Nothing to list")
        else:
            self.list_objects(rez_search)
    

    def most_rented_books(self):
        
        most_rented_books = self.__rental_service.most_rented_books()
        self.list_objects(most_rented_books)
    
    
    def most_active_clients(self):
        
        most_active_clients = self.__rental_service.most_active_clients()
        self.list_objects(most_active_clients)
    
    def most_rented_authors(self):
        
        most_rented_authors = self.__rental_service.most_rented_author()
        self.list_objects(most_rented_authors)
    
    
    def late_rentals(self):
        
        late_rentals = self.__rental_service.late_rentals()
        self.list_objects(late_rentals)
    

    def undo(self):
        undo = self.__undo_service.undo()
        if not undo:
            messagebox.showerror("Undo", "No more Undo's!")
    
    
    def redo(self):
        redo = self.__undo_service.redo()
        if not redo:
            messagebox.showerror("Redo", "No more Redo's!")
    
    
    def run_console(self):
        self.main_window = Tk()
        self.main_window.title("Library ")
        
        #Book stuff
        
        self.frame_1 = Frame(self.main_window, bg = "MediumPurple1")
        self.frame_1.pack(side = TOP)
        
        self.frame_2 = Frame(self.main_window, bg = "MediumPurple1")
        self.frame_2.pack(side = TOP)
        
        self.frame_3 = Frame(self.main_window, bg = "MediumPurple1")
        self.frame_3.pack(side = TOP)

        """
        creating book entry
        """
        self.l_bid = Label(self.frame_1, text = "*ID: ")
        self.l_bid.pack(side = LEFT)
        
        self.bid_entr = Entry(self.frame_1, {})
        self.bid_entr.pack(side = LEFT)
        
        self.l_title = Label(self.frame_1, text = "*Title: ")
        self.l_title.pack(side = LEFT)
        
        self.title_entr = Entry(self.frame_1, {})
        self.title_entr.pack(side = LEFT)
        
        self.l_author = Label(self.frame_1, text = "*Author: ")
        self.l_author.pack(side = LEFT)
        
        self.author_entr = Entry(self.frame_1, {})
        self.author_entr.pack(side = LEFT)
        
        self.l_description = Label(self.frame_1, text = "Description: ")
        self.l_description.pack(side = LEFT)
        
        self.description_entr = Entry(self.frame_1, {})
        self.description_entr.pack(side = LEFT)
        
        
        self.addBook_button = Button(self.frame_2, text = "Add book", command = self._addBook)
        self.addBook_button.pack(side = LEFT)
        
        self.removeBook_button = Button(self.frame_2, text = "Remove book", command = self._removeBook)
        self.removeBook_button.pack(side = LEFT)
        
        self.updateBook_button = Button(self.frame_2, text = "Update book", command = self._updateBook)
        self.updateBook_button.pack(side = LEFT)
        
        self.listBook_button = Button(self.frame_2, text = "List books", command = self._listBook)
        self.listBook_button.pack(side = LEFT)
        
        #Buttons for searching
        
        self.search_id_Book_button = Button(self.frame_3, text = "Search by id", command = self.search_id_Book)
        self.search_id_Book_button.pack(side = LEFT)
        
        self.search_title_Book_button = Button(self.frame_3, text = "Search by title", command = self.search_title_Book)
        self.search_title_Book_button.pack(side = LEFT)
        
        self.search_author_Book_button = Button(self.frame_3, text = "Search by author", command = self.search_author_Book)
        self.search_author_Book_button.pack(side = LEFT)
        
        self.search_description_Book_button = Button(self.frame_3, text = "Search by description", command = self.search_description_Book)
        self.search_description_Book_button.pack(side = LEFT)
        
        
        #Client stuff
        
        self.frame_4 = Frame(self.main_window, bg = "SkyBlue1")
        self.frame_4.pack(side = TOP)
        
        self.frame_5 = Frame(self.main_window, bg = "SkyBlue1")
        self.frame_5.pack(side = TOP)
        
        self.frame_6 = Frame(self.main_window, bg = "SkyBlue1")
        self.frame_6.pack(side = TOP)
        
        """
        Creating a client entry
        """
        
        self.l_cid = Label(self.frame_4, text = "*ID: ")
        self.l_cid.pack(side = LEFT)
        
        self.cid_entr = Entry(self.frame_4, {})
        self.cid_entr.pack(side = LEFT)
        
        self.l_name = Label(self.frame_4, text = "*Name: ")
        self.l_name.pack(side = LEFT)
        
        self.name_entr = Entry(self.frame_4, {})
        self.name_entr.pack(side = LEFT)
        
        self.addClient_button = Button(self.frame_5, text = "Add client", command = self._addClient)
        self.addClient_button.pack(side = LEFT)
        
        self.removeClient_button = Button(self.frame_5, text = "Remove client", command = self._removeClient)
        self.removeClient_button.pack(side = LEFT)
        
        self.updateClient_button = Button(self.frame_5, text = "Update client", command = self._updateClient)
        self.updateClient_button.pack(side = LEFT)
        
        self.listClient_button = Button(self.frame_5, text = "List clients", command = self._listClients)
        self.listClient_button.pack(side = LEFT)
        
        #Searching clients
        
        self.search_id_client_button = Button(self.frame_6, text = "Search by id", command = self.search_id_client)
        self.search_id_client_button.pack(side = LEFT)
        
        self.search_name_client_button = Button(self.frame_6, text = "Search by name", command = self.search_name_client)
        self.search_name_client_button.pack(side = LEFT)
        
        #Rental stuff
        
        self.frame_7 = Frame(self.main_window, bg = "DarkSlateGray1")
        self.frame_7.pack(side = TOP)
        
        self.frame_8 = Frame(self.main_window, bg = "DarkSlateGray1")
        self.frame_8.pack(side = TOP)
        
        self.frame_9 = Frame(self.main_window, bg = "DarkSlateGray1")
        self.frame_9.pack(side = TOP)
        
        """
        Creating a rental entry
        """
        
        self.l_rid = Label(self.frame_7, text = "*Rental ID: ")
        self.l_rid.pack(side = LEFT)
        
        self.rid_entr = Entry(self.frame_7, {})
        self.rid_entr.pack(side = LEFT)
        
        self.l_bid_rental = Label(self.frame_7, text = "*Book ID: ")
        self.l_bid_rental.pack(side = LEFT)
        
        self.bid_entr_rental = Entry(self.frame_7, {})
        self.bid_entr_rental.pack(side = LEFT)
        
        self.l_cid_rental = Label(self.frame_7, text = "*Client ID: ")
        self.l_cid_rental.pack(side = LEFT)
        
        self.cid_entr_rental = Entry(self.frame_7, {})
        self.cid_entr_rental.pack(side = LEFT)
        
        self.l_rdate = Label(self.frame_7, text = "*Rent date: ")
        self.l_rdate.pack(side = LEFT)
        
        self.rdate_entr = Entry(self.frame_7, {})
        self.rdate_entr.pack(side = LEFT)
        
        self.l_ddate = Label(self.frame_7, text = "*Due date: ")
        self.l_ddate.pack(side = LEFT)
        
        self.ddate_entr = Entry(self.frame_7, {})
        self.ddate_entr.pack(side = LEFT)
        
        self.l_retdate = Label(self.frame_7, text = "Retur date: ")
        self.l_retdate.pack(side = LEFT)
        
        self.retdate_entr = Entry(self.frame_7, {})
        self.retdate_entr.pack(side = LEFT)
        
        
        self.rent_button = Button(self.frame_8, text = "Rent", command = self._rent)
        self.rent_button.pack(side = LEFT)
        
        self.return_button = Button(self.frame_8, text = "Return", command = self._return)
        self.return_button.pack(side = LEFT)
        
        
        self.listRental_button = Button(self.frame_8, text = "List rentals", command = self._listRentals)
        self.listRental_button.pack(side = LEFT)
        
        # Statistics
        
        self.most_rented_books_button = Button(self.frame_9, text = "Most rented books", command = self.most_rented_books)
        self.most_rented_books_button.pack(side = LEFT)
        
        self.most_active_clients_button = Button(self.frame_9, text = "Most active clients", command = self.most_active_clients)
        self.most_active_clients_button.pack(side = LEFT)
        
        self.most_rented_authors_button = Button(self.frame_9, text = "Most rented authors", command = self.most_rented_authors)
        self.most_rented_authors_button.pack(side = LEFT)
        
        self.late_rentals_button = Button(self.frame_9, text = "Late rentals", command = self.late_rentals)
        self.late_rentals_button.pack(side = LEFT)
        
        
        """
        Undo and Redo
        """
        
        self.frame_10 = Frame(self.main_window, bg = "thistle1")
        self.frame_10.pack(side = TOP)
        
        self.undo_button = Button(self.frame_10, text = "Undo", command = self.undo)
        self.undo_button.pack(side = LEFT)
        
        self.redo_button = Button(self.frame_10, text = "Redo", command = self.redo)
        self.redo_button.pack(side = LEFT)
        
        """
        The place for lists
        """
        
        self.frame_11 = Frame(self.main_window)
        self.frame_11.pack(side = TOP)
        
        self.scroll_bar_y = Scrollbar(self.frame_11)
        self.scroll_bar_y.pack(side = RIGHT, fill = Y)
            
        self.scroll_bar_x = Scrollbar(self.frame_11, orient = HORIZONTAL)
        self.scroll_bar_x.pack(side = BOTTOM, fill = X)
            
        self.listbox = Listbox(self.frame_11, height = 10, width = 180,  justify = LEFT)
        self.listbox.pack(side = TOP, fill = BOTH, expand = 1)
           
        self.listbox.config(yscrollcommand = self.scroll_bar_y.set)
        self.scroll_bar_y.config(command = self.listbox.yview)
        self.listbox.config(xscrollcommand = self.scroll_bar_x.set)
        self.scroll_bar_x.config(command = self.listbox.xview)
        
        self.main_window.mainloop()
       
        
    def _addBook(self):
        try:
            if self.description_entr.get() == "":
                self.__book_service.add_book(int(self.bid_entr.get()), self.title_entr.get(), self.author_entr.get())
            else:
                self.__book_service.add_book(int(self.bid_entr.get()), self.title_entr.get(), self.author_entr.get(), self.description_entr.get())
            messagebox.showinfo("Added", "{} by {} has been added.".format(self.title_entr.get(), self.author_entr.get()))
        except Exception as e:
            messagebox.showerror("Error", "Error saving the book: "+str(e))
    
    def _removeBook(self):
        try:
            self.__book_service.remove_book(int(self.bid_entr.get()))
            messagebox.showwarning("Removed", "The book with the id {} has been removed.".format(int(self.bid_entr.get())))
        except Exception as e:
            messagebox.showerror("Error", "Error removing the book: "+str(e))
    
    def _updateBook(self):
        try:
            if self.description_entr.get() == "":
                self.__book_service.update_book(int(self.bid_entr.get()), self.title_entr.get(), self.author_entr.get())
            else:
                self.__book_service.update_book(int(self.bid_entr.get()), self.title_entr.get(), self.author_entr.get(), self.description_entr.get())
            messagebox.showinfo("Updated", "The book with the id: {} has been updated.".format(self.bid_entr.get()))
        except Exception as e:
            messagebox.showerror("Error", "Error updating the book: "+str(e))
    
    def _listBook(self):
        
        books = self.__book_service.list_books().split("\n")
        self.list_objects(books)
        
    def list_objects(self, objects):
        self.listbox.delete(0, END)
        
        for o in objects:
            self.listbox.insert(END, str(o))


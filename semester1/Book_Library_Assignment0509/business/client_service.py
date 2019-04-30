'''
Created on Nov 26, 2018

@author: Korina
'''

from model.client import Client
from errors.error import LibraryError
from extra_help import date_to_str_format
from business.undo_service import UndoService, FunctionCall, Operations, CascadeOperations



class ClientService:
    def __init__(self,client_repo, client_valid, undo_ser, rental_serv):
        self.__client_repo = client_repo
        self.__client_valid = client_valid
        self.__undo_service = undo_ser
        self.__rental_service = rental_serv
        
    def add_client(self, cid, name):
        """
        Creates a client with the given attributes and adds it to the repository
        Input: cid - positive integer
               name - string
        
        """
        client = Client(cid, name)
        self.__client_valid.valid_client(client)
        self.__client_repo.add(client)
        
        """
        If everything goes right we add the operation to the undo stack
        """
        redo = FunctionCall(self.add_client, cid, name)
        undo = FunctionCall(self.remove_client, cid)
        oper = Operations(undo, redo)
        
        self.__undo_service.add(oper)
        
    def remove_client(self, cid):
        """
        Removes the client with the given id from the repository
        Input: cid - positive integer
        """
        client = Client(cid, None)
        c = self.__client_repo.remove(client)
        
        """
        Need to remove all rentals with this client!
        """
        rentals = self.__rental_service.filter_rentals(None, cid)
        for r in rentals:
            self.__rental_service.remove_rental(r.get_id())
        
        redo = FunctionCall(self.remove_client, cid)
        undo = FunctionCall(self.add_client, c.get_id(), c.get_name())
        oper1 = Operations(undo, redo)
        
        co = CascadeOperations()
        co.add(oper1)
        
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
        
        self.__undo_service.add(co)
        
    
        
    def update_client(self, cid, name):
        """
        Creates a client with the given attributes and updates the client, from the repository, with the given id 
        Input: cid - positive integer
               name - string
        """
        client = Client(cid, name)
        self.__client_valid.valid_client(client)
        c = self.__client_repo.update(client)
        
        redo = FunctionCall(self.update_client, cid, name)
        undo = FunctionCall(self.update_client, c.get_id(), c.get_name())
        oper = Operations(undo, redo)
        
        self.__undo_service.add(oper)
        
    def list_clients(self):
        """
        Returns a list containing the clients from the repository
        """
        return self.__client_repo.list()    
    
    def search_client_id(self, Id):
        """
        Returns a list containing the clients with the given id
        """
        return self.__client_repo.search_id(Id)

    def search_client_name(self, name):
        """
        Returns a list containing the clients which have a name that includes the given name
        """
        return self.__client_repo.search_name(name)





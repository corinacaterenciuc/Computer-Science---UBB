'''
Created on Nov 26, 2018

@author: Korina
'''
from errors.error import RepoError
import json
# import pickle


class ClientRepository:
    
    def __init__(self):
        self._clients = []
        self._idx = 0
        
    def __next__(self):
        try:
            item = self._clients[self._idx]
        except IndexError:
            raise StopIteration()
        self._idx += 1
        return item
        
    def __contains__(self, client):
        return client in self._clients
    
    def __iter__(self):
        return iter(self._clients)
    
    def __len__(self):
        """
        Gives the amount of clients that are in the repository
        """
        return len(self._clients)
        
    def find(self, clientID):
        """
        Gives the client with the given id
        Input: clientID - positive integer
        Output: returns the client with the given id if it exists
                returns None otherwise
        """
        for i in self.get_clients():
            if i.get_id() == clientID:
                return i
        return None
    
    def exists_client(self, client):
        """
        Verifies if the given client is in the repository
        Input: client - an object of the class Client
        """
        if client in self._clients:
            return True
        return False
    
    def add(self, client):
        """
        Adds a given client in the repository
        Input: client - an object of the class Client
        Exception: RepoError - if the client exists in the repository already
        """
        if client in self._clients:
            raise RepoError("! This client already exists.")
        self._clients.append(client)
#         self._saveFile()
#         
# #         fileName = "clients.pickle"    
# #         f = open(fileName, "wb")
# #         pickle.dump(self._clients, f)
# #         f.close()        
# 
#     def client_to_json(self, client):
# #         json_list = []
# #         if book.get_description()!= None:
# #             json_list.append({"id": str(book.get_id()), "title": book.get_title(), "author": book.get_author(), "description": book.get_description()})
# #         else:
# #             json_list.append({"id": str(book.get_id()), "title": book.get_title(), "author": book.get_author()})
#         
#         return {"id": str(client.get_id()), "name": client.get_name()}
#         
#     def _saveFile(self):
#         json_list = []
#         for c in self.get_clients():
#             json_list.append(self.client_to_json(c))
#             
#         with open("clients.json", "w") as f:
#             json.dump(json_list, f)
        
    def remove(self,client):
        """
        Removes the given client from the repository
        Input: client - an object of the class Client
        Exception: RepoError - if the client does not exist in the repository 
        """
        if client not in self._clients:
            raise RepoError("! This client does not exist, therefore cannot be removed.")
        i=0
        while i < len(self._clients):
            if self._clients[i] == client:
                c = self._clients[i]
                del self._clients[i]
            else:
                i+=1
        return c
                
    def update(self,client):
        """
        Changes the name of the client with the same id as the given client
        Input: client - an object of the class Client
        Exception: RepoError - if the client does not exist in the repository 
        """
        if client not in self._clients:
            raise RepoError("! This client does not exist, therefore cannot be updated.")
        
        for i in range (0,len(self._clients)):
            if self._clients[i] == client:
                c = self._clients[i]
                self._clients[i] = client
                return c
            
    def list(self):
        """
        Gives a list containing the clients from repository in a printable form
        Output: a list of the clients in the repository
        Exception: RepoError - if the repository is empty
        """
        if len(self._clients) == 0:
            raise RepoError("! There is nothing to list.")
        clients = "ID \t Name \n"
        for c in self._clients:
            clients += str(c)+"\n"
        return clients
    
    def get_clients(self):
        """
        Returns the list of clients in the repository
        """
        return self._clients[:]
    
    def search_id(self, Id):
        """
        Searches for the clients which have at least a part of their id equal to the given id
        Input: id - positive integer
        Output: search_result -  a list of books which satisfy the criteria
        """
        search_result = []
        for c in self._clients:
            if str(c.get_id()).find(str(Id))!=-1:
                search_result.append(c)
        return search_result
    
    def search_name(self, name):
        """
        Searches for the clients which have at least a part of their name equal to the given name
        Input: name - string
        Output: search_result -  a list of books which satisfy the criteria
        """
        
        search_result = []
        for c in self._clients:
            if str(c.get_name()).lower().find(name.lower())!=-1:
                search_result.append(c)
        return search_result
        


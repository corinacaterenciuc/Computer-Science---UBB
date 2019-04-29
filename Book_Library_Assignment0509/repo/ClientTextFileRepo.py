'''
Created on Nov 29, 2018

@author: Korina
'''
from repo.client_repository import ClientRepository
from model.client import Client
from errors.error import RepoError
from _io import open

class ClientTextFileRepo(ClientRepository):
    def __init__(self, fileName = "clients.txt"):
        ClientRepository.__init__(self)
        self._fileName = fileName
        self._loadFile()
    
    def add(self, client):
        ClientRepository.add(self, client)
        self._saveFile()
        
    def remove(self, client):
        c = ClientRepository.remove(self, client)
        self._saveFile()
        return c
        
    def update(self, client):
        c= ClientRepository.update(self, client)
        self._saveFile()
        return c
    
    def _saveFile(self):
        try:
            f = open(self._fileName, "w")
            for c in ClientRepository.get_clients(self):
                f.write(str(c.get_id())+","+c.get_name()+"\n")
        except Exception as e:
            raise RepoError("Error writing file: "+str(e))
        finally:
            f.close()
    
    
    def _loadFile(self):
        try:
            f = open(self._fileName, "r")
            s = f.readline()
            
            while len(s) > 1:
                tok = s.split(",")
                tok[1] = tok[1].split("\n")
                client = Client(int(tok[0]), tok[1][0])
                ClientRepository.add(self, client)
                s = f.readline()
        except Exception as e:
            raise RepoError("Error reading input file: "+ str(e))
        finally:
            f.close()
            
            
'''
Created on Dec 11, 2018

@author: Korina
'''
from repo.ClientTextFileRepo import ClientTextFileRepo
import json
from model.client import Client
from repo.client_repository import ClientRepository
from model import client
from json.decoder import JSONDecodeError
from errors.error import RepoError


class Client_JSON_Repo(ClientTextFileRepo):
    def __init__(self, fileName = "clients.json"):
        ClientTextFileRepo.__init__(self, fileName)
        
    def json_to_client(self, json_client):
        return Client(int(json_client["id"]), json_client["name"])
        

    def client_to_json(self, client):
        return {"id": str(client.get_id()), "name": client.get_name()}
        
    def _saveFile(self):
        json_list = []
        for c in self.get_clients():
            json_list.append(self.client_to_json(c))
            
        with open(self._fileName, "w") as f:
            json.dump(json_list, f)
    
    def _loadFile(self):
        with open(self._fileName, "r") as f:
            try:
                
                json_clients = json.load(f)
                for c in json_clients:
                    client = self.json_to_client(c)
                    ClientRepository.add(self, client)
            except JSONDecodeError as je:
                raise RepoError("could not load file: "+str(je))
                
                
                
from repo.client_repository import ClientRepository
from errors.error import RepoError
import pickle
from model.client import Client


class ClientBinaryFileRepo(ClientRepository):
    def __init__(self, fileName = "clients.pickle"):
        ClientRepository.__init__(self)
        self._fileName = fileName
        self._loadBinaryFile()
        
    def add(self, client):
        ClientRepository.add(self, client)
        self._saveBinaryFile()
        
    def update(self, client):
        c = ClientRepository.update(self, client)
        self._saveBinaryFile()
        return c
        
    def _saveBinaryFile(self):
        f = open(self._fileName, "wb")
        pickle.dump(self._clients, f)
        f.close()    
    
        
    def _loadBinaryFile(self):
        try:
            f = open(self._fileName, "rb")
            self._clients = pickle.load(f)
        except EOFError:
            self._clients = []
        except IOError as ioe:
            raise RepoError("An error occured: "+str(ioe))
#         finally:
#             f.close()









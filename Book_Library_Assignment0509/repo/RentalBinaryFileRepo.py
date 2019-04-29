from repo.rental_repository import RentalRepository
import pickle
from errors.error import RepoError


class RentalBinaryFileRepo(RentalRepository):
    def __init__(self, fileName = "rentals.pickle"):
        RentalRepository.__init__(self)
        self._fileName = fileName
        self._loadBinaryFile()
    
    def add(self, rental):
        RentalRepository.add(self, rental)
        self._saveBinaryFile()
        
    def update(self, rental):
        RentalRepository.update(self, rental)
        self._saveBinaryFile()
    
    def _saveBinaryFile(self):
        f = open(self._fileName, "wb")
        pickle.dump(self._rentals, f)
        f.close()
    
    def _loadBinaryFile(self):
        try:
            f = open(self._fileName, "rb")
            self._rentals = pickle.load(f)
        except EOFError:
            self._rentals = []
        except IOError as ioe:
            raise RepoError("An error occured: "+str(ioe))
        finally:
            f.close()
            
            



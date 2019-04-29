'''
Created on Nov 29, 2018

@author: Korina
'''
from repo.rental_repository import RentalRepository
from model.rental import Rental
from errors.error import RepoError
from _io import open
from extra_help import date_to_str_format


class RentalTextFileRepo(RentalRepository):
    def __init__(self, fileName = "rentals.txt"):
        RentalRepository.__init__(self)
        self._fileName = fileName
        self._loadFile()
        
    def add(self, rental):
        RentalRepository.add(self, rental)
        self._saveFile()
        
    def remove(self, rental):
        RentalRepository.remove(self, rental)
        self._saveFile()
        
    def update(self, rental):
        RentalRepository.update(self, rental)
        self._saveFile()
    
        
    def _saveFile(self):
        try:
            f = open(self._fileName, "w")
            for r in RentalRepository.get_rentals(self):
                if r.get_returned_date() != None:
                    f.write(str(r.get_id())+","+str(r.get_b_id())+","+str(r.get_c_id())+","+date_to_str_format(r.get_rent_date())+","+date_to_str_format(r.get_due_date())+","+date_to_str_format(r.get_returned_date())+"\n")
                else:
                    f.write(str(r.get_id())+","+str(r.get_b_id())+","+str(r.get_c_id())+","+date_to_str_format(r.get_rent_date())+","+date_to_str_format(r.get_due_date())+"\n")
        except Exception as e:
            raise RepoError("Error writing file" +str(e))
        finally:
            f.close()
            
    def _loadFile(self):
        
        try:
            
            f = open(self._fileName, "r")
            s = f.readline()
            
            while len(s)>1:
                tok = s.split(",")
                if len(tok) == 5:
                    tok[4] = tok[4].split("\n")
                    rental = Rental(int(tok[0]), int(tok[1]), int(tok[2]), tok[3],  tok[4][0])
                else:
                    tok[5] = tok[5].split("\n")
                    rental = Rental(int(tok[0]), int(tok[1]), int(tok[2]),  tok[3],  tok[4],  tok[5][0])
                RentalRepository.add(self, rental)
                s = f.readline()
        except Exception as e:
            raise RepoError("Error reading input file: " + str(e))
        finally:
            f.close()
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
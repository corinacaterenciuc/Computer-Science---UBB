'''
Created on Dec 11, 2018

@author: Korina
'''
from repo.RentalTextFileRepo import RentalTextFileRepo
from model.rental import Rental
from extra_help import date_to_str_format
from repo.rental_repository import RentalRepository
import json
from json.decoder import JSONDecodeError
from errors.error import RepoError


class Rental_JSON_Repo(RentalTextFileRepo):
    def __init__(self, fileName = "rentals.json"):
        RentalTextFileRepo.__init__(self, fileName)
        
    def json_to_rental(self, json_rental):
        if "retur_date" in json_rental:
            return Rental(int(json_rental["id"]), int(json_rental["b_id"]), int(json_rental["c_id"]), json_rental["rent_date"], json_rental["due_date"], json_rental["retur_date"])
        return Rental(int(json_rental["id"]), int(json_rental["b_id"]), int(json_rental["c_id"]), json_rental["rent_date"], json_rental["due_date"])
        
    def rental_to_json(self, rental):
        if rental.get_returned_date()!= None:
            return {"id":rental.get_id(), "b_id":rental.get_b_id(),"c_id":rental.get_c_id(), "rent_date": date_to_str_format(rental.get_rent_date()), "due_date": date_to_str_format(rental.get_due_date()),"rentur_date": date_to_str_format(rental.get_returned_date()) }
        return {"id":rental.get_id(), "b_id":rental.get_b_id(),"c_id":rental.get_c_id(), "rent_date": date_to_str_format(rental.get_rent_date()), "due_date": date_to_str_format(rental.get_due_date()) }
    
    def _saveFile(self):
        json_list = []
        for r in self.get_rentals():
            json_list.append(self.rental_to_json(r))
            
        with open(self._fileName, "w") as f:
            json.dump(json_list, f)    
    
    def _loadFile(self):
        with open(self._fileName, "r") as f:
            try:
                
                json_rentals = json.load(f)
                for r in json_rentals:
                    rental = self.json_to_rental(r)
                    RentalRepository.add(self, rental)
            except JSONDecodeError as je:
                raise RepoError("could not load file: "+str(je))
                
                
                
                
                
                
                
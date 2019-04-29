'''
Created on Nov 26, 2018

@author: Korina
'''
from errors.error import RepoError
import json
from extra_help import date_to_str_format


class RentalRepository:
    def __init__(self):
        self._rentals = []
        self._idx = 0
        
    def __next__(self):
        try:
            item = self._rentals[self._idx]
        except IndexError:
            raise StopIteration()
        self._idx += 1
        return item
        
    def __contains__(self, rental):
        return rental in self._rentals
    
    def __iter__(self):
        return iter(self._rentals)
    
        
    def find(self, rentalID):
        """
        Gets the rental with the given id
        Input: rentalID - positive integer
        Output: returns the rental with the given id if it exists
                returns None otherwise
        """
        for i in self.get_rentals():
            if i.get_id() == rentalID:
                return i
        return None
        
        
    def add(self, rental):
        """
        Adds the given rental in the repository
        Input: rental - an object of the class Rental
        Exceptions: RepoError - if the rental exists in the repository already
        """
        if rental in self._rentals:
            raise RepoError("! This book rental exists already")
        self._rentals.append(rental)

    def remove(self,rental ):
        """
        Removes the given rental from the repository
        Input: rental - an object of the class Rental
        Exceptions: RepoError - if the rental does not exist in the repository 
        """
        if rental not in self._rentals:
            raise RepoError("! There is no such rental, so it cannot be removed")
        i=0
        while i < len(self._rentals):
            if self._rentals[i] == rental:
                del self._rentals[i]
                return 
            else:
                i+=1
                
    def update(self, rental):
        """
        Updates the given rental (changes every attribute except the rental id)
        Input: rental - an object of the class Rental
        Output: r - the oldest version of the updated rental
        Exception: RepoError -  if the rental does not exist in the repository
        """
        if rental not in self._rentals:
            raise RepoError("! We cannot update the rentas, as it does not exist.")
        
        for i in range (0,len(self._rentals)):
            if self._rentals[i] == rental:
                r = self._rentals[i]
                self._rentals[i] = rental
                return r
                
    def available_rent(self,rental):
        """
        Checks id the book from the given rent is available to be rented
        Input: rental - an object of the class Rental
        Exceptions: RepoError - if the book is not available to be rented
        """
        for i in range (0,len(self._rentals)):
            if self._rentals[i].get_b_id() == rental.get_b_id() and (self._rentals[i].get_returned_date() == None):
                raise RepoError("! The book is not available at the moment")
        return
    
    def get_rentals(self):
        """
        Returns a list containing the rentals in the repository
        """
        return self._rentals[:]
        
    
    def __len__(self):
        """
        Returns the amount of rentals that exist in the repository
        """
        return len(self._rentals)

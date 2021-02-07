'''
Created on Nov 22, 2018

@author: Korina
'''
from datetime import datetime
from errors.error import ValidError

class Rental:
    """
    Rental has attributes such as: id, b_id, c_id, r_date, due_date, returned_date
    """
    def __init__(self, rent_id, b_id, c_id, r_date, due_date, returned_date=None):
        
        self.__id = rent_id
        self.__b_id = b_id
        self.__c_id = c_id
        self.__rent_date = Rental.__to_date(r_date)
        self.__due_date = Rental.__to_date(due_date)
        if returned_date != None:
            self.__returned_date = Rental.__to_date(returned_date)
        else:
            self.__returned_date = returned_date
    

    def get_id(self):
        return self.__id


    def get_b_id(self):
        return self.__b_id


    def get_c_id(self):
        return self.__c_id


    def get_rent_date(self):
        return self.__rent_date


    def get_due_date(self):
        return self.__due_date


    def get_returned_date(self):
        return self.__returned_date


    def set_rent_date(self, value):
        self.__rent_date = Rental.__to_date(value)


    def set_due_date(self, value):
        self.__due_date = Rental.__to_date(value)


    def set_returned_date(self, value):
        if value != None:
            self.__returned_date = Rental.__to_date(value)
        else:
            self.__returned_date = value

        
    def days(self):
        """
        Returns the number of days a book has been rented for
        """
        if self.returned_date == None:
            return ( datetime.today()- self.rent_date).days +1
        return (self.returned_date -  self.rent_date).days +1
    
    def is_late(self):
        if self.__returned_date == None:
            return True
        return False
    
    def how_late(self):
        if self.returned_date != None and self.returned_date> self.due_date:
            return (self.returned_date - self.due_date).days +1
        return (datetime.today() - self.due_date).days +1

    @staticmethod
    def __to_date(date):
        if date == "":
            raise ValidError("! invalid date")
        dformat = "%d.%m.%Y"
        
        return datetime.strptime(date, dformat)
        

    def __str__(self):
        return str(self.__id)+"_"+str(self.__b_id)+"_"+str(self.__c_id)+" \t "+str(self.__rent_date) + " \t " + str(self.__due_date) + " \t " + str(self.__returned_date)
    
    def __eq__(self,rent):
        return self.__id == rent.__id #and self.__b_id == rent.__b_id and self.__c_id == rent.__c_id
    
    id = property(get_id, None, None, None)
    b_id = property(get_b_id, None, None, None)
    c_id = property(get_c_id, None, None, None)
    rent_date = property(get_rent_date, set_rent_date, None, None)
    due_date = property(get_due_date, set_due_date, None, None)
    returned_date = property(get_returned_date, set_returned_date, None, None)
    
    





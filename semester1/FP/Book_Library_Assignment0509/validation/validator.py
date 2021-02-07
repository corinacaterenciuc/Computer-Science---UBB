'''
Created on Nov 22, 2018

@author: Korina
'''
from errors.error import ValidError

class BookValidator(object):
    
    def valid_book(self,book):
        """
        Validates each attribute of the object book (object of the class Book)
        Exceptions: ValidError - if the id is smaller or equal than 0
                                    or the title is an empty string
                                    or the author is an empty string
        """
        
        error = ""
        if book.get_id() <= 0:
            error += "! invalid ID"
        if book.get_title() == "":
            error += "! invalid Title"
        if book.get_author() == "":
            error += "! invalid Author"
            
        if len(error) != 0:
            raise ValidError(error)
        
        
        
class ClientValidator:
    
    
    def valid_client(self, client):
        """
        Validates each attribute of the object client (object of the class Client)
        Exceptions: ValidError - if the id is smaller or equal than 0
                                    or the name is an empty string
        """
        
        error = ""
        if client.get_id() <= 0:
            error += "! invalid ID\n"
        if client.get_name() == "":
            error += "! invalid Name\n"
            
        if len(error) != 0 :
            raise ValidError(error)


class RentalValidator(object):
    
    def valid_rent(self, rent):
        """
        Validates each attribute of the object rent (object of the class Rental)
        Exceptions: ValidError - if the rent id is smaller or equal than 0
                                    the book id is smaller or equal than 0
                                    the client id is smaller or equal than 0
                                    or the rented date is greater than the due date
                                    or the rented date  is greater than returned date
        """
        error = ""
        if rent.get_id() <= 0:
            error += "! invalid rent ID\n"
        if rent.get_b_id() <= 0:
            error += "! invalid book ID\n"
        if rent.get_c_id() <= 0:
            error += "! invalid client ID/n"
        if rent.get_rent_date() > rent.get_due_date():
            error += "! invalid date for due date\n"
            
        if rent.get_returned_date() != None:
            if rent.get_rent_date() > rent.get_returned_date():
                error += "! invalid returned  date\n"
            
        if len(error) !=0:
            raise ValidError(error)






'''
Created on Nov 26, 2018

@author: Korina
'''

class BookRentalDays:
    def __init__(self, book, days):
        self.__book = book
        self.__days = days
        
    def __str__(self):
        return str(self.__days) +" \t "+ str(self.__book)
    
    def __lt__(self, another):
        return self.__days < another.__days       
    def get_book(self):
        return self.__book    
    def get_days(self):
        return self.__days
    @property
    def days(self):
        return self.__days
            
class ClientRentalDays:
    
    def __init__(self, client, days):
        self.__client = client
        self.__days = days
        
    def __str__(self):
        return str(self.__days) +" \t "+ str(self.__client)
    
    def __lt__(self, another):
        return self.__days < another.__days  
    
    @property
    def days(self):
        return self.__days
    
class AuthorRentalDays:
    def __init__(self, author, days):
        self.__author = author
        self.__days = days
        
    def __str__(self):
        return str(self.__days)+" \t "+str(self.__author)
    
    def __lt__(self, another):
        return self.__days < another.__days
    
    @property
    def days(self):
        return self.__days
    @property
    def author(self):
        return self.__author
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
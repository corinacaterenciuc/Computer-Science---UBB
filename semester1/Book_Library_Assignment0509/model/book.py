'''
Created on Nov 22, 2018

@author: Korina
'''
import unittest
class Book:
    """
    Books with attributes such as: id, title, description and author.
    Allows objects to be added, removed, updated and listed.
    """
    
    

    def __init__(self, book_id, title, author, description = None):

        self.__id = book_id
        self.__title = title
        self.__description = description
        self.__author = author
    
    def set_title(self, value):
        """
        Changes the title
        """
        self.__title = value


    def set_description(self, value):
        self.__description = value


    def set_author(self, value):
        self.__author = value

        
    def __eq__(self, book):
        return self.__id == book.__id
    
    def get_id(self):
        return self.__id


    def get_title(self):
        return self.__title


    def get_description(self):
        return self.__description


    def get_author(self):
        return self.__author

    def __str__(self):
        if self.__description != None:
            return (" {},  {} by {},  described as follows: {}".format(self.__id, self.__title,self.__author,self.__description))
        else:
            return (" {},  {} by {}".format(self.__id, self.__title,self.__author))
    

    id = property(get_id, None, None, None)
    title = property(get_title, None, None, None)
    description = property(get_description, None, None, None)
    author = property(get_author, None, None, None)
    title = property(None, set_title, None, None)
    description = property(None, set_description, None, None)
    author = property(None, set_author, None, None)



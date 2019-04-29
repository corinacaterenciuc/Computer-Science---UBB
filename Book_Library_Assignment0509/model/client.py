'''
Created on Nov 22, 2018

@author: Korina
'''
class Client:
    """
    Clients with attributes such as: id and name
    Allows objects to be added, removed, updated and listed.
    """
    def __init__(self, client_id, name):
        self.__id = client_id
        self.__name = name

    def set_name(self, value):
        self.__name = value


    def get_name(self):
        return self.__name


    def get_id(self):
        return self.__id


    def del_name(self):
        del self.__name

        
    def __eq__(self,client):
        return self.__id == client.__id


    def __str__(self):
        return str(self.__id)+" \t "+ self.__name

    id = property(get_id, None, None, None)
    name = property(get_name, set_name, del_name, None)




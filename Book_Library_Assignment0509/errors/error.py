'''
Created on Nov 22, 2018

@author: Korina
'''
class LibraryError(Exception):
    """
    Catches errors from the Business (Library) layer
    """
    pass


class ValidError(Exception):
    """
    Catches errors from the Model layer
    """
    pass


class RepoError(Exception):
    """
    Catches errors from the Repository layer
    """
    pass

class UndoError(Exception):
    """
    Catches errors from the Undo Service
    """
    pass



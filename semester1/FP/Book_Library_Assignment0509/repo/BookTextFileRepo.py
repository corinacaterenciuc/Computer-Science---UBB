'''
Created on Nov 28, 2018

@author: Korina
'''
from repo.book_repository import BookRepository
from model.book import Book
from errors.error import RepoError
from _io import open



class BookTextFileRepo(BookRepository):
    def __init__(self, fileName = "books.txt"):
        BookRepository.__init__(self)
        self._fileName = fileName
        self._loadFile()
        
    def add(self, book):
        BookRepository.add(self,book)
        self._saveFile()
         
    def remove(self, book):
        b = BookRepository.remove(self, book)
        self._saveFile()
        return b

    def update(self, book):
        b = BookRepository.update(self, book)
        
        self._saveFile()
        return b
        
    def _saveFile(self):
        try:
                
            f = open(self._fileName, "w")
            for b in BookRepository.get_books(self):
                """
                function to turn entity into string
                
                """
                if b.get_description() != None:
                    f.write(str(b.get_id()) +","+b.get_title()+","+ b.get_author()+","+b.get_description()+"\n")
                else:
                    f.write(str(b.get_id()) +","+b.get_title()+","+ b.get_author()+"\n")
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
                """
                function to turn string into entity
                """
                if len(tok) == 3:
                    tok[2] = tok[2].split("\n")
                    book = Book(int(tok[0]), tok[1], tok[2][0])
                else:
                    tok[3] = tok[3].split("\n")
                    book = Book(int(tok[0]), tok[1], tok[2], tok[3][0])
                BookRepository.add(self, book)
                s = f.readline()
            
            
        except Exception as e:
            raise RepoError("Error reading input file: " + str(e))
        finally:
            f.close()
    
    























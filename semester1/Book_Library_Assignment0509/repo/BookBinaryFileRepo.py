from repo.book_repository import BookRepository
from errors.error import RepoError
import pickle
from model.book import Book


class BookBinaryFileRepo(BookRepository):
    def __init__(self, fileName = "books.pickle"):
        BookRepository.__init__(self)
        self._fileName = fileName
        self._loadBinaryFile()
        
    def add(self, book):
        BookRepository.add(self, book)
        self._saveBinaryFile()
        
    def update(self, book):
        b = BookRepository.update(self, book)
        self._saveBinaryFile()
        return b
        
    def _saveBinaryFile(self):
        f = open(self._fileName, "wb")
        pickle.dump(self._books, f)
        f.close()    
    
        
    def _loadBinaryFile(self):
        try:
            f = open(self._fileName, "rb")
            self._books = pickle.load(f)
        except EOFError:
            self._books = []
        except IOError as ioe:
            raise RepoError("An error occured: "+str(ioe))
        finally:
            f.close()
            
            
            


'''
Created on Nov 26, 2018

@author: Korina
'''
from errors.error import RepoError



class BookRepository:
    
    def __init__(self):
        self._books = []
        self._idx = 0
        
    def __next__(self):
        try:
            item = self._books[self._idx]
        except IndexError:
            raise StopIteration()
        self._idx += 1
        return item
        
    def __contains__(self, book):
        return book in self._books
    
    def __iter__(self):
#         self._idx = 0
#         return self
        return iter(self._books)
        
    def __len__(self):
        """
        Returns the amount of books existing in the repository
        """
        return len(self._books)

    
    
    def find(self, bookID):
        """
        Gets the book with the given id
        Input: bookID - positive integer
        Output: returns the book with the given id if it exists 
                return None if the book does not exist
        """
        for b in self.get_books():
            if b.get_id() == bookID:
                return b
        return None
    
    def exists_book(self, book):
        """
        Verifies if the given book exists in the repository
        Input: book - an object of the Class Book
        Output: True if the book exists in the repository
                False otherwise
        """
        if book in self._books:
            return True
        return False
    
    def add(self,book):
        """
        Adds a given book to the repository
        Input: book - an object of the class Book
        Output: 
        Exceptions: RepoError - if the book exists in the repository already
                    
        """        
        if book in self._books:
            raise RepoError("! We already have this book.")
        self._books.append(book)

        
    def remove(self,book):
        """
        Removes the given book from the repository
        Input: book - an object of the class Book
        Output:
        Exceptions: RepoError - if the book does not exist in the repository 
        """
        if book not in self._books:
            raise RepoError("! We don't even have that book.")
        i=0 
        while i < len(self._books):
            if self._books[i] == book:
                b=self._books[i]
                del self._books[i]
            else:
                i+=1
                
        return b
    
    def update(self, book):
        """
        Updates the given book ( changes only the title, author or description)
        Input: book - an object of the class Book
        Output: b - the old version of the book
        Exceptions: RepoError - if the book does not exist in the repository 
        """
        if book not in self._books:
            raise RepoError("! We can't update the book because it doesn't exist.")
        
         
        for i in range (0,len(self._books)):
            if self._books[i] == book:
                b=self._books[i]
                self._books[i] = book
                return b        
            
    def list(self):
        """
        Gives a list containing the books as printable strings
        Input: 
        Output: a list of the books in the repository
        Exceptions: RepoError - if the repository is empty
        """
        if len(self._books) == 0:
            raise RepoError("! Nothing to list")
        books = "ID \t Title \t  Author \t\t\t\t Description \n"
        for i in range(0,len(self._books)):
            books += str(self._books[i])+"\n"
        return books
    
    def get_books(self):
        """
        Returns the list representing the repository
        """
        return self._books[:]
    
    def search_id(self, Id):
        """
        Searches for the books which have at least a part of their id equal to the given id
        Input: id - positive integer
        Output: search_result -  a list of books which satisfy the criteria
        """
        search_result = []
        Id = str(Id)
        for b in self._books:
            if str(b.get_id()).find(Id)!=-1:
                search_result.append(b)
        return search_result
    
    def search_title(self, title):
        """
        Searches for the books which have at least a part of their title equal to the given title
        Input: title - string
        Output: search_result -  a list of books which satisfy the criteria
        """
        search_result = []
        for b in self._books:
            if b.get_title().lower().find(title.lower())!=-1:
                search_result.append(b)
        return search_result
    
    def search_author(self, author):
        """
        Searches for the books which have at least a part of their author equal to the given author
        Input: author - string
        Output: search_result -  a list of books which satisfy the criteria
        """
        search_result = []
        for b in self._books:
            if b.get_author().lower().find(author.lower())!=-1:
                search_result.append(b)
        return search_result
    
    def search_description(self, description):
        """
        Searches for the books which have at least a part of their description equal to the given description
        Input: description - string
        Output: search_result -  a list of books which satisfy the criteria
        """
        search_result = []
        for b in self._books:
            if b.get_description() != None:
                if b.get_description().lower().find(description.lower())!=-1:
                    search_result.append(b)
        return search_result
    
    

    
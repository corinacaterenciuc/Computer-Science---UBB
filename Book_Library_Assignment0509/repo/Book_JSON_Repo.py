'''
Created on Dec 11, 2018

@author: Korina
'''
from repo.BookTextFileRepo import BookTextFileRepo
import json
from model.book import Book
from repo.book_repository import BookRepository
from errors.error import RepoError
from json.decoder import JSONDecodeError


class Book_JSON_Repo(BookTextFileRepo):
    def __init__(self, fileName = "books.json"):
        BookTextFileRepo.__init__(self, fileName)
        

    def json_to_book(self, json_book):
        
        if "description" in json_book:
            return Book(int(json_book["id"]), json_book["title"], json_book["author"], json_book["description"])
        return Book(int(json_book["id"]), json_book["title"], json_book["author"])
        


    def book_to_json(self, book):
        
        if book.get_description()!= None:
            return {"id": str(book.get_id()), "title": book.get_title(), "author": book.get_author(), "description": book.get_description()}
        return {"id": str(book.get_id()), "title": book.get_title(), "author": book.get_author()}
        
    def _saveFile(self):
        json_list = []
        for b in self.get_books():
            json_list.append(self.book_to_json(b))
            
        with open(self._fileName, "w") as f:
            json.dump(json_list, f)
    
    def _loadFile(self):
        with open(self._fileName, "r") as f:
            try:
                json_books = json.load(f)
                for b in json_books:
                    book = self.json_to_book(b)
                    BookRepository.add(self, book)
            except JSONDecodeError as je:
                raise RepoError("could not load file: "+str(je))
                
                
                
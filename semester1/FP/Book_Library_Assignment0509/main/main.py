
'''
Created on 4 nov. 2018

@author: corina
'''


from validation.validator import RentalValidator, BookValidator, ClientValidator
from repo.book_repository import BookRepository
from repo.client_repository import ClientRepository
from repo.rental_repository import RentalRepository

from business.client_service import ClientService
from business.book_service import BookService
from business.rental_service import RentalService
from business.undo_service import UndoService 
from ui.console import  Console

from random import randint
from datetime import datetime, timedelta
from extra_help import date_to_str_format
from repo.ClientTextFileRepo import ClientTextFileRepo
from repo.RentalTextFileRepo import RentalTextFileRepo

from repo.BookBinaryFileRepo import BookBinaryFileRepo
from repo.ClientBinaryFileRepo import ClientBinaryFileRepo
from repo.RentalBinaryFileRepo import RentalBinaryFileRepo
from ui.GUI import GUI
from repo.Book_JSON_Repo import Book_JSON_Repo
from repo.Client_JSON_Repo import Client_JSON_Repo
from repo.Rental_JSON_Repo import Rental_JSON_Repo



"""
Assignment 8
"""

from repo.BookTextFileRepo import BookTextFileRepo

def readSettings():
    
    settings = {}
     
    f = open("settings")  
    tokens = f.read().split("\n") 
     
    for tok in tokens:
        t = tok.split("=")
        settings[t[0].strip()] = t[1].strip()
    return settings
         
settings = readSettings()
 
book_repo = None
 
if settings["repo_type"] == "memory":
    book_repo = BookRepository()
    client_repo = ClientRepository()
    rental_repo = RentalRepository()
elif settings["repo_type"] == "text":
    book_repo = BookTextFileRepo(settings["book_repo_file"])
    client_repo = ClientTextFileRepo(settings["client_repo_file"])
    rental_repo = RentalTextFileRepo(settings["rental_repo_file"])
elif settings["repo_type"] == "binaryfile":
#     print("its here")
    book_repo = BookBinaryFileRepo(settings["book_repo_file"])
    client_repo = ClientBinaryFileRepo(settings["client_repo_file"])
    rental_repo = RentalBinaryFileRepo(settings["rental_repo_file"])
elif settings["repo_type"] == "json":
    book_repo = Book_JSON_Repo(settings["book_repo_file"])
    client_repo = Client_JSON_Repo(settings["client_repo_file"])
    rental_repo = Rental_JSON_Repo(settings["rental_repo_file"])
    
    
book_valid = BookValidator()


client_valid = ClientValidator()


rental_valid = RentalValidator()

undo_ser = UndoService() # creating an object of the class UndoService
rental_serv = RentalService(rental_repo, rental_valid, book_repo, client_repo, undo_ser)

book_serv = BookService(book_repo, book_valid, undo_ser, rental_serv)
"""
Populating the book repository
"""
if  not isinstance(book_repo, BookTextFileRepo) and not isinstance(book_repo, BookBinaryFileRepo):
    authors = open("author_names").read().splitlines()
    titles = open("book_titles").read().splitlines()
    descriptions = open("book_descriptions").read().splitlines()
    for i in range (0, len(authors)):
        if i%3 == 2:
            book_serv.add_book(i*56+25, titles[i], authors[i], descriptions[i//3-1])
        else:
            book_serv.add_book(i*56+25, titles[i], authors[i])
            
    



client_serv = ClientService(client_repo, client_valid, undo_ser, rental_serv)
"""
Populating the client repository
"""
if  not isinstance(client_repo, ClientTextFileRepo) and not isinstance(client_repo, ClientBinaryFileRepo):
    names = open("client_names").read().splitlines()
    for i in range (0,len(names)):
        client_serv.add_client(i*8952+521, names[randint(0,len(names)-1)])

    


"""
Populating the rental repository
"""
if  not isinstance(rental_repo, RentalTextFileRepo) and not isinstance(rental_repo, RentalBinaryFileRepo):
    
    for i in range (100):
        date =str(randint(1,28))+"."+ str(randint(1,10))+"."+ str(randint(2016,2018))
        dformat = "%d.%m.%Y"
        
        duedate = datetime.strptime(date, dformat) + timedelta(days = 7)
        duedate = date_to_str_format(duedate)
        returdate = datetime.strptime(date, dformat) + timedelta(days = randint(3,11))
        returdate = date_to_str_format(returdate)
        if i%3 == 0:
            rental_serv.rent(i*46+77, i*56+25, i*8952+521, date , duedate, returdate)
        else:
            rental_serv.rent(i*46+77, i*56+25, i*8952+521,date , duedate)
        
        


"""
creating an object of the class Console and running the program
"""
console = None
 
if settings["ui"] == "console":
    console = Console(book_serv, client_serv, rental_serv, undo_ser)
elif settings["ui"] == "GUI":
    console = GUI(book_serv, client_serv, rental_serv, undo_ser)


console.run_console()



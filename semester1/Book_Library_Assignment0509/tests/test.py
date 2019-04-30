from errors.error import ValidError,RepoError, LibraryError
from datetime import datetime

from model.book import Book
from validation.validator import BookValidator
from repo.book_repository import BookRepository

from business.client_service import ClientService
from business.book_service import BookService

import unittest
from GnomeSort_and_Filter import GnomeSort, k_filter

class Test_Book(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
        self.__id = 23
        self.__title = "FP"
        self.__description = "work on your assignments daily"
        self.__author = "Arthur Molnar"
        self.__book = Book(self.__id, self.__title, self.__author, self.__description)
        
        self.__noid = -85
        self.__notitle = ""
        self.__noauthor = ""
        self.__nobook = Book(self.__noid, self.__notitle, self.__noauthor,self.__description)
 
        self.__validator = BookValidator()
        self.__repo = BookRepository()
      
        
    def tearDown(self):
        unittest.TestCase.tearDown(self)
    
    def test_Model(self):
        
        self.assertEqual(self.__book.get_id(), self.__id)
        self.assertEqual(self.__book.get_author(), self.__author)
        self.assertEqual(self.__book.get_description(), self.__description)
        self.assertEqual(self.__book.get_title(), self.__title)
        self.__book.set_title("Work harder")
        self.assertEqual(self.__book.get_title(), "Work harder")
        self.__book.set_author("somebody")
        self.assertEqual(self.__book.get_author(), "somebody")
        self.__book.set_description("Can't do this anymore")
        self.assertEqual(self.__book.get_description(), "Can't do this anymore")
        self.assertEqual(self.__book==self.__book, True)
                
    def test_Valid(self):
        self.assertRaises(ValidError, self.__validator.valid_book, self.__nobook)
        
        with self.assertRaises(ValidError):
            self.__validator.valid_book(self.__nobook)
    
    def test_Repo(self):
        
        self.assertEqual( len(self.__repo), 0)
        self.__repo.add(self.__book)
        self.assertEqual( len(self.__repo), 1)
        
        
        
        with self.assertRaises(RepoError):
            self.__repo.add(self.__book)
        
        with self.assertRaises(RepoError):
            self.__repo.remove(self.__nobook)
                         
        with self.assertRaises(RepoError):
            self.__repo.update(self.__nobook)
            
        self.__repo.update(self.__book)
        self.assertEqual( self.__repo.list(), \
                          "ID \t Title \t  Author \t\t\t\t Description \n {},  {} by {},  described as follows: {}\n".\
                          format(self.__id, self.__title,self.__author,self.__description))
        self.__repo.remove(self.__book)
        with self.assertRaises(RepoError):
            self.__repo.list()
            
        
        self.__repo.add(self.__book)
        book = Book(45, "ASC", "Vancea", "du-te la cursurile de ASC")
        self.__repo.add(book)
        self.assertEqual(self.__repo.find(45), book)
        self.assertEqual(self.__repo.find(9), None)
        
        self.assertEqual(self.__repo.exists_book(book), True)
        self.assertNotEqual(len(self.__repo.get_books()), 0)
        self.assertEqual(len(self.__repo.search_id(45)), 1)
        self.assertEqual(len(self.__repo.search_author("van")), 1)
        self.assertEqual(len(self.__repo.search_description("ursuri")), 1)
        self.assertEqual(len(self.__repo.search_title("asc")), 1)
        
        




from model.client import Client
from validation.validator import ClientValidator
from repo.client_repository import ClientRepository

class Test_Client(unittest.TestCase):
    def setUp(self):
        
        self.__id = 3
        self.__name = "Corina"
        self.__client = Client(self.__id, self.__name)
        
        self.__meanid = -5
        self.__meanname = ""
        self.__meanclient = Client(self.__meanid, self.__meanname)
        
        self.__validator = ClientValidator()
        
        self.__repo = ClientRepository()
        self.__newname = "Korina"
        self.__updateclient = Client(self.__id, self.__newname)
        
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        
    def test_model(self):
        self.assertEqual(self.__client.get_id(),self.__id)
        self.assertEqual(self.__client.get_name() ,self.__name)
        self.__client.del_name()
        self.__client.set_name("Korina")
        self.assertEqual(self.__client.get_name(), "Korina")
        
    def test_validator(self):
        
        try:
            self.__validator.valid_client(self.__client)
            assert True
        except ValidError as ve:
            assert False
            
        with self.assertRaises(ValidError):
            self.__validator.valid_client(self.__meanclient)
            
    def test_repo(self):
        
        self.assertEqual(len(self.__repo), 0)
        self.__repo.add(self.__client)
        self.assertEqual(len(self.__repo), 1)
        
        with self.assertRaises(RepoError):
            self.__repo.add(self.__client)
        
        c= Client(5 , "Adrian")
        with self.assertRaises(RepoError):
            self.__repo.remove(c)
            
        try:
            self.__repo.remove(self.__client)
            assert True
        except RepoError as re:
            assert False
        
        self.__repo.add(self.__client)
        with self.assertRaises(RepoError):
            self.__repo.update(c)
            
        try:
            self.__repo.update(self.__updateclient)
            assert True
        except RepoError as re:
            assert False
            
        try:
            assert self.__repo.list() == "ID \t Name \n3 \t Korina\n"
        except RepoError as re:
            assert False
            
        self.__repo.remove(self.__updateclient)
        with self.assertRaises(RepoError):
            assert self.__repo.list() == "ID \t Name \n"
        self.__repo.add(self.__client)
        self.assertEqual(self.__repo.find(3), self.__client)
        self.assertEqual(self.__repo.find(999), None)
        self.assertEqual(self.__repo.exists_client(self.__client), True)
        self.assertEqual(len(self.__repo.search_id(3)), 1)
        self.assertEqual(len(self.__repo.search_name("rina")), 1)
        
        
        

        
        


from model.rental import Rental
from validation.validator import RentalValidator
from repo.rental_repository import RentalRepository

from business.rental_service import RentalService
from business.undo_service import *


class Test_Rental(unittest.TestCase):
    
    def setUp(self):
        self.__rid = 4
        self.__bid = 8
        self.__cid = 2
        self.__rdate = "25.11.2018"
        self.__duedate = "2.12.2018"
        self.__returdate = "28.11.2018"
        self.__rental = Rental(self.__rid, self.__bid, self.__cid, self.__rdate, self.__duedate, self.__returdate)
        
        self.__validator = RentalValidator()
        
        self.__repo = RentalRepository()
        #self.__lib = Library(self.__repo, self.__validator)
        
    def test_model(self):
        formatt = "%d.%m.%Y"
        
        self.assertEqual(self.__rental.get_id(), self.__rid)
        self.assertEqual(self.__rental.get_b_id(), self.__bid)
        self.assertEqual(self.__rental.get_c_id(), self.__cid)
        self.assertEqual(self.__rental.get_rent_date(), datetime.strptime("25.11.2018", formatt))
        self.assertEqual(self.__rental.get_due_date(), datetime.strptime(self.__duedate, formatt))
        self.assertEqual(self.__rental.get_returned_date(), datetime.strptime(self.__returdate, formatt))
        self.__rental.set_rent_date("11.11.2018")
        self.__rental.set_due_date("18.11.2018")
        self.__rental.set_returned_date("15.11.2018")
        self.assertEqual(self.__rental.get_rent_date(), datetime.strptime("11.11.2018", formatt))
        self.assertEqual(self.__rental.get_due_date(), datetime.strptime("18.11.2018", formatt))
        self.assertEqual(self.__rental.get_returned_date(), datetime.strptime("15.11.2018", formatt))
        self.assertEqual(self.__rental.days(), 5)
        self.assertEqual(self.__rental.is_late(), False)
        self.__rental.set_returned_date(None)
        self.assertEqual(self.__rental.how_late(), 24)
        self.assertEqual(str(self.__rental), \
                         str(self.__rid)+"_"+\
                         str(self.__bid)+"_"+str(self.__cid)+" \t "+\
                         str(self.__rental.get_rent_date()) \
                         + " \t " + str(self.__rental.get_due_date())+" \t "+ str(self.__rental.get_returned_date()))
        
        
    def test_validator(self):
        try:
            self.__validator.valid_rent(self.__rental)
            assert True
        except ValidError as ve:
            assert False
        with self.assertRaises(ValidError):
            r1 = Rental(-3, 0, -8, "", "", "")  
            
        r2 = Rental(-3, 0, -8, "12.11.2018", "10.11.2018", "11.11.2018")
        with self.assertRaises(ValidError):
            self.__validator.valid_rent(r2)
             
             
    def test_repo(self):
        self.assertEqual(len(self.__repo), 0)
        self.__repo.add(self.__rental)
        self.assertEqual(len(self.__repo), 1)
        
        with self.assertRaises(RepoError):
            self.__repo.add(self.__rental)
            
        try:
            self.__repo.remove(self.__rental)
            assert True
        except RepoError as re:
            assert False
            
        with self.assertRaises(RepoError):
            self.__repo.remove(self.__rental)
        
        r1 = Rental(1, 1, 1, "12.09.2018", "20.09.2018") 
        self.__repo.add(r1)
        r2 = Rental(2,1,3, "15.09.2018", "25.09.2018")
        
        with self.assertRaises(RepoError):
            self.__repo.available_rent(r2)
        
        
        self.assertEqual(self.__repo.find(1), r1)
        self.assertEqual(self.__repo.find(999), None)
        self.__repo.add(r2)
        self.__repo.remove(r2)
        self.assertEqual(len(self.__repo.get_rentals()), 1)
        
            
            
class Test_Business(unittest.TestCase):
    def setUp(self):
        
        self.__id_b = 23
        self.__title = "FP"
        self.__description = "work on your assignments daily"
        self.__author = "Arthur Molnar"
        self.__book = Book(self.__id_b, self.__title, self.__author, self.__description)
 
        self.__id_cl = 3
        self.__name = "Corina"
        self.__client = Client(self.__id_cl, self.__name)
         
        self.__rid = 4
        self.__bid = 8
        self.__cid = 2
        self.__rdate = "25.11.2018"
        self.__duedate = "2.12.2018"
        self.__returdate = "28.11.2018"
        self.__rental = Rental(self.__rid, self.__bid, self.__cid, self.__rdate, self.__duedate, self.__returdate)
 
        self.__bvalid = BookValidator()
        self.__cvalid = ClientValidator()
        self.__rvalid = RentalValidator()
         
        self.__brepo = BookRepository()
        self.__crepo = ClientRepository()
        self.__rrepo = RentalRepository()
        
        self.__undoserv = UndoService()
        
        self.__rental_serv = RentalService(self.__rrepo, self.__rvalid,  self.__brepo, self.__crepo, self.__undoserv,)
        self.__book_serv = BookService(self.__brepo, self.__bvalid, self.__undoserv, self.__rental_serv)
        self.__client_serv = ClientService(self.__crepo, self.__cvalid, self.__undoserv, self.__rental_serv)
        #self.__library = Library(self.__brepo, self.__crepo, self.__rrepo, self.__bvalid, self.__cvalid, self.__rvalid)
         
         
    def test_book_service(self):
        self.__book_serv.add_book(self.__bid, self.__title, self.__author, self.__description)
        self.assertEqual(len(self.__brepo), 1) 
         
        
        with self.assertRaises(ValidError):
            self.__book_serv.add_book(-1, "", "")
            
        self.__book_serv.remove_book(self.__bid)
        self.assertEqual(len(self.__brepo), 0) 
        
        self.__book_serv.add_book(self.__id_b, self.__title, self.__author, self.__description)
        self.__book_serv.update_book(self.__id_b, "Updated title", "updated author", "do sth i am giving up on you")
        self.assertEqual(len(self.__book_serv.search_books_id(self.__id_b)), 1)
        self.assertEqual(len(self.__book_serv.search_books_title("tit")), 1)
        self.assertEqual(len(self.__book_serv.search_books_author("date")), 1)
        self.assertEqual(len(self.__book_serv.search_books_description("giving up")), 1)
        
        self.__client_serv.add_client(self.__id_cl, self.__name)
        self.__rental_serv.rent(self.__rid, self.__id_b, self.__id_cl, self.__rdate, self.__duedate, self.__returdate)
        self.__book_serv.remove_book(self.__id_b)
        self.assertEqual(len(self.__brepo), 0) 
        
    def test_client_service(self):
        self.__client_serv.add_client(self.__id_cl, self.__name)
        self.assertEqual(len(self.__crepo), 1) 
        
        with self.assertRaises(ValidError):
            self.__client_serv.add_client(-4, "")
            
        self.__client_serv.remove_client(self.__id_cl)
        self.assertEqual(len(self.__crepo), 0)
        
        self.__client_serv.add_client(self.__id_cl, self.__name)
        self.__client_serv.update_client(self.__id_cl, "Korina")
        self.assertEqual(len(self.__client_serv.search_client_id(self.__id_cl)), 1)
        self.assertEqual(len(self.__client_serv.search_client_name("rin")), 1)
        
        self.__book_serv.add_book(self.__id_b, self.__title, self.__author, self.__description)
        self.__rental_serv.rent(self.__rid, self.__id_b, self.__id_cl, self.__rdate, self.__duedate, self.__returdate)
        self.__client_serv.remove_client(self.__id_cl)
        self.assertEqual(len(self.__crepo), 0) 
        
    def test_rental_service(self):
        self.__book_serv.add_book(self.__id_b, self.__title, self.__author, self.__description)
        self.__book_serv.add_book(9, "hope", "workers", "hello")
        self.__book_serv.add_book(8, "hope", "workers", "hello")
        self.__client_serv.add_client(self.__id_cl, self.__name)
        self.__client_serv.add_client(99, "somebody")
        self.__client_serv.add_client(88, "somebody")
        self.__rental_serv.rent(self.__rid, self.__id_b, self.__id_cl, self.__rdate, self.__duedate, self.__returdate)
        self.assertEqual(len(self.__rrepo.get_rentals()), 1)
        
        self.__rental_serv.remove_rental(self.__rid)
        self.assertEqual(len(self.__rental_serv.list_rentals()), 0)
        self.assertEqual(len(self.__rrepo.get_rentals()), 0)
        
        self.__rental_serv.rent(self.__rid, self.__id_b, self.__id_cl, self.__rdate, self.__duedate)
        self.assertEqual(len(self.__rental_serv.filter_rentals(self.__id_b, self.__id_cl)), 1)
        self.__rental_serv.retur(self.__rid, self.__returdate)
        self.assertEqual(self.__rental_serv.list_rentals(), [self.__rental])
        self.__rental_serv.undo_retur(self.__rid)
        
        self.__rental_serv.rent(999, 9,99, "11.11.2018", "18.11.2018", "19.11.2018")
        self.__rental_serv.rent(1000, 9, 99, "11.09.2018", "18.09.2019")
        self.assertEqual(len(self.__rental_serv.most_rented_books()), 3)
        self.assertEqual(len(self.__rental_serv.most_active_clients()), 3)
        self.assertEqual(len(self.__rental_serv.most_rented_author()), 2)
        self.assertEqual(len(self.__rental_serv.late_rentals()), 3)
        
    def test_undo_service(self):
        self.__book_serv.add_book(self.__id_b, self.__title, self.__author, self.__description)
        self.__book_serv.add_book(9, "hope", "workers", "hello")
        self.__book_serv.add_book(8, "hope", "workers", "hello")
        self.__client_serv.add_client(self.__id_cl, self.__name)
        self.__client_serv.add_client(99, "somebody")
        self.__client_serv.add_client(88, "somebody")
        self.__rental_serv.rent(self.__rid, self.__id_b, self.__id_cl, self.__rdate, self.__duedate, self.__returdate)
        self.assertEqual(len(self.__rrepo.get_rentals()), 1)
        
        self.__rental_serv.remove_rental(self.__rid)
        self.assertEqual(len(self.__rental_serv.list_rentals()), 0)
        self.assertEqual(len(self.__rrepo.get_rentals()), 0)
        
        self.__rental_serv.rent(self.__rid, self.__id_b, self.__id_cl, self.__rdate, self.__duedate)
        self.__rental_serv.retur(self.__rid, self.__returdate)
        
        self.__rental_serv.rent(999, 9,99, "11.11.2018", "18.11.2018", "19.11.2018")
        self.__rental_serv.rent(1000, 9, 99, "11.09.2018", "18.09.2019")
        
        self.__undoserv.undo()
        self.assertEqual(len(self.__rental_serv.list_rentals()), 2)
        self.__undoserv.redo()
        self.assertEqual(len(self.__rental_serv.list_rentals()), 3)
        
        self.__client_serv.remove_client(99)
        self.assertEqual(len(self.__rental_serv.list_rentals()), 1)
        self.__undoserv.undo()
        self.assertEqual(len(self.__rental_serv.list_rentals()), 3)
        
        
class Test_GnomeSort(unittest.TestCase):
    def setUp(self):
        self._list_list = [[8,7],[3,0],[3,7],[8,9],[3,2],[1,5],[7,9],[0,8]]
        self._list_dict = [{"name": "Korina", "age": 21, "fav_color": "pink"},{"name": "Maria", "age": 21, "fav_color": "blue"},{"name": "Georgiana", "age": 19, "fav_color": "purple"},{"name": "Alexandra", "age": 19, "fav_color": "gray"}]
        
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        
    def test_list_of_list(self):
        GnomeSort(self._list_list, lambda x, y:x[1]<y[1] if x[0]==y[0] else x[0]<y[0])
        self.assertEquals(self._list_list[0][0], 0)
        self.assertEquals(self._list_list[3][1], 2)
        self.assertEquals(self._list_list[7][1], 9)
        self.assertEquals(self._list_list[7][0], 8)
    
    def test_list_of_dict(self):
        l = self._list_dict.copy()
        GnomeSort(self._list_dict, lambda x, y: x["name"]< y["name"])
        self.assertEqual(self._list_dict, sorted(l,key = lambda x: x["name"]))
        GnomeSort(self._list_dict, lambda x, y: x["age"]<y["age"] if x["age"]!=y["age"] else x["fav_color"]<y["fav_color"])
        self.assertEquals(self._list_dict, sorted(l,key = lambda x: (x["age"],x["fav_color"])))
        
        
class Test_k_filter(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
        self._list_list = [[8,1],[3,0],[3,7],[8,9],[3,2],[1,5],[7,9],[0,8]]
        self._list_dict = [{"name": "Korina", "age": 21, "fav_color": "pink"},{"name": "Maria", "age": 21, "fav_color": "blue"},{"name": "Georgiana", "age": 19, "fav_color": "purple"},{"name": "Alexandra", "age": 19, "fav_color": "gray"}]
        
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        
    def test_filter_list_of_list(self):
        self.assertEquals(len(k_filter(self._list_list, lambda x: x[0] > 2 and x[1]<=2)), 3)
        self.assertEquals(len(k_filter(self._list_list, lambda x: x[0]< 2 and x[1]<=2)), 0)
        self.assertEquals(len(k_filter(self._list_list, lambda x: x[0] == 3 and x[1]>0)), 2)
        self.assertEquals(len(k_filter(self._list_list, lambda x: x[0] <9 )), 8)
    
    def test_filter_list_of_dict(self):
        self.assertEquals(len(k_filter(self._list_dict, lambda x: x["name"] > "B" and x["age"]<=21)), 3)
        self.assertEquals(len(k_filter(self._list_dict, lambda x: x["name"] < "M" and x["age"]>21)), 0)
        self.assertEquals(len(k_filter(self._list_dict, lambda x: x["name"]=="Korina" and x["age"]<=21)), 1)
        self.assertEquals(len(k_filter(self._list_dict, lambda x: x["age"] > 19)), 2)
    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
#
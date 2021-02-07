'''
Created on Jan 6, 2019

@author: Korina
'''
from Game.Model import Board, Square
import unittest
from Game.game import Game
from Game.errors import GameException


class Test_Game(unittest.TestCase):
    def setUp(self):
        unittest.TestCase.setUp(self)
        
        self.__rows = 4
        self.__columns = 5
        self.__10board = Board(10,10)
        self.__board = Board(self.__rows, self.__columns)
        
        self.__game = Game([self.__rows, self.__columns])
        
        self.__sq1 = Square(1,1)
        self.__sq2 = Square(2,2)
        self.__sq34 = Square(3,4)
        self.__sq45 = Square(4,5)
        
    def tearDown(self):
        unittest.TestCase.tearDown(self)
        
        
    def test_board(self):
        self.assertEquals(len(self.__10board.empty_squares()), 10*10)
        self.assertEquals(len(self.__board.empty_squares()), self.__rows*self.__columns)
        
        self.assertEquals(self.__board.get_square(2,3), " ")
        
        self.assertEquals(self.__board.won(), False)
        
        self.__board.move(Square(2,3), "X")
        self.assertEquals(self.__board.get_square(2,3), "X")
        
        self.assertEquals(len(self.__board.empty_squares()), 11)
        self.assertEquals(self.__board.get_square(1,2), ".")
        
        try:
            self.__board.move(Square(2,3), "X")
            assert False
        except GameException as ge:
            self.assertEquals(str(ge) ,"Square already taken!")
        
        self.__board.move(Square(2,3), "E")
        self.assertEquals(self.__board.get_square(2,3), " ")
        
        self.assertEquals(len(self.__board.empty_squares()), 4*5)
        self.assertEquals(self.__board.get_square(1,2), " ")
        

    def test_game(self):
        
        self.assertEquals(len(self.__game.board.empty_squares()), self.__rows*self.__columns)
        
        self.__game.board.move(self.__sq1, "X")
        self.assertEquals(len(self.__game.board.empty_squares()), 11)
        
        try:
            self.__game.board.move(self.__sq45, "X")
            assert False
        except GameException as ge:
            self.assertEquals(str(ge), "Move outside board!")
            
        self.__game.board.move(self.__sq34, "O")
        self.assertEquals(len(self.__game.board.empty_squares()), 7)
        
        self.__game.board.move(Square(0,4), "X")
        
        board = self.__game.board.copy()
        best_move = self.__game.computer_AI(board, "computer", 0, -100, 100)

        self.assertEquals(str(best_move[0]), str(Square(3,0)))
        
        self.__game.computer_move()
        self.assertEquals(self.__game.board.get_square(3, 0), "O")
         
        self.__game.board.move(Square(3,2), "X")
         
        self.assertEquals(self.__game.board.won(), True)
        



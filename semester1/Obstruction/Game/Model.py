'''
Created on Dec 27, 2018

@author: Korina
'''
from texttable import Texttable
import copy
from Game.errors import GameException




class Square:
    """
    Represents a square of the board
    """
    def __init__(self, r, c):
        self.__row = r
        self.__col = c 
        
    def __str__(self):
        return "row = {}, col = {}".format(self.row, self.col)
        
    @property
    def row(self):
        return self.__row
    
    @property
    def col(self):
        return self.__col
        

class Board:
    def __init__(self, x, y):
        self.__r = x 
        self.__c = y
        
        self.__data = []
        
        for i in range(self.__r):
            self.__data.append([" "]*self.__c)
            
    @property
    def r(self):
        return self.__r
    @property
    def c(self):
        return self.__c
    
    def get_square(self, row, col):
        """
        Gives the content of the square represented by the given coordonates
        Input: int - row, int - col
        Output:The content of the square represented by row and col
        """
        return self.__data[row][col]
    
    def __str__(self):
        t = Texttable()
        res = []
        for i in range(self.r):
            res.append(self.__data[i][:])
            for j in range(self.c):
                res[i][j] = self.__data[i][j]
                
        for row in res:
            t.add_row(row)
            
        return t.draw()
    
    def copy(self):
        """
        Creates a deepcopy of the board
        """
        b = Board(self.r, self.c)
        b.__data = copy.deepcopy(self.__data)
        return b
    
    def empty_squares(self):
        """
        Gives the empty squares of the board
        Input: Board - self
        Output: a list containing the empty squares of the board
        """
        res = []
        for i in range(self.r):
            for j in range(self.c):
                if self.__data[i][j] == " ":
                    res.append(Square(i,j))
                    
        return res
    
    def won(self):
        """
        Returns True if the game has been won and False otherwise
        """
        return len(self.empty_squares()) == 0
    
    def mark_neighbours(self, sq):
        """
        Marks the neighbours of the given square
        Input: Square - sq
        Output: puts the symbol "." in the squares representing the neighbours of sq
        """
        n = [Square(sq.row-1, sq.col-1), Square(sq.row, sq.col-1), Square(sq.row+1, sq.col-1),\
              Square(sq.row-1, sq.col+1), Square(sq.row, sq.col+1), Square(sq.row+1, sq.col+1),\
               Square(sq.row-1, sq.col), Square(sq.row+1, sq.col)]
        
        for s in n:
            if s.row in list(range(self.r)) and s.col in list(range(self.c)):
                self.__data[s.row][s.col] = "."
                
    def unmark_neighbours(self, sq):
        """
        Unmarks the neighbours of the given square
        Input: Square - sq
        Output: puts the symbol " " in the squares representing the neighbours of sq
        """
        n = [Square(sq.row-1, sq.col-1), Square(sq.row, sq.col-1), Square(sq.row+1, sq.col-1),\
              Square(sq.row-1, sq.col+1), Square(sq.row, sq.col+1), Square(sq.row+1, sq.col+1),\
               Square(sq.row-1, sq.col), Square(sq.row+1, sq.col)]
        
        for s in n:
            if s.row in list(range(self.r)) and s.col in list(range(self.c)):
                self.__data[s.row][s.col] = " "
    
    def move(self, sq, symbol):
        """
        Marks the given square of the board with the given symbol + its neighbours
        Input:Square - sq
              str - symbol
        Output: returns the board
        """
        if (sq.row not in list(range(self.r))) or (sq.col not in list(range(self.c))):
            raise GameException("Move outside board!")
        if symbol not in ['X','O',"E"]:
            raise GameException("Invalid symbol!")
        d = self.__data
        
        if d[sq.row][sq.col] in ["O", "X", "."] and symbol != "E":
            raise GameException("Square already taken!")
        
        
        if symbol == "E":
            d[sq.row][sq.col] = " "
            self.unmark_neighbours(sq)
        else:
            d[sq.row][sq.col] = symbol
            self.mark_neighbours(sq)
        
        
        return self.__data

        
        
    
    
        
        
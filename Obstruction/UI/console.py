'''
Created on Dec 30, 2018

@author: Korina
'''
from Game.Model import Square
from Game.game import Game
from Game.errors import GameException


class Console:
            
    def _get_move(self):
        while True:
            try:
                row = int(input("row: "))       
                col = int(input("col: ")) 
                return Square(row, col)
            except Exception as e:
                print("Invalid move! -> "+str(e))
                
    def start(self):

        player_move = True
        while True:
            
            try:
                
                rows = int(input("Number of rows for the board: "))
                columns = int(input("Number of columns for the board: "))
                if rows <2 or rows >20 or columns <2 or columns >20:
                    raise GameException("The number of rows and columns must be between 2 and 20!")
                self.__game = Game([rows, columns])
                break
            except Exception as e:
                print(str(e))
            
        b  = self.__game.board
        
        while b.won() == False:
            try:
                
                if player_move:
                    print(b)
                    move = self._get_move()
                    self.__game.human_move(move)
                else:
                    self.__game.computer_move()
                player_move = not player_move
            except Exception as e:
                print(str(e))
        
        print("Game over!")
        print(b)
        if player_move == True:
            print("Computer wins!")
        else:
            print("Player wins!")
            

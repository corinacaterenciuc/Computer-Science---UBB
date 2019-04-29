'''
Created on Dec 30, 2018

@author: Korina
'''
from Game.Model import Board
from Game.errors import GameException
from random import choice
#import math


class Game:
    """
    Handles the moves of the game
    """
    def __init__(self, board_size):
        self.__board = Board(board_size[0], board_size[1])
        
    @property
    def board(self):
        return self.__board
    
    def human_move(self, sq):
        """
        Performs the human move in the given square 
        Input: Square = sq
        Output: Puts a "X" in the given square sq
        """
        self.board.move(sq, "X")


    def computer_move(self):
        """
        Performs the computer move
        Input: -
        Output: Puts the symbol "O" on the best option chosen fom the empty squares
        """
        
        options = self.board.empty_squares()
        if len(options) == 0:
            raise GameException("Game won by human!")
             
        for op in options:
            b = self.board.copy()
            b.move(op,"O")
                 
            if b.won() == True:
                self.board.move(op, "O")
                return
                 
        for op in options:
            b = self.board.copy()
            b.move(op, "X")
                  
            if b.won() == True:
                self.board.move(op, "O")
                return
                 
        self.board.move(choice(options), "O")
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        



# failed trials: 

#in computer_move function :

#         #try 3
#         result = self.max_turn(self.board, 0)
#         best_move = result.move
#         self.board.move(best_move, "O")
        
#         #try 2
#         board_state = self.board.copy()
#         self.board.move(self._minimax(board_state), "O")
        
#         # try 1
#         best_move = self._best_move_minimax(board_state, "computer")
#         self.board.move(best_move.square, "O")
#         
#         #try 4
#         board = self.board.copy()
#         best_move = self.computer_AI(board, "computer", 0, -100, 100)
#         self.board.move(best_move[0], "O")
#         
        
        
#as separate functions:


    """
    #TRY 1
    
    def _best_move_minimax(self, board_state, player, iter = 0): #, iter = 0):
        print(iter)
#         if len(board_state.empty_squares())==1:
#             return self._utility(player)
        if board_state.won() or iter == 4:
            return Move(Square(-1,-1),self._utility(player))
        
        moves = []
        
        for op in board_state.empty_squares():
            if player == "computer":
                board_state.move(op, "O")
                m = Move(op, self._best_move_minimax(board_state, "user", iter+1).score)
                
            else:
                board_state.move(op, "X")
                m = Move(op, self._best_move_minimax(board_state, "computer", iter+1).score)
            moves.append(m)
            board_state.move(op, "E")
            
                
        best_move = 0
        if player == "computer":
            best_score = -1000
            for i in range(len(moves)):
                if int(moves[i].score) > best_score:
                    best_move = i 
                    best_score = moves[i].score
        else:
            best_score = 1000
            for  i in range(len(moves)):
                print(moves[i].score)
                if int(moves[i].score) < best_score:
                    best_move = i
                    best_score = moves[i].score
#         self._best_move = moves[best_move]
        return moves[best_move]
    """
    """ 
    #TRY 2
    
    def _minimax(self, state):
        l = self._max_value(state)
        return l[0]
         
         
    def _max_value(self, state):
        player = "computer"
        if state.won():
            return [Square(-1,-1),self._utility(player)]
        value = -1000
        for op in state.empty_squares():
            sq = op
            value = min(value,self._min_value(state.move(op,"X"))[1])
        return [sq,value]
             
    def _min_value(self, state):
        player = "user"
        if state.won():
            return [Square(-1,-1),self._utility(player)]
        value = 1000
        for op in state.empty_squares():
            sq = op
            value = max(value,self._max_value(state.move(op,"X"))[1])
        return [sq,value]
        
        
    def _utility(self, player):
        if player == "computer":
            return -100
        return 100
    """
    """
    #TRY 3
    
    def play_best_move(self, game, player ):
        result = self.max_turn(game, 0)
        
        best_move = result.move
        
        game.move(best_move, "O")
        
        
    def max_turn(self, board, depth):
        if board.won() == True:
            return Result(self.score(board, depth, "computer"), None)
        
        mx = Result(math.inf, Square(-1,-1))
        
        for op in board.empty_squares():
            board.move(op, "O")
            
            current_move = self.min_turn(board, depth+1)
            
            if current_move.score > mx.score:
                mx.score = current_move.score
                mx.move = op
            
            board.move(op, "E")
            
        return mx
    
    def min_turn(self, board, depth):
        if board.won() == True:
            return Result(self.score(board, depth, "user"), None)
        
        mn = Result(-math.inf, Square(-1,-1))
        
        for op in board.empty_squares():
            board.move(op, "X")
            
            current_move = self.max_turn(board, depth+1)
            
            if current_move.score < mn.score:
                mn.score = current_move.score
                mn.move = op
            
            board.move(op, "E")
            
        return mn
    
    def score(self, board, depth, player):
        if player == "computer":
            return depth - 3
        else:
            return 3 - depth
    """
    """
    #Last
     """
    
#     def computer_AI(self, board, player, depth, alph, bet):
#         """
#         Calculates the best move with a minimax algorithm
#         Input: int - depth, alph, bet
#                Board - board
#                str - player
#         Output:a alist containing the best option square and the points received for that option
#         """
#         if board.won() or depth == 5:
#             if player == "computer":
#                 return [Square(-1, -1), -10]
#             else:
#                 return [Square(-1,-1), 10]
#              
#         if player == "computer":
#             best_points = [Square(-1,-1), -100]
#             rival = "human"
#             sign = "O"
#         else:
#             best_points = [Square(-1,-1), 100]
#             rival = "computer"
#             sign = "X"
#              
#         for op in board.empty_squares():
#             board.move(op, sign)
#              
#             points = self.computer_AI(board, rival, depth+1, alph, bet)
#             points[0] = op
#             board.move(op, "E")
#              
#             if player == "computer":
#                 if points[1] > best_points[1]:
#                      
#                     best_points = points
#                     alph = max([alph, points[1]])
#                     if alph >= bet:
#                         break
#                      
#             elif points[1] < best_points[1]:
#                 best_points = points
#                 bet = min([bet, points[1]])
#                 if alph >= bet:
#                     break
#                  
#         return best_points


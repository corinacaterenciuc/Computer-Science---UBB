'''
Created on Dec 30, 2018

@author: Korina
'''
from tkinter import *
from tkinter import messagebox
from Game.game import Game
from Game.Model import Square
from Game.errors import GameException



class GUI:
    
    def start(self):
        self.main_window = Tk()
        self.main_window.title("Obstruction - ")
        self.main_window.configure(background = "thistle2")
        
        #Creating entries for the board size
        
        self.frame_1 = Frame(self.main_window)
        self.frame_1.pack(side = TOP)
        
        self.l_row = Label(self.frame_1, text = "Nr. Rows: ", bg = "thistle2")
        self.l_row.pack(side = LEFT)
        
        self.row_entr = Entry(self.frame_1,width = 10)
        self.row_entr.pack(side = LEFT)
        
        self.l_col = Label(self.frame_1, text = "Nr. Columns: ", bg = "thistle2")
        self.l_col.pack(side = LEFT)
        
        self.col_entr = Entry(self.frame_1, width = 10)
        self.col_entr.pack(side = LEFT)

        #Creating the board
        
        self.frame_play = Frame(self.main_window)
        self.frame_play.pack()
        
        self.play_btn = Button(self.frame_play, compound = CENTER,\
                                text = "START GAME",\
                                 bg = "thistle1", \
                                 command = self._play)
        self.play_btn.pack()
        
        
        self.main_window.mainloop()
        
    def _play(self):
        self.frame_2 = Frame(self.main_window)
        self.frame_2.pack()
        try:
            self._rows = int(self.row_entr.get())
            self._columns = int(self.col_entr.get())
            
            if self._rows < 2 or self._rows >20 or self._columns<2 or self._columns>20:
                raise GameException("This size of the board is not allowed!")
        
        
            self.frame_1.pack_forget()
            self.frame_play.pack_forget()
            
            self._game = Game([self._rows, self._columns])
            
            self.buttons = []
            count = 0
            
            for row in range(self._rows):
                for col in range(self._columns):
                    
                    self.buttons.append(Button(self.frame_2,text = " ",\
                                                width = 3, height = 1, bg = "thistle2",\
                                                 command = lambda col = col,row = row : self._move(row,col) ))
                    self.buttons[count].grid(column = col , row = row )
                    count += 1
        
        except Exception as e:
            messagebox.showerror("Error!", str(e))
                
    def _move(self, row, col):
        try: 
            self._game.human_move(Square(row,col))
            
            self._show_change()
                    
            if self._game.board.won():
                messagebox.showinfo("Game won!", "Congratulation YOU WON this game!")
                self.main_window.destroy()
                
            else:
                self._game.computer_move()
                self._show_change()
                if self._game.board.won():
                    messagebox.showinfo("Game won!", "The Computer WON this game!")
                    self.main_window.destroy()
                
            
        except Exception as e:
            messagebox.showerror("Error!", str(e))

            
    def _show_change(self):
        count = 0
        for r in range(self._rows):
            for c in range(self._columns):
                if self._game.board.get_square(r,c) == ".":
                    self.buttons[count].config(bg = "thistle4")
                else:
                    self.buttons[count].config(text = self._game.board.get_square(r,c))
                count += 1
        
        
        

    
'''
Created on Nov 26, 2018

@author: Korina
'''
class UndoService:
    def __init__(self):
        self._oper = []
        self._index = -1
        self.duringUndo = False
    
    def add(self, oper):
        """
        Adds an operation to 
        """
        if self.duringUndo == True:
            return
        self._oper=self._oper[:self._index+1]
        self._oper.append(oper)
        
        self._index = len(self._oper) -1
    
    def undo(self):
        if self._index < 0 :
            return False
        self.duringUndo = True
        self._oper[self._index].undo()
        self._index -= 1
        self.duringUndo = False
        return True
        
    def redo(self):
        if self._index+1 >= len(self._oper):
            return False
        self._index +=1
        self._oper[self._index].redo()
        
        self.duringUndo = False
        return True
    
class FunctionCall:
    def __init__(self, function, *params):
        self._fun = function
        self._param = params
        
    def call(self):
        self._fun(*self._param)


class Operations:
    
    def __init__(self, undo_f, redo_f):
        self.undo_f = undo_f
        self.redo_f = redo_f
        
        
        
    def undo(self):
        self.undo_f.call()
        
    
    def redo(self):
        self.redo_f.call()
        
        
        

class CascadeOperations:
    def __init__(self):
        self.oper = []
    
    def add(self, oper):
        self.oper.append(oper)
    
    def undo(self):
        for o in self.oper:
            o.undo()
            
    def redo(self):
        for o in self.oper:
            o.redo()

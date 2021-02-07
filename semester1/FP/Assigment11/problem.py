'''
Created on Jan 10, 2019

@author: Korina
'''

"""
 14). Generate all numbers of n digits with the property that no number has two identical neighboring
subsequences. For example, for n=6, 121312 is correct, and 121313 and 132132 are not correct.
"""




def consistent(x):
    
    for len_ssq in range(1, len(x)//2+1):
        l = len(x)
        if x[l-len_ssq:l] == x[l-2*len_ssq:l-len_ssq]:
            return False
    return True
        
            
 
def solution(x,n):
    
    return len(x) == n
 
def solutionFound(x):
    
    print(x)
 
 
def backtracking_iterative(n):
    
    x = [-1]
    while len(x) >0:
        chosen = False
        while not chosen and x[len(x)-1] <n -1:
            x[len(x)-1] += 1
            chosen = consistent(x)
        if chosen:
            if solution(x, n):
                solutionFound(x)
            else:
                x.append(-1)
        else:
            x = x[:-1]
             
# backtracking_iterative(4)


sol = []

def backtracking_recursiv(x,n):
    x.append(0)
    for i in range(n):
        x[len(x)-1] = i
        if consistent(x):
            if solution(x, n):
                solutionFound(x)
            else:
                backtracking_recursiv(x[:], n)
                
# backtracking_recursiv(sol, 3)
                
                
                
def start():
    while True:
        
        try:
            
            op = int(input("Type \n 0 to stop \n 1 for iterative version \n 2 for the recursive version. \n  --> "))
            if op == 0:
                return
            elif op !=1 and op!=2:
                raise Exception("We only accept valid options, please!")
            n = int(input("Give a positive and natural number: "))
            if n<1:
                raise ValueError("The number is not positive or natural at all!")
            
            if op == 1:
                backtracking_iterative(n)
            elif op == 2:
                backtracking_recursiv([], n)
                
                
            
            
            
           
            
        except Exception as e:
            print(str(e))
        
    
start()
                
                
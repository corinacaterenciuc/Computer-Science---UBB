'''
Created on Dec 10, 2018

@author: Korina
'''
def GnomeSort(items, f):
    """
    Sorts the given list by the given function f
    Input: items - list
            f - a function to be considered when sorting (usually a lambda function)
    Output: Returns None, but sorts the given list
    
    """
    
    i = j = 0
    n = len(items)
    while i < n:
        if i and f(items[i],items[i-1] ):
            items[i], items[i-1] = items[i-1], items[i]
            i -= 1
        else:
            if i < j: # teleport!
                i = j
            j = i = i+1
    return

def k_filter(items, f):
    """
    Filters the given list by the given function
    Input: items - list
            f - a function to be considered when filtering (usually a lambda function)
    Output: a list which contains only the elements accepted by the given function
    
    """
    filtered = []
    for i in items:
        if f(i):
            filtered.append(i)
    return filtered





    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
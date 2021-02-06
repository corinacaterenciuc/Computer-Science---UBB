'''
Created on Oct 14, 2020

@author: Korina
'''

    
class Node(object):
    
    def __init__(self, d, pos):
        self.data = d
        self.position = pos
        self.left = None
        self.right = None
        
    def insert(self, d):
        if self.data == d:
            return False
        elif d < self.data:
            if self.left:
                return self.left.insert(d)
            else:
                self.left = Node(d, BST.position)
                BST.position += 1
                return True
        else:
            if self.right:
                return self.right.insert(d)
            else:
                self.right = Node(d, BST.position)
                BST.position += 1
                return True
            
    def get_data(self):
        return self.data
    
    def get_position(self):
        return self.position
    
    def get_left(self):
        return self.left
    
    def get_right(self):
        return self.right

         
        
        
class BST(object):
    
    position = 0
    
    def __init__(self):
        self.root = None
        BST.position = 0
        
    # return True if successfully inserted, false if exists
    def insert(self, d):
        if self.root:
            return self.root.insert(d)
        else:
            self.root = Node(d, BST.position)
            BST.position += 1
            return True
        
        
    # return True if d is found in tree, false otherwise
    def find(self, d):

        node = self.root
        while node :
            if node.get_data() == d:
                return node.get_position()
            elif d < node.get_data() and node.get_left():
                node = node.get_left()
            elif d > node.get_data() and node.get_right():
                node = node.get_right()
            else: return -1
         
    # return list of inorder elements starting from a given node
    def inside_inorder(self, node , l ):
        if node.get_left():
            self.inside_inorder(node.get_left(), l)
        l.append([node.get_data(), node.get_position()])
        if node.get_right():
            self.inside_inorder(node.get_right(), l)
            
        return l
        
        
    # return list of inorder elements ( wrapper function)
    def inorder(self):
        if self.root:
            return self.inside_inorder(self.root, [])
        else:
            return []
        
    def __str__(self):
        l = self.inorder()
        table_bst = "symbol|pos\n"
        for p in l:
            table_bst +=   "{} | {}\n".format(p[0],  p[1]) 
        return table_bst
        
        
        

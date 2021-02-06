'''
Created on Oct 21, 2020

@author: Korina
'''

# from lab2.lab2_here import  BST
# from lab4.lab4 import FA
import re as re

from flcd_lab2.lab4.lab4 import FA
from lab2 import BST


class Scanner(object):
    def __init__(self, program, tokens):
        self.program_file = program
        self.tokens_file = tokens
        self.st = BST()
        self.PIF = []
        self.token_dict = self.create_dict_tokens()
        self.init_out_files()
        self.FA_identifier = FA("identifierFA.in")
        self.FA_integer = FA("integerFA.in")

    def init_out_files(self):
        f = open("ST.out", 'w')
        f.write("")
        f.close()
        f = open("PIF.out", 'w')
        f.write("")
        f.close()

    def write_st(self):
        f = open("ST.out", 'w')
        f.write(str(self.st))
        f.close()

    def write_PIF(self):
        f = open("PIF.out", 'w')
        f.write('token|ST_pos\n')
        f.close()
        with open('PIF.out', 'a') as PIF:
            for el in  self.PIF:
                PIF.write(str(el[0]) + " | " + str(el[1]) + "\n")

    def genPIF(self, token, pos):
        self.PIF.append((token, pos))

    def create_dict_tokens(self):
        dictionary = {}
        with open(self.tokens_file) as f:
            line = f.readline()
            line = re.sub(r"\n", "", line)
            while line:
                values = line.split(" ")
                dictionary[values[0]] = values[1]
                line = f.readline()
                line = re.sub(r"\n", "", line)
        return dictionary

    def scan(self):
        all_good = True
        with open(self.program_file) as f:

            line = f.readline()
            line_nr = 1
            while line:
                tokens = self.detectTokens(line)
                for token in tokens:
                    if self.is_oper_separ(token) or self.is_rez_word(token):
                        self.genPIF(self.token_dict[token], -1)
                    elif self.is_id(token) or self.is_const(token):
                        self.st.insert(token)
                        index = self.st.find(token)
                        if self.is_id(token):
                            self.genPIF(self.token_dict["identifiers"], index)
                        else:
                            self.genPIF(self.token_dict["constants"], index)
                    else:
                        print("Lexical error! @line number: {} with token: {} ".format(line_nr, token))
                        all_good = False
                        return

                line = f.readline()
                line_nr += 1
        self.write_st()
        self.write_PIF()
        if all_good:
            print("Lexically correct!")


    def detectTokens(self, line):
        tkns = []
        line.strip()
        i=0
        j=0
        while j < len(line):
            if line[j] == "\"":
                tkns.append(line[i:j])
                i = j
                j += 1
                if "\"" not in line[i+1:-1]:
                    j = len(line)-1
                else:
                    while line[j] != "\"" and j < len(line):
                        j += 1
                    j += 1
            if self.is_oper_separ(line[j]):
                tkns.append(line[i:j])
                if (line[j] in ["=", "!", "<", ">"])  and line[j+1] == "=":
                    tkns.append(line[j:j+2])
                    i = j+2
                    j += 1
                else:
                    tkns.append(line[j])
                    i = j+1
            j +=1

        tkns = [i for i in tkns if i and i not in [' ','\n', '\t']]
#         print(tkns)
        return tkns

    def is_oper_separ(self, token):
        operators = ["+", "-", "*", "/", "=", "==", "!=", "<=", ">=", "<", ">", "^", "&", "|", "!"]
        separators = ["(", ")", "[", "]", "{", "}", ":", ";", ",", "", " ", "\t", "\n"]
        return token in operators + separators

    def is_rez_word(self, token):
        reserved_words = ["start", "finish", "if", "else", "endif", "for", "from", "to", "do", "endfor", "while", "endwhile", "get", "print", "int", "string", "vector", "const", "bool", "char", "real", "sqrt"]
        return (token in reserved_words)

    def is_id(self, token):
        return self.FA_identifier.check_sequence(token)
        # return re.match(r"^([a-zA-Z]|_[a-zA-Z])([_a-zA-Z]|[0-9])*$", token) is not None

    def is_const(self, token):
        # re.match('^(0|([-]?|[+]?)[1-9][0-9]*)$', token) is not None or
        is_const = self.FA_integer.check_sequence(token) or re.match('^\"([a-zA-Z0-9 ])*\"$', token) is not None \
               or re.match('^\'([a-zA-Z0-9])\'$', token) is not None
        return  is_const



def main():
    while True:
        try:
            option = int(input("\nEnter \n1 for scanning \n0 to exit.\n>> "))
            if(option == 1):
                souce_code_file = input("Enter the filename of the souce code>> ")
                scanner = Scanner(souce_code_file, "Token.in")
                scanner.scan()
            elif option == 0:
                return
            else:
                print("Wrong option!")
        except Exception as e:
            print(e)
            print("Something went wrong!")
            
            
    
    
main()

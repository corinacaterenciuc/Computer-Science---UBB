'''
Created on Nov 4, 2020

@author: Korina
'''

class FA:
    def __init__(self, filename="FA.in"):
        self.file = filename
        self.FA = self.read_FA()
        self.FA_Q = self.FA[0]
        self.FA_E = self.FA[1]
        self.FA_d = self.represent_transitions(self.FA[4])
        self.FA_q0 = self.FA[2]
        self.FA_F = self.FA[3]

    def read_FA(self):
        fa = []
        with open(self.file) as f:
            #get the finite set of states
            line = f.readline()
            fa.append(line[0:-1].split(" "))
            #get the alphabet
            line = f.readline()
            fa.append(line[0:-1].split(" "))
            # get the start state
            line = f.readline()
            fa.append(line[0:-1].split(" "))
            # get the final states
            line = f.readline()
            fa.append(line[0:-1].split(" "))
            #-------
            #get the transition function
            d = []
            line = f.readline()
            while line:

                transition = line[0:-1]

                d.append(transition.split(","))
                line = f.readline()
            fa.append(d)



        return fa

    def represent_transitions(self, transitions):
        rep = {}
        for t in transitions:
            s = (t[0], t[1])
            if s not in rep.keys():
                rep[s] = []
            rep[s].append(t[2])
        return rep

    def is_deterministic(self):
        for val in self.FA_d.values():
            if len(val) > 1:
                return False
        return True

    def check_sequence(self, sequence):
        if not self.is_deterministic():
            print("The FA is non deterministic!")
            return False
        current_state = self.get_FA_q0()[0]

        for i in sequence:
            if (current_state, i) not in self.FA_d.keys():
                return False
            current_state = self.FA_d[(current_state, i)][0]
        if current_state not in self.FA_F:
            return False
        return True




    def get_FA_Q(self):
        return self.FA_Q


    def get_FA_E(self):
        return self.FA_E


    def get_FA_d(self):
        return self.FA_d


    def get_FA_q0(self):
        return self.FA_q0


    def get_FA_F(self):
        return self.FA_F



def menu():
    fa = FA("FA.in")
    while True:
        try:
            option = int(input("\nEnter \n1 get finite set of states \n2 get the alphabet \n3 get the start state \n4 get the final states1 \n5 get the transition function \n6 check sequence \n0 to exit.\n>> "))
            if option == 1:
                print(fa.get_FA_Q())
            elif option == 2:
                print(fa.get_FA_E())
            elif option == 5:
                print(fa.get_FA_d())
            elif option == 3:
                print(fa.get_FA_q0())
            elif option == 4:
                print(fa.get_FA_F())
            elif option == 6:
                seq = input("Give the sequence >> ")
                if fa.check_sequence(seq):
                    print("Sequence accepted!")
                else:
                    print("NOT accepted!")
            elif option == 0:
                return
            else:
                print("Wrong option!")
        except Exception as e:
            print(e)
            print("Something went wrong!")


# menu()

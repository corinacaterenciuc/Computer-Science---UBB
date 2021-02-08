%EvenNrElems(L: list)
%EvenNreLEMS(i)


evenNrElems([]).
evenNrElems(L):-L = [_|T], not(evenNrElems(T)).


%min(A: int, B: int, C: int)
%min( i, i, o)

min(A, B, C):- A < B, C = A.
min(A, B, C):- A>= B, C = B.

%minimList(L:list, M: int)
%minimList(i, o)

minimList([H], H).
minimList(L, M):- L=[H|T], T\=[] , minimList(T, Min) , min(H, Min, M).

%deleteFirst(L :list, E: int, R: list)
%deleteFirst(i, i, o)

deleteFirst([E|T], E, T).
deleteFirst([H|T], E,[H|Rez]):- H\= E, deleteFirst(T, E, Rez).

%deleteFirstMinim(L:list, R:list)
%deleteFirstMinim( i, o)

deleteFirstMinim(L, R):- minimList(L, M), deleteFirst(L, M, R).

%produce(L: List, E: int, R: int)
%produce(i, i, o)

produce([],E, E).
produce([H|T], E, R):-  produce(T, E, Rez), R is H*Rez.

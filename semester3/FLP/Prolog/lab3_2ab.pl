%lab3 - 2a

%min(a,b) = a, if a<b   | b, otherwise
%
%min(A: int, B: int, C: int)
%min( i, i, o)

min(A, B, C):- A < B, C = A.
min(A, B, C):- A>= B, C = B.

%MinimList(l1l2..ln) =
%                     l1, if n=1
%                     min(l1, MinimList(l2l3..ln)), otherwise


%minimList(L:list, M: int)
%minimList(i, o)

minimList([H], H).
minimList(L, M):- L=[H|T], T\=[] , minimList(T, Min) , min(H, Min, M).

%DeleteFirst(l1l2..ln, elem) =
%                             l2l3..ln, if l1 = elem
%                           l1 U DeleteFirst(l2l3..ln, elem),otherwise

%deleteFirst(L :list, E: int, R: list)
%deleteFirst(i, i, o)

deleteFirst([E|T], E, T).
deleteFirst([H|T], E,[H|Rez]):- H\= E, deleteFirst(T, E, Rez).

%DeleteFirstMinim(l1l2..ln)= DeleteFirst(l1l2..ln, minimList(l1l2..ln))

%deleteFirstMinim(L:list, R:list)
%deleteFirstMinim( i, o)

deleteFirstMinim(L, R):- minimList(L, M), deleteFirst(L, M, R).

%sortDouble(l1..ln) =
%                    [], if n=0
%                    l1, if n=1
%                    minimList(l1..ln) U
%                    sortDouble(deleteFirstMinim(l1..ln)), otherwise

%sortDouble(L: list, R: list)
%sortDouble(i, o)

sortDouble([], []).
sortDouble([H], [H]).
sortDouble(L,[M|Rez]):- minimList(L, M), deleteFirstMinim(L, L_new),L_new\=[],  sortDouble(L_new, Rez).

%sortDoubleSublist(l1..ln)=
%                          l1, if n=1 and l1 !=list
%                          sortDouble(l1),if n=1 and l1 =list
%                          l1 U sortDoubleSublist(l2..ln), if l1 !=list
%                          sortDouble(l1) U sortDoubleSublist(l2..ln),
%                          otherwise

%sortDoubleSublist(L: list, R: list)
%sortDoubleSublist(i, o)

sortDoubleSublist([H],[H]):- not(is_list(H)).
sortDoubleSublist([H], [R]):- is_list(H), sortDouble(H, R).
sortDoubleSublist([H|T], [H|Rez]):- not(is_list(H)),T\=[], sortDoubleSublist(T, Rez).
sortDoubleSublist([H|T], [HRez|Rez]):- is_list(H), T\=[], sortDouble(H,HRez), sortDoubleSublist(T, Rez).



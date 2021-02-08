%candidat(n) = n
%              candidat(n-1), if n>1

% candidat(N:integer, I:integer)
%(i,o)-nedeterminist
candidat(N,N).
candidat(N,I):-
    N>1,
    N1 is N-1,
    candidat(N1,I).


%all_close_different(l1..ln) =
%               true, if n=1
%               all_close_different(l2.ln), if l1 =\= l2
%               false, otherwise

%all_close_different(L: list)
%all_close_different(i)

%all_close_different([H1,H2]):- \+ H1 is H2.

all_close_different([_]).
all_close_different([H1,H2|T]):- H1\=H2, all_close_different([H2|T]).


%permutari_aux(n, m, lg, col) =
%               col , if lg =n and all_close_different(col) = true
%               permutari_aux(n,m,lg+1, candidat(m) U col),
%                     if all_close_different(col) = true

% permutari_aux(N:integer, M:integer, L:list, Lg:integer, Col:list)
%(i,i,o,i,i)-nedeterminist
permutari_aux(N,_,Col,N,Col):-all_close_different(Col),!.
permutari_aux(N,M,L,Lg,Col):-
    candidat(M,I),
    all_close_different(Col),
    Lg1 is Lg+1,
    permutari_aux(N,M,L,Lg1,[I|Col]).


%permutari(n,m) = permutari_aux(n, m, 1, [candidat(m)])

% permutari(N:integer, M:integer, L:list)
%(i,i,o)-nedeterminist
permutari(N,M,L):-
    candidat(M,I),
    permutari_aux(N,M,L,1,[I]).


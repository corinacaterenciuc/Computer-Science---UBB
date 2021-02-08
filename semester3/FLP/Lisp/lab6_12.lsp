;l2:  12. Determine the list of nodes accesed in preorder in a tree of type (2).

;  nr_elems(l1..ln, c) = 
;							c, if n=0
;							nr_elems(l2..ln, c+1), if l1 is an atom
;							;nr_elems(l2..ln, c) + nr_elems(l1, 0), if l1 is a list

(defun nr_elems(l c) 
	(cond 
		((null l) c) 
		(t (nr_elems (cdr l) (+ c 1))) 
		;((listp (car l)) (+ (nr_elems (cdr l) c) (nr_elems (car l) 0))) 
	) 
) 


;  give_nth_elem(l1..ln, nth, pos) = 
;									l1, if pos = nth
;									nil, if pos < nth and n = 0
;									give_nth_elem(l2..ln, nth, pos+1), if pos < nth


(defun give_nth_elem (l n pos)
	(cond
		((= pos n) (car l))
		((null l) nil)
		((< pos n) (give_nth_elem (cdr l) n (+ pos 1)))
	)
)

; preorder (l1..ln) = 
;						[l1] U preorder(give_nth_elem(l, 2, 1)) U preorder(give_nth_elem(l, 3, 1)), if nr_elems(l) = 3
;						[l1] U preorder(give_nth_elem(l, 2, 1)), if nr_elems(l) = 2
;						[l1], otherwise

(defun preorder(l)
	(cond
		((= (nr_elems l 0) 3) (append (list (car l)) (preorder (give_nth_elem l 2 1)) (preorder (give_nth_elem l 3 1))))
		((= (nr_elems l 0) 2) (append (list (car l)) (preorder (give_nth_elem l 2 1))))
		(t (list (car l)))
	)
) ; if there is one child, then it is a left child.


; preordine (l1..ln) = 
;						[], if n = 0
;						[l1] U preordine(l2) U preordine(l3), otherwise

; works for inexisting child as well

(defun preordine(l)
	(cond
		((null l) nil)
		(t (append (list (car l)) (preordine (cadr l)) (preordine (caddr l)))) 
	)
)

;(load "lab6_12.lsp")
;
(print (preordine '(a)))
(print (preordine '(A (B))))
(print (preordine '(A (B) (C))))
(print (preordine '(a (b () (f)) (d (e)))))
(print (preordine '(A (B (D) (E)) (C (F) (G)))))
;(print 'preorder')
(print (preorder '(A)))
(print (preorder '(A (B))))
(print (preorder '(A (B) (C))))
(print (preorder '(A (B (D) (E)) (C (F) (G)))))
(print (preorder '(A (B) (C (D) (E)))))




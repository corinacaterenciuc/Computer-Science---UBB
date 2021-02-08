;1

;a) Write a function to return the n-th element of a list, or NIL if such an element does not exist.

;  nr_elems(l1..ln, c) = 
;							c, if n=0
;							nr_elems(l2..ln, c+1), if l1 is an atom
;							nr_elems(l2..ln, c) + nr_elems(l1, 0), if l1 is a list

(defun nr_elems(l c) 
	(cond 
		((null l) c) 
		((atom (car l)) (nr_elems (cdr l) (+ c 1))) 
		((listp (car l)) (+ (nr_elems (cdr l) c) (nr_elems (car l) 0))) 
	) 
) 

;  give_nth_elem1(l1..ln, nth, pos) = 
;									l1, if pos = nth
;									nil, if pos < nth and n = 0
;									nil, pos> nth
;									give_nth_elem1(l2..ln, nth, pos+1), if l1 = atom

;									give_nth_elem1(l1, nth, pos) if pos + nr_elems(l1 0) > nth     |, if l1 = list 
;									give_nth_elem1(l2..ln, nth, pos+nr_elems(l1 0)), otherwise


(defun give_nth_elem1 (l n pos)
	(cond
		((and (= pos n) (atom (car l))) (car l))
		((null l) nil)
		((> pos n) nil)
		((atom (car l)) (give_nth_elem1 (cdr l) n (+ pos 1)))
		((listp (car l)) (if (> (+ pos (nr_elems (car l) 0)) n) (give_nth_elem1 (car l) n pos) (give_nth_elem1 (cdr l) n (+ pos (nr_elems (car l) 0)))))

	)
)

		;((listp (car l)) (give_nth_elem1 (cdr l) n (+ pos (nr_elems (car l) 0))))
		;(t (give_nth_elem1 (car l) n pos))
(print 'a1)
(print (give_nth_elem1 '(1 2) 5 1)) ; nil
(print (give_nth_elem1 '() 5 1)) ; nil
(print (give_nth_elem1 '(1 2 (3 (4 5) 6 7)) 0 1)) ; nil
(print (give_nth_elem1 '(1 2 (3 (4 5) 6 7)) 2 1)) ; 2
(print (give_nth_elem1 '(1 2 (3 (4 5) 6 7)) 7 1)) ; 7
(print (give_nth_elem1 '(1 2 (3 (4 5) 6 7)) 4 1)) ; 4
;a) Write a function to return the n-th element of a list, or NIL if such an element does not exist.
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

(print 'a)
(print (give_nth_elem '(1 2) 5 1)) ; nil
(print (give_nth_elem '() 5 1)) ; nil
(print (give_nth_elem '(1 2 (3 (4 5) 6 7)) 0 1)) ; nil
(print (give_nth_elem '(1 2 (3 (4 5) 6 7)) 2 1)) ; 2
(print (give_nth_elem '(1 2 (3 (4 5) 6 7)) 7 1)) ; nil
(print (give_nth_elem '(1 2 (3 (4 5) 6 7)) 3 1)) ; (3 (4 5) 6 7)

;b) Write a function to check whether an atom E is a member of a list which is not necessarily linear.
;   is_member(e, l1..ln) = 
;							false, if n = 0
;							true, if e is atom and  e = l1
;							is_member(e, l1) or is_member(e, l2..ln), if e is list
;							is_member(e, l2..ln), otherwise

(defun is_member (e l)
	(cond
		((null l) nil)
		((and (atom (car l)) (equal e (car l))) t)
		((listp (car l)) (or (is_member e (car l)) (is_member e (cdr l))))
		(t (is_member e (cdr l)))
	)
)

(print 'b)
(print (is_member 2 '())) ; nil
(print (is_member 2 '(1 3 2 4))) ; true
(print (is_member 2 '(1 (3 2) 4))) ; true
(print (is_member 2 '(1 3 (8) 4))) ; nil
(print (is_member 2 '(1 3 7 4))) ; nil

;c) Write a function to determine the list of all sublists of a given list, on any level.
 ;A sublist is either the list itself, or any element that is a list, at any level. Example:
 ;(1 2 (3 (4 5) (6 7)) 8 (9 10)) => 5 sublists :
 ;( (1 2 (3 (4 5) (6 7)) 8 (9 10)) (3 (4 5) (6 7)) (4 5) (6 7) (9 10) )
 ;
;   nr_sublists(l1..ln) = 
;							1, if n = 0
;							nr_sublists(l1) + nr_sublists(l2..ln), if l1 is list
;							nr_sublists(l2..ln), otherwise

(defun nr_sublists (l)
	(cond
		((null l) 1)
		((listp (car l)) (+ (nr_sublists (car l)) (nr_sublists (cdr l))))
		;list is not the same as listp!!!
		(t (nr_sublists (cdr l)))
	)
)

(print 'c)
(print (nr_sublists '())) ; 1
(print (nr_sublists '(1 3 2 4))) ; 1
(print (nr_sublists '(1 (3 2) 4))) ; 2
(print (nr_sublists '(1 3 (8) 4))) ; 2
(print (nr_sublists '(1 (3 (7)) (4 2) 4))) ; 4
(print (nr_sublists '(1 2 (3 (4 5) (6 7)) 8 (9 10)))) ; 5 exemplu dat


;d) Write a function to transform a linear list into a set.
;   - delete_elem(e, l1..ln) = 
;									[], if n =0
;									delete_elem(e, l2..ln), if e = l1
;									l1 U delete_elem(e, l2..ln), otherwise

(defun delete_elem (e l)
	(cond
		((null l) nil)
		((equal e (car l)) (delete_elem e (cdr l)))
		(t (cons (car l) (delete_elem e (cdr l))))
	)
)



;d) - list_to_set(l1..ln) = 
;						[], if n=0
;						l1 U list_to_set(delete_elem(l1, l2..ln)), otherwise

(defun list_to_set (l)
	(cond
		((null l) nil)
		(t (cons (car l) (list_to_set (delete_elem (car l) (cdr l)))))
	)
)


(print 'd)
(print (list_to_set '())) ; nil
(print (list_to_set '(1 3 2 4))) ; (1 3 2 4)
(print (list_to_set '(1 3 2 1 4))) ; (1 3 2 4)
(print (list_to_set '(1 2 3 1 2 3 1 2 3))) ; (1 2 3)



















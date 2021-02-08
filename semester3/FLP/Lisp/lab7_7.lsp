 
 
 ;7. Write a function that substitutes an element E with all elements of a list L1 
 ;at all levels of a given list L
 
 
 ; replace(e, l1, l) = 
 ;				    	l1 , if l is atom and l = e
 ;						[l1], if l is atom and l != e
 ;						[APPEND i=1, i = m replace(e, l1, l_i)], if l is a list
 
 
  (defun replace_1(e l1 l)
	(cond
		((and (atom l) (equal l e)) l1)
		((atom l) (list l))
		;((and (atom l) (not (equal l e))) l)
		((listp l) (list (apply #'append (mapcar #'(lambda (elem)
					(replace_1 e l1 elem)
			)
		l))))
	)
 )
 
 ;wrapper function
 (defun replace_e_with_l1 (e l1 l)
	(car (replace_1 e l1 l))
 )
 
 
 ;(load "lab7_7.lsp")
 
 (print 'bad_exampple)
 (print (replace_1 1 '(8 9) '(1 a (2 c) 3 1 (4 5 (6 1 7) 1))))
 (print 'good_exampples)
(print (replace_e_with_l1 1 '(8 9) '(1 a (2 c) 3 1 (4 5 (6 1 7) 1))))
 ;should be => (8 9 a (2 c) 3 8 9 (4 5 (6 8 9 7) 8 9))
 (print (replace_e_with_l1 1 '(8 9) '(1)))
 (print (replace_e_with_l1 1 '(8 (9)) '(1)))
 (print (replace_e_with_l1 1 '() '(1)))
 (print (replace_e_with_l1 1 '(7 7 7) '(3 ((1 (3 (1))) 1))))
 (print (replace_e_with_l1 1 '() '(1 a (2 c) 3 1 (4 5 (6 1 7) 1))))
 

 
 
 ;Ctrl + K
 ;Ctrl + Shift + K
 
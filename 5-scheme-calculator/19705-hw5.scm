(define (twoOperatorCalculator lis) 
    ( 
	cond
		((eq? (cdr lis) '()) (car lis))
		((and (number? (car lis)) (eq? (cadr lis) '+) (number? (caddr lis))) (twoOperatorCalculator(cons (+ (car lis) (caddr lis)) (cdddr lis) ))  )
		((and (number? (car lis)) (eq? (cadr lis) '-) (number? (caddr lis))) (twoOperatorCalculator(cons (- (car lis) (caddr lis)) (cdddr lis) ))  )
	)
)

(define (fourOperatorCalculator lis) 
    ( 
	cond
		((eq? (cdr lis) '()) lis)
		((and (number? (car lis)) (eq? (cadr lis) '*) (number? (caddr lis))) (fourOperatorCalculator(cons (* (car lis) (caddr lis)) (cdddr lis) ))  )
		((and (number? (car lis)) (eq? (cadr lis) '/) (number? (caddr lis))) (fourOperatorCalculator(cons (/ (car lis) (caddr lis)) (cdddr lis) ))  )
		(else (cons (car lis) (fourOperatorCalculator (cdr lis))) )
	)
)

(define (Nested k)
	(
	cond
		((pair? k) (twoOperatorCalculator(fourOperatorCalculator(calculatorNested k))))
		(else k)
	)
)

(define (calculatorNested lis)(map Nested lis))

(define (checkOperators lis)
	(
	cond
		((null? lis) #f)
		((and (number? (car lis)) (null? (cdr lis))) #t)
		((and (pair? (car lis)) (null? (cdr lis))) (checkOperators (car lis)))
		((and (number? (car lis)) (or (eq? '- (cadr lis)) (eq? '+ (cadr lis)) (eq? '/ (cadr lis)) (eq? '* (cadr lis)))) (checkOperators (cddr lis)) )
		((and (pair? (car lis))   (or (eq? '- (cadr lis)) (eq? '+ (cadr lis)) (eq? '/ (cadr lis)) (eq? '* (cadr lis)))) (and (checkOperators (car lis)) (checkOperators (cddr lis))))
		(else #f)
	)
)

(define (calculator lis)
	(
	cond
		((checkOperators lis) (twoOperatorCalculator (fourOperatorCalculator (calculatornested lis))))
		(else #f)
	)
)
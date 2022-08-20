max(X,Y):-
(  
 X=Y -> 
  write('both are equal');
 X>Y -> 
  (
  Z is X, 
  write(Z)
  );
  (
  Z is Y, 
  write(Z)
  ) 
).

min(X,Y):-
(  
 X=Y -> 
  write('both are equal')
 ;
 X<Y -> 
  (
  Z is X, 
  write(Z)
  )
  ;
  (
  Z is Y, 
  write(Z)
  ) 
).

add(A,B):-
(
C is A+B,
write(C)

).

sub(A, B):-
(
C is A-B,
write('Answer is '),
write(C)
).

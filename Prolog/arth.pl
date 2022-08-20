sum(Y,X):-
    S is Y+X,
    write(S).
subtract(Y,X):-
    S is Y-X,
    write(S).
multiply(Y,X):-
    S is Y*X,
    write(S).
divide(Y,X):-
    S is Y/X,
    write(S).
power(Y,X):-
    K is Y**X,
    write(K).
intdivision(Y,X):-
    G is Y//X,
    write(G).
mod(Y,X):-
    A is Y mod X,
    write(A).

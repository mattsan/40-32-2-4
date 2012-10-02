factorial(0, 1).
factorial(X, F) :- X > 0, X1 is X - 1, factorial(X1, F1), F is F1 * X.

for([N], N, N).
for([], Min, Max)  :- Min > Max.
for([N|L], Min, N) :- N > Min, N1 is N - 1, for(L, Min, N1).

cartesian_product(_, [], []).
cartesian_product([], _, []).
cartesian_product(N, M, L)   :- cartesian_product2(N, N, M, L).
cartesian_product2(_, _, [], []).
cartesian_product2([], N0, [_|MS], L) :- cartesian_product2(N0, N0, MS, L).
cartesian_product2([N|NS], N0, [M|MS], [[N, M]|L]) :- cartesian_product2(NS, N0, [M|MS], L).

verify([], _, _, []).
verify([[A, C]|CS], N, F, [[A, B, C]|R]) :-
  B is C * (A - F),
  (A - B) / C =:= N,
  A - (B / C) =:= F,
  verify(CS, N, F, R).
verify([_|CS], N, F, R) :- verify(CS, N, F, R).

unique([],[]).
unique([H|T], [H|U]) :- delete(T, H, V), unique(V, U).

gensets([], _, _, []).
gensets([A|AS], N, F, R0) :-
  Cmax is A div (A - F),
  for(CS, 2, Cmax),
  cartesian_product([A|AS], CS, R1),
  gensets(AS, N, F, R2),
  append(R1, R2, R0).

f(N, R) :-
  factorial(N, F),
  Amin is F + 1,
  Amax is F * 2,
  for(AS, Amin, Amax),
  gensets(AS, N, F, S),
  verify(S, N, F, R0),
  unique(R0, R),
  write(R),
  !.

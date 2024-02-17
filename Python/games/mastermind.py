from random import choices

colors = ["red", "green", "blue", "yellow", "orange", "white"]
sc, guess = choices(colors,  k=4), ["red", "orange", "white", "blue"]
print(sc)
print(guess)
status = ["exact" if c in sc and guess.index(c) == sc.index(c) else ("inexact" if c in sc else "") for c in guess]
print(status)
rows = 2
cols = 3

A = matrix(c(1, 2, 3, 4, 5, 6), nrow = rows, ncol = cols)
B = matrix(c(6, 5, 4, 3, 2, 1), nrow = rows, ncol = cols)

C = A + B

print("Matrix A:")
print(A)

print("Matrix B:")
print(B)

print("Sum of A and B:")
print(C)

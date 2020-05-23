def mat_mult(A, B):
    #filling with zeros
    C = [[0 for row in range(len(A))] for col in range(len(B[0]))]
        
    for i in range(len(A)):
        for j in range(len(B[0])):
            summ = 0
            for k in range(len(A[0])):
                summ += A[i][k] * B[k][j]
            C[i][j] = summ
    return C

def mat_mult_while(A,B):
    #filling with zeros
    C = [[0 for row in range(len(A))] for col in range(len(B[0]))]

    i = 0
    while i < len(A):
        j = 0
        while j < len(B[0]):
            summ = 0
            k = 0
            while k < len(A[0]):
                summ += A[i][k] * B[k][j]
                k += 1
            C[i][j] = summ
            j += 1
        i += 1
    return C

def print_mat(A):
    for i in range(len(A)):
        for j in range(len(A[0])):
            print(str(A[i][j]), end=' ')
        print()

    

A = [[1, 2, 3], [4, 5, 6]]

B = [[7, 8], [9, 10], [11, 12]]

C = mat_mult(A,B)
D = mat_mult_while(A,B)

print_mat(C)
print()
print_mat(D)

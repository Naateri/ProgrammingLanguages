from random import randint

def quicksort(A):
    if (len(A) <= 1):
        return A

    p = randint(0, len(A)-1)
    left = list()
    right = list()


    for i in range(len(A)):
        if (i == p):
            continue
        if A[i] < A[p]:
            left.append(A[i])
        else:
            right.append(A[i])

    return quicksort(left) + [A[p]] + quicksort(right)

def iter_quicksort(A):
    q_stack = list()
    result = A.copy()

    q_stack.append(0)
    q_stack.append(len(A))

    while len(q_stack) > 0:

        left_half = False
        right_half = False

        left = list()
        right = list()
        r = q_stack.pop()
        l = q_stack.pop()

        if r <= l:
            continue
        
        p = randint(l, r-1)
        p_val = result[p]

        for i in range(l, r):
            if i == p:
                continue
            if result[i] < p_val:
                left.append(result[i])
                left_half = True
            else:
                right.append(result[i])
                right_half = True
                
        temp = left + [p_val] + right
        result[l:r] = temp
        position = l + len(left)

        if left_half:
            q_stack.append(l)
            q_stack.append(position)
        if right_half:
            q_stack.append(position+1)
            q_stack.append(r)

    return result

example = list()

for i in range(50):
    example.append(randint(0, 5000))

e = quicksort(example)
print(e)
print()
ex = iter_quicksort(example)
print(ex)

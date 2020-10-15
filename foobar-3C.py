from fractions import Fraction

def matrix_sub(A, B):
    res = [[ 0 for i in range(len(A))] for j in range(len(A))]
    for i in range(0,len(A)):
        for j in range(0,len(A[i])):
            res[i][j] = A[i][j] - B[i][j]
    return res

def matrix_mul(A, B):
    res = [[ 0 for i in range(len(B[0]))] for j in range(len(A))]
    for i in range(len(A)):
        for j in range(len(B[i])):
            for k in range(len(B)):
                res[i][j] += A[i][k] * B[k][j]
    return res

def invert(matrix):
    n = len(matrix)
    inverse = [[Fraction(0) for col in range(n)] for row in range(n)]
    for i in range(n):
        inverse[i][i] = Fraction(1)
    for i in range(n):
        for j in range(n):
            if i != j:
                if matrix[i][i] == 0:
                    return False
                ratio = matrix[j][i] / matrix[i][i]
                for k in range(n):
                    inverse[j][k] = inverse[j][k] - ratio * inverse[i][k]
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k]
    for i in range(n):
        a = matrix[i][i]
        if a == 0:
            return False
        for j in range(n):
            inverse[i][j] = inverse[i][j] / a
    return inverse

def proper_form(matrix):
    l = len(matrix)
    j = []
    final = [[Fraction(0) for col in range(l)] for row in range(l)]
    #print(final)
    for i in range(0,l):
        if(sum(matrix[i]) == 0):
            j.append(i)
    zero_len = len(j)
    for i in range(0,l):
        if i not in j:
            j.append(i)
    #print(j)
    a = 0
    for i in j:
        b = 0
        for k in j:
            if(matrix[i][k] == 0):
                final[a][b] = Fraction(matrix[i][k])
            else:
                final[a][b] = Fraction(matrix[i][k],sum(matrix[i]))
            b = b+1
        a = a+1
        #print(final)
    return final, zero_len

def cal_R(matrix, l):
    f = []
    if(len(matrix) == 1):
        return [[1]]
    for i in range(l,len(matrix)):
        f.append(matrix[i][0:l])
    return f

def cal_Q(matrix, l):
    q = []
    if(len(matrix) == 1):
        return [[0]]
    for i in range(l,len(matrix)):
        q.append(matrix[i][l:len(matrix)])
    return q

def cal_identity(l):
    I = [[0 for col in range(l)] for row in range(l)]
    for i in range(l):
        I[i][i] = 1
    return I

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a,n):
    ans = a[0]
    for i in range(1,n):
        ans = (a[i]*ans)//gcd(a[i],ans)
    return ans

def final_ans(matrix):
    e=[]
    for i in range(0,len(matrix)):
        e.append(matrix[i].denominator)
    k=lcm(e,len(e))
    e=[]
    for i in range(0,len(matrix)):
        e.append((matrix[i].numerator*k)//matrix[i].denominator)
    e.append(k)
    return e

def main(m):
    final, zero_len = proper_form(m)
    #print(m[0][0])
    R = cal_R(final, zero_len)
    #print(R)
    Q = cal_Q(final, zero_len)
    #print(Q)
    I = cal_identity(len(Q))
    #print(I)
    F = matrix_sub(I,Q)
    print(F)
    F = invert(F)
    FR = matrix_mul(F,R)
    print(FR)
    return final_ans(FR[0])
 
#TEST 4
m = [[0]]
#a = [1, 1]
print(main(m))
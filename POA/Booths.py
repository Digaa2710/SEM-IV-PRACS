def add(a, b, carry, n, q0):
    ans = [0] * (n + 1)
    j = len(a) - 1
    while j >= 0:
        bit = a[j] + b[j] + carry
        if bit == 0:
            carry = 0
            ans[j] = 0
        elif bit == 1:
            carry = 0
            ans[j] = 1
        elif bit == 2:
            carry = 1
            ans[j] = 0
        elif bit == 3:
            carry = 1
            ans[j] = 1
        j -= 1
    return ans


def one_complement(M, n):
    new_M = []
    for i in range(n + 1):
        if M[i] == 1:
            new_M.append(0)
        elif M[i] == 0:
            new_M.append(1)
    return new_M


def two_complement(M, n):
    M_ocomplement = one_complement(M, n)
    print("Ones ",M_ocomplement)
    answer = [0] * (n + 1)
    M_tcomplement = add(M_ocomplement, answer, 1, n, 0)  # Ensure q0 value is passed
    return M_tcomplement


def Booths(Q, M, accum, n, q0):
    for i in range(n+1):
     
        last_Q=Q[-1]
        if Q[-1] == 0 and q0 == 1:
            accum = add(accum, M, 0, n, q0)
            Q = [accum[-1]] + Q[:-1]
            accum = [accum[0]] + accum[:-1]
            print("Accum after shifting:",accum)
            print("Q:",Q)
            q0=last_Q
        elif Q[-1] == 1 and q0 == 0:
            t_complement = two_complement(M, n)
            print(t_complement)
            accum = add(accum, t_complement, 0, n, q0)
            print(accum)
            Q = [accum[-1]] + Q[:-1]
            accum = [accum[0]] + accum[:-1]
            print("Accum after shifting:",accum)
            print("Q:",Q)
            q0=last_Q
        elif Q[-1] == 1 and q0 == 1:
            Q = [accum[-1]] + Q[:-1]
            accum = [accum[0]] + accum[:-1]
            print("Accum after shifting:",accum)
            
            print("Q:",Q)
            q0=last_Q
        elif Q[-1] == 0 and q0 == 0:
            Q = [accum[-1]] + Q[:-1]
            accum = [accum[0]] + accum[:-1]
            print("Accum after shifting:",accum)
            print("Q:",Q)
            q0=last_Q
      
    print(accum,Q)
  


Q = int(input("Enter multiplicant(decimal):"))
M = int(input("Enter multiplier(decimal):"))


    
l1 = []
l2 = []
q0 = 0
value=Q
while Q != 0:
    l1.append(Q % 2)
    Q = Q // 2
while M != 0:
    l2.append(M % 2)
    M = M // 2
n = max(len(l1), len(l2))
accum = [0] * (n + 1)
while len(l1) < n + 1:
    l1.append(0)
while len(l2) < n + 1:
    l2.append(0)

l1.reverse()
l2.reverse()



print(l1)
print(l2)

Booths(l1, l2, accum, n, q0)

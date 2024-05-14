def add(a, b, carry):
    answer = [0, 0, 0, 0,0]
    j = len(a) - 1
    while j >= 0:
        bit = a[j] + b[j] + carry
        if bit == 0:
            carry = 0
            answer[j] = 0
        elif bit == 1:
            carry = 0
            answer[j] = 1
        elif bit == 2:
            carry = 1
            answer[j] = 0
        else:
            carry = 1
            answer[j] = 1
        j -= 1
    if carry == 1:  
        answer.insert(0, 1)
    return answer

def one_complement(M):
    new_M = []
    for i in range(5):
        if M[i] == 0:
            new_M.append(1)
        else:
            new_M.append(0)
    return new_M

def two_complement(M):
    ans = [0, 0, 0, 0, 0]
    new_M = one_complement(M)
    M_complement = add(new_M, ans, 1)
    return M_complement

def Non_restoring(Q, M, accum):
 k=4
 while k>0:
    digit=accum[0]
    accum = accum[1:] + [Q[0]]
   
    print("Accumulator after shifting:", accum[1:])
    if digit == 0:
        M_complement = two_complement(M)
        answer = add(accum, M_complement, 0)
        if len(answer)==6:
            answer=answer[1:]
        accum=answer
        print("Answer of the addition:",answer)
        print("Carry:",accum[0])
        if answer[0] == 0:
            Q = Q[1:] + [1]
        else:
            Q = Q[1:] + [0]
        
    elif digit == 1:
        
        answer = add(accum, M, 0)
        if len(answer)==6:
            answer=answer[1:]
        accum=answer
        print("Answer of the addition is :",answer)
        print("Carry:",accum[0])
        if answer[0] == 0:
            Q = Q[1:] + [1]
            
        else:
            Q = Q[1:] + [0] 
    print("Q after every right shift",Q)
    print(" ")
    k-=1
 if answer[0]==1:
     answer=add(answer,M,0)
     print("Quotient:",Q)
     print("Reminder:",answer[2:])
     Quotient=Q
     Reminder=answer[2:]
     
 else:
     print("Quotient:",Q)
     print("Reminder:",answer[1:])
     Quotient=Q
     Reminder=answer[1:]
 print(" ")
 binary_decimal(Quotient,Reminder)
def binary_decimal(Q, R):
    i = len(Q) - 1
    decimal_sum = 0
    power = 0
    while i >= 0:
        decimal_sum += Q[i] * (2 ** power)
        power += 1
        i -= 1
    print("Quotient in decimal:", decimal_sum)

    i = len(R) - 1
    decimal_sum = 0
    power = 0
    while i >= 0:
        decimal_sum += R[i] * (2 ** power)
        power += 1
        i -= 1
    print("Reminder in decimal:", decimal_sum)
    
 
 

if __name__ == "__main__":
    # User input default 4
    Q = int(input("Enter the dividend(decimal):"))
    M = int(input("Enter the divisor(decimal):"))
    print(" ")
    l1 = []
    l2 = []
    accum = [0, 0, 0, 0, 0]
    while Q != 0:
        l1.append(Q % 2)
        Q = Q // 2 
    while len(l1) < 4:
        l1.append(0)

    l1.reverse()
    print("Binary representation of Q:", l1)

    while M != 0:
        l2.append(M % 2)
        M = M // 2 
    while len(l2) < 4:
        l2.append(0)

    l2.reverse()
    l2=[0]+l2
    print("Binary representation of M:", l2[1:])
  
    print("Accumulator:", accum)

    Non_restoring(l1, l2, accum)
    

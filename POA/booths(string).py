n = 4

def tobin(num:int, n_bits=n):
    return bin(num)[2:].zfill(n_bits) if num >= 0 else bin((1 << n_bits) - (-num))[2:]

def twoc(bits:str, n_bits=n):
    return tobin((1 << n_bits) - int(bits, 2), n_bits)
    #bits 2 mean binary yeh int wala part wapas batana
    # int(bits) matlab woh int me convert krega
# Now apni bits ki string is in binary format, toh usko batana padega ki base 2 hai
# Isiliye int(bits, 2) ohk thike baki sab toh yaad hain
def right_shift(A:str, Q:str):
    return A[0] + A[:-1], A[-1] + Q[:-1], Q[-1]

def add(A:str, M:str):
    S = tobin(int(A, 2) + int(M, 2))
    n_bits = globals()["n"]
    if len(S) > n_bits:
        S = S[1:]
    return S

def booths(M:int, Q:int):
    n_bits:int = globals()["n"]
    Q = tobin(Q)
    
    Q1 = '0'
    M = tobin(M, n_bits)
    M2 = twoc(M, n_bits)
    A = '0' * n_bits
    count:int = globals()["n"]
    print("n","A","Q","Q1","Action", sep='\t')
    action = "Initialize"
    print(count,A, Q, Q1, action, sep='\t')
    while count > 0:
        if (Q[-1] != Q1):
            if (Q1 == '1'):
                action = "A = A + M"
                A = add(A, M)
            else:
                action = "A = A - M"
                A = add(A, M2)
        print(count,A, Q, Q1, action, sep='\t')
        A, Q, Q1 = right_shift(A, Q)
        action = "Right Shift"
        print(count,A, Q, Q1, action, sep='\t')
        count -= 1
    result = A + Q
    neg = 0
    if (result[0] == '1'):
        neg = 1
        result = twoc(result, 2 * n_bits)
    print("Answer =", result)
    print("Numerical answer:", -int(result, 2) if neg else int(result, 2))

inputText = "Enter a number from " + str(-2**(n - 1)) + " to " + str(2**(n - 1) - 1) + ": "
x = int(input(inputText))
y = int(input(inputText))
booths(x, y)
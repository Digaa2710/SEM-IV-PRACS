def binary_decimal(accum,Q):
    i=len(accum)-1
    sum=0
    power=0
    while i>=0:
        sum+=accum[i]*(2**power)
        power+=1
        i-=1
    print("reminder is :",sum)   
    i=len(Q)-1
    sum=0
    power=0
    while i>=0:
        sum+=Q[i]*(2**power)
        power+=1
        i-=1
    print("quotient is :",sum)   
def add(a,b,carry,n):
    ans=[0]*(len(a))
    j=len(a)-1
    while j>=0:
        bit=a[j]+b[j]+carry
        if bit==0:
            carry=0
            ans[j]=0
        elif bit==1:
            carry=0
            ans[j]=1
        elif bit==2:
            carry=1
            ans[j]=0
        elif bit==3:
            carry=1
            ans[j]=1
        j=j-1
    return ans
def one_complement(M,n):
    new_M=[]
    for i in range(n+1):
        if M[i]==1:
            new_M.append(0)
        elif M[i]==0:
            new_M.append(1)
   
    return new_M

def two_complement(M,n):
    M_ocomplement=one_complement(M,n)
    answer=[0]*(n+1)
    M_tcomplement=add(M_ocomplement,answer,1,n)
    return M_tcomplement
    
def Non_restoring(Q,M,accum,n):
    for i in range(n):
        
       
        if accum[0]==0:
            accum=accum[1:]+[Q[0]]
            M_tcomplement=two_complement(M,n)
            accum=add(accum,M_tcomplement,0,n)
            if accum[0]==1:
                Q=Q[1:]+[0]
                print("Q:",Q)
                print("A:",accum)
            elif accum[0]==0:
                Q=Q[1:]+[1]
                print("Q:",Q)
                print("A:",accum)
        elif accum[0]==1:
                accum=accum[1:]+[Q[0]]
                accum=add(accum,M,0,n)
                if accum[0]==1:
                    Q=Q[1:]+[0]
                    print("Q:",Q)
                    print("A:",accum)
                elif accum[0]==0:
                    Q=Q[1:]+[1]
                    print("Q:",Q)
                    print("A:",accum)
    if accum[0]==1:
        accum=add(accum,M,0,n)
        print(accum); 
    print(accum)
    print(Q)
    binary_decimal(accum,Q)
    
Q=int(input("Enter dividend(decimal):"))
M=int(input("Enter divisor(decimal):"))
n=int(input("Enter highest number of bits of dividend:"))
l1=[]
l2=[]
accum=[0]*(n+1)
while Q!=0:
    l1.append(Q%2)
    Q=Q//2

l1.reverse()
print(l1)
while M!=0:
    l2.append(M%2)
    M=M//2
while len(l2)<(n+1):           
    l2.append(0)
l2.reverse()
print(l2)
Non_restoring(l1,l2,accum,n)

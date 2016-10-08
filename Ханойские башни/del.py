a=[]
b=int(input())
while b>0:
    a.append(b%2)
    b=b//2
s=""
for i in range(len(a)):
    s=s+str(a[len(a)-i-1])
print(s)
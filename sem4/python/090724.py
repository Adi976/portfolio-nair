i=1
for i in range(4):
    s=""
    j=0
    for j in range(3-i):
        s=s+" "
    k=0
    for k in range(2*i-1):
        s=s+"*"
    print(s)
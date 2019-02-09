
test=int(input())
for i in range(test):
    len=int(input())
    x=input()
    y=x.spilt()
    sum=0
    for k in range(len):
        sum=sum+int(y[k])
    print(sum-len+1)




test=int(input())
for i in range (test):
    count=0
    n=int(input())
    l=[]
    d={}
    for j in range (n):
        str3 = raw_input()
        m = ("".join(set(str3)))
        s = ''.join(sorted(m))
        #print(s)
        if s in d:
            d[s]+=1
        else:
            d[s]=1
    l = list(d.keys())
    for j in range (len(l)):
        if(d[l[j]]-1>0  and len(l[j])==5):
            count=int(count+((d[l[j]]*(d[l[j]]-1))/2))
        for k in range (j+1,len(l)):
            s=set(l[j]+l[k])
            if(len(s)==5):
                count=count+(d[l[j]]*d[l[k]])
    print(count)
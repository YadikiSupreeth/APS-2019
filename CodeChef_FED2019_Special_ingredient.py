from collections import OrderedDict
from collections import Counter 
maintest=int(input())
for i in range(maintest):
    test=int(input())
    main=""
    foo=""
    k=""
    for i in range(test):
        foo = raw_input()
        k="".join(OrderedDict.fromkeys(foo))
        main=main+k
    res = Counter(main)
    count=0
    for k in res:
        if(res[k]==test):
            count=count+1
    print(count)
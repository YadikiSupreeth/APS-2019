t = int(input())
while t > 0:
    count = 0
    x = {}
    n = int(input())
    for k in range(n):
        str3 = raw_input()
        m = ("".join(set(str3)))
        m = ''.join(sorted(m))
        if m in x:
            x[m] = x[m]+1
        else:
            x[m] = 1

    key = list(x.keys())
    value = list(x.values())
    for i in range(len(key)):
            for j in range(i+1, len(key)):
                str2 = key[i]+key[j]
                m = ("".join(set(str2)))
                if(len(m) == 5):
                    count = count+(value[i]*value[j])
    if(x.get("aeiou")):
        count = count+((x["aeiou"]*(x["aeiou"]-1))/2)
    print(count)
    t = t-1

    # if(len(key) > 1):
    #     for i in range(len(key)):
    #         for j in range(i+1, len(key)):
    #             str2 = key[i]+key[j]
    #             m = ("".join(set(str2)))
    #             if(len(m) == 5):
    #                 count = count+(value[i]*value[j])
    #     if(x.get("aeiou")):
    #         count = count+((x["aeiou"]*(x["aeiou"]-1))/2)
    #     print(count)
    # elif(x.get("aeiou")):
    #     count = ((x["aeiou"]*(x["aeiou"]-1))/2)
    #     print(count)
    # else:
    #     print("0")
    # t = t-1


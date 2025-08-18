def count_hi(str):
    c = 0
    i = 0
    while len("hi")+i <= len(str):
        if str[i:len("hi")+i] == "hi":
            c+= 1
        i+=1
    return c
         

print(count_hi("abchi hi Hi"))
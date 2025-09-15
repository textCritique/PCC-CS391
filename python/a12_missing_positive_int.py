# find the first missing positive integers from the list containing both positive and negative

l = [3,4,-1,1]

def missing(l):
    l = sorted(l)
    i = 0
    while (l[i] < 1):
        i+=1
    for k in range(len(l)-1):
        if l[i+1] - l[]
    return i

print(missing(l))
print(l)
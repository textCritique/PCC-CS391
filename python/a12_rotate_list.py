# rotate list's element
l = [1,2,3,4,5,6,7]

def rotate(l,pos):
    for i in range(pos):
        l.insert(0,l.pop())
    return l

print(rotate(l,9))
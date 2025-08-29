l1 = [i**2 for i in range(1,11)]
print(l1)

l2 = [i for i in range(1,51) if i%2 == 0]
print(l2)

l3 = [i**3 for i in range(1,20) if i%2]
print(l3)

l4 = [i for i in "GKCIET" if i in "aeiou" or i in "AEIOU"]
print(l4)

l5 = [len(i) for i in ["hello","hi","hola"]]
print(l4)

def isprime(n):
    if n==1:
        return False
    if n==2:
        return True
    c = 0
    for i in range(2,n):
        if n%2 == 0:
            return False
    return True
l6 = [i for i in range(1,101) if isprime(i)]
print(l6)

l2d = [[1,2,3],[4,5,6],[7,8,9]]
l7 = [ l2d[i][j] for i in range(len(l2d)) for j in range(len(l2d[i])) ]
print(l7)

from string import ascii_uppercase
s = "The quick brown Fox"
l8 = [i for i in s if i in ascii_uppercase]
print(l8)

l = [-1,-2,6,-6,5]
l9 = [i for i in l if i >0]
print(l9)

l10 = [(i,i**2) for i in range(1,11)]
print(l10)

s = "We are going."
l11 = [i for i in s.split() if i in ascii_uppercase]
print(l11)

l12 = [i for i in range(1,101) if i%15 == 0 ]
print(l12)

words = ["lol","foo","bar","samas"]
l13 = [i for i in words if i[::-1] == i]
print(l13)

l14 = [i if i >0 else 0 for i in l ]
print(l14)

s = "2 apples, 1 banana"
l15 = [i for i in s if i.isdigit()]
print(l15)

l16 = [[j*i for i in range(1,11)] for j in range(1,11)]
print(l16)

matrix = [
    [1,2,3],
    [4,5,6]
]
l17 = [[matrix[i][j] for i in range(2)] for j in range(3)]
print(l)
l3 = [i for i in range()]
print(l)
l3 = [i for i in range()]
print(l)
l3 = [i for i in range()]
print(l)

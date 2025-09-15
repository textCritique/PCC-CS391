# to find maximum product pair from the list of integers

l = [1, 10, 2, 6, 5, 3]
def max_product(l):
    possible_products = [l[i] * l[j] for i in range(len(l)) for j in range(i+1,len(l))]
    return max(possible_products)

print(max_product(l))
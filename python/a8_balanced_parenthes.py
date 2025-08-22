# working assumption is that whole string is already balanced then it finds second largest balanced substring
# to find largest balanced parenthes substring 
# we keep track of start and end when stack is empty
# later we can find largest pair by comparing with each pairs' end - start
# for that we use list of tuple of start and end which is declared globally and modified inside is_balanced rest of implementation of it is kept as it is
tracker = []
def is_balanced(str):
    #^^^^^^^^^^^^^^^#
    start = 0
    #_______________#
    stack = []
    closed = {")":"(", "}" : "{", "]" : "["} # it contains corresponding opening braces - helps to refactor lines 2nd case 
    for i,c in enumerate(str):
        #^^^^^^^^^^^^^^#
        if stack==[]:
            tracker.append((start,i))
            start = i
        #______________#
        match c:
            case "("| "{" | "[":
                stack.append(c)  # keeps tracks of last inserted braces
            case c if c in closed.keys():
                try:
                    if stack[-1] == closed[c]:# checks closed braces is of the last opened braces - if not then not balances
                        stack.pop()
                    else:
                        return False
                except IndexError: # if closing braces is encountered without any previous opening braces - then stack is empty - parentheses is unbalances
                    return False
    if stack == []: # if there unequal no of closing and opening braces - then stack will non empty 
        #^^^^^^^^^^^^^#
        tracker.append((start,len(str)))
        #_____________#
        return True
    return False

def largest_balanced(str):
    is_balanced(str)
    largest = 0,0
    for start,end in tracker:
        if end - start > largest[1]-largest[0]:
            largest = start, end
    return str[largest[0]:largest[1]]

unbalanced = "()[{}(])"
balanced = "()[{}()]"

print(largest_balanced(balanced))

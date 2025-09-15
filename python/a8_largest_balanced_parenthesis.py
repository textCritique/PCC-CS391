# finds the largest balanced substring by creating list of all possible substring

def is_balanced(str):
    stack = []
    closed = {")":"(", "}" : "{", "]" : "["} # it contains corresponding opening braces - helps to refactor lines 2nd case 
    for c in str:
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
        return True
    return False

def longest_balanced_parentheses(str):
    balanced_substring = [str[i:j]  for i in range(len(str)) for j in range(i+1,len(str)+1) if is_balanced(str[i:j])]
    len_balanced_substring = list(map(len,balanced_substring))
    # fot returning whole substring
    #return balanced_substring[len_balanced_substring.index(max(len_balanced_substring))]
    # for just returning length of longest substring
    return max(len_balanced_substring)

unbalanced = "()[{}(])"
balanced = "()[{}()]"

# print(largest_balanced(balanced))
print(longest_balanced_parentheses(unbalanced))

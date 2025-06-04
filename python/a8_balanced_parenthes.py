
def balanced(str):
    stack = []
    for c in str:
        if c == "(":
            stack.append()
        elif c == ")":
            if stack[-1] == "(":
                return False
        
def explode(str):
    return "".join([str[:i+1] for i in range(len(str))])

print(explode("Code"))


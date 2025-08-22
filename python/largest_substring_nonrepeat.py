# to find start and stop position of longest non repeating substring
# start position will be fixed
# start and stop are all inclusive indices
def substring_inner(string: str,start:int,stop:int,length:int) -> tuple[int,int]:
    if stop == length-1:
        return start, stop
    # in following: i is always ahead of stop by 1 - this helps to keep stop to a value such that string is non repeating when for loop ends
    for i in range(stop+1,length):
        if string[i] in string[start:stop]:
            break
        else:
            stop+=1
    return start,stop

def substring(string: str) -> str:
    length = len(string)
    max = 0,0
    for i in range(length):
        current: tuple[int,int] = substring_inner(string,i,i,length)
        if current[1]-current[0] > max[1] - max[0]:
            max = current
    return string[max[0]:max[1]+1]

print(substring("abcabqwertcbb"))
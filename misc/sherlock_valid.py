def isValid(s):

    checker={}

    for ascii in range(ord('a'),ord('z')+1):
        checker[chr(ascii)]=0

    for char in s:
        checker[char]+=1

    max_val = -1

    for char in checker.keys():
        if checker[char]>max_val:
            max_val = checker[char]

    is_valid = True
    for char in checker.keys():
        if checker[char]!=0:
            if checker[char]!=max_val or checker[char]!=max_val-1:
                return "YES"

    return "NO"


print(isValid("aabbcd"))

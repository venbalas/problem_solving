#code
import math

def get_max_sum(array,n):

    if n==0 or len(array)==0:
        return 0

    max_sum = -math.inf
    max_number = -math.inf

    for i,number in enumerate(array):
         if number> max_sum:
            max_sum = number
            max_index = i

    print('Max_index:',max_index)
    print('max_sum number:',max_sum)

    i = max_index
    temp_sum = 0

    while(i>=0):
        temp_sum = temp_sum + array[i]

        if temp_sum > max_sum:
            max_sum = temp_sum

        i -= 1

    j = max_index+1
    temp_sum = max_sum

    while j <= n-1:
        temp_sum = temp_sum + array[j]

        if temp_sum > max_sum:
            max_sum = temp_sum

        j+=1

    return max_sum


t = int(input())

while t>0:
    n = int(input())
    array = [int(s) for s in input().split(" ")]

    print(get_max_sum(array,n))

    t-=1

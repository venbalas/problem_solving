
import math
import os
import random
import re
import sys

def minimumSwaps(arr):

    count = 0
    ind = [0]*len(arr)

    for i, element in enumerate(arr):
        ind[element-1]=i

    for i in range(len(arr)-1):

        if arr[i]!=(i+1):
            print('arr:',arr)
            print('ind:',ind)
            index = ind[i]
            print('index:',index)
            ind[i] = i
            ind[arr[i]-1] = index
            arr[i],arr[index] = arr[index],arr[i]

            count+=1

    return count

if __name__ == '__main__':

    arr = [2,3,4,1,5]

    res = minimumSwaps(arr)
    print(res)

import math
import os
import random
import re
import sys

def isAnagram(s1,s2):
    sorted_s1 = sorted(s1)
    sorted_s2 = sorted(s2)

    if sorted_s1 == sorted_s2:
        return True
    else:
        return False

def sherlockAndAnagrams(s):
    substrings = []
    count=0
    for length in range(1,len(s)):
        for start_index in range(len(s)-length+1):
            substrings.append(s[start_index:start_index+length])

    for i in range(len(substrings)):
        print(substrings[i])
        for j in range(len(substrings)):
            if j!=i:
                if isAnagram(substrings[i],substrings[j]):
                    count+=1

    print(count)
    return count

sherlockAndAnagrams("abba")

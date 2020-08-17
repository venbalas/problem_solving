import numpy

def set_sum(set):
    sum=0
    for elem in set:
        sum=sum+elem
    return sum

def subset_sum(set, num):
    if num == 0:
        return 1
    if set is None or len(set)==0 or num<0:
        return 0
    if len(set)==1:
        if set[0]==num:
            return 1
        else:
            return 0

    return subset_sum(set[1:],num-set[0])+ subset_sum(set[1:],num)

print('Sum of subsets')
print('Number of subsets:{0}'.format(subset_sum([2,4,3,6,10],17)))

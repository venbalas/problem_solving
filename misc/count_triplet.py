#code

def count_triplets():
    t = int(input())

    count = 1
    count_triplets = 0

    while count<=t:
        array_size = int(input())
        array  = [int(s) for s in input().split(" ")]
        array = sorted(array)
        min_element = array[0]
        max_element = array[array_size-1]

        i = 0
        j = array_size-1

        while i<j:

            if array[i]+array[j] in array:
                count_triplets += 1
                i += 1
            elif array[i]+array[j] < min_element:
                i += 1
            elif array[i]+array[j] > max_element:
                j -= 1
            else:
                i += 1

        if count_triplets == 0:
            print(-1)
        else:
            print(count_triplets)
        count+=1

count_triplets()

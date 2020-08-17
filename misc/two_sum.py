class Solution:
    def twoSum(self, nums, target):
        nums.sort()
        i=0
        j=len(nums)-1
        print(nums)
        while(i<j):

            print('nums[{0}]:{1} nums[{2}]:{3}'.format(i,nums[i],j,nums[j]))
            if nums[i]+nums[j]==target:
                print('answer:{0}'.format([i,j]))
                return [i,j]
            elif nums[i]+nums[j]>target:
                j-=1
            else:
                i+=1

        return []

sol = Solution()
nums = [3,2,4]
target = 6
sol.twoSum(nums,target)
# print('Answer:{0}'.format(answer))

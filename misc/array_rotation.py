# Given an ascending sorted rotated array Arr of distinct integers of size N. The array is right rotated K times. Find the value of K.

class Solution:
    
    def perform_binary_search(self, arr, n):
        
        if n <= 1:
            return 0
            
        mid =n//2
        
        if n%2==0:
            left_subarray_size = n//2
            right_subarray_size = n//2
        else:
            left_subarray_size = n//2
            right_subarray_size = (n//2) + 1  
        
        # Check if transition is here
        if arr[mid-1] > arr[mid]:
            return mid
        
        left = self.perform_binary_search(arr[0:mid],left_subarray_size)
        
        # left sub array has transition; return immediately
        if left > 0:
            return left
        else:
            # Perform right search and add up the left part's result
            right = self.perform_binary_search(arr[mid:n],right_subarray_size)
            if right>0 :
                return mid + right
            else:
                return 0
        
    def findKRotation(self,arr,  n):
        # code here
        return self.perform_binary_search(arr, n)


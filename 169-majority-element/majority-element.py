class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        c = None 
        n = len(nums)
        for i in range(n):
            if count == 0:
                c = nums[i]
                count = 1
            elif nums[i] == c:
                count+= 1 
            else:
                count-=1
        return c 
       
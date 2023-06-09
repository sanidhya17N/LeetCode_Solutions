class Solution:
    def findMin(self, nums: List[int]) -> int:
        res=nums[0]
        l=0
        r=len(nums)-1
        while nums[r]<nums[l]:
            mid=int(r-(r-l)/2)
            res=nums[mid]
            if nums[mid]>=nums[l]:
                l=mid+1
            else:
                r=mid-1 
        return min(res,nums[l])
"""
https://leetcode-cn.com/problems/two-sum/submissions/
"""
class Solution(object):
    def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        r = []
        for i in range(len(nums)):
            try:
                if(i in r): continue
                ind = nums.index(target-nums[i])
                if(i==ind):continue  # for the element number is half of target
            except:
                continue
            else:
                r.extend([i,ind])
        return r

    def twoSum2(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_dict={}
        r=[]
        for i in range(len(nums)):
            if(nums_dict.get(target-nums[i])==None):
                nums_dict.update({nums[i]: i})
            else:
                r.append(nums_dict[target-nums[i]])
                r.append(i)
        return r


nums=[2,7,11,15]
r=Solution.twoSum(nums,9)
print(r)

r=Solution.twoSum2(nums,9)
print(r)


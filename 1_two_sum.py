"""
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
"""

class Solution(object):
    def twoSum(numlist:list, target: int) -> list:
        """
        :type numlist: List[int]
        :type target: int
        :rtype: List[int]
        """
        r = []
        for i in range(len(numlist)):
            try:
                if i in r: continue
                ind = numlist.index(target - numlist[i])
                if i==ind :continue  # for the element number is half of target
            except:
                continue
            else:
                r.extend([i,ind])
        return r

    def twoSum2(numlist:list, target:int)->list:
        """
        :type numlist: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_dict={}  # value:index in array, sum-value is not kept in the dictionary
        r=[]
        for i in range(len(numlist)):
            if nums_dict.get(target - numlist[i]) is None:
                nums_dict.update({numlist[i]: i})
            else:
                r.append(nums_dict[target - numlist[i]])
                r.append(i)
        return r

if __name__=="__main__":
    nums=[2,7,11,15]
    r=Solution.twoSum(nums,9)
    print(r)

    r=Solution.twoSum2(nums,9)
    print(r)


"""
https://leetcode-cn.com/problems/two-sum/submissions/
"""
from typing import Any


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


/*
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
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapNum;
        vector<int> idxVec;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = mapNum.find(target - nums[i]);
            if (iter != mapNum.end())
            {
				idxVec.push_back(iter->second);
                idxVec.push_back(i);
                break;
            }
            else
            {
                mapNum[nums[i]] = i;
            }
        }
        return idxVec;
    }

    vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> idxVec;
        for (int i = 0; i < nums.size(); i++)
        {
            if (std::find(idxVec.begin(), idxVec.end(), i) != idxVec.end()) continue;
            auto iter = std::find(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (iter != idxVec.end())
            {
                auto idx = std::distance(nums.begin(), iter);
                if(idx!=i)
                {
                    idxVec.push_back(i);
                    idxVec.push_back(idx);
                    break;
                }
            }
        }
        return idxVec;
    }
};
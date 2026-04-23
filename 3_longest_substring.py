"""
https://leetcode.com/problems/longest-substring-without-repeating-characters
Given a string s, find the length of the longest substring without duplicate characters.



Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window={}
        left,right=0,0
        res=0
        while right < len(s):
            c=s[right]
            right += 1
            window[c]=window.get(c,0)+1
            while window[c]>1:
                d=s[left]
                left+=1
                window[d]=window.get(d,0)-1
            res= max(res,right-left)
        return  res


if __name__ == "__main__":
    s = "abcabcbb"
    sol = Solution()
    n = sol.lengthOfLongestSubstring(s)
    print(n)
    s = "bbbbb"
    n = sol.lengthOfLongestSubstring(s)
    print(n)
    s = "pwwkew"
    n = sol.lengthOfLongestSubstring(s)
    print(n)

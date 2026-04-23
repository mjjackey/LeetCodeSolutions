"""
https://leetcode.com/problems/reverse-string/
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.



Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]


Constraints:

1 <= s.length <= 105
s[i] is a printable ascii character.
"""

class Solution:
    def reverseString(self, s: list[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = int(len(s)/2)
        for i in range(n):
             s[i],s[len(s)-1-i] = s[len(s)-1 - i],s[i]

if __name__ == "__main__":
     sol = Solution()
     s = ["h", "e", "l", "l", "o"]
     print(s)
     sol.reverseString(s)
     print(s)
     s2= ["H","a","n","n","a","h"]
     print(s2)
     sol.reverseString(s2)
     print(s2)

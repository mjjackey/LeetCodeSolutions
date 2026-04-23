"""
https://leetcode.com/problems/reverse-words-in-a-string
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.


Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?
"""
import collections

class Solution:
    def reverse_words(self, s: str) -> str:
        return ' '.join(s.strip().split()[::-1])

class Solution1:
    # double pointer
    def reverse_words(self, s: str) -> str:
        s=s.strip()
        # Search from last word
        i=j=len(s)-1
        res=[]
        while i>=0:
            while i>=0 and s[i]!=' ': i-=1 #Search the first space
            res.append(s[i+1:j+1])
            while i>=0 and s[i]==' ': i-=1 #Search the tail of the next word
            j=i
        return  ' '.join(res)

class Solution2:
    def reverse_words(self, s: str) -> str:
        left,right= 0,len(s)-1
        deq,str_word=collections.deque(),[]
        # eliminate the spaces of head and nail
        while left<=right and s[left]==' ': left+=1
        while right>=left and s[right]==' ': right-=1
        while left<=right:
            if s[left]!=' ': str_word.append(s[left])
            elif s[left]==' ' and str_word:
                deq.appendleft(''.join(str_word))
                str_word=[]
            left+=1
        if str_word: deq.appendleft(''.join(str_word))
        return ' '.join(deq)

if __name__=="__main__":
    sol=Solution2()
    s=" hello world  "
    res=sol.reverse_words(s)
    print(res)


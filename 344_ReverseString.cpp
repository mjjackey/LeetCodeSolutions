/*
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
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = (int)s.size()/2;
        for (int i = 0; i < n; i++)
        {
            auto tmpStr=s[i];
            s[i]=s[s.size()-1-i];
            s[s.size()-1-i]=tmpStr;
        }
    }
};

int main()
{
   vector<char> str={'H','a','n','n','a','h'};
   for (const auto& s: str)
   {
        std::cout << s << ' ';
   }
   std::cout << endl;
   
   auto sol=new Solution();
   sol->reverseString(str);
   for (const auto& s: str)
   {
        std::cout << s << ' ';
   }
   std::cout << endl;

   vector<char> str2 = { 'H','a', 'p', 'p','y'};
   for (const auto& s : str2)
   {
       std::cout << s << ' ';
   }
   std::cout << endl;

   sol->reverseString(str2);
   for (const auto& s : str2)
   {
       std::cout << s << ' ';
   }
   std::cout << endl;
}

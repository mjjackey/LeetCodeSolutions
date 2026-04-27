/*
https://leetcode.com/problems/valid-palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        toLowerAndTrim(s);
        int left=0,right=s.length()-1;
        while(left<right)
        {
            if(s[left++]!=s[right--]) return false;
        }
        return true;
    }
    
    void toLowerAndTrim(string& s){
        auto iter=std::remove_if(s.begin(),s.end(),[](char ch){
            return !std::isalnum(ch);
        });
        s.erase(iter,s.end());
        std::transform(s.begin(),s.end(),s.begin(),[](unsigned char ch){
            return std::tolower(ch);
        });
    }

    void toLowerAndTrim2(string& s){
        std::string ss;
        for(auto ch:s)
        {
            if(std::isalnum(ch)) ss+=std::tolower(ch);
        }
        s=ss;
    }

};

int main()
{
    Solution* sol=new Solution();
    std::string s="A man, a plan, a canal: Panama";
    auto t=sol->isPalindrome(s);
    cout<<t<<std::endl;
    cin;
}
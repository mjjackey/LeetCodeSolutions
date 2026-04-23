/*
* https://leetcode.com/problems/reverse-words-in-a-string/
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
*/
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <deque>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;
        trim(s);

        /* auto arrStr = splitString(s, ' ');
        auto arrRes = reverseStringArr(arrStr);
        for (const auto& str: arrRes)
        {
            res += str + " ";
        }*/

        auto deqStr = splitString2(s, ' ');
        /*auto str = deqStr.front();
        while (str!="")
        {
            auto str = deqStr.front();
            res += str + " ";
            deqStr.pop_front();
        }*/
        for (int i = deqStr.size()-1; i >= 0; i--)
        {
            auto str = deqStr.at(i);
            res += str + " ";
        }

        res.erase(res.end()-1);
        //res.substr(res.size() - 1);
        return res;
    }
    
    vector<string> splitString(const string& str, const char& deli)
    {
        std::vector<string> arrStr;
        auto pStr = str.c_str();
        int i = 0;
        string tempStr;
        while (pStr[i] != '\0')
        {
            //(pStr[i] != ' ') ? tempStr += pStr[i] : (arrStr.push_back(tempStr), tempStr = "");
            if (pStr[i] != ' ')
            {
                tempStr += pStr[i];
            }
            else
            {
                if (tempStr != "")
                {
                    arrStr.push_back(tempStr);
                    tempStr = "";
                }
            }
            i++;
        }
        if(tempStr != "")
            arrStr.push_back(tempStr);
        return arrStr;
    }


    std::vector<std::string> reverseStringArr(const vector<string>& arrStr)
    {
        std::vector<std::string> arrRes;
        for (auto iter = arrStr.crbegin(); iter != arrStr.crend(); iter++)
        {
            arrRes.push_back(*iter);
        }
        return arrRes;
    }

    deque<string> splitString2(const string& str, const char& deli)
    {
        deque<string> deqStr;
        auto pStr = str.c_str();
        int i = 0;
        string tempStr;
        while (pStr[i] != '\0')
        {
            //(pStr[i] != ' ') ? tempStr += pStr[i] : (arrStr.push_back(tempStr), tempStr = "");
            if (pStr[i] != ' ')
            {
                tempStr += pStr[i];
            }
            else
            {
                if (tempStr != "")
                {
                    deqStr.push_back(tempStr);
                    tempStr = "";
                }
            }
            i++;
        }
        if (tempStr != "")
            deqStr.push_back(tempStr);
        return deqStr;
    }
        
    void trim(string& s)
    {
        if(s.empty())
            return;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of("　") + 1);
    }
};

int main()
{
    //string s = "the sky is blue";
    string s = "  hello world  ";
    //string s = "a good   example";
    Solution sol;
    auto res = sol.reverseWords(s);
    std::cout << res << std::endl;
}
/*
* https://leetcode.com/problems/merge-strings-alternately/
* You are given two strings word1 and word2. Merge the strings by adding letters in alternating
 * order, starting with word1. If a string is longer than the other, append the additional letters
 * onto the end of the merged string.
 *
 * Return the merged string.
 *
 * Example 1:
 *
 * Input: word1 = "abc", word2 = "pqr"
 * Output: "apbqcr"
 * Explanation: The merged string will be merged as so:
 * word1:  a   b   c
 * word2:    p   q   r
 * merged: a p b q c r
 *
 * Example 2:
 *
 * Input: word1 = "ab", word2 = "pqrs"
 * Output: "apbqrs"
 * Explanation: Notice that as word2 is longer, "rs" is appended to the end.
 * word1:  a   b
 * word2:    p   q   r   s
 * merged: a p b q   r   s
 *
 * Example 3:
 *
 * Input: word1 = "abcd", word2 = "pq"
 * Output: "apbqcd"
 * Explanation: Notice that as word1 is longer, "cd" is appended to the end.
 * word1:  a   b   c   d
 * word2:    p   q
 * merged: a p b q c   d
 *
 * Constraints:
 *
 * 	1 <= word1.length, word2.length <= 100
 * 	word1 and word2 consist of lowercase English letters.
*/
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
		auto len1 = word1.size();
		auto len2 = word2.size();
		auto len = len1 > len2 ? len1 : len2;
		string res;
		for (size_t i = 0; i < len; i++)
		{
			if (i < len1 && i <len2)
			{
				res.push_back(word1[i]);
				res.push_back(word2[i]);
			}
			else if (i>=len1 && i<len2)
			{
				res.push_back(word2[i]);
			}
			else if (i >= len2 && i < len1)
			{
				res.push_back(word1[i]);
			}
		}
		return res;
    }

	string mergeAlternately2(string word1, string word2) {
		auto len1 = word1.size();
		auto len2 = word2.size();
		auto len = len1 < len2 ? len1 : len2;
		string res;
		for (size_t i = 0; i < len; i++)
		{
			res.push_back(word1[i]);
			res.push_back(word2[i]);
		}
		if (len1 != len2)
		{
			res.append(len1 < len2 ? word2.substr(len1) : word1.substr(len2));
		}
	
		return res;
	}

	string mergeAlternately3(string word1, string word2)
	{
		int i = 0;
		auto len1 = word1.size();
		auto len2 = word2.size();
		string res;
		//auto len = len1 > len2 ? len1 : len2;
		res.reserve(len1 + len2);
		
		while (i < len1 || i < len2)
		{
			if (i < len1)
			{
				res.push_back(word1[i]);
			}
			if (i < len2)
			{
				res.push_back(word2[i]);
			}
			i++;
		}
		return res;
	}
};
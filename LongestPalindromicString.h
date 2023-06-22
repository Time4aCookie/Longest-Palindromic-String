// Created by Rohan Tatikonda on 6/18/23.
#include "iostream"
#include "string"

using namespace std;

class Solution{
public:
	string longestPalindromicString(string s);
	string optimalLongestPalindromicString(string s);
	int expand(int i, int j, string s);
};
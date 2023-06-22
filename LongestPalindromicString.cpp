
// Created by Rohan Tatikonda on 6/18/23.
#include <vector>
#include "string"
#include "iostream"
#include "LongestPalindromicString.h"
#pragma once

string Solution::longestPalindromicString(string s) {
	if (s.size() == 1) {
		return s;
	}
	if (s.size() == 2) {
		if (s.substr(0, 1) == s.substr(1, 1)) {
			return s;
		}
		return s.substr(0, 1);
	}
	string realAns = "";
	for (int i = 1; i < s.size(); ++i) {
		string ans = "";
		int back = i - 1;
		int front = i + 1;
		int curr = 0;
		// case 1: if we have an odd palindrome
		if (i < s.size()-1 && s.substr(i - 1, 1) == s.substr(i + 1, 1)) {
			while (curr < min(i, int(s.size()) - i - 1) && s.substr(back, 1) == s.substr(front, 1)) {
				if (s.substr(back, 1) == s.substr(front, 1)) {
					ans = s.substr(back, front - back + 1);
					front++;
					back--;
					curr++;
				}
			}
			if (ans.size() > realAns.size()) {
				realAns = ans;
			}
			curr = 0;
			continue;
			i = front;
		}
		//case 2: if we have an even palindrome
		if (s.substr(i - 1, 1) == s.substr(i, 1)) {
			back = i - 1;
			front = i;
			while (curr <= min(i - 1, int(s.size() - i - 1)) && s.substr(back, 1) == s.substr(front, 1)) {
				if (s.substr(back, 1) == s.substr(front, 1)) {
					ans = s.substr(back, front - back + 1);
					front++;
					back--;
					curr++;
				}
			}
			if (ans.size() > realAns.size()) {
				realAns = ans;
			}
		}
	}
	if (realAns.size() == 0) {
		return s.substr(0, 1);
	}
	return realAns;
}


string Solution::optimalLongestPalindromicString(string s){   //let use a helper method to do the palindrome check 4 us.
	int left = 0;
	int right = 0;
	for(int i = 0; i < s.size(); ++i){
		 int oddExpand = expand(i,i,s);
		 if(oddExpand > right-left+1) {
			 left = i-oddExpand/2;
			 right = i+oddExpand/2;
		 }
		 int evenExpand = expand(i, i+1, s);
		 if(evenExpand > right-left+1) {
			 left = i+1-evenExpand/2;
			 right = i+evenExpand/2;
		 }
	}
	return s.substr(left, right-left+1);
}

int Solution::expand(int i, int j, string s) {
	int left = i;
	int right = j;
	while(left >= 0 && right < s.size() && s.substr(left,1) == s.substr(right,1)){
		left--;
		right++;
	}
	return right-left-1;
}
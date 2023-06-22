// Created by Rohan Tatikonda on 6/18/23.
#include "iostream"
#include "string"
#include "vector"
#include "LongestPalindromicString.h"
#pragma once

using namespace std;
int main(int argc, char* argv[]){
	Solution test;
	string input = "racecar";
	string ans = test.optimalLongestPalindromicString(input);
	cout << ans << endl;
}
/*
 * LongestPalindromic.cpp
 *
 *  Created on: 2013-6-5
 *      Author: glx
 */
//求字符串的回文子串

#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(string s, int c1, int c2) {
    int left = c1;
    int right = c2;
    int length = s.length();
    while(left >= 0 && right <= length-1 && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left+1, right-left-1);
}

string LongestPalindromic(string s) {
    int length = s.length();
    if(length == 0)
        return "";
    string longest = s.substr(0, 1);
    for(int i=0; i<length; i++) {
        string s1 = expandAroundCenter(s, i, i);
        if(s1.length() > longest.length())
            longest = s1;
        string s2 = expandAroundCenter(s, i, i+1);
        if(s2.length() > longest.length())
            longest = s2;
    }
    return longest;
}

int main() {
    //string str = "abcdefggfh";
    //string str = "abcdefgh";
    string str = "deed";
    cout << LongestPalindromic(str) << endl;
    return 0;
}

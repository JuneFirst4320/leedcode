#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		string res = "";
		int maxnum = 0;
		int flag = 1;//0 for i to move, 1 for j to move
		if (len == 1) {
			return s;
		}
		for (int i = 0, j = 1; i < len - 1, j < len;) {
			if (s[i] == s[j]) {
				int tempnum = j - i + 1;
				int tempi = i;
				int tempj = j;
				while (tempi > 0 && tempj < len - 1) {
					tempi--;
					tempj++;
					if (s[tempi] == s[tempj]) {
						tempnum += 2;
					}
					else {
						tempi++;
						tempj--;
						break;
					}
				}
				if (tempnum > maxnum) {
					res = s.substr(tempi, tempnum);
					maxnum = tempnum;
				}
				if (flag) {
					j++;
					flag = 0;
				}
				else {
					i++;
					flag = 1;
				}
			}
			else {
				if (flag) {
					j++;
					flag = 0;
				}
				else {
					i++;
					flag = 1;
				}
			}
		}
		if (maxnum == 0) {
			res = s[0];
		}
		return res;
	}
};

int main() {
	Solution s;
	string str = "hellol";
	cout << s.longestPalindrome(str) << endl;
	_getch();
	return 0;
}
#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int size = strs.size();
		if (size == 0)
			return "";
		int temp = strs[0].length();
		string result = "";
		//sort(strs.begin(), strs.end());
		for (int i = 0; i < size; i++) {
			int len = strs[i].length();
			if (temp > len) {
				temp = len;
			}
		}
		for (int i = 0; i < temp; i++) {
			char t = strs[0][i];
			int flag = 1;
			for (int j = 1; j < size; j++) {
				if (strs[j][i] != t) {
					flag = 0;
					return result;
				}
			}
			if (flag) {
				result += t;
			}
		}
		return result;
	}
};

int main() {
	vector<string> strs;
	strs.push_back("hello");
	strs.push_back("he");
	strs.push_back("heiios");
	strs.push_back("helo");
	strs.push_back("m");
	Solution s;
	cout <<"the result:"<< s.longestCommonPrefix(strs) << endl;
	_getch();
	return 0;
}
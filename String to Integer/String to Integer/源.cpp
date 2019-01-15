#include<iostream>
#include<conio.h>
#include<string>
#include <cctype>
#include<sstream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		string res = "";
		int resInt = 0;
		int len = str.length();
		bool flag = false;
		for (auto c : str) {
			if (!flag && (c == ' '||c == '0'))
				continue;
			else if (!flag&&(isdigit(c)||c=='-'||c=='+')) {
				res.push_back(c);
				flag = true;
			}
			else if(flag&&(isdigit(c))) {
				res.push_back(c);
			}
			else {
				break;
			}
		}
		if (res.length() == 0 || (res.length() == 1 && ((res[0] == '-')||(res[0] == '+')))) {
			return 0;
		}
		else {
			char temp = '+';
			if (res[0] == '+' || res[0] == '-') {
				temp = res[0];
				res = res.substr(1, res.length() - 1);
			}
			int index = 0;
			for (int i = 0; i < res.length(); i++) {
				if (res[i] != '0') {
					break;
				}
				else if (res[i] == '0')
					index++;
			}
			if (index >= res.length()) {
				res = "0";
			}else
				res = res.substr(index, res.length() - index);

			stringstream ss(res);
			ss >> resInt;
			if (resInt == 0 && temp == '-' && res[0]!='0') 
				return INT32_MIN;
			else if (resInt == 0 && temp == '+' && res[0] != '0')
				return INT32_MAX;
			if (temp == '-')
				return -resInt;
			return resInt;
		}
	}
};

int main() {
	Solution s;
	string str = "-91283472332";
	cout << s.myAtoi(str) << endl;
	_getch();
	return 0;
}
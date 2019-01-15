#include<iostream>
#include<conio.h>
#include<string>
using namespace std;



class Solution {
public:
	int romanToInt(string s) {
		int len = s.length();
		int temp = 0;
		int sum = 0;
		for (int i = len-1; i >=0; i--) {
			int num = romanToNum(s[i]);
			if (num >= temp) {
				sum += num;
			}
			else {
				sum -= num;
			}
			temp = num;
		}
		return sum;
	}

	int romanToNum(char c) {
		int re;
		switch (c)
		{
		case 'I':re = 1; break;
		case 'V':re = 5; break;
		case 'X':re = 10; break;
		case 'L':re = 50; break;
		case 'C':re = 100; break;
		case 'D':re = 500; break;
		case 'M':re = 1000; break;
		default:
			break;
		}
		return re;
	}
};

int main() {
	string hello;
	cin >> hello;
	while (hello != "0") {
		Solution s;
		int result = s.romanToInt(hello);
		cout << "the answer is :" << result << endl;
		cin >> hello;
	}
	_getch();
	return 0;
}
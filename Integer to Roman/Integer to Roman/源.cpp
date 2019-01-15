#include<iostream>
#include<string>
#include<map>
#include<math.h>
#include<sstream>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		stringstream s;
		string res = "";
		string numToString;
		int len;
		map<int, char> myMapC = {
			{1, 'I'},
			{5, 'V'},
			{10, 'X'},
			{50, 'L'},
			{100, 'C'},
			{500, 'D'},
			{1000, 'M'}
		};
		map<int, int> myMapN = {
			{ 1,1},
			{ 2,5},
			{ 3,10},
			{ 4,50},
			{ 5,100},
			{ 6,500},
			{ 7,1000}
		};
		for (int i = 7; i >= 1; i--) {
			s.clear();
			s << num;
			s >> numToString;
			len = numToString.length();
			if (num == 0)
				break;
			int temp = num / myMapN.at(i);
			if (temp == 0)
				continue;
			else if (numToString[0] == '4') {
				res.push_back(myMapC.at(1 * (int)(pow(10, len - 1))));
				res.push_back(myMapC.at(5 * (int)(pow(10, len - 1))));
				num -= 4 * (int)(pow(10, len - 1));
			}else if (numToString[0] == '9') {
				res.push_back(myMapC.at(1 * (int)(pow(10, len - 1))));
				res.push_back(myMapC.at(10 * (int)(pow(10, len - 1))));
				num -= 9 * (int)(pow(10, len - 1));
			}
			else {
				int iter = temp;
				while (iter) {
					res.push_back(myMapC.at(myMapN.at(i)));
					num -= myMapN.at(i);
					iter--;
				}
			}
		}
		return res;
	}
};

int main() {
	Solution s;
	cout << s.intToRoman(58) << endl;
	system("pause");
	return 0;
}
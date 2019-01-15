#include<iostream>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.length();
		string result = "";
		vector<vector<char> > temp(numRows, vector<char>(numRows));
		int rowN = 0;
		bool isplus = true;
		if (len == 0 || numRows == 1)
			return s;
		for (int i = 0; i < len; i++) {
			if (isplus && rowN <= numRows - 1) {
				temp[rowN].push_back(s[i]);
				if (rowN == numRows - 1) {
					rowN--;
					isplus = false;
				}
				else {
					rowN++;
				}
			}
			else if(~isplus && rowN >= 0){
				temp[rowN].push_back(s[i]);
				if (rowN == 0) {
					rowN++;
					isplus = true;
				}
				else {
					rowN--;
				}
			}
		}
		for (int i = 0; i < numRows; i++) {
			int size = temp[i].size();
			for (int j = 0; j < size; j++) {
				char hello = temp[i][j];
				if (hello != NULL) {
					result += hello;
				}
			}
		}
		return result;
	}
};

int main() {
	string s = "PAYPALISHIRING";
	int rows = 4;
	Solution so;
	cout << so.convert(s, rows) << endl;
	_getch();
	return 0;
}
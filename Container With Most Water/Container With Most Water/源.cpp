#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int size = height.size();
		int waterV = 0;
		for (int i = 0; i < size-1; i++) {
			for (int j = i + 1; j < size; j++) {
				int waterN = theSmallOne(height[i], height[j])* (j - i);
				waterV = waterN > waterV ? waterN : waterV;
			}
		}
		return waterV;
	}

	int theSmallOne(int x, int y) {
		if (x > y)
			return y;
		else
			return x;
	}
};

int main() {
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(8);
	v.push_back(60);
	v.push_back(2);
	v.push_back(9);
	v.push_back(4);
	v.push_back(8);
	v.push_back(3);
	v.push_back(80);
	cout << s.maxArea(v) << endl;
	system("pause");
	return 0;
}
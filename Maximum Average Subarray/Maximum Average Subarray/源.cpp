#include<iostream>
#include<conio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int n = nums.size();
		int max_sum = 0;
		int temp_sum = 0;
		queue<int> my_q;
		for (int j = 0; j < k; j++) {
			my_q.push(nums[j]);
			temp_sum += nums[j];
		}
		max_sum = temp_sum;
		for (int i = 1; i < n-k+1; i++) {
			my_q.pop();
			my_q.push(nums[i + k - 1]);
			temp_sum = temp_sum - nums[i - 1] + nums[i + k - 1];
			max_sum = max(temp_sum, max_sum);
		}
		return (double)max_sum / k;
	}
};

int main() {
	Solution s;
	vector<int> nums;
	int k;
	nums.push_back(1);
	nums.push_back(12);
	nums.push_back(-5);
	nums.push_back(-6);
	nums.push_back(50);
	nums.push_back(3);
	k = 4;
	cout << s.findMaxAverage(nums, k);
	_getch();
	return 0;
}
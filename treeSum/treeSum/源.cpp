#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		vector<int> digt_indx;
		vector<int> sum_indx;
		sort(nums.begin(), nums.end());
		int num_temp = nums[0];
		int sum_temp = 1;
		digt_indx.push_back(num_temp);
		for (int i = 1; i < len; i++) {
			if (num_temp == nums[i]) {
				sum_temp++;
			}
			else {
				sum_indx.push_back(sum_temp);
				num_temp = nums[i];
				digt_indx.push_back(num_temp);
				sum_temp = 1;
			}
		}
		sum_indx.push_back(sum_temp);
		if (digt_indx.size() == sum_indx.size())
			cout << "excellent processing!!" << endl;
		else
			cout << "bad processing!!" << endl;
		for (int i = 0; i < digt_indx.size(); i++) {
			if (sum_indx[i] > 3)
				sum_indx[i] = 3;
		}
		return selet_num(digt_indx, sum_indx, 0, 3);
	}
	vector<vector<int>> selet_num(vector<int>& digt_indx, vector<int>& sum_indx, int sum, int num) {
		int size = digt_indx.size();
		vector<vector<int>> res;
		vector<int> res_item;
		if (num == 1) {
			for (int i = 0; i < size; i++) {
				if (digt_indx[i] == sum) {
					res_item.push_back(sum);
					res.push_back(res_item);
					return res;
				}
			}
			return;
		}
		int temp_digt, temp_num;
		for (int i = 0; i < size; i++) {
			temp_digt = digt_indx[i];
			temp_num = sum_indx[i];
			for (int j = 0; j < temp_num; j++) {
				if (j == 0) {
					digt_indx.erase[0];

					res.push_back(selet_num())
				}
			}
		}

	}
};

int main() {
	Solution s;
	vector<int> nums;
	vector<vector<int> > res;
	nums.push_back(-1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(-1);
	nums.push_back(4);
	res = s.threeSum(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
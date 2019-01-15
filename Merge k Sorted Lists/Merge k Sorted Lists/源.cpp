#include<iostream>
#include<conio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int num = lists.size();
		vector<stack<ListNode*>> stack_vec;
		ListNode* p;
		int max_len = 0;
		for (int i = 0; i < num; i++) {
			stack<ListNode*> temp;
			int temp_len = 0;
			p = lists[i];
			while (p != NULL) {
				temp.push(p);
				temp_len++;
				p = p->next;
			}
			max_len += temp_len;
			stack_vec.push_back(temp);
		}
		int vec_num = num;
		vector<int> vec_empty_index;
		ListNode* pp = NULL;
		for (int i = 0; i < max_len; i++) {
			int temp_max = int(-INFINITY);
			int max_index = 0;
			for (int j = 0; j < vec_num; j++) {
				if (!stack_vec[j].empty()) {
					ListNode* temp_node = stack_vec[j].top();
					if (temp_node->val > temp_max) {
						temp_max = temp_node->val;
						max_index = j;
					}
				}
			}
			if (i == 0) {
				pp = stack_vec[max_index].top();
				stack_vec[max_index].pop();
			}
			else {
				stack_vec[max_index].top()->next = pp;
				pp = stack_vec[max_index].top();
				stack_vec[max_index].pop();
			}
		}
		return pp;
	}
};


int main() {
	Solution s;
	vector<ListNode*> lists;
	ListNode* result;
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(8);
	ListNode* l4 = new ListNode(12);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	lists.push_back(l1);

	ListNode* l5 = new ListNode(3);
	ListNode* l6 = new ListNode(4);
	ListNode* l7 = new ListNode(8);
	ListNode* l8 = new ListNode(10);
	l5->next = l6;
	l6->next = l7;
	l7->next = l8;
	lists.push_back(l5);

	ListNode* l9 = new ListNode(7);
	ListNode* l10 = new ListNode(9);
	ListNode* l11 = new ListNode(18);
	l9->next = l10;
	l10->next = l11;
	lists.push_back(l9);

	result = s.mergeKLists(lists);
	ListNode* p = result;
	while (p != NULL) {
		cout << p->val<<" ";
		p = p->next;
	}
	_getch();
	return 0;
}
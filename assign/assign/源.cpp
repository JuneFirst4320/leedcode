#include <iostream>
#include <vector>
#include <time.h>
#include<fstream>
using namespace std;
#define citynum 50
#define INF 9999

vector <int> trace;             //当前路径
vector <int> solution;  //所有解
int dis[citynum][citynum];
int cost[citynum][citynum];
int min_dis[citynum][citynum];
int lowest = INF;
int visited[citynum];
int cost_now;

void floyd() {
	for (int i = 0; i < citynum; i++) {
		for (int j = 0; j < citynum; j++) {
			min_dis[i][j] = dis[i][j];
		}
	}
	for (int i = 0; i < citynum; i++)
		min_dis[i][i] = 0;

	for (int i = 0; i < citynum; i++) {
		for (int j = 0; j < citynum; j++) {
			for (int k = 0; k < citynum; k++) {
				if (min_dis[i][j] > min_dis[i][k] + min_dis[k][j])
					min_dis[i][j] = min_dis[i][k] + min_dis[k][j];
			}
		}
	}
}

int cal_bound(int cur_dis, int city_in) {
	int bound = 0;
	bound = cur_dis + min_dis[city_in][citynum - 1];
	return bound;
}

void search(vector<int> &trace, int city_in) {
	visited[city_in] = 1;
	trace.push_back(city_in);

	int cur_dis = 0;                    //当前路程
	int cur_cost = 0;                   //当前路费


	for (int i = 1; i < trace.size(); i++) {
		cur_cost += cost[trace[i - 1]][trace[i]];
		cur_dis += dis[trace[i - 1]][trace[i]];
	}

	//减枝
	if (cur_dis > lowest || cur_cost > 1500 || cal_bound(cur_dis, city_in) >= lowest) {
		trace.pop_back();
		visited[city_in] = 0;
		return;
	}

	if (city_in == citynum - 1) {
		if (cur_dis < lowest) {
			lowest = cur_dis;
			cost_now = cur_cost;
			solution.clear();
			for (int i = 0; i < trace.size(); i++) {
				solution.push_back(trace[i]);
			}
		}
		trace.pop_back();
		visited[city_in] = 0;
		return;
	}

	//继续搜索
	for (int i = 0; i < citynum; i++) {
		if (visited[i] != 1 && dis[city_in][i] != INF) {
			search(trace, i);
		}
	}

	trace.pop_back();
	visited[city_in] = 0;

}

void test_data() {
	ifstream tests;
	tests.open("m1.txt");
	if (!tests) {
		cout << "file not exit!" << endl;
	}
	for (int i = 0; i < citynum; i++) {
		for (int j = 0; j < citynum; j++) {
			tests >> dis[i][j];
		}
	}
	tests.close();

	ifstream tests2;
	tests2.open("m2.txt");
	if (!tests2) {
		cout << "file not exit!" << endl;
	}
	for (int i = 0; i < citynum; i++) {
		for (int j = 0; j < citynum; j++) {
			tests2 >> cost[i][j];
		}
	}
	tests2.close();

	//floyd();
}

int main() {
	time_t start, stop;
	start = clock();
	test_data();
	memset(visited, 0, citynum);
	
	floyd();
	search(trace, 0);
	stop = clock();
	for (int i = 0; i < solution.size(); i++) {
		printf("%d ", solution[i]);
	}
	printf("cost=%d,dis= %d\n", cost_now, lowest);
	printf("Use Time:%ld ms\n", (stop - start));

	getchar();
	return 0;
}
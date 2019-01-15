#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

const int N = 50;
int C[N][N];
int D[N][N];
int dis[N][N];        //存储各个定到各个顶点的最短路径
int cost[N][N];       //存储各个顶点到各个顶点之间的最小花费
vector<int> shortest_path;
int minidist;

struct link {
	int index;
	int cost;
	int dist;
	vector<int> path;
};

void floyd()
{
	for (int i = 0; i < N; i++)              //初始化
	{

		for (int j = 0; j < N; j++)
		{
			dis[i][j] = D[i][j];
			cost[i][j] = C[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		dis[i][i] = 0;
		cost[i][i] = 0;
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				//dis[i] = min(dis[i],dis[j] + L[j][i]);
				if (dis[k][i] > dis[k][j] + dis[j][i])               //求源点到节点的最短路径，利用现有的L矩阵
				{
					dis[k][i] = dis[k][j] + dis[j][i];
				}
				if (cost[k][i] > cost[k][j] + cost[j][i]) {
					cost[k][i] = cost[k][j] + cost[j][i];
				}
			}
			for (int m = 0; m < i; m++)              //更新节点最短路径
			{
				for (int j = 0; j < N; j++)
				{
					if (dis[k][m] > dis[k][j] + dis[j][m])
					{
						dis[k][m] = dis[k][j] + dis[j][m];
					}
					if (cost[k][m] > cost[k][j] + cost[j][m]) {
						cost[k][m] = cost[k][j] + cost[j][m];
					}
				}
			}
		}
	}

	
}

void find_the_shortest() {
	queue<link> link_queue;
	minidist = 9999;
	link node1, temp;
	node1.index = 0;
	node1.cost = 0;
	node1.path.push_back(0);
	node1.dist = 0;
	link_queue.push(node1);

	while (!link_queue.empty()) {
		temp = link_queue.front();
		link_queue.pop();
		if (shortest_path.size() != 0) {
			cout << minidist << endl;
		}
		for (int i = 0; i < 50; i++) {
			vector<int>::iterator it;
			it = std::find(temp.path.begin(), temp.path.end(), i);

			if (it != temp.path.end())
				continue;
			else if (D[temp.index][i] == 9999)
				continue;
			else if (i == 49 &&	(temp.cost + C[temp.index][i] <= 1500) &&
				(temp.dist + D[temp.index][i] < minidist)) {
				//update the minidist
				minidist = temp.dist + D[temp.index][i];
				temp.path.push_back(i);
				shortest_path = temp.path;
			}else if ((temp.cost + C[temp.index][i] + cost[i][49] <= 1500)&&
				(temp.dist + D[temp.index][i] + dis[i][49] < minidist)) {
				//add the new link
				link node_new;
				node_new.cost = temp.cost + C[temp.index][i];
				node_new.dist = temp.dist + D[temp.index][i];
				node_new.index = i;
				node_new.path = temp.path;
				node_new.path.push_back(i);
				link_queue.push(node_new);
			}
			else {
				continue;
			}
		}
	}
}

void test_data() {
	ifstream tests;
	tests.open("m1.txt");
	if (!tests) {
		cout << "file not exit!" << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tests >> D[i][j];
		}
	}
	tests.close();

	ifstream tests2;
	tests2.open("m2.txt");
	if (!tests2) {
		cout << "file not exit!" << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tests2 >> C[i][j];
		}
	}
	tests2.close();

	//floyd();
}

int main() {
	test_data();
	floyd();
	find_the_shortest();

	cout << "最小路径：" << minidist<<endl;
	cout << "the shortest path is:";
	int length = shortest_path.size();
	for (int i = 0; i < length; i++) {
		cout << shortest_path[i]+1 << "  ";
	}

	_getch();
	return 0;
}
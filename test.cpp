
/*
	a* test project
	
	
 author:
	von
	backer500@163.com
	
 build:
	build on windows vs12
	nmake -f makefile.vc
	
	build on linux gcc 5.2.1
	make
	
	
 notice:
	test data from boost::graph prgen_20_70_2.net
*/

#include <stdio.h>

#include <iostream>

#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

#include "astar.hpp"

struct graph
{
	vector<pair<int, int>> get_edges(int v) const
	{
		vector<pair<int, int>> edges;

		auto iter = data.find(v);
		if (iter != data.end())
		{
			for (auto e : iter->second)
			{
				edges.push_back(make_pair(v, e.first));
			}
		}
		return edges;
	}

	float distance(int a, int b) const
	{
		auto iter = data.find(a);
		if (iter != data.end())
		{
			auto piter = iter->second.find(b);
			if (piter != iter->second.end())
			{
				return piter->second;
			}
		}

		return 0.0f;
	}

	float heuristic(int a, int b) const
	{
		return 0.0f;
	}

	map<int, map<int, float>> data;
};

int main(int argv, char** argc)
{
	void fill_data(graph&);
	
	unordered_map<int, int> p;
	unordered_map<int, float> d;

	graph g;
	fill_data(g);

	int start = 1, goal = 15;

	if (astar<graph, int, float>(g, p, d, start, goal))
	{
		cout << goal;
		//
		auto iter = p.find(goal);
		while (iter != p.end())
		{
			cout << " <- " << iter->second;
			
			if (start == iter->second)
			{
				break;
			}

			iter = p.find(iter->second);
		}
	}
	else
	{
		cout << "can't find!";
	}
	cout << endl;
}

void make_graph(graph& g, int a, int b, float d)
{
	auto iter = g.data.find(a);
	if (iter == g.data.end())
	{
		g.data[a] = map<int, float>();
		iter = g.data.find(a);
	}
	if (iter != g.data.end())
	{
		iter->second[b] = d;
	}
}

void fill_data(graph& g)
{
	make_graph(g, 1, 2, 180);
	make_graph(g, 1, 6, 880);
	make_graph(g, 1, 7, 1640);
	make_graph(g, 1, 9, 1620);
	make_graph(g, 1, 10, 80);
	make_graph(g, 1, 11, 98);
	make_graph(g, 1, 12, 31);
	make_graph(g, 1, 13, 60);
	make_graph(g, 1, 16, 91);
	make_graph(g, 1, 17, 9);
	make_graph(g, 1, 18, 48);
	make_graph(g, 1, 19, 91);
	make_graph(g, 1, 20, 41);
	make_graph(g, 2, 3, 1300);
	make_graph(g, 2, 4, 620);
	make_graph(g, 2, 5, 1540);
	make_graph(g, 2, 8, 1000);
	make_graph(g, 2, 9, 1100);
	make_graph(g, 2, 10, 620);
	make_graph(g, 2, 11, 68);
	make_graph(g, 2, 15, 64);
	make_graph(g, 2, 16, 55);
	make_graph(g, 2, 17, 31);
	make_graph(g, 2, 19, 29);
	make_graph(g, 2, 20, 98);
	make_graph(g, 3, 4, 1540);
	make_graph(g, 3, 6, 1100);
	make_graph(g, 3, 8, 1340);
	make_graph(g, 3, 9, 1840);
	make_graph(g, 3, 10, 840);
	make_graph(g, 3, 14, 48);
	make_graph(g, 3, 15, 88);
	make_graph(g, 3, 17, 81);
	make_graph(g, 3, 18, 42);
	make_graph(g, 3, 19, 98);
	make_graph(g, 3, 20, 70);
	make_graph(g, 4, 5, 200);
	make_graph(g, 4, 6, 560);
	make_graph(g, 4, 7, 1800);
	make_graph(g, 4, 9, 1220);
	make_graph(g, 4, 10, 1640);
	make_graph(g, 4, 11, 62);
	make_graph(g, 4, 12, 75);
	make_graph(g, 4, 14, 31);
	make_graph(g, 4, 16, 44);
	make_graph(g, 4, 17, 54);
	make_graph(g, 4, 19, 39);
	make_graph(g, 5, 6, 1460);
	make_graph(g, 5, 8, 1020);
	make_graph(g, 5, 10, 1340);
	make_graph(g, 5, 11, 12);
	make_graph(g, 5, 12, 21);
	make_graph(g, 5, 13, 72);
	make_graph(g, 5, 14, 68);
	make_graph(g, 5, 15, 2);
	make_graph(g, 5, 16, 12);
	make_graph(g, 5, 17, 28);
	make_graph(g, 5, 18, 87);
	make_graph(g, 6, 7, 640);
	make_graph(g, 6, 8, 380);
	make_graph(g, 6, 9, 940);
	make_graph(g, 6, 10, 1140);
	make_graph(g, 6, 12, 21);
	make_graph(g, 6, 13, 17);
	make_graph(g, 6, 15, 54);
	make_graph(g, 6, 17, 92);
	make_graph(g, 6, 18, 5);
	make_graph(g, 6, 19, 34);
	make_graph(g, 6, 20, 47);
	make_graph(g, 7, 8, 1980);
	make_graph(g, 7, 9, 1340);
	make_graph(g, 7, 10, 820);
	make_graph(g, 7, 12, 68);
	make_graph(g, 7, 13, 54);
	make_graph(g, 7, 14, 4);
	make_graph(g, 7, 15, 32);
	make_graph(g, 7, 17, 54);
	make_graph(g, 7, 20, 18);
	make_graph(g, 8, 9, 500);
	make_graph(g, 8, 11, 55);
	make_graph(g, 8, 12, 100);
	make_graph(g, 8, 13, 35);
	make_graph(g, 8, 14, 65);
	make_graph(g, 8, 15, 78);
	make_graph(g, 8, 17, 48);
	make_graph(g, 8, 18, 11);
	make_graph(g, 8, 19, 14);
	make_graph(g, 8, 20, 2);
	make_graph(g, 9, 10, 180);
	make_graph(g, 9, 13, 92);
	make_graph(g, 9, 14, 39);
	make_graph(g, 9, 15, 17);
	make_graph(g, 9, 16, 2);
	make_graph(g, 9, 17, 57);
	make_graph(g, 9, 19, 72);
	make_graph(g, 10, 11, 8);
	make_graph(g, 10, 12, 65);
	make_graph(g, 10, 14, 97);
	make_graph(g, 10, 15, 1);
	make_graph(g, 10, 16, 78);
	make_graph(g, 10, 17, 94);
	make_graph(g, 10, 19, 28);
	make_graph(g, 10, 20, 1);
	make_graph(g, 11, 12, 1520);
	make_graph(g, 11, 13, 1300);
	make_graph(g, 11, 15, 940);
	make_graph(g, 11, 16, 1400);
	make_graph(g, 11, 17, 1600);
	make_graph(g, 11, 18, 100);
	make_graph(g, 11, 20, 100);
	make_graph(g, 12, 13, 1320);
	make_graph(g, 12, 15, 780);
	make_graph(g, 12, 17, 160);
	make_graph(g, 12, 18, 1680);
	make_graph(g, 12, 19, 560);
	make_graph(g, 12, 20, 540);
	make_graph(g, 13, 14, 1220);
	make_graph(g, 13, 18, 580);
	make_graph(g, 13, 19, 180);
	make_graph(g, 14, 15, 1580);
	make_graph(g, 14, 16, 1220);
	make_graph(g, 14, 17, 940);
	make_graph(g, 14, 18, 840);
	make_graph(g, 15, 16, 920);
	make_graph(g, 15, 17, 300);
	make_graph(g, 15, 19, 1820);
	make_graph(g, 16, 17, 1020);
	make_graph(g, 16, 19, 1200);
	make_graph(g, 16, 20, 280);
	make_graph(g, 17, 18, 520);
	make_graph(g, 17, 19, 20);
	make_graph(g, 17, 20, 540);
	make_graph(g, 18, 19, 1980);
	make_graph(g, 18, 20, 1420);
	make_graph(g, 19, 20, 300);
	
}

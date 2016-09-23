
/*
 
	a* algorithm
	Copyright (C)2016 by von

	mail:
	backer500@163.com
	
	time:
	2016/9/23
 
*/

#include <list>
#include <unordered_map>

struct less_pair_first
{
	template<typename Elem>
	bool operator()(const Elem & a, const Elem & b)
	{
		return a.first < b.first;
	}
};

template<typename Graph, typename ElemKey, typename CostType>
bool astar(Graph & g, std::unordered_map<ElemKey, ElemKey> & predecessor, 
	std::unordered_map<ElemKey, CostType> & distance,
	const ElemKey & start, const ElemKey & goal)
{
	std::list<pair<CostType, ElemKey>> open_list;
	open_list.push_back(make_pair(CostType(), start));

	// 
	distance[start] = CostType();
	predecessor[start] = ElemKey();

	while (!open_list.empty())
	{
		auto v = open_list.front();
		open_list.pop_front();

		CostType current_distance = distance[v.second];

		auto edges = g.get_edges(v.second);
		for (auto edge : edges)
		{
			if (predecessor.end() == predecessor.find(edge.second))
			{
				CostType dis = g.distance(edge.first, edge.second) + current_distance;

				auto edge_weight = g.get_edges(edge.second);
				for (auto ew : edge_weight)
				{
					auto iter = distance.find(ew.second);
					if (iter != distance.end())
					{
						float d = g.distance(iter->first, iter->second);
						if (dis > d + iter->second)
						{
							dis = d + iter->second;
						}
					}
				}

				distance[edge.second] = dis;

				dis += g.heuristic(edge.second, goal);
				open_list.push_front(make_pair(dis, edge.second));

				predecessor[edge.second] = v.second;

				if (goal == edge.second)
				{
					return true;
				}
			}
		}
		open_list.sort(less_pair_first());
	}

	return false;
}

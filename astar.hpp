
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
bool astar(const Graph & g, std::unordered_map<ElemKey, ElemKey> & predecessor, 
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

		ElemKey current = v.second;
		CostType current_distance = distance[current];

		auto edges = g.get_edges(current);
		for (auto edge : edges)
		{
			ElemKey source = edge.first;
			ElemKey target = edge.second;

			CostType target_distance = g.distance(source, target);
			target_distance += current_distance;

			if (distance.end() != distance.find(target) &&
				target_distance > distance[target])
			{
				continue;
			}

			auto weight = g.get_edges(target);
			for (auto w : weight)
			{
				auto iter = distance.find(w.second);
				if (iter != distance.end())
				{
					CostType d = g.distance(target, w.second);
					if (target_distance > d + iter->second)
					{
						target_distance = d + iter->second;
					}
				}
			}

			distance[target] = target_distance;
			predecessor[target] = current;

			target_distance += g.heuristic(target, goal);
			open_list.push_front(make_pair(target_distance, target));

			if (goal == target)
			{
				return true;
			}
		}
		open_list.sort(less_pair_first());
	}

	return false;
}

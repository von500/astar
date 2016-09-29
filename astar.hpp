
/*
 
	a* algorithm
	Copyright (C)2016 by von

	mail:
	backer500@163.com
	
	time:
	2016/9/23
 
*/

#include <map>
#include <unordered_map>
#include <unordered_set>

template<typename Graph, typename ElemKey, typename CostType>
bool astar(const Graph & g, std::unordered_map<ElemKey, ElemKey> & predecessor, 
	std::unordered_map<ElemKey, CostType> & distance,
	const ElemKey & start, const ElemKey & goal)
{
	std::unordered_set<ElemKey> open_set;
	std::unordered_set<ElemKey> close_set;
	std::multimap<CostType, ElemKey> open_map;

	open_map.insert(make_pair(CostType(), start));

	// 
	distance[start] = CostType();
	predecessor[start] = ElemKey();

	while (!open_map.empty())
	{
		auto v = open_map.begin();

		ElemKey current = v->second;
		CostType current_distance = distance[current];

		open_map.erase(v);

		auto edges = g.get_edges(current);
		for (auto edge : edges)
		{
			ElemKey source = edge.first;
			ElemKey target = edge.second;

			if (close_set.end() != close_set.find(target))
			{
				continue;
			}

			CostType target_distance = g.distance(source, target);
			target_distance += current_distance;

			if (distance.end() != distance.find(target) &&
				target_distance > distance[target])
			{
				continue;
			}

			close_set.insert(source);

			distance[target] = target_distance;
			predecessor[target] = current;

			if (open_set.end() == open_set.find(target))
			{
				target_distance += g.heuristic(target, goal);
				open_map.insert(make_pair(target_distance, target));
				open_set.insert(target);
			}

			if (goal == target)
			{
				return true;
			}
		}
	}

	return false;
}

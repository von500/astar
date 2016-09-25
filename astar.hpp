
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
#include <unordered_set>

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
	std::unordered_set<ElemKey> open_set;
	std::unordered_set<ElemKey> close_set;
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
				open_list.push_front(make_pair(target_distance, target));
				open_set.insert(target);
			}

			if (goal == target)
			{
				return true;
			}
		}
		open_list.sort(less_pair_first());
	}

	return false;
}

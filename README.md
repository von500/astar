# astar algorithm in c++ (A*)

To Use:
---------
first write a struct or class like:

    struct graph
    {
        vector<pair<int, int>> get_edges(int v);
        float distance(int a, int b);
        float heuristic(int a, int b);
    };

a map to receive path, distance

    unordered_map<int, int> p;
    unordered_map<int, float> d;


pass graph, p, d, start, goal to astar algorithm
the result will write to p.

----------

Build test.cpp:
------

build on windows vs12

    nmake -f makefile.vc
	
build on linux gcc 5.2.1

    make

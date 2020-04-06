#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <list>
#include <vector>
using list = std::list<int>;
using ptr = std::unique_ptr<list>;
class Graph
{
public:
    Graph(int v);
    void add_edge(size_t v, size_t w);
    void BFS(int s); //breadth first search
    void DFS(int v); // depth first search traversal of the vertices reachable from v
private:
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);
private:
    int v_{};
    std::vector<ptr> list_ {};
};

#endif // GRAPH_H

#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <list>
#include <vector>
#include <set>
using list = std::list<int>;
using ptr = std::unique_ptr<list>;
using pair = std::pair<int, std::pair<int,int>>;
using pair_ptr = std::unique_ptr<pair>;

class Graph
{
public:
    Graph(int v, int n);
    void add_edge(size_t v, size_t w);
    void add_edge(size_t v, size_t n, size_t w);
    void BFS(int s); //breadth first search
    void DFS(int v); // depth first search traversal of the vertices reachable from v
//    inline size_t get_graph_size() {return edges_.size();}
//    class Kruskal
//    {
//        Kruskal(size_t size);
        void join(int u, int v);
        int find(int u);
        void initialize();
        void kruskal();
//    };
private:
    // A recursive function used by DFS
    void DFSUtil(int v, bool visited[]);


private:
    int v_{};
    int n_{};
    std::vector<ptr> list_ {};
    std::vector<pair_ptr> edges_ {};

    std::vector<int> set_{};
    std::vector<int> included_ {};
};

#endif // GRAPH_H

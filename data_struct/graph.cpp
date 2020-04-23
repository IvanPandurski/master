#include "graph.h"
#include<iostream>
#include <iterator>
#include <algorithm>
Graph::Graph(int v, int n)
{
    this->v_ = v;
    this->n_ = n;
    for(int i = 0; i < v; i++)
    {
        list_.emplace_back(std::make_unique<list>());
    }

}

void Graph::add_edge(size_t v, size_t w)
{
    list_.at(v)->push_back(w);
}

void Graph::add_edge(size_t v, size_t n, size_t w)
{
    edges_.emplace_back(std::make_unique<pair>(std::make_pair(w, std::make_pair(v,n))));
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[v_];
    for(int i = 0; i < v_; i++)
    {
        visited[i] = false;
    }

    // Create a queue for BFS
    list queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list::iterator i;

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        std::cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = list_.at(s)->begin(); i != list_.at(s)->end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[v_];
    for (int i = 0; i < v_; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

void Graph::join(int u, int v)
{
    set_.at(u) = set_.at(v);
}

int Graph::find(int u)
{
    int x = u;

    while(set_.at(x) != x)  //if x is not itself parent then update its parent
    {
        set_.at(x) = set_.at(set_.at(x));
        x = set_.at(x);
    }
    return x;
}

void Graph::initialize()
{
    set_.reserve(edges_.size());
    included_.reserve(edges_.size());
    for(size_t i = 0; i < edges_.size(); ++i)
    {
        set_.push_back(i);
        included_.push_back(-1);
    }
    set_.pop_back();
}

void Graph::kruskal()
{
   std::cout<< "\n";
   int min_cost {0};
   std::stable_sort(edges_.begin(), edges_.end(), [](auto& i, auto& j){return i->first < j->first;});
   for(auto it = edges_.begin(); it != edges_.end(); ++it)
   {
       int u = it->get()->second.first;
       int v = it->get()->second.second;
       int cost = it->get()->first;
       if(find(u) != find(v))
       {
           min_cost += cost;
           std::cout<<u<<" ----> "<<v<<" :"<<it->get()->first<<"\n";
           join(find(u), find(v));
       }
   }

   std::cout<< "cost of spanning tree is: "<< min_cost << "\n";
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    std::cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list::iterator i;
    for (i = list_.at(v)->begin(); i != list_.at(v)->end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}


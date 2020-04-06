#include "graph.h"
#include<iostream>

Graph::Graph(int v)
{
    this->v_ = v;
    for(int i = 0; i < v; i++)
    {
        list_.emplace_back(std::make_unique<list>());
    }
}

void Graph::add_edge(size_t v, size_t w)
{
    list_.at(v)->push_back(w);
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

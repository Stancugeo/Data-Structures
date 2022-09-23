#ifndef GRAPH_HPP
#define GRAPH_HPP
class Graph{
    public:
    int NumOfVertices;
    map<int,unordered_set<int>> Adjacency_List;
    bool directed;
    Graph(map<int,unordered_set<int>>& list, bool directed = false);
    Graph(vector<pair<int,int>>Edges, bool directed = false);
    void Print();
    void InsertEdge(pair<int,int>Edge);
    void DeleteEdge(pair<int,int>Edge);
    void InsertVertex(int Vertex);
    void DeleteVertex(int Vertex);
    void BFS(int Vertex);
    void DFS(int Vertex);
    void DFS_func(int Vertex,map<int,bool>& Visited);
    void Do_something(int vertex);

};

#endif

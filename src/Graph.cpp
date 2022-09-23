#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include "Graph.hpp"

using namespace std;

Graph :: Graph(map<int,unordered_set<int>>& list, bool directed = false){
    this->NumOfVertices = list.size();
    this->Adjacency_List = list;
    this->directed = directed;
}
Graph :: Graph(vector<pair<int,int>>Edges, bool directed = false){
    this->directed = directed;
    for(int i = 0 ; i < Edges.size(); i++){
        this->Adjacency_List[Edges[i].first].insert(Edges[i].second);
        if(!this->directed){
            this->Adjacency_List[Edges[i].second].insert(Edges[i].first);
        }
    }
    this->NumOfVertices = this->Adjacency_List.size();
}
void Graph ::  Print(){
    for(auto each_list : Adjacency_List){
        //cout << Vertices[cnt] << ":";
        cout << each_list.first << ":";
        for(auto it = each_list.second.begin(); it!=each_list.second.end(); it++){
            //cout << Vertices[*it] << " ";
            cout << *it << " ";
        }
        cout<<endl;
    }
}
void Graph ::  InsertEdge(pair<int,int>Edge){
    if(this->Adjacency_List.find(Edge.first)!= this->Adjacency_List.end() &&
    this->Adjacency_List.find(Edge.second) != this->Adjacency_List.end()){
        this->Adjacency_List[Edge.first].insert(Edge.second);
        if(!this->directed){
            this->Adjacency_List[Edge.second].insert(Edge.first);
        }
    }
}
void Graph :: DeleteEdge(pair<int,int>Edge){
    if(this->Adjacency_List.find(Edge.first)!= this->Adjacency_List.end() &&
    this->Adjacency_List.find(Edge.second) != this->Adjacency_List.end()){
        this->Adjacency_List[Edge.first].erase(Edge.second);
        if(!this->directed){
            this->Adjacency_List[Edge.second].erase(Edge.first);
        }
    }
}
void Graph :: InsertVertex(int Vertex){
    if(this->Adjacency_List.find(Vertex)==this->Adjacency_List.end()){
        this->Adjacency_List[Vertex] = unordered_set<int>();
        this->NumOfVertices++;
    }
}
void Graph :: DeleteVertex(int Vertex){
    if(this->Adjacency_List.find(Vertex)!=this->Adjacency_List.end()){
        for(auto it = this->Adjacency_List[Vertex].begin(); it!= this->Adjacency_List[Vertex].end(); it++){
            this->Adjacency_List[*it].erase(Vertex);
        }
        this->Adjacency_List.erase(Vertex);
        this->NumOfVertices--;
    }
}
void Graph :: BFS(int Vertex){
    map<int,bool>Visited;
    queue<int>Q;
    Q.push(Vertex);
    Visited[Vertex] = true;
    while(!Q.empty()){
        int st = Q.front();
        Do_something(st);
        for(auto value : this->Adjacency_List[st]){
            if(!Visited[value]){
                Q.push(value);
                Visited[value] = true;
            }
        }
        Q.pop();
    }
}
void Graph :: DFS(int Vertex){
    map<int,bool>Visited;
    DFS_func(Vertex,Visited);
}
void Graph :: DFS_func(int Vertex,map<int,bool>& Visited){
    cout << Vertex << " ";
    Visited[Vertex] = true;
    for(auto value : Adjacency_List[Vertex]){
        if(!Visited[value]){
            DFS_func(value,Visited);
        }
    }
}
void Graph :: Do_something(int vertex){
    cout  << vertex << " ";
}

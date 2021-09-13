#include <iostream>
#include <list>

using namespace std;

class Graph {
    int V; // number of verticies
    list<int> *adj; //pointer to an array containing adjacent lists
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    //marks all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    //Create a queue for BFS
    list<int> q;

    //Marking the first node that was given as visited and adding it to the queue
    visited[s] = true;
    q.push_back(s);

    list<int>::iterator i;

    while(!q.empty()){
        //Dequeue the vertex from the queue and print it out
        s = q.front();
        cout << s << " ";
        q.pop_front();

        //uses the iterator to go for all of the adjacent verticies of the dequeued vertex
        for(i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
}

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "BFS: ";
    g.BFS(2);

    return 0;
}
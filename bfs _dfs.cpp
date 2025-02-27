#include<iostream>
#include<list>
using namespace std;
class graph{
    int vertices;
    list<int> *adjacancylist;

    public:
    graph(int V){
        vertices=V;
        adjacancylist=new list<int>[v];
    }
    void addedge(int V,int w){
        adjacancylist[V].push_back(w);
    }
    void BFS(int startvertex){
        bool *visited=new bool[vertices];
        for(int i=0;i<vertices;i+++){
            visited[i]=false;
            list<int>queue;
            visited[startvertex]=true;
            queue.pushback(startvertex);

            while(!queue=empty()){
                startvertex=queue.front();
                cout<<startVertex<<" ";
                queue.pop_front()
            }
        }
    }

}

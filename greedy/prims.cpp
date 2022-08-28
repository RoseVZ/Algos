#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
const int V = 5;
int selectMin(int value[],int visited[])
{
    int min = INT_MAX;
    int minVertex;
    for (int i = 0; i < V; i++)
    {
        if(visited[i]==0&&value[i]<min)
        {
            min = value[i];
            minVertex = i;
        }
    }
    return minVertex;
}
void prims(int graph[V][V])
{
    int value[V];
    int visited[V];
    for (int i = 0; i < V;i++)
    {
        value[i] = INT_MAX;
        visited[i] = 0;
    }

    int parent[V];

    parent[0] = -1;
    value[0] = 0;

    for (int i = 0; i < V - 1;i++)
    {
        int u = selectMin(value, visited);
        visited[u] = 1;
        for (int j = 0; j < V;j++)
        {
            if(graph[u][j]!=0&&visited[j]==0&&graph[u][j]<value[j])
            {
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    for(int i = 1; i < V;i++)
    {
        cout<< "Vertex " << parent[i] << "->" << i << ":" << value[i] << endl;
    }
}

int main(void){
    
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    prims(graph);
}
#include<iostream>
using namespace std;

class bfs{
    int a[10][10], s[10], n, source;
    public:
    void read();
    void print();
    void bfs1();
};

void bfs:: read()
{
    cout << "Enter the no of nodes";
    cin >> n;
    cout << "Enter the source node";
    cin >> source;
    cout << "Enter the adh=jacency matrix";
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            cin >> a[i][j];
}

void bfs:: bfs1(){
    int f = 0,r = 0,u,v;
    int q[10];
    for (int i = 0; i < n;i++)
        s[i] = 0;
    q[r] = source;
    s[source] = 1;
    while(f<=r){
        u = q[f++];
        for (int v = 0; v < n;v++)
        {
            if(a[u][v]!=0&&s[v]==0)
            {
                q[++r] = v;
                s[v] = 1;
            }

        }

    }
}

void bfs::print()
{
    for (int i = 0; i < n;i++)
    {
        if(s[i]==0)
            cout << "Vertex=" << i << "Not reachable";
        else
            cout << "vertex" << i
                 << "Reachable";

    }
}
int main()
{
    bfs b;
    b.read();
    b.bfs1();
    b.print();
}
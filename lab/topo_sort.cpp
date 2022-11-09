#include<iostream>
using namespace std;
class topo{
    int a[10][10], in[10], n;
    public:
        void read();
        void find();
        void sort();
};

void topo::read()
{
    cout << "No of nodes";
    cin >> n;
    for (int i = 0; i < n;i++)
        for (int j = 0; j < n;j++)
            cin >> a[i][j];

}

void topo::find(){
 
    for (int i = 0; i < n;i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += a[i][j];
        
    }
}
#include<iostream>
using namespace std;
#define MAX 100
class quick{
    int high, low;
    public:
        void q_sort(int *, int, int);
        int partition(int *, int, int);
};

void quick:: q_sort(int a[],int low,int high){
    if(low<high){
        int p = partition(a, low, high);
        q_sort(a, low,p-1);
        q_sort(a, p+1,high);
    }
}

int quick::partition(int a[],int low,int high)
{
    int i = low + 1, j = high;
    int key = a[low];
    int temp;
    while (1)
    {
        while(i<high&&a[i]<=key)
            i++;
            while(j>=low&&a[j]>key)
                j--;
        if(i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else{
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}

int main()
{
int *a,n,i;
// clock_t start,stop;
quick q;
cout<<"Enter the number of elements"<<endl;
cin>>n;
a=new int[n];
cout<<"Enter the elements"<<endl;
for(i=0;i<n;i++)
cin>>a[i];
// start=clock();
q.q_sort(a,0,n-1);
// stop=clock();
cout<<"Sorted elements are"<<endl;
for(i=0;i<n;i++)
cout<<a[i]<<endl;
// cout<<"Time taken= "<<(stop-start)/CLK_TCK<<"seconds"<<endl;
// cout<<"Space consumed= "<<sizeof(n)+n*sizeof(a)+sizeof(i)+sizeof(q)<<"bytes"<<endl; return 0;
}

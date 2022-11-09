#include<iostream>
#include<time.h>
#define MAX 100
using namespace std;
class merge1
{
    int low ,high;
    public:
        void msort(int *, int,int);
        void s_merge(int *, int, int,int);
};

void merge1::msort(int A[],int low,int high)
{
    if(low<high){
    int mid = (low + high) / 2;
    msort(A, low, mid);
    msort(A, mid + 1, high);
    s_merge(A, low, mid, high);
    }
}

void merge1::s_merge(int A[],int low,int mid,int high){
    int i = low, j = mid+1, k = low;
    int c[MAX];
    while(i<=mid&&j<=high){
        if(A[i]<A[j]){
            c[k] = A[i];
            k++;
            i++;
        }
        else{
            c[k] = A[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        c[k++] = A[i++];
    }
    while(j<=high)
        c[k++] = A[j++];
    for (int i = 0; i <= high;i++){
        A[i] = c[i];
    }
}

int main()
{
    int n,*A;
    clock_t start, stop;
    merge1 m;
    cout << "Enter the number of elements";
    cin >> n;
    A = new int[n];
    cout << "Enter the elements";
    for (int i = 0; i < n;i++)
        cin >> A[i];
    start = clock();
    m.msort(A, 0, n - 1);
    stop = clock();



}
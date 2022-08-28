
#include<iostream>
#include<stdbool.h>
#include <algorithm>

using namespace std;

struct Item
{
    int value;
    int weight;
};

    bool cmp(struct Item a, struct Item b)
    {
        double w1=(a.value*1.0)/(a.weight*1.0);
        double w2=(b.value*1.0)/(b.weight*1.0);
        return w1>w2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,cmp);
        double current_weight=0.0;
        double profit=0.0;
        
        for(int i=0;i<n;i++)
        {
            if(current_weight+arr[i].weight<=W)
            {
                profit+=arr[i].value;
                current_weight+=arr[i].weight;
            }
            else{
                int diff=(W-current_weight);
                profit+=diff*(arr[i].value*1.0/arr[i].weight*1.0);
                
                break;
            }
        }
        return profit;
    }
    int main(void){
        Item a[10];
        int W,n;
        cin >> n;
        cin >> W;
        for (int i = 0; i < n;i++)
            cin >> a[i].value >> a[i].weight;
        cout<<fractionalKnapsack(W, a, n);
    }
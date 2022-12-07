#include<vector>
#include<bits/stdc++.h>
bool finishComparator(vector<pair<int,int>>f1,vector<pair<int,int>>f2)
{
    return f1.second>f2.second;
}

vector<int> activity(vector<int>s,vector<int>f)
{
    vector<pair<int,int>> x,ans;
    for(int i=0;i<s.size();i++)
        x.push_back(make_pair(s[i],f[i]));      // make the start and end times into a vector pair for sorting simulaneously
    int n=s.size();
    sort(x,x+n,finshComparator);        //custom comparator to compare the finish times
    int k=0;
    int start=x[k].first;           
    int end=x[k].second;
    ans.push_back(make_pair(start,end));        // the first activity selected will be the first int he sorted list
    
    for(int i=1;i<x.size();i++)
    {
        if(x[i].start>=end)                     //if the start of the next activity is after the end off the previous then w can complete it
        {
            start=x[i].start;
            end=x[i].end;
            ans.push_back(make_pair(start,end));    // the answer vector which contains both the start and end time of selected vectors.
        }
    }
    return ans;


}
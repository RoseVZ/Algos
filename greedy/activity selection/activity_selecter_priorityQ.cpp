
/*
Input in the form of 2 vectors containg starts and finsh times
*/
vector<pair<int,int>> actvity(vector<int> s, vector<int> f)
{
    vector<pair<int,int>> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>) p; //Creation of a priorty queue(Min heap) of pairs 

    //insertion into hte priority queue
    for(int i=0;i<s.size();i++)
    {
        p.push(make_pair(f[i],s[i]));//finish is added first as the sorting must be on basis of finish times

    }
    auto it=p.top();
    p.pop();
    int start =it.second; //as the start time is the second field
    int end=it.first;
    ans.push_back(make_pair(start, end));// the first activity is too be selected

    //loop through the priority queue
    while(!p.empty())
    {
        auto it=p.top();
        p.pop();
        if(it.second>=end)
        {
            start=it.second;
            end=it.first;
            ans.push_back(make_pair(start,end));
        }
    }
    return ans;
}
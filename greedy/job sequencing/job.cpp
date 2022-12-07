/*
    INPUT IN FORM OF an array of structure having 3 fields jobname, DEADLINES AND PROFITS
*/
int compare(const int*a,const int* b)
{
    //typecast to job type
    Job* temp1=(Job*)a;
    Job* temp2=(Job*)b;
    //temp2 - temp1 because descending
    return temp2->profit-temp1->profit;
}
int min(int a,int b)
{
    return a<b?a:b;
}
vector<int> Jobsceduling(Job arr[],int n)
{
    vector<int> ans;
    //qsort takees the following parameters the firstindex, no of elements,size of each element and comaprator 
    qsort(arr,n,sizeof(Job),compare);
    bool slot[n]; //keep track of the time slots
    for(int i=0;i<n;i++)
        slot[i]=false;

    //iterate through all the jobs
    for(int i=0;i<n;i++)
    {
        for(int j=min(n,arr[i])-1;j>=0;j--)
        {
            if(slot[j]==false)
                {
                    ans.push_back(arr[i].id);
                    slot[j]=true;
                    break;
                }
        }
    }

}
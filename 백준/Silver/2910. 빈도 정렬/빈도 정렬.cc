#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N,C;
map<int,int> mpCnt; // num/cnt
map<int,int> mpIdx; // num/Idx
vector<pair<int,int>> ret;  // num/cnt

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second==b.second)
        return mpIdx[a.first]<mpIdx[b.first];
    else
        return a.second>b.second;
}

int main()
{
    cin>>N>>C;
    
    for(int i=0; i<N; ++i)
    {
        int temp;
        cin>>temp;
        mpCnt[temp]++;
        
        if(mpIdx.find(temp) == mpIdx.end())
            mpIdx[temp] = i;
    }
    
    for(auto it:mpCnt)
    {
        ret.push_back({it.first, it.second});
    }
    
    sort(ret.begin(), ret.end(), cmp);
    
    for(auto it: ret)
    {
        while(it.second--)
            cout<<it.first<<' ';
    }
    
    return 0;
}
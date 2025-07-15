#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> clothes(n+1,0);
    
    for(int lostNum:lost)
    {
        clothes[lostNum]--;
    }
    for(int reserveNum: reserve)
    {
        clothes[reserveNum]++;
    }
    
    for(int i=0; i<clothes.size()-1; i++)
    {
        if(clothes[i]+clothes[i+1]==0)
        {
            clothes[i]=0;
            clothes[i+1]=0;
        }
    }
    
    for(int clothesCount: clothes)
    {
        if(clothesCount==-1)
            answer--;
    }
    
    return answer;
}
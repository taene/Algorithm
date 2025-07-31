#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    pair<int,int> mn = {51,51};
    pair<int,int> mx = {0,0};
    
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j=0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j]=='#')
            {
                if(mn.first > i)
                    mn.first = i;
                
                if(mn.second > j)
                    mn.second = j;
                
                if(mx.first < i)
                    mx.first = i;
                
                if(mx.second < j)
                    mx.second = j;
            }
        }
    }
    
    answer.push_back(mn.first);
    answer.push_back(mn.second);
    answer.push_back(mx.first+1);
    answer.push_back(mx.second+1);
    
    
    return answer;
}
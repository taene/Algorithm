#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    const int dx[]={-1,1,0,0};
    const int dy[]={0,0,-1,1};
    const char dir[]={'N','S','W','E'};
    
    int curX = 0;
    int curY = 0;
    int parkH = park.size();
    int parkW = park[0].size();
    
    for(int i=0; i<parkH; i++)
    {
        for(int j=0; j<parkW; j++)
        {
            if(park[i][j]=='S')
            {
                curX = i;
                curY = j;
                break;
            }
        }
    }
    
    for(const string& route: routes)
    {
        char op = route[0];
        int n = stoi(route.substr(2));
        
        int dirIndex = -1;
        for(int i=0; i<4; i++)
        {
            if(dir[i]==op)
            {
                dirIndex = i;
                break;
            }
        }
        
        int nextX = curX;
        int nextY = curY;
        bool bCanMove = true;
        
        for(int i=0; i<n; i++)
        {
            nextX += dx[dirIndex];
            nextY += dy[dirIndex];
            
            if(nextX<0||nextY<0||nextX>=parkH||nextY>=parkW)
            {
                bCanMove = false;
                break;
            }
            if(park[nextX][nextY]=='X')
            {
                bCanMove = false;
                break;
            }
        }
        
        if(bCanMove)
        {
            curX += dx[dirIndex]*n;
            curY += dy[dirIndex]*n;
        }
    }
    
    answer.push_back(curX);
    answer.push_back(curY);
    
    return answer;
}
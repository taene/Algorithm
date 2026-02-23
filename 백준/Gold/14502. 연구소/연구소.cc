#include <iostream>
#include <vector>
using namespace std;

int N,M,ret;
int arr[10][10];
vector<pair<int,int>> canSetWall;
vector<pair<int,int>> virusStart;
bool visited[10][10];
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

void dfs(int y, int x)
{
    visited[y][x] = true;
    
    for(int i=0; i<4; ++i)
    {
        int ny = y+dy[i];
        int nx = x+dx[i];
        
        if(ny<0||nx<0||ny>=N||nx>=M) continue;
        if(visited[ny][nx]) continue;
        if(arr[ny][nx]==1) continue;
        
        dfs(ny,nx);
    }
}

int main()
{
    cin>>N>>M;
    for(int i=0; i<N; ++i)
    {
        for(int j=0; j<M; ++j)
        {
            int temp;
            cin>>temp;
            arr[i][j] = temp;
            
            if(temp == 0)
            {
                canSetWall.push_back({i,j});
            }
            else if(temp == 2)
            {
                virusStart.push_back({i,j});
            }
        }
    }
    
    for(int i=0; i<canSetWall.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            for(int k=0; k<j; k++)
            {
                fill(&visited[0][0], &visited[0][0]+100, 0);
                
                for(int t=0; t<virusStart.size(); t++)
                {
                    arr[canSetWall[i].first][canSetWall[i].second]=1;
                    arr[canSetWall[j].first][canSetWall[j].second]=1;
                    arr[canSetWall[k].first][canSetWall[k].second]=1;
                
                    dfs(virusStart[t].first, virusStart[t].second);
                
                    arr[canSetWall[i].first][canSetWall[i].second]=0;
                    arr[canSetWall[j].first][canSetWall[j].second]=0;
                    arr[canSetWall[k].first][canSetWall[k].second]=0;
                }
                
                int cnt = -3;
                for(int y=0; y<N; y++)
                {
                    for(int x=0; x<M; x++)
                    {
                        if(arr[y][x]==0 && !visited[y][x])
                            cnt++;
                    }
                }
                
                ret = max(ret,cnt);
            }
        }
    }
    
    cout<<ret;
    
    return 0;
}
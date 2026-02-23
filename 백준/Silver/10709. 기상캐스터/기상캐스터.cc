#include <iostream>
using namespace std;

int H,W;
int arr[101][101];

int main()
{
    cin>>H>>W;
    fill(&arr[0][0],&arr[100][101],-1);
    for(int i=0; i<H; ++i)
    {
        int num=0;
        for(int j=0; j<W; ++j)
        {
            char c;
            cin>>c;
            
            if(c=='c')
            {
                num=0;
                arr[i][j]=num++;
            }
            else
            {
                if(num)
                    arr[i][j]=num++;
                else
                    arr[i][j]=-1;
            }
        }
    }
    
    for(int i=0; i<H; ++i)
    {
        for(int j=0; j<W; ++j)
        {
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}
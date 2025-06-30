#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool arr[100001];

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    for(int i=section.size()-1; i>=0; i--)
    {
        if(arr[section[i]]) continue;
        
        for(int j=section[i]; j>=max(1,section[i]-m+1); j--)
        {
            arr[j]=true;
        }
        answer++;
    }
    
    return answer;
}
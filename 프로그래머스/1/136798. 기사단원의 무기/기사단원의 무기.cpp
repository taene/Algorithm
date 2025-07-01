#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> attack(number+1,0);
    for(int i=1; i<=number; i++)
    {
        for(int j=i; j<=number; j+=i)
        {
            attack[j]++;
        }
    }
    
    for(int i=1; i<=number; i++)
    {
        if(attack[i]>limit)
            attack[i]=power;
        
        answer+=attack[i];
    }
    
    return answer;
}
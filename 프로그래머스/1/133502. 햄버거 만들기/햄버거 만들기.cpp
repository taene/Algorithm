#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient)
{
    int answer = 0;
    vector<int> stack; // 변수명을 더 명확하게 변경

    for (int igd : ingredient)
    {
        stack.push_back(igd);

        if (stack.size() >= 4)
        {
            if (stack[stack.size() - 4] == 1 &&
                stack[stack.size() - 3] == 2 &&
                stack[stack.size() - 2] == 3 &&
                stack[stack.size() - 1] == 1)
            {
                answer++;
                
                for(int i=0; i<4; i++)
                    stack.pop_back();
            }
        }
    }
    
    return answer;
}
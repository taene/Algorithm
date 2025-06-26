#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;

    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            for(int k=0; k<j; k++)
            {
                int ret = nums[i]+nums[j]+nums[k];
                int temp = 2;
                while(temp<=ret)
                {
                    if(ret%temp == 0) break;
                    else temp++;
                }
                if(temp == ret) answer++;
            }
        }
    }

    return answer;
}
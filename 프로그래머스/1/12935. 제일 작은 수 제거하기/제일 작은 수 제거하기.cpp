#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int minIndex = 0;
    
    if(arr.size()==1)
    {
        return {-1};
    }
    else
    {
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[minIndex] > arr[i])
            {
                minIndex = i;
            }
        }
        
        arr.erase(arr.begin()+minIndex);
    }
    
    return arr;
}
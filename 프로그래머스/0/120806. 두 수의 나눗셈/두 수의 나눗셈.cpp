#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    double k = (double)num1/(double)num2;
    answer = k*1000;
    return answer;
}
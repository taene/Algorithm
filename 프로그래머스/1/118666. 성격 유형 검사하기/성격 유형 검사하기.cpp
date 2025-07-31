#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{    
    string answer = "";

    map<char, int> scores;
    int score_table[8] = {0, 3, 2, 1, 0, 1, 2, 3};

    for (int i = 0; i < survey.size(); ++i) 
    {
        int choice = choices[i];
        
        if (choice == 4) 
        {
            continue;
        }
        
        int score = score_table[choice];

        if (choice < 4) 
        { 
            scores[survey[i][0]] += score;
        } 
        else 
        {
            scores[survey[i][1]] += score;
        }
    }
    
    answer += (scores['R'] >= scores['T']) ? 'R' : 'T';
    answer += (scores['C'] >= scores['F']) ? 'C' : 'F';
    answer += (scores['J'] >= scores['M']) ? 'J' : 'M';
    answer += (scores['A'] >= scores['N']) ? 'A' : 'N';

    return answer;
}
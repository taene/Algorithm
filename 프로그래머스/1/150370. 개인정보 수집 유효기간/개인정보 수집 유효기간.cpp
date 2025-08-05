#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dateToDays(const string& dateStr)
{
    size_t first_dot = dateStr.find('.');
    size_t second_dot = dateStr.find('.', first_dot + 1);
    size_t third_dot = dateStr.find(' ', second_dot + 1);

    string yearStr = dateStr.substr(0, first_dot);
    string monthStr = dateStr.substr(first_dot + 1, second_dot - (first_dot + 1));
    string dayStr = dateStr.substr(second_dot + 1, third_dot);

    int year = stoi(yearStr);
    int month = stoi(monthStr);
    int day = stoi(dayStr);
    
    return (year * 12 * 28) + ((month - 1) * 28) + day;
}

vector<int> solution(string today, vector<std::string> terms, vector<std::string> privacies) 
{
    vector<int> answer;
    unordered_map<string, int> termsMap;
    
    for (const string& term : terms)
    {
        size_t space_pos = term.find(' ');
        string termType = term.substr(0, space_pos);
        string durationStr = term.substr(space_pos + 1);
        
        termsMap[termType] = stoi(durationStr);
    }
    
    int todayInDays = dateToDays(today);
    
    for (int i = 0; i < privacies.size(); ++i)
    {
        const string& privacy = privacies[i];
        
        size_t space_pos = privacy.find(' ');
        string collectionDateStr = privacy.substr(0, space_pos);
        string termType = privacy.substr(space_pos + 1);
        
        int collectionDateInDays = dateToDays(collectionDateStr);
        int durationInMonths = termsMap[termType];
        
        if (todayInDays >= collectionDateInDays + (durationInMonths * 28))
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}

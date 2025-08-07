#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    unordered_map<string, int> playerPosition;
    for (int i = 0; i < players.size(); ++i)
    {
        playerPosition[players[i]] = i;
    }

    for (const string& cp : callings)
    {
        int curIndex = playerPosition[cp];
        string change = players[curIndex - 1];

        playerPosition[cp] = curIndex - 1;
        playerPosition[change] = curIndex;
        
        swap(players[curIndex], players[curIndex - 1]);
    }

    return players;
}
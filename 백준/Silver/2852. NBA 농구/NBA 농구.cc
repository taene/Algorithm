#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n, teamNum;
string goalTime;
stack<pair<int, int>> timer;
int teamWinTime[3];
pair<int, int> inputGoalTime;

int switchTimeStringToInt(string s)
{
	string a = s.substr(0, s.find(":"));
	string b = s.substr(s.find(":") + 1);

	int min = stoi(a);
	int sec = stoi(b);

	int timer = min * 60 + sec;

	return timer;
}

string switchTimeIntToString(int timer)
{
	string s;
	
	int min = timer / 60;
	int sec = timer % 60;

	if (min >= 0 && min < 10)
		s += "0" + to_string(min) + ":";
	else
		s += to_string(min) + ":";

	if (sec >= 0 && sec < 10)
		s += "0" + to_string(sec);
	else
		s += to_string(sec);

	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	while (n--)
	{
		cin >> teamNum;
		cin >> goalTime;

		int t = switchTimeStringToInt(goalTime);

		inputGoalTime = { teamNum,t };
		pair<int, int> winTeamTime;

		if (!timer.empty())
		{
			winTeamTime = timer.top();
			if (inputGoalTime.first != timer.top().first)
				timer.pop();
			else
				timer.push(inputGoalTime);
		}
		else
			timer.push(inputGoalTime);

		if (timer.empty())
		{
			teamWinTime[winTeamTime.first] += inputGoalTime.second - winTeamTime.second;
		}
	}

	if (!timer.empty())
	{
		while (timer.size() > 1)
		{
			timer.pop();
		}

		teamWinTime[timer.top().first] += 48 * 60 - timer.top().second;
	}

	string ret1 = switchTimeIntToString(teamWinTime[1]);
	string ret2 = switchTimeIntToString(teamWinTime[2]);
	cout << ret1 << '\n' << ret2;

	return 0;
}
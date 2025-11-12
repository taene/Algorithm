#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, M;	//N은 카드의 개수, M은 고른 카드의 합
	cin >> N >> M;

	int p;
	vector<int> card;	//카드에 쓰여있는 수들
	int sum;	//3개의 카드들의 합

	int max = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> p;
		card.push_back(p);
	}

	for (int i = 0; i < card.size(); i++)
	{
		for (int j = i + 1; j < card.size(); j++)
		{
			for (int k = j + 1; k < card.size(); k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum <= M && max < sum)
				{
					max = sum;

				}
			}
		}
	}
	cout << max;
}

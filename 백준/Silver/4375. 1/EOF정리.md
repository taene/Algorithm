### while(!cin.eof())와 while(cin>>n)의 차이
EOF bit는 마지막 값을 읽었을 때 (성공이기 때문에) 켜지지 않는다. 그 다음에 또 읽으려고 했을 때(실패했을 때) 켜진다.
Code 1: 5까지 쓴 뒤 cin.eof()가 아직 false이므로 while문에 한 번 더 들어가며, 이 때는 cin >> n;이 실패하므로 n에 5가 그대로 들어 있어 5가 2번 찍힌다.
Code 2: 5까지 쓴 뒤 6번째로 cin >> n;을 실행했을 때 EOF bit가 켜지면서 while의 조건을 false로 만들어주므로 while문에 또 들어가지 않는다.
```cpp
input: "1 2 3 4 5"

// Code 1
int n;
while (!cin.eof())
{
    cin >> n;
    cout << n << ' ';
}
output: 1 2 3 4 5 5

// Code 2
int n;
while (cin >> n)
{
    cout << n << ' ';
}
output: 1 2 3 4 5
```

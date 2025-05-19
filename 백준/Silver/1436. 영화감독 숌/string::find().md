### C++ STL string::find()
```cpp
size_t find(const string& str, size_T pos) const;
```
- str : 찾고자 하는 문자열
- pos : 검색을 시작할 위치
- 문자열을 찾았다면, 해당 문자열의 시작 위치를 리턴하고, 그렇지 않을 경우 npos 리턴

<br/>

### string::npos란?
- size_type으로 정의된 특수값
- string::npos란 -1 값을 가지는 상수로 find() 함수 수행 시에 **찾는 문자열이 없을 때 반환**됨

> find 함수가 해당 문자열의 시작 위치를 반환해주므로, 문자열을 찾았다면 그 위치에서 문자열의 크기만큼 더해준 위치에서부터 다시 해당 문자열을 탐색해나가는 식으로도 사용 가능함

<br/>

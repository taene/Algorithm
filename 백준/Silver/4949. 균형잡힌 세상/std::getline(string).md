### std::getline(string)
```cpp
istream& getline(istream& is, string& str, char delim); 
```
- **is**: 문자들이 추출되어질 istream(입력 스트림)오브젝트(**키보드 입력을 받을거면 cin 쓰면 됨**)
- **str**: 입력받은 문자열들이 저장될 string 오브젝트
- **delim**: 제한자로, 지정한 문자가 나타나면 입력을 멈춤(대신 제한자는 저장x)
  - 지정안하면 개행문자('\n')로 설정됨
  - ⚠️ 주의: getline(cin, str, '.');를 선언하고 ".(enter)"하면 개행문자('\n')를 str에 저장하게됨!!
    - 해결법: 버퍼에 남은 '\n'를 없애기 위해 cin.ignore()로 버퍼에 남은 문자를 모두 삭제함(cin.ignore(3) = 버퍼에 개행 포함 3글자가 삭제돼야 해당 코드 뒤로 넘어가짐)
    - 만약 getline이 호출되기 전 받는입력이 있다면, 버퍼에 개행문자가 남아있어 '\n'이 getline에 바로 입력되어버리는 현상이 발생하기 때문에, cin 입력 후 cin.ignore()해주면 됨

## static_cast와 C스타일 cast의 차이
```c
// C style
int main(void)
{
    double a = 1.354;
    int b = (int)a;
    cout << b << endl;
    return 0;
}
```
```cpp
// C++ style
int main(void)
{
    double a = 1.354;
    int b = static_cast<int>(a);
    cout << b << endl;
    return 0;
}
```

#### 1. 컴파일러의 오류 체크
- C++은 **컴파일러가 캐스팅을 확인**하기 때문에 error가 나도 컴파일단에서 나기 때문에 추후 문제될 일을 미리 막을 수 있다.
- C style cast는 컴파일시 확인이 불가하기 때문에 **추후 런타임 에러**가 난다.

#### 2. 총 4가지 형태(static_cast, dynamic_cast, const_cast, reinterpret_cast)가 있어 기능을 직관적 확인 가능

#### 3. 보다 엄격(restrictive)함
- C++ style은 **포인터 형변환이 안된다**.
- C style은 컴파일단에서 캐스팅을 전혀 신경쓰지 않기 때문에 포인터 형변환이 가능함;;
- **포인터단에서 형변환이 의미 있는 경우는 상속받은 객체에 대한 업캐스팅, 다운캐스팅**이다.
  - 업캐스팅: 자식을 부모에게 할당하는 것
    - 자식(구체화 객체)을 부모(추상적 객체)에 할당하니 큰 문제가 되지 않는다.
    - 이 포인터(부모형)를 통해 자식의 멤버에 접근할 수 없다는 것 빼고는 자식들의 다형성을 보편화시켜 다룰 수 있다는 점 때문에 의미있게 사용된다.
  - 다운캐스팅: 부모를 자식에게 할당하는 것
    - 부모를 자식에게 할당할 경우 부모가 존재하지 않았던 값을 자식 포인터를 통해 접근할 수 있게 된다.
    - ⚠️ 따라서 **본래 있지도 않았던 값을 참조할 수 있으므로 위험하다**.
  - dynamic_cast: 업캐스팅/다운캐스팅을 위한 C++ style cast
    - 다운캐스팅을 할 경우 **null을 반환**해 위험함을 알리므로, **dynamic_cast시에 값이 null인 경우의 예외처리**를 해야 한다.

#### 4. 키워드 형태로 노출(작성)되어 있어 찾기가 편함
- C style은 (int)a 괄호로 캐스트하는 반면, C++ style은 static_cast<int>(a) 키워드로 캐스트하기 때문에 찾기 편하다.


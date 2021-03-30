### ex01 - My Awesome

|TOPIC|CONTENTS|
|:--:|:--:|
|Turn-in directory|ex01/|
|Files to turn in|Makefile, \*.cpp, \*.{h, hpp}|
|Forbidden functions|None|

80년 대에는 전화번호부를 사용했었다.

전화번호부를 만드는 프로그램을 작성하는 문제이다!

프로그램이 시작할 때, ADD, SEARCH, EXIT 명령어 중 하나를 입력 받아야 한다.

다른 입력은 무시된다.

프로그램은 빈 전화번호부로 시작하고, 다른 동적할당을 사용하면 안되고, 8개 이상의 연락처를 저장할 수 없다.

9번째 연락처가 저장되면, 적절한 행동을 실행해야 한다.

---

#### EXIT

* 프로그램이 중단되고, 연락처는 사라진다.

#### ADD

* 프로그램은 새로운 연락처 정보를 입력해야 한다.

* 연락처는 first name, last name, nickname, login, postal address, email address, phone number, birthday date, favorite meal, underwear color, darkest secret 내용을 저장해야 한다.

* 연락처는 무조건 코드에서 하나의 클래스의 인스턴스여야 한다.

* 원하는 대로 클래스를 구성할 수 있지만, 동료평가는 선택의 일관성을 확인할 것이다.

#### SEARCH

* 프로그램은 4개의 열에 가능한 연락처의 리스트를 보여주어야 한다.(index, first name, last name, nickname)

* 각 열은 10개의 문자만 출력하고, 오른쪽 정렬을 하며, '|' 로 구분지어야 한다.

* 출력 길이는 칸의 너비보다 길어서는 안되며 칸의 너비보다 넓은 경우, 문자를 자르고 마지막에 '.' 을 출력해야 한다.

* 프로그램은 인덱스의 입력을 기다리고, 연락처 정보를 출력한다.
 
* 한 줄에 하나의 연락처 정보만 나와야 한다.

* 만약, 입력이 잘못된 경우, 적절한 행동을 정의해야 한다.

* 다른 입력들은 무시된다!

### 만약, 명력어가 적절하게 실행되었다면, 프로그램은 다른 ADD, SEARCH, EXIT 명령어가 입력될 때까지 기다린다.

---

### Review

#### ADD

* add, ADD 둘 다 가능
* 정보 없이 엔터만 입력한 경우
* 8개 이상의 정보를 add 하려는 경우 확인
* 입력의 중간에 ctrl + D 를 누른 경우! (오류 처리)

#### SEARCH

* search, SEARCH 둘 다 가능
* 연락처가 1개도 없을 때, search 한 경우
* search 명령어 입력 후, 전체 연락처 정보가 나오는 지 확인
* 검색의 기준 입력받기(index, first name, last name, nickname)
* index - 없는 인덱스 번호를 입력한 경우, 특수 문자를 입력한 경우(std::ignore() 오류 처리)
* first name, first - 없는 이름을 입력한 경우, 같은 이름의 정보가 여러 개인 경우
* last name, last - 없는 이름을 입력한 경우, 같은 이름의 정보가 여러 개인 경우
* nick, nickname - 없는 이름을 입력한 경우, 같은 이름의 정보가 여러 개인 경우
* 입력의 중간에 ctrl + D 를 누른 경우! (오류 처리)

#### EXIT

* EXIT, exit 둘 다 가능

## CPP module 00

### ex00 - Megaphone

|TOPIC|CONTENTS|
|:--:|:--:|
|Turn-in directory|ex00/|
|Files to turn in|Makefile, megaphone.cpp|
|Forbidden functions|None|

소문자를 대문자로 바꾸어 출력하는 문제!


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

* 프로그램은 입력받은 정보에 대한 인덱스를 출력하고, 연락처 정보를 출력한다.
 
* 한 줄에 하나의 연락처 정보만 나와야 한다.

* 만약, 입력이 잘못된 경우, 적절한 행동을 정의해야 한다.

* 다른 입력들은 무시된다!

### 만약, 명력어가 적절하게 실행되었다면, 프로그램은 다른 ADD, SEARCH, EXIT 명령어가 입력될 때까지 기다린다.


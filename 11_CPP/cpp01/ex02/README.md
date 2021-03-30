## ex02

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex02/|
|Files to turn in|Zombie.cpp, Zombie.hpp, ZombieEvent.cpp, ZombieEvent.hpp|
|Forbidden functions|None|

### Zombie

* announce() 함수로 좀비가 울어야 한다.
* 멤버변수 name, type이 존재한다.
* setName, setType 함수를 이용하여 외부에서 멤버변수를 변경할 수 있다.
* getName, getType 함수를 이용하여 외부에서 멤버변수 값을 호출할 수 있다.

### ZombieEvent

* setZombieType 함수가 존재해야 한다.
* Zombie\* newZombie(std::string name) 함수를 만들어야 한다.
* newZombie 함수는 새로운 좀비를 만들고, 타입을 정하여 저장하고, name을 저장해야 한다.
* randomChump 함수는 랜덤한 이름을 저장하고, announce 함수를 실행한다.
* randomChump 함수에서 새로운 좀비는 **스택 영역**에 저장되어야 한다!!

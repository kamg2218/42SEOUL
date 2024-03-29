## CPP module 01

### Memory allocation, References, Pointers to members, File streams

### [ex00 - Heap of quadrupeds](./ex00)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex00/|
|Files to turn in|Pony.cpp, Pony.hpp, main.cpp|
|Forbidden functions|None|

* Pony 클래스를 만들고, pony를 적절하게 묘사하는 어떤 것이든 포함해야 한다.
* Pony를 할당하고, 뭐든 하는 두 개의 함수, ponyOnTheHeap, ponyOnTheStack 를 만들어야 한다.
* 물론, 첫번째 당나귀는 힙에 할당하고, 두번째 당나귀는 스택에 할당해야 한다.
* 의도한 실행을 증명하는 충분한 코드가 있는 main 을 제출해야 한다.
* 두 함수에서 당나귀 객체는 함수가 컨트롤 할 수 있어야 하고, 끝나고 나면 존재해서는 안된다.

---

### [ex01 - Plumbing problem](./ex01)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex01/|
|Files to turn in|ex01.cpp|
|Forbidden functions|None|

* 그 안에 포함된 메모리 누수를 수정한 후에, 아래의 함수를 제출해야 한다.
* 물론, 메모리 할당과 해제를 다루어야 한다.
* 단순하게 변수를 없애거나 실질적인 문제를 해결하는 것이 아닌 문제를 없애는 것은 잘못된 답이다.

~~~

void    memoryLeak()
{
    std::string*    panther = new std::string("String panther");
    std::cout << *panther << std::endl;
}

~~~

---

### [ex02 - Plucking some brains](./ex02)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex02/|
|Files to turn in|Zombie.cpp, Zombie.hpp, ZombieEvent.cpp, ZombieEvent.hpp|
|Forbidden functions|None|

* 첫째로, Zombie 클래스를 만들어라
* type, name을 포함하도록 하고, announce() 멤버함수를 포함해야 한다.
* announce() 멤버함수는 "<name (type)> Braiiiiiiinnnssss..."를 출력해야 한다.
* ZombieEvent 클래스를 만들어라.
* ZombieEvent 클래스는 setZombieType 함수를 포함하고, 객체에서 type을 저장하고, 함수 "Zombie*  newZombie(std::string name)"은 새로운 타입의 좀비를 만든다.
* randomChump 함수는 무작위한 이름을 갖고, 스스로 말하는 Zombie를 만든다.
* random 메소드가 어떤 것이든, 완전히 무작위한 이름이거나 무작위한 선택이어야 한다.
* 전체 프로그램을 제출해야한다. 요구된 일들을 하는 것을 충분히 증명하는 메인이 포함되어야 한다.
* 예를 들어, 새로 만든 좀비가 스스로를 알리게 해야 한다.
* 좀비들은 적적한 때에 사라져야 한다.
* 좀비들은 적절한 패션에 할당되어야 한다. 때론 스택에 있어야 적절하고, 다른 때엔 힙 영역에 있는 것이 더 낫다.
* 긍정적인 점수를 받기 위해 한 것을 정의해야 한다.

---

### [ex03 - Moar brainz!](./ex03)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex03/|
|Files to turn in|Zombie.cpp, Zombie.hpp, ZombieHorde.cpp, ZombieHorde.hpp, main.cpp|
|Forbidden functions|None|

* 이전에 만든 좀비 클래스를 재사용하여 ZombieHorde 클래스를 만들어라.
* 좀비떼 클래스는 integer N을 갖는 생성자가 있어야 한다.
* 랜덤한 이름으로 N Zombie 객체들을 할당해야 하고 저장해야 한다.
* 각각의 좀비 객체를 갖는 announce() 함수를 포함해야 한다.
* 각각의 할당에서 모든 Zombie 객체를 할당해야 하고, ZombieHorde를 파괴할 때, 사라져야 한다.
* 평소대로 테스트할 메인을 제공해야 하고, 선택들을 설명해야 한다.

---

### [ex04 - HI THIS IS BRAIN](./ex04)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex04/|
|Files to turn in|ex04.cpp|
|Forbidden functions|None|

* "HI THIS IS BRAIN"을 포함하는 문자열을 만들고 가리키고 참조하는 프로그램을 만들어라.
* 포인터를 사용하여 가리키고, 참조자를 사용하여 가리켜라.

---

### [ex05 - HI BRAIN THIS IS HUMAN](./ex05)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex05/|
|Files to turn in|Brain.cpp, Brain.hpp, Human.cpp, Human.hpp, main.cpp|
|Forbidden functions|None|

* Brain 클래스를 만들어라.
* Brain 클래스는 brain에 적절하다고 생각하는 것들을 포함한다.
* identify() 함수를 포함하고, 메모리에 뇌의 주소(16진수 형태, ex)0x194F87EA)를 포함하는 문자열을 반환한다.
* Human 클래스를 만들어라.
* human 클래스는 같은 생활을 갖는 brain 속성을 갖는다.
* identify() 함수를 갖고, Brain의 함수를 호출하고 결과를 반환한다.

~~~

int         main()
{
    Human   bob;
    
    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
}

~~~

* 위의 코드는 두개의 같은 주소를 출력한다.
* 위의 코드는 main으로 제출해야 하고, Human이나 Brain 클래스에 무엇을 더하든지 "될 때까지 해봤다"는 말 보다는 다른 말로 주장해야 한다.

---

### [ex06 - Unnecessary violence](./ex06)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex06/|
|Files to turn in|Weapon.cpp, Weapon.hpp, HumanA.cpp, HumanA.hpp, HumanB.cpp, HumanB.hpp, main.cpp|
|Forbidden functions|None|

* Weapon 클래스는 string type 멤버변수가 있고, string에 const reference 를 반환하는 getType 함수가 있고, setType 함수가 있다.
* HumanA 클래스와 HumanB 클래스는 Weapon 멤버변수가 있고, name 가 있고, attack() 함수가 있다.
* attack 함수는 "NAME attacks with his WEAPON_TYPE" 같은 것을 출력해야 한다.

~~~

    int main()
    {
        {
            Weapon club = Weapon("crude spiked club");
            HumanA bob("Bob", club);
            bob.attack();
            club.setType("some other type of club");
            bob.attack();
        }
        {
            Weapon club = Weapon("crude spiked club");
            HumanB jim("Jim");
            jim.setWeapon(club);
            jim.attack();
            club.setType("some other type of club");
            jim.attack();
        }
    }

~~~

---

### [ex07 - Sed is for losers](./ex07)

|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex07/|
|Files to turn in|Makefile, and whatever else you need|
|Forbidden functions|None|

* replace 프로그램을 만들어라.
* 프로그램은 filename, 두 개의 string, s1과 s2를 입력 받는다.
* s1를 s2로 교체하여 filename.replace에 저장한다.
* 오류 처리에 신경써야 한다.
* test files 를 포함하여 제출해야 한다.


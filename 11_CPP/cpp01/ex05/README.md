|TOPIC|CONTENTS|
|:--:|:--|
|Turn-in directory|ex05/|
|Files to turn in|Brain.cpp, Brain.hpp, Human.cpp, Human.hpp, main.cpp|
|Forbidden functions|None|

~~~

  #include "Human.hpp"

  int			main(void)
  {
  	Human	bob;
  
  	std::cout << bob.identify() << std::endl;
	  std::cout << bob.getBrain().identify() << std::endl;
  }

~~~

위 코드의 결과 값이 주솟값이며, 두 주솟값은 같아야 한다.

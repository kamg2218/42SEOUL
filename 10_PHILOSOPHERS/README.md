## 10_PHILOSOPHOERS

I've never though philosophy would be so deadly.

### 프로세스(Process)와 쓰레드(thread)

### mutex

mutex는 wait 함수를 호출한 오직 한 쓰레드로 시그널을 받을 수 있다.

### semaphore

semaphore는 wait 함수를 호출한 쓰레드가 다른 쓰레드에서 시그널을 받을 수 있다.

두 개의 원자 조작(기능적으로 분할할 수 없거나 분할되지 않도록 보증된 조작)인 wait, signal을 사용한다.

https://worthpreading.tistory.com/90 //뮤텍스와 세마포어 개념

### Mandatory part

#### basic rules

* C 언어로 작성해야 하고, 놈 규칙을 따른다.
* 어떤 메모리 누수나 충돌, 정의되지 않은 행동이나 놈 에러는 허용되지 않는다.
* 많은 철학자들이 원탁에 둘러 앉아, 먹거나 자거나, 생각하는 3가지 행동을 반복한다.
* 먹는 동안에는 자거나 생각하지 않고, 자는 동안에는 먹거나 생각하지 않고, 생각하는 동안에도 자거나 먹지 않는다.
* 철학자들은 중앙에 스파게티가 담긴 큰 볼이 있는 원탁에 앉아있다.
* 테이블에는 같은 포크가 놓여있다.
* 스파게티는 포크 하나로는 덜거나 먹기 어렵고, 각 손에 하나씩 두 개의 포크를 사용하여 먹어야 한다.
* 철학자들은 굶주려서는 안된다.
* 모든 철학자들은 먹어야한다.
* 철학자들은 서로 얘기하지 않는다.
* 철학자들은 다른 철학자가 죽으려 하는 것을 알지 못한다.
* 철학자가 식사를 마칠때마다 포크를 내려놓고 잠이 든다.
* 철학자가 자고 일어나면, 그는 생각하기 시작한다.
* 시뮬레이션은 철학자가 죽으면 끝이 난다.
* 각 프로그램은 같은 조건을 갖는다. (number_of_philosophers, time_to_die, time_to_eat, time_to_sleep\[number_of_times_each_philosopher_must_eat])
* 각 철학자들은 1번부터 number_of_philosophers까지 번호를 부여받는다.
* 철학자 1번은 number_of_philosopher 번 옆에 있다. N번인 다른 철학자는 N-1번과 N+1번 사이에 앉아있다.
* 철학자 상태의 변화는 아래와 같이 작성해야한다.\n 'timestamp_in_ms X has taken a fork', 'timestamp_in_ms X is eating', 'timestamp_in_ms X is sleeping', 'timestamp_in_ms X is thinking', 'timestamp_in_ms X died'.
* 출력한 상태는 다른 철학자의 상태와 섞여서는 안된다.
* 철학자의 죽음과 죽음을 출력하는 사이에 10 ms를 넘어서는 안된다.
* 철학자가 죽어서는 안된다.

#### Philo_one

* Program_name : philo_one
* arguments : number_of_philosophers, time_to_die, time_to_eat, time_to_sleep\[number_of_times_each_philosopher_must_eat]
* external functs. : memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock
* libft : NO
* Description : philosopher with threads and mutex
* 철학자 사이에 1개의 포크가 있고, 철학자의 좌우에 1개씩 포크가 있다.
* 철학자가 포크를 동시에 사용하지 않도록하기위해서, 각자를 mutex로 포크 상태를 보호해야한다.
* 각 철학자는 하나의 쓰레드가 되어야 한다.

#### Philo_two


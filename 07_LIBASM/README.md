# Libasm

## INDEX
   
   [1. Assembly Language](#assembly-language)
   
   [2. Mandatory part](#mandatory-part)
   
   [3. Bonus part](#bonus-part)

## Assembly language
    
    기계어와 일대일 대응이 되는 컴퓨터 프로그래밍의 저급 언어이다.
    
    컴퓨터의 CPU에 따라 지원하는 오퍼레이션의 타입과 개수가 다르며 레지스터의 크기와 개수, 저장된 데이터 형의 표현도 다르다.
    
    
## Mandatory part    
    
### ft_strlen

    size_t ft_strlen(const char *s);

   * 매개변수 : rdi
   * 반환 값 : rax
   * NULL 변수를 입력한 경우, 본래 함수에서는 SEGV fault 발생.
   * check point! : ""인 경우, null인 경우
  
  
### ft_strcpy

    char *ft_strcpy(char *dest, const char *src);

   * 매개변수 : rdi, rsi
   * 반환 값 : rax
   * NULL 변수를 입력한 경우, 본래 함수는 SEGV fault 발생.
   * check point! : buf,null인 경우, null, ""인 경우, buf, ""인 경우

#### ft_strcmp

    int ft_strcmp(const char *s1, const char *s2);

   * 매개변수 : rdi, rsi
   * 반환 값 : rax
   * 두 매개변수가 널인 경우, 본래 함수에서는 SEGV fault 발생.
   * check point! : "string", null인 경우, null, null인 경우, "", null인 경우
       
#### ft_write

    ssize_t write(int fd, const void *buf, size_t count);
    
   * 매개변수 : rdi, rsi, rdx 순서로 차례로 담긴다.
   * 반환 값 : rax
   * system call : 0x2000004 / exit : 0x2000001
   * reference :  http://www.linfo.org/system_call_number.html
   * rax, rbx, rcx, rdx 에 차례로 변수를 담아 system call 하면 된다.
   * 함수 호출 이후에 사용할 값들은 스택에 저장해두어 값이 변하지 않도록 한다.
    
#### ft_read

    ssize_t read(int fd, void *buf, size_t count);
    
   * 매개변수 : rdi, rsi, rdx 차례로 담긴다.
   * 반환 값 : rax
   * system call : 0x2000003
   * rax, rbx, rcx에 값을 차례로 넣어 함수를 호출한다.
   * 함수 호출 이후에 사용할 값들은 스택에 저장해두어 값이 변하지 않도록 한다.

#### ft_strdup

    char *strdup(const char *s);
    
   * 매개변수 : rdi, rsi, rdx 차례로 담긴다.
   * 반환 값 : rax
   * call malloc : malloc의 매개변수는 rdi에 저장하여 함수를 호출한다.
   * 함수 호출 이후에 사용할 값들은 스택에 저장해두어 값이 변하지 않도록 한다.
   * null인 경우, 실제 함수에서 오류가 발생한다.
   * check point! : ""인 경우, null인 경우

## Bonus part

#### ft_atoi_base
    
    int ft_atoi_base(char *string, char *base);
    
   * 매개변수 : rdi, rsi
   * 반환 값 : rax
   * base : "0123456789"와 같이 진법을 알려준다.
   * base 문자열에 문자, 숫자가 아닌 경우, 0을 반환.
   * base 문자열에 같은 문자나 숫자가 반복되는 경우, 0을 반환.
   * 공백, 부호, 숫자 순서로 확인.
   * 문자열에서 베이스에 없는 문자가 나온 경우, 그때까지 계산한 값을 반환
   * check point! : "2147483648", "0123456789"의 경우, "-2147483649", "0123456789"인 경우, "age", "damage"인 경우 - 0, "42age", "0123456789"인 경우 - 42, "doae", "dom age"인 경우 - 0

#### ft_list_push_front

    void ft_list_push_front(t_list **begin_list, void *data);
    
   * 매개변수 : rdi, rsi
   * 반환 값 : rax
   * [rdi]에 새로 만들어진 첫 노드의 주소를 저장해야한다!

#### ft_list_size

    int ft_list_size(t_list *begin_list);
    
   * 매개변수 : rdi
   * 반환 값 : rax


#### ft_list_sort

    void ft_list_sort(t_list **begin_list, int (*cmp)());
   
   * 매개변수 : rdi, rsi
   * 반환 값 : none
   * [rdi]에 새로 만들어진 첫 노드의 주소를 저장해야한다!
   * int (\*cmp)() : 함수 포인터, 주소값으로 함수를 호출할 수 있다. (call 명령어 사용)
   * 데이터 값이 바뀌는 지, 리스트가 바뀌는 지 확인해야한다.
   * check point! : 리스트의 데이터에 null이 있는 경우!


#### ft_list_remove_if

    void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
    
   * 매개변수 : rdi, rsi, rdx, rcx
   * 반환 값 : none
   * cmp : strcmp 함수
   * free_fct : data 포인터를 free하는 함수이다.
   * check point! : begin_list, cmp, free 값이 null인 경우, 오류 처리!
   * check data : "" 인 경우, null인 경우
   * check list : 첫번째 노드 제거, 중간 노드 제거, 마지막 노드 제거 확인!


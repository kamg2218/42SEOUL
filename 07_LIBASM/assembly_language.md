## Assembly Language

### order : [x86 vs x64](#calling-convention), [s file](#s-file), [operand](#operand-register), [opcode](#opcode-register)

### Assembler
    
    **어셈블러는 어셈블리어를 기계어 형태의 오브젝트 코드로 해석해주는 컴퓨터 언어 변역 프로그램이다.**
    
    어셈블러는 기본 컴퓨터 명령어들을 컴퓨터 프로세서가 기본 연산을 수행하는데 사용할 수 있는 비트 패턴으로 변환시키는 프로그램이다.
    
    이런 명령어들을 어셈블러 언어, 어셈블리 언어라고 부른다.
    
    어셈블러는 니모닉 기호를 opcode로 변환하고 메모리 위치와 기타 존재물에 따라 식별자를 다시 분석하여 목적 코드를 만들어낸다.
    
    거꾸로 기계어를 어셈블리어로 바꾸는 것은 역어셈블러(disassembler)이다.
    
    1패스(one-pass) 어셈블러 : 소스 코드를 한 번만 거친다.
    
    다중 패스(multi-pass) 어셈블러 : 처음 패스들에서 모든 기호와 관련 값들이 포함된 테이블 하나를 만들고 나중 패스들에서 테이블을 이용하여 코드를 만들어낸다.
    

### Calling convention

    윈도우 환경에서는 인자 전달을 위해 4개의 레지스터만을 사용하며, 정수인자의 경우 rcx, rdx, r8, r9를 순서대로 사용한다.
    
    실수인자의 경우, xmm0 ~ xmm3까지를 순서대로 사용하고, 4개가 넘을 경우, 스택을 통해 전달한다.
    
    리눅스 환경에서는 인자 전달을 위해 6개의 레지스터를 사용하고, 정수인자의 경우 rdi, rsi, rdx, rcx, r8, r9를 순서대로 사용한다.
    
    실수인자의 경우, xmm0 ~ xmm7까지 8개를 순서대로 사용하고, 그 이상의 경우, 스택을 통해 전달한다.

#### x86
    
    인텔에서 개발한 8086에 적용된 명령어 세트이자 그 호환 프로세서 또는 후속작을 부르는 말이다.
    
    x64와 대비하여 32비트 아키텍처의 관습적 명칭으로도 쓰인다. (ex> eax, ebx, ...)
    
    EBP를 기준으로 argument, local variable에 접근한다.
    
    ebp + 숫자 : argument (ex> ebp + 8h : 첫번째, ebp + ch : 두번째)
    
    ebp - 숫자 : local variable
    
    x86 아키텍쳐는 8개의 범용 레지스터, 6개의 세그먼트 레지스터, 1개의 플래그 레지스터, 명령어 포인터를 갖는다.
    
    * 범용 레지스터
        
        ax, cx, dx, bx, sp, bp, si, di
        
    * 세그먼트 레지스터

        ss(stack segment), cs(code segment), ds(data segment), es(extra segment), fs(f segment), gs(g segment)
    
    * EFLAGS 레지스터

        프로세서의 작동 결과와 상태를 저장하기 위해 부울 값들의 모음으로 사용되는 32비트 레지스터
        
    * 명령어 포인터

        분기가 수행되지 않은 경우, eip 레지스터는 다음에 실행되어야 할 명령어의 주소를 가지고 있다.
        
        eip 는 오직 call 명령어를 사용해 스택을 통해서만 읽을 수 있다.
        
#### x64

    레지스터의 사이즈가 64비트로 rax, rbx 와 같이 사용된다.
    
    eax, ax, al, ah와 같은 레지스터들도 사용되고, 이때의 메모리는 rax의 하위 비트들을 사용한다.
    
    없었던 레지스터 R8, R9, R10, R11, R12, R13, R14, R15가 추가되었다.
 
    이는 비휘발성(non-volatile) 레지스터로 RCX, RDX, R8, R9 네 개의 레지스터는 함수를 호출할 때 아규먼트를 전달하는데 사용된다.
    
    rbp는 x86에서는 사용 중인 스택 영역을 확인할 수 있었는데, x64에서는 일반적인 목적으로 사용된다.
    
    스택 포인터 rsp를 기준으로 argument, local variable에 접근한다.
    
    rsp + 숫자 : argument
    
    rsp + 숫자 : local variable / 스택 사이즈보다 작은 값이 들어간다.
    
 
### GDB(GNU Debuger)

    brew install gdb : gdb 설치
    
    gdb [object file name] : object file을 gdb로 실행
    
    GDB는 AT&T 문법이 기본이다.
    
    C 파일을 컴파일하여 오브젝트 파일로 만들어 어셈블리어를 확인할 수 있다.
    
    gnu [object file] : 오브젝트 파일로 gnu 확인
    
    set disassembly-flavor intel : intel 문법으로 변경

    disass [function name] : 특정 함수의 어셈블리어 확인
   
   * Reference : https://itsaessak.tistory.com/78
   
### lldb
   
   * lldb [file name]
   * b [function name] - set breakpoint!
   * run
   * next - 다음 줄 실행
   * reg read - 레지스터 값 확인
	
### NASM(Netwide Assembler)
    
    컴파일 : nasm -f macho64 [file name]
    
## S file
    
    assembly language 언어로 작성한 파일을 말한다.
    
    global : .s 파일 내에 global이 있는 경우, 실행파일이 실행될 때, 그 위치에서 시작한다. 
    
    만약, global이 없는 경우, 시작 위치를 정하지 못하고 오류가 발생한다.

#### Data section
	
	초기값을 가지는 변수를 저장하는 섹션
	
	[레이블]: <white space> [크기] <white space> [문자열이나 숫자의 초기값]
	
	ex> section	.data	; initialized data section data (데이터 섹션 영역을 선언)	

	ex> msg:	 db	‘Hello, World!’, 10, 00

	ex> buffer:  dd	  1,2,3,4,5;  - int buffer[] = {1, 2, 3, 4, 5};

	data section 의 msg 레이블(주소)에 문자열을 위치시킨다.

	레이블 : 16진수인 주소에 이름을 붙인 것

#### Bss section

	초기화하지 않고 크기만을 예약한다.

	[레이블]: <white space> [단위] <white space> [크기]
	
	ex> section	.bss 
	
	ex> a: resd 1		; int a
	
	ex> str: resb 1024	; char str[1024]

	b : 1byte / w : 2byte / d : 4byte / q : 8byte 

#### Text section

	레지스터와 메모리라는 개념을 사용하게 된다.

    아래의 내용은 32비트 레지스터를 기준으로 작성되었다.
    
	레지스터 : cpu가 사용하는 고속 기억 소자 / CPU당 1개의 레지스터를 제공한다.

		범용 레지스터 (general-purpose registers)
		
            EAX : 산술 연산 /  32bit
			
            EBX : EAX 보조 역할
			
            ECX : 명령어 반복 처리시 반복횟수 저장
			
            EDX : I/O pointer, EAX 보조 역할
		
        포인터 레지스터
			
            ESI : 문자열 복사시에 주로 사용, source
			
            EDI : 문자열 복사시에 주로 사용, destination
			
            EBP : 스택 시작 주소
			
            ESP : 스택 마지막 주소
			
            EIP : 다음 실행할 명령어의 주소
		
        상태 레지스터
			
            EFLAGS : 상태정보 (32 비트)
			
            SF : 부호가 발생한 경우
			
            ZF : 연산 결과가 0
			
            CF : 올림수
		
        세그먼트 레지스터 : 물리 메모리와 가상메모리 매핑시에 사용

    * 메모리란? CPU가 사용하는 데이터 저장공간

### Intel   VS   AT&T
    
    어셈블리 언어는 Intel과 AT&T 두 가지 문법을 사용한다.
    
    서로 호환되지 않는 문법으로 많은 차이점이 있다.
    
    어셈블리 언어는 명령어인 opcode와 피연산자인 operand 2개를 사용한다.

    어셈블리어에서는 연산자를 사용할 수 없고 명령어를 사용하지만, 괄호 내부에서는 연산자를 사용할 수 있다.

#### Intel

    인텔 문법은 opcode destination source 순서로 작성한다.
    
    숫자 그대로 표시한다.
    
    메모리는 [] 괄호로 표시한다.
    
    offset [이름 + 숫자]

#### AT&T 

    at&t 문법은 opcode source destination 순서로 작성한다.
    
    숫자 앞에 $를 표시한다.
    
    메모리는 () 괗호로 표시한다.
    
    offset 숫자(이름)
    
### Operand Register

    아래의 레지스터는 32비트를 기준으로 작성되었다. 64비트의 경우, E 대신 R을 붙이면 된다.

    16 bit : AX, BX, CX, DX
    
	32 bit : EAX, EBX, ECX, EDX
	
    64 bit : RAX, RBX, RCX, RDX

    1. EAX(Extended Accumulator Register) : +, - 연산에 사용, 함수 리턴값 저장된다.
	2. EDX(Extended Base Register) : 연산에 사용, 함수 리턴값이 저장되지 않는다.
	3. ECX(Extended Counter Register) : 반복문에서의 변수 역할, 반복할 최대 숫자에서 감소하면서 카운트한다. 여분의 레지스터
	4. ESI(Extended Source Index) : 복사할 데이터의 주소 저장
	5. EDI(Extended Destination Index) : 복사한 데이터를 저장할 주소 저장(ESI에서 복사한 데이터를 EDI 에 저장한다.)
	6. ESP(Extended Stack Pointer) : stack frame의 끝 주소 저장(64비트 환경에서는 일반적인 레지스터로 사용된다.)
	7. EBP(Extended Base Pointer) :  stack frame의 시작 주소 저장(64비트 환경에서는 일반적인 레지스터로 사용된다.)
	8. RIP : 돌아갈 함수의 주소를 저장한다. 

### Opcode Register

    1. PUSH : stack에 값 저장 (ex> PUSH EBP - stack에다 값 저장)
	2. POP : stack 에서 값 삭제 (ex> POP EBP - stack에서 값 삭제) 
	3. MOV : 값을 넣는다. (ex> MOV EAX, ECX - ECX 값을 EAX 값에 넣는다.)
	4. LEA : (load effective address)주소를 넣는다. (ex> LEA EAX, [ESI] - ESI 주소값을 EAX에 넣는다.)
	5. ADD : 더하기
	6. SUB : 빼기
	7. INC : 1 증가 (64bit 에서 [] 내부에는 레지스터만 들어갈 수 있다.)
	8. DEC : 1 감소
	9. CMP : 비교 (ex> CMP EAX, EDX - EDX 와 EAX 비교), 상태 레지스터에만 영향을 준다.
			—> sf(부호, 비교값이 음수일때 1), cf(올림수), zf(0, 비교값이 같을 때)
	10. CALL : 함수 호출 (push tip + jump [function name] - 호출할 주소값 넣고, 함수로 이동), 호출할 함수의 인자는 rdi, rsi 레지스터에 저장하여 호출한다.
	11. RET :  함수를 종료하고, CALL 다음 줄로 이동 (pop eip - 다음 실행할 명령어의 주소)
	12. NOP : 아무것도 하지 않는다.
	13. JNE : jump not equal 값이 같지 않으면 점프한다.
	14. JLE : jump less or equal
	15. JGE : jump greater or equal 
	16. JMP : jump, 특정 주소나 offset으로 점프한다.
	17. LEAVE : stack 정리한다. (Mov esp, ebt;   pop ebt.  — 지역변수 공간 회수, 실행전의 ebt 가져온다.)
	18. MOVSXD : move doubleword to quadword with sign-extension(형변환)
	19. AL / BL : 값 저장 
	20. AND : 각 비트가 모두 1일 때만 결과 값이 1.
	21. OR : 각 비트가 하나라도 1이면 결과 값이 1.
	22. XOR : 값이 서로 다른 경우 값이 1.  / 초기화할 때 많이 사용한다.
	23. MUL : 곱하기 (ex> mul dl -  al * dl)
	24. DIV : 나누기
	25. CWD : change word to DWORD
	26. SHL : shift left - 부호가 없는 연산
	27. SHR : shift right - 부호가 있는 연산
	28. SAL : 부호가 있는 연산
	29. SAR : 부호가 있는 연산
	30.  NOT : (= NEG) not 비트 연산자 (ex> exa = 15;  neg eax;  —> exa = -15)
	31. MOVZX : zero extend 부호가 없는 경우, 형변환 —> 작은 값에서 큰 값으로
	32. MOVSX : sign extend 부호가 있는 경우, 형변환 —> 작은 값에서 큰 값으로 (반대의 경우 자동으로 가능함)
	33. JA : jump above
	34. JG : jump greater
	35. JB : jump below
	36. JL : jump less
	37. JC : jump carry (cf = 1)
	38. JS : jump sign (sf = 1)
	39. JZ : jump zero (zf = 1)
	40. INT : intercept (ex> int 0x80, int 80h : 시스템 콜 호출, eax에 저장된 함수를 호출한다.  —> 시스템 콜 번호 참고!)

#### MUL
	
    AL(8 bit) * 8bit x/m		-> 	AX (16bit)
	
    AX(16 bit) * 16bit x/m	->	DX:AX(16bit 레지스터 2개 사용)
	
    EAX(32bit) * 32bit x/m	->	EDX:EAX(32bit 레지스터 2개 사용)
	
	ex> eax = 0; edx = 0; ax = 10000; dx = 10000; mul dx; ——> edx : 1525, eax : 57600
	
        -> edx * 2^16 + eax = 100000000 : edx와 eax로 나누어 데이터가 담긴다. 따라서 16비트의 eax 크기만큼 2를 제곱하여 원래 수를 얻을 수 있다.
		
        -> 16비트로 수를 표현할 수 있을 때에는 dx:ax 형식을 사용하지 않고 ax에 저장한다.

#### DIV
	
    AX by DIV r/m8 : AX레지스터 값을 8비트 레지스터로 나눈다. -> AL에 몫, AH에 나머지 저장
	
    DX:AX by DIV r/m16 : 32bit 레지스터를 16bit로 나눈다. -> AX에 몫, DX에 나머지 저장
	
	ex> eax = 0; ax = 10; dl = 4; div dl;  ——> eax : 514  —> 2진수 00000010 00000010
	
        -> 16비트 ax를 8비트 dl로 나누므로 8비트씩 나누어 몫과 나머지가 저장된다. 나머지가 저장되는 부분을 AH, 몫이 저장되는 부분을 AL이라 한다.
        
            -> and eax, FFh	——> 몫
		
            -> eax >> 8		——> 나머지

#### Shift 연산
	
    eax = 4;
	
    eax << 1     —> 4 * 2 = 8 / 1칸씩 왼쪽으로 이동
	
    eax >> 1	  —> 8 / 2 = 4 / 1칸씩 오른쪽으로 이동

#### leave
	
    mov		esp, ebt
	
    pop		ebp

#### ret

    pop		rip
	
    jump	eip

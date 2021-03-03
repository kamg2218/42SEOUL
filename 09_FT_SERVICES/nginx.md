## Nginx

### Alpine linux

    알파인 리눅스는 가볍고 간단한, 보안성을 목적으로 개발한 리눅스 배포판이다.
    
    용량을 줄이기 위해 시스템의 기본 C runtime을 glibc 대신 musl libc를 사용하며 다양한 쉘 명령어는 GNU util 대신 busybox를 탑재했다.
    
    용량이 80M인 초경량화된 배포판이므로 Embedded 나 네트웍 서버등 특정 용도에 적합하며 특히 도커에 채택되어 5M 크기의 리눅스 이미지로 유명하다.
    
   * docker run -it alpine /bin/sh : bash가 없으므로 /bin/sh 실행한다.

#### apk 패키지 관리자

   * apk update
   * apk upgrade
   * apk add vim : vim 설치(add)
   * apk del vim : vim 삭제(del)
   * apk search zsh : zsh가 포함된 패키지 검색
   * apk info zsh : zsh 자세한 정보
   * apk info -L vim : 설치한 패키지내 파일 확인
   

### SSL vs SSH

#### SSL

    보안 소켓 계층(Secure Socket Layer)은 넷스케이프사에서 개발한 인터넷 보안 프로토콜이다.
    
    
#### SSH

    시큐어 쉘(Secure SHell)은 네트워크 상의 다른 컴퓨터에 로그인하거나 원격 시스템에서 명령을 실행하고 다른 시스템으로 파일을 복사할 수 있도록 해 주는 응용 프로그램 또는 그 프로토콜을 가리킨다.
    
    기존의 텔넷, rlogin, rsh 등을 대체하기 위해 설계되었으며, 안전하게 통신을 할 수 있는 기능을 제공한다.
    
    기본적으로 22번 포트를 사용한다.
    
    ssh는 암호화 기법을 사용하기 때문에, 통신이 노출된다고 하더라도 이해할 수 없는 암호화된 문자로 보인다.
    
    

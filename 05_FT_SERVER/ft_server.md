# ft_server

## 1. System Administration

    시스템 관리는 시스템이 최적의 환경에서 최대의 성능을 발휘하도록 시스템을 설정하고, 동작을 감시하며, 운영하는 업무이다.
    
    시스템 관리는 성능관리, 고장 관리, 교육과 기타 관리로 나눌 수 있다.
    
    성능관리는 시스템 자원이 성능을 발휘할 수 있도록 최적의 환경을 구성하고 운영하는 것을 말한다.
    
    고장관리는 문제없이 정상적으로 동작하는지 감시하고 고장이 발생했을 때 신속히 복구할 수 있도록 하는 것을 말한다.
    
    교육과 기타 관리는 사용자를 교육하고 시스템과 관련한 기타 업무를 수행하는 것을 말한다.
    
    
### System

    각 구성요소들이 상호작용하거나 상호의존하여 복잡하게 얽힌 통일된 하나의 집합체
    
### Server

    클라이언트에게 네트워크를 통해 정보나 서비스를 제공하는 컴퓨터 시스템
    
    기존에는 자체적인 시스템 설계를 통해 인프라를 직접 관리하거나,
    
    인프라를 가상화하여 관리가 용이한 서비스인 IaaS(Infrastructure as a Service)를 사용하거나,
    
    IaaS에서 더 추상화된 모델로, 네트워크, 런타임까지 제공하는 PaaS(Platform as a Service)를 이용했다.
    
### Serverless

    작업을 처리하는 서버가 존재하긴 하지만, 서버의 존재를 신경쓰지 않아도 된다는 의미로,
    
    Firebase와 같은 BaaS(Backend as a Service)를 사용한다.
    
    앱 개발에 필요한 기능을 api로 제공함으로서, 개발자들이 서버를 개발하지 않고도 필요한 기능을 빠르게 구현할 수 있게 한다.
    
    개발 시간의 단축과 서버 확장 작업가 필요하지 않다는 장점이 있다.
    
    FaaS(Function as a Service)는 프로젝트를 함수로 쪼개서 등록하고, 함수들이 실행되는 횟수만큼 비용을 지불하는 방식이다.
    
    24시간 애플리케이션이 작동하는 것이 아닌 이벤트가 발생했을 때에만 작동하여 비용이 절약된다.
    
    그러나, 함수에서 사용할 수 있는 자원에 제한이 있고, 함수 호출 시에 제한이 있다.
    
## 2. Docker

   도커는 2013년에 등장한 컨테이너 기반의 가상화 도구이다.
   
   리눅스 상에서 컨테이너 방식으로 프로세스를 격리해서 실행하고 관리할 수 있으며, 계층화된 파일 시스템에 기반하여 이미지(프로세스 실행 환경)를 구출할 수 있도록 한다.
   
   이미지를 기반으로 컨테이너를 실행할 수 있고, 특정 컨테이너의 상태를 이미지로도 만들 수 있다.
   
   만들어진 이미지는 파일로 보관, 공유가 용이하다.
   
  * docker pull [image name] : download images files
  * docker -v : docker version
  * docker version : docker version details
  * docker ps : 실행 중인 docker containers
  * docker ps -a : all docker containers
  * docker images : docker images
  * docker run -it [image name] commands : 이미지 기반의 컨테이너 실행 / bash 실행
  * docker run -it --rm [image name] commands : 이미지 기반의 컨테이너 실행 / bash 실행 / 종료시 컨테이서 삭제
  * docker restart [container ID] : 컨테이너 재실행
  * docker attach [container ID] : bash 실행
  * docker diff [container ID] : image 와 다른 점 출력
  * docker commit [container ID] : container ID를 복사하여 새로 생성
  * docker rm [container ID] : delete container
  * docker rmi [image ID] : delete image

  * reference : https://www.44bits.io/ko/post/easy-deploy-with-docker
   
### Dockerfile

    dockerfile을 빌드하여 이미지를 추가할 수 있다.
    
   * FROM : 어떤 이미지로부터 생성할 지를 지정한다. / dockerfile 내에 from은 한번만!
   * RUN  : 명령어를 실행한다.
   * WORKDIR : 이후 실행되는 모든 작업의 실행 디렉터리 변경
   * ENV  : 컨테이너 실행 환경에 적용되는 환경변수의 기본값을 지정
   * EXPOSE : 포트 지정
   * CMD  : 컨테이너에서 실행될 명령어 지정
   * docker build -t [container ID] : dockerfile 빌드 / 컨테이너 생성
   * docker run -d -p [port number] container ID : -d = i 와 반대로 백그라운드에서 실행 / -p = 포트 넘버 지정
   * dockerfile에서 CMD 명령어를 사용하여 bash 파일을 실행시켜 어플리케이션을 다운 받는 것이 이미지 파일의 크기를 축소시킬 수 있다!
  
   
## 3. ubuntu vs centOS for server OS

### ubuntu

   * It's based on the Debian architecture.
   * open-source and frequent updates
   * A ton of applications.
   * highly customizable
   * top-notch security features.
   * download DEB packages using the apt-get package manager
   * Greate deal of support for container and cloud deployments

### centOS

   * Red Hat Enterprise Linux.
   * an open-source Linux distribution.
   * Enterprise class operating system supported by the community and released in 2004.
   * customize, secure
   * yum command to download and install RPM packages
   * more stable distribution compared to Ubuntu.
   * less frequent updates

   * reference : https://www.hostinger.com/tutorials/centos-vs-ubuntu

## 4. nginx vs apache for web server

    웹 서비스는 HTTP protocol을 이용하여 클라이언트와 서버의 통신을 의미한다.
    
    웹 서버는 HTTP request를 받고, HTML, CSS, Javascript, Image 등의 정적인 정보를 반환하는 역할을 한다.
    
    IIS, Apache, Nginx, GWS 등이 있다.

### nginx

   * 요청이 들어오면 어떤 동작을 해야하는 지를 알려주고 다른 요청을 처리하는 Event Driven 방식 사용
   * system resource를 적게 처리하는 장점

### apache

   * MPM(Multi Processing Module, 다중처리모듈)방식 사용
   * open-source 

## 5. WordPress

   * An open-source, free website creation tool
   * 모바일 반응형 웹 디자인
   * 소셜 마케팅 최적화 서비스
   * 검색 엔진 최적화 인프라

## 6. phpMyAdmin

   * MySQL을 월드 와이드 웹(www)상에서 관리할 목적으로 PHP로 작성한 오픈 소스 도구이다.
   * 데이터베이스, 테이블, 필드, 열의 작성, 수정, 삭제 등의 다양한 작업을 수행할 수 있다.

## 7. MySQL vs MariaDB vs MongoDB

### MySQL

   * 가장 많이 쓰이는 오픈 소스의 관계형 데이터베이스 관리 시스템이다. (RDBMS)
   * 오라클이 관리 및 지원하고있다.
    
### MariaDB

   * open-source
   * 관계형 데이터베이스 관리 시스템(RDBMS)
   * MySQL과 동일한 소스 코드를 기반으로 하고, GPL v2 라이선스를 따른다.
   * MySQL과 비교하여 어플리케이션 부분 속도가 4 ~ 5천배 정도 빠르다.

### MongoDB

   * 비관계형 데이터베이스 관리 시스템인 NoSQL 기반의 소프트웨어
   * NoSQL의 경우, 스키마가 없어 유연하고, 속도가 빠르다.
   * 데이터가 JSON 형태로 저장되고, 조인의 개념이 없어 데이터가 중복되어 있고, 데이터를 수정하는 경우 모든 컬렉션에서 수행해야한다.

## 8. SSL protocol

   * Secure Socket Layer, 보안 소켓 계층
   * 인터넷 상에서 데이터를 안전하게 전송하기 위한 인터넷 암호화 통신 프로토콜
   * (= TLS, Transport Layer Security)
   * OSI 7계층 모델의 응용계층과 전송계층 사이에 독립적인 프로토콜 계층을 만들어서 동작한다.
   * 데이터를 전달 받을 때, TCP로 부터 받아 데이터를 복호화하여 응용계층에 전달하고, 이때 Application은 SSL을 TCP로 인식하고, TCP는 SSL을 Application으로 인식한다.
   * 데이터를 외부로 보내는 경우, 데이터를 TCP가 아닌 SSL에 보내게 되고, SSL은 데이터를 암호화하여 TCP를 통해 외부로 전달한다.

   * reperence : https://m.blog.naver.com/xcripts/70122755291

### HTTP

   * HyperText Transfer Protocol
   * 정보를 주고받을 수 있는 프로토콜 / HTML 문서 전송
   * TCP를 주로 사용하고, 80번 포트를 사용한다.
   * 클라이언트와 서버 사이에 이루어지는 요청, 응답 프로토콜
   * http를 통해 전달되는 자료는 http: 로 시작하는 URL로 조회할 수 있다.

### HTTPS
   
   * HyperText Transfer Protocol Secure socket Layer
   * HTTP 보안이 강화된 버전
   * SSL이나 TLS 프로토콜을 통해 세션 데이터를 암호화한다.
   * 기본 TCP/IP 포트는 443이다.
   * https:// 로 시작한다.
   
## 9. DNS protocol

   * Domain Name System, 도메인 네임 시스템
   * 호스트의 도메인 이름을 호스트의 네트워크 주소로 바꾸거나 그 반대의 변환을 수행한다.
   * 사람이 이해하기 쉬운 도메인 이름을 숫자로 된 식별번호인 IP주소로 변환해 준다.
   * 인터넷은 도메인 네임 게층과 인터넷 프로토콜 주소 공간을 관리한다.


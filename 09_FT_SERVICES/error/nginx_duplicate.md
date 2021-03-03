## nginx: [emerg] "keepalive_timeout" directive is duplicate in /etc/nginx/nginx.conf:52


nginx.conf 파일을 COPY 하여 저장한 경우에 발생했다.

keepalive_timeout 3000 부분을 #으로 주석처리하여 오류를 해결했다.


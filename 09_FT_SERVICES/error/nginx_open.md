## nginx: [emerg] open() "/run/nginx/nginx.pid" failed (2: No such file or directory)


debian:buster와는 다르게 Alpine linux에서는 설치와 동시에 파일이나 디렉토리가 생성되지 않는다.

따라서, /run/nginx 디렉토리를 직접 생성해줘야 한다.


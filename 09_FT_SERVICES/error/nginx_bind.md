## nginx: [emerg] bind() to 0.0.0.0:80 failed (98: Address in use)


### nginx: [emerg] bind() to 0.0.0.0:80 failed (98: Address in use)
### nginx: [emerg] bind() to [::]:80 failed (98: Address in use)

nginx 명령어로 이미 실행 중이기 때문에 다시 실행하기 위해서는 nginx가 아닌 

nginx -s reload 명령어를 사용하여 실행해야 한다.


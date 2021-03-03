## 400 Bad Request

External_IP:443으로 접근한 경우, 400 Error 가 발생했다.

https://www.tecmint.com/fix-400-bad-request-in-nginx/#:~:text=You%20encounter%20this%20error%20because,it%20complains%20with%20the%20error.&text=Then%20restart%20the%20nginx%20service. //400 error 참고

매번 http를 경유해서 https로 redirection되지만, 본래의 요청은 http와 같다.

반면, https로 접속하는 경우, 에러가 발생하지 않는다.

ssl 을 사용하지 않는 웹사이트가 있는 경우, nginx는 기본적으로 https를 사용하려고 할 것이다.

에러를 고치기위해서, configuration을 'ssl off'로 수정하거나 'ssl on'을 지워야한다.

또는, listen 443 ssl;에서 ssl을 지우는 방법도 있다.
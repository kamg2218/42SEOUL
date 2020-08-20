## 06_CUB3D

### How to use Makefile

    make maps/map_name.cub
    
### How to make screenshot

    make maps/map_name.cub --save

* Before starting this project : http://users.atw.hu/wolf3d


|NAME|CONTENTS|
|:--|:---|
|Program name|cub3D|
|Turn in files|All your files|
|Makefile|all, clean, fclean, re, bonus|
|External functs.|open, close, read, write, malloc, free, perror, strerror, exit<br>All functions of the math library (-lm man man 3 math)<br>All functions of the MinilibX|
|Libft authorized|Yes|
|Description|You must create a realistic 3D graphical representation of the inside of a maze from a first person perspective. you have to create this representation using the Ray-Casting principles mentioned earlier.|

* This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It will enable you to explore ray-casting.

### FPS (Frame Per Second)

    초당 프레임을 말한다.
    
    정지 사진 하나를 프레임이라 하고, 이런 사진 토막이 1초에 보이는 속도를 Frame Rate라고 한다.
    
    프레임률이라고도 하며, 단위로 fps를 사용한다.

### Ray-casting

    광선 투사로, 광선과 표면의 교차검사를 사용하는 기법을 말한다.
    
    광선 투사는 2D 지도에서 3D 관점을 만드는 렌더링 기술이다.
    
    ![raycasting1](./raycasting1.png)
    
    ![raycasting2](.raycasting2.png)
    
    reference : https://lodev.org/cgtutor/raycasting.html

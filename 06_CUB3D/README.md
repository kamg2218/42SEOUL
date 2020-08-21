## 06_CUB3D

### How to use Makefile

    make maps/map_name.cub
    
### How to make screenshot

    make maps/map_name.cub --save

### gcc flags

    BFLAGS : -Wall -Wextra -Werror
    
    CFLAGS : -L./mlx_opengl -lmlx -framework OpenGL -framework AppKit
    
    DFLAGS : -D BUFFER_SIZE=1024
    
    EFLAGS : -L./utils -lutils
    
    Memory leaks : -fsanitize=address

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
    
  <img src=".raycasting1.png" height="250px" width="250px">  <img src=".raycasting2.png" height="250px" width="250px">
    
    특정한 방향으로 광선을 쏘아 장애물을 만나는 지 확인하고 장애물까지의 거리를 구할 수 있다.
    
    플레이어의 시야를 60도로 정하고, 방향벡터를 이용하여 각도에 따른 장애물과 플레이어의 거리를 구한다.
    
    구한 거리를 이용하여 화면에 나타날 이미지의 길이를 결정할 수 있다.
    
   reference : https://lodev.org/cgtutor/raycasting.html

### Minilibx

   * minilibx : an easy way to create graphical software.
    
    mlx_init() : create void pointer mlx
    
    mlx_new_window(void *mlx, int width, int height, char *name) : create a new window on the screen, using width, height parameters to determine its size, and name as the text that should be displayed in the window's title bar.

    mlx_clear_window(void *mlx, void *win) : clear the given window.
    
    mlx_destroy_window(void *mlx, void *win) : destroy the given window.

    mlx_new_image(void *mlx, int width, int height) : create a new image in memory.
    
    mlx_put_image_to_window(void *mlx, void *win, void *img, int x, int y) : draw image and dump the image inside a window. x, y coordinates define where the image should be placed in the window.
    
    mlx_get_data_addr(void *img, int *pixel, int *size, int *endian) : it returns information about the created image, allowing a user to modify it later. pixel will be filled with the number of bits needed to represent a pixel color. size is the number of bytes used to store one line of the image in memory. endian tells you wether the pixel color in the pixel color in the image needs to be stored in (little, 0) or (big, 1).

    mlx_xpm_file_to_image(void *mlx, char *file, int *width, int *height): create a new image. minilibX does not use the standard xpm library to deal with xpm images.

    mlx_destroy_image(void *mlx, void *img) : destroys the given image.

    mlx_hook() : on key and mouse events, additional information is passed. keycode tells you which key is pressed.
    
    mlx_loop_hook(void *mlx, int (*funct)(), void *param) : it is identical to the previous ones, but the given function will be called when no event occurs.

    mlx_loop(void *mlx) : To handle keyboard or mouse events, it must be used. it never returns. It is infinite loop that waits for an event, and then calls a user-defined function associated with this event.
    
   reference : https://github.com/qst0/ft_libgfx //minilibX tutorial
    
### 지도 유효성 검사

    지도가 벽으로 둘러싸여있는 유효한 지도인지를 확인하고, 유효한 지도인 경우, 게임을 실행하고, 아닌 경우, 게임을 종료한다.
    
#### DFS (Depth-first Search, 깊이 우선 탐색)
   
  


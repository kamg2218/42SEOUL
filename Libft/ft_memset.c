#include <unistd.h>

void  *ft_memset(void *ptr, int value, size_t num){
  int   i;

  i = 0;
  while (i < num){
    *(unsigned char *)(ptr + i) = value;
    i++;
  }
  return (ptr);
}

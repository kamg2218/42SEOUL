void    *ft_memset(void *ptr, int value, unsigned int num){
  unsigned int  i;

  i = 0;
  while (i < num){
    *((unsigned char *)ptr + i) = value;
    i++;
  }
  return (ptr);
}

# Libft

   your very first own library

## ORDER

#### [Intro](#introduction)
#### [Mandatory](#mandatory-part) 
   ##### [part 1](#part-1---libc-functions)
   ##### [part 2](#part-2---additional-functions)
#### [Bonus](#bonus-part)

## Introduction

This project gives me the opportunity to re-write those functions, understand them, and learn to use them.

## Mandatory part

- Define these sub-functions as static to avoid publishing them with your library.
- Forbidden to use global variables.
- Use ar to create librairy, using the command lib tool is forbidden.

### Part 1 - Libc functions

Re-code a set of the libc functions, as defined in their man.

- memset

    void    \*ft_memset(void \*ptr, int value, size_t num);

- bzero

    void     ft_bzero(void \*s, size_t n);

- memcpy

    int    ft_memcpy(void *dst, const void \*source, size_t num);

- memccpy

    void    \*ft_memccpy(void \*dest, const void \*src, int c, size_t n);

- memmove

    void    \*ft_memmove(void \*dest, const void \*src, size_t n);

- memchr

    void    \*ft_memchr(const void \*s, int c, size_t n);

- memcmp

    void    \*ft_memcmp(const void \*ptr1, const void \*ptr2, size_t n);

- strlen

    size_t    ft_strlen(const char \*string);

- strlcpy

    size_t    ft_strlcpy(char \*dst, const char \*src, size_t n);

- strlcat

    size_t    ft_strlcat(char \*dst, const char \*src, size_t n);

- strchr

    char    \*ft_strchr(char \*str, int c);

- strrchr

    char    \*ft_strrchr(char \*str, int c);

- strnstr

    char    \*ft_strnstr(char \*str1, char \*str2, size_t n);

- strncmp

    int    ft_strncmp(const char \*str1, const char \*str2, size_t n);

- atoi

    int    ft_atoi(const char \*str);

- isalpha

    int    ft_isalpha(int c);

- isdigit

    int    ft_isdigit(int c);

- isalnum

    int    ft_isalnum(int c);

- isascii

    int    ft_isascii(int c);

- isprint

    int    ft_isprint(int c);

- toupper

    int    ft_toupper(int c);

- tolower

    int    ft_tolower(int c);

- calloc

    void    \*ft_calloc(size_t count, size_t size);

- strdup

    char    \*ft_strdup(const char \*s);

---

### Part 2 - Additional functions

- substr
    
    |Name|Contents|
    |:--:|:--|
    |Function name|ft_substr|
    |Prototype|char    \*ft_substr(char const \*s, unsigned int start, size_t len);|
    |Parameters| 1. The string from which to create the substring.\n 2. The start index of the substring in the string 's'.\n 3. The maximum length of the substring.|
    |Return value| The substring.\n NULL if the allocation fails.|
    |External functs.|malloc|
    |Description|Allocates (with malloc(3)) and returns a substring from the string 's'.\n The substring begins at index 'start' and is of maximum size 'len'.|

- strjoin

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_strjoin|
    |Prototype|char    \*ft_strjoin(char const \*s1, char const \*s2);|
    |Parameters| 1. The prefix string.\n 2. The suffix string.|
    |Return value| The new string.\n NULL if the allocation fails.|
    |External functs.|malloc|
    |Description|Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of 's1' and 's2'.|

- strtrim

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_strtrim|
    |Prototype|char    \*ft_strtrim(char const \*s1, char const \*set);|
    |Parameters| 1. The string to be trimmed.\n 2. The reference set of characters to trim.|
    |Return value| The trimmed string.\n NULL if the allocation fails.|
    |External functs.|malloc|
    |Description|Allocates (with malloc(3)) and returns a copy of 's1' with the characters specified in 'set' removed from the beginning and the end of the string.|

- split

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_split|
    |Prototype|char    \*\*ft_split(char const \*s, char c);|
    |Parameters| 1. The string to be split.\n 2. The delimiter character.|
    |Return value| The array of new strings resulting from the split.\n NULL if the allocation fails.|
    |External functs.|malloc, free|
    |Description|Allocates (with malloc(3)) and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter.\n The array must be ended by a NULL pointer.|

- itoa

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_itoa|
    |Prototype|char    \*ft_itoa(int n);|
    |Parameters| 1. The integer to convert.|
    |Return value| The string representing the integer.\n NULL if the allocation fails.|
    |External functs.|malloc|
    |Description|Allocates (with malloc(3)) and returns a string representing the integer received as an argument.\n Negative numbers must be handled.|

- strmapi

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_strmapi|
    |Prototype|char    \*ft_strmapi(char const \*s, char (\*f)(unsigned int, char));|
    |Parameters| 1. The string on which to iterate.\n 2. The function to apply to each character.|
    |Return value| The string created from the successive applications of 'f'.\n Returns NULL if the allocation fails.|
    |External functs.|malloc|
    |Description|Applies the function 'f' to each character of the string 's' to create a new string (with malloc(3)) resulting from successive applications of 'f'.|

- putchar_fd

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_putchar_fd|
    |Prototype|void ft_putchar_fd(char c, int fd);|
    |Parameters| 1. The character to output.\n 2. The file descriptor on which to write.|
    |Return value| None|
    |External functs.|write|
    |Description|Outputs the character 'c' to the given file descriptor.|

- putstr_fd

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_putstr_fd|
    |Prototype|void ft_putstr_fd(char \*s, int fd);|
    |Parameters| 1. The string to output.\n 2. The file descriptor on which to write.|
    |Return value| None|
    |External functs.|write|
    |Description|Outputs the string 's' to the given file descriptor.|

- putendl_fd

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_putendl_fd|
    |Prototype|void ft_putendl_fd(char \*s, int fd);|
    |Parameters| 1. The string to output.\n 2. The file descriptor on which to write.|
    |Return value| None|
    |External functs.|write|
    |Description|Outputs the string 's' to the given file descriptor, followed by a newline.|

- putnbr_fd

    |Name|Contents|
    |:--:|:--|
    |Function name|ft_putnbr_fd|
    |Prototype|void ft_putnbr_fd(int n, int fd);|
    |Parameters| 1. The integer to output.\n 2. The file descriptor on which to write.|
    |Return value| None|
    |External functs.|write|
    |Description|Outputs the integer 'n' to the given file descriptor.|


## Bonus part

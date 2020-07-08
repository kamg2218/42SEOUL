# Lift

Property: your very first own library

## Introduction

This project gives me the opportunity to re-write those functions, understand them, and learn to use them.

---

[Mandatory part](https://www.notion.so/960aee94b4ff4a648e19572ea5595a47)

- Define these sub-functions as static to avoid publishing them with your library.
- Forbidden to use global variables.
- Use ar to create librairy, using the command lib tool is forbidden.

### Part 1 - Libc functions

Re-code a set of the libc functions, as defined in their man.

- memset

    void    *ft_memset(void *ptr, int value, size_t num);

- bzero

    void     ft_bzero(void *s, size_t n);

- memcpy

    int    ft_memcpy(void *dst, const void *source, size_t num);

- memccpy

    void    *ft_memccpy(void *dest, const void *src, int c, size_t n);

- memmove

    void    *ft_memmove(void *dest, const void *src, size_t n);

- memchr

    void    *ft_memchr(const void *s, int c, size_t n);

- memcmp

    void    *ft_memcmp(const void *ptr1, const void *ptr2, size_t n);

- strlen

    size_t    ft_strlen(const char *string);

- strlcpy

    size_t    ft_strlcpy(char *dst, const char *src, size_t n);

- strlcat

    size_t    ft_strlcat(char *dst, const char *src, size_t n);

- strchr

    char    *ft_strchr(char *str, int c);

- strrchr

    char    *ft_strrchr(char *str, int c);

- strnstr

    char    *ft_strnstr(char *str1, char *str2, size_t n);

- strncmp

    int    ft_strncmp(const char *str1, const char *str2, size_t n);

- atoi

    int    ft_atoi(const char *str);

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

    void    *ft_calloc(size_t count, size_t size);

- strdup

    char    *ft_strdup(const char *s);

---

### Part 2 - Additional functions

[ft_substr](https://www.notion.so/358f099d7c90489a865134719da60fd1)

[ft_strjoin](https://www.notion.so/79fbb19d137f451483c6a05e0663eca1)
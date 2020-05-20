## FT_PRINTF

### Mandatory part

|Title|Contents|
|:---|:---|
|Program name|libftprintf.a|
|Turn in files|*.c, */*.c, *.h, */*.h, Makefile|
|Makefile|all, clean, fclean, re, bonus|
|External func|malloc, free, write, va_start, va_arg, va_copy, va_end|
|Libft authorized|yes|
|Description|Write a library that contains ft_printf, a function that will mimic the real printf|
|Prototype|ft_printf(const char *, ... );*|
|Type|cspdiuxX%|
|Flags|'-0.\*'|

### Bonus part

|Title|contents|
|:---|:---|
|Type|nfge|
|Length|l ll h hh|
|Flags|'# +'|

### Check Point

    * Type이 '%'인 경우, width, flags, precision의 값에 관계없이 '%'만 출력한다. (예외)
    * Type이 'p'인 경우, 주솟값이 0인 경우 고려해야 한다. (단, Moulinette은 확인하지 않는다.)
        - 값 = 0, precision = 0 : '0x' 출력
        - 값 = 0, precision 있음 : '0x0'과 앞, 뒤 공백 출력
        
    * Type이 's'인 경우, Flags '0'은 사용하지 않는다. (관련 에러는 Moulinette에서 확인하지 않는다.)

### Tester

[42TESTERS-PRINTF by Mazoise] : https://github.com/Mazoise/42TESTERS-PRINTF
[pft_2019 by cclaude42] : https://github.com/cclaude42/PFT_2019
[printf_lover by charMstr] : https://github.com/charMstr/printf_lover_v2

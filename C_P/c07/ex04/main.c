#include <stdlib.h>
#include <stdio.h>

int		ft_str_len(char *str);
int		ft_is_valid_base(char *str);
int		ft_find_num(char str, char *base);
int		ft_check_minus(char *str);
int		ft_atoi_base(char *str, char *base);
int		ft_sqrt(int nbr, int base_len);
char	*ft_strcat(char *dest, char *src);
char	*ft_putnbr_base(int nbr, char *base, char *fnbr);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int		main()
{
	char	nbr[20] = "101101";
	char	base_from[10] = "01";
	char	base_to[20] = "poneyvf";
	char	*str;

	str =  ft_convert_base(nbr, base_from, base_to);
	printf("%s\n", str);
	return (0);
}

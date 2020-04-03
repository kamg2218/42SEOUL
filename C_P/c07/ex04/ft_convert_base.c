#include <stdlib.h>

int		ft_str_len(char *str);
int		ft_is_valid_base(char *str);
int		ft_find_num(char str, char *base);
int		ft_check_minus(char *str);
int		ft_atoi_base(char *str, char *base);

int		ft_sqrt(int nbr, int base_len)
{
	int		i;

	i = 0;
	while (nbr)
	{	
		nbr /= base_len;
		i++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_putnbr_base(int nbr, char *base, char *fnbr)
{
	int		len;
	char	c_nbr;

	len = ft_str_len(base);
	if (nbr == -2147483648)
	{
		fnbr = ft_putnbr_base(nbr / len, base, fnbr);
		fnbr = ft_strcat(fnbr, &base[-1 * (nbr % len)]);
		return (fnbr);
	}
	else if (nbr < 0)
	{
		fnbr = ft_strcat(fnbr, "-");
		nbr = -nbr;
	}
	if (nbr >= len)
	{
		ft_putnbr_base(nbr / len, base, fnbr);
		c_nbr = base[nbr % len];
	}
	else
		c_nbr = base[nbr];
	fnbr = ft_strcat(fnbr, &c_nbr);
	return (fnbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	int		len;
	int		base_len;
	char	*final_nbr;

	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from);
	base_len = ft_str_len(base_to);
	len = ft_sqrt(num, base_len);
	final_nbr = (char*)malloc(sizeof(char) * (len + 1));
	if (final_nbr == NULL)
		return (0);
	final_nbr = ft_putnbr_base(num, base_to, final_nbr);
	return (final_nbr);
}

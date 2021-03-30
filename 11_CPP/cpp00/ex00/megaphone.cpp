#include <iostream>
#include <cstring>
#include <cctype>

int			main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		len;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		len = strlen(argv[i]);
		for (j = 0; j < len; j++)
			std::cout << (char)toupper(argv[i][j]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}

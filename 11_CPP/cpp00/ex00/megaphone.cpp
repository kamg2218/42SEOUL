#include <iostream>
#include <cstring>
#include <cctype>

int			main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		len;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (i > 1)
			std::cout << " ";
		len = strlen(argv[i]);
		for (j = 0; j < len; j++)
			std::cout << (char)toupper(argv[i][j]);
		i++;
	}
	std::cout << std::endl;
	return (0);
}

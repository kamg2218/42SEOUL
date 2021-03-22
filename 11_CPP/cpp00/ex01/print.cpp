#include "phonebook.hpp"

void		put_char(std::string str, int cnt)
{
	for (int i = 0; i < cnt; i++)
		std::cout << str;
}

void		put_empty(void)
{
	put_char("-", 50);
	std::cout << std::endl;
	std::cout << "|";
	put_char(" ", 19);
	std::cout << "IT'S EMPTY";
	put_char(" ", 19);
	std::cout << "|" << std::endl;
	put_char("-", 50);
	std::cout << std::endl;
}

void		put_full(void)
{
	put_char("-", 50);
	std::cout << std::endl;
	std::cout << "|";
	put_char(" ", 13);
	std::cout << "THERE IS NO MORE SPACE";
	put_char(" ", 13);
	std::cout << "|" << std::endl;
	put_char("-", 50);
	std::cout << std::endl;
}

void		put_string(int start, int end, int count, phonebook book[8])
{
	int		i;

	if (count == 0)
		return (put_empty());
	put_char("-", 50);
	std::cout << std::endl;
	std::cout << "|";
	put_char(" ", 18);
	std::cout << "MY PHONEBOOK";
	put_char(" ", 18);
	std::cout << "|" << std::endl;
	put_char("-", 50);
	std::cout << std::endl;
	for (i = start; i <= end; i++)
	{
		std::cout << "| " << i << " |   ";
		book[i].put_str();
		std::cout << " |" << std::endl;
	}
	put_char("-", 50);
	std::cout << std::endl;
}

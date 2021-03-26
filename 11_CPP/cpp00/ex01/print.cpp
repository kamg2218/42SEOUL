#include "phonebook.hpp"

void		put_char(std::string str, int cnt)
{
	for (int i = 0; i < cnt; i++)
		std::cout << str;
}

void		put_empty(void)
{
	put_char("-", 53);
	std::cout << std::endl;
	std::cout << "|";
	put_char(" ", 21);
	std::cout << "IT'S EMPTY";
	put_char(" ", 20);
	std::cout << "|" << std::endl;
	put_char("-", 53);
	std::cout << std::endl;
}

void		put_full(void)
{
	put_char("-", 53);
	std::cout << std::endl;
	std::cout << "|";
	put_char(" ", 15);
	std::cout << "THERE IS NO MORE SPACE";
	put_char(" ", 14);
	std::cout << "|" << std::endl;
	put_char("-", 53);
	std::cout << std::endl;
}

void		put_phonebook(int start, int end, int count, phonebook book[8])
{
	int		i;

	if (count == 0)
		return (put_empty());
	put_char("-", 53);
	std::cout << std::endl;
	std::cout << "|";
	put_char(" ", 20);
	std::cout << "MY PHONEBOOK";
	put_char(" ", 19);
	std::cout << "|" << std::endl;
	put_char("-", 53);
	std::cout << std::endl;
	for (i = start; i <= end; i++)
	{
		std::cout << "| ";
		book[i].put_ten(std::to_string(i));
		std::cout << " | ";
		book[i].put_str();
		std::cout << " |" << std::endl;
	}
	put_char("-", 53);
	std::cout << std::endl;
}

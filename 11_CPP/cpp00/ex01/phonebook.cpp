#include "phonebook.hpp"

int			check_command(std::string cmd)
{
	if (cmd.compare("ADD") == 0)
		return (1);
	else if (cmd.compare("SEARCH") == 0)
		return (2);
	else if (cmd.compare("EXIT") == 0)
		return (-1);
	return (0);
}

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

void		find_string(std::string search, int count, phonebook book[8])
{
	int			i;
	std::string	name;

	std::cout << search << " : ";
	std::cin >> name;
	for (i = 0; i < count ; i++)
	{
		if (book[i].find_idx(search, name))
		{
			put_string(i, i, count, book);
			return ;
		}
	}
	std::cout << "IT DOESN NOT EXIST : " << name << std::endl;
}

int			do_search(int count, phonebook book[8])
{
	int			idx;
	std::string	search;

	std::cout << "Search with (ex> index, firstname, lastname, nickname, all): ";
	std::cin >> search;
	if (search.compare("all") == 0)
		put_string(0, count - 1, count, book);
	else if (search.compare("index") == 0)
	{
		std::cout << "0 ~ " << count - 1 << ": ";
		std::cin >> idx;
		put_string(idx, idx, count, book);
	}
	else if (search.compare("first") == 0 || search.compare("firstname") == 0)
		find_string("first_name", count, book);
	else if (search.compare("last") == 0 || search.compare("lastname") == 0)
		find_string("last_name", count, book);
	else if (search.compare("nick") == 0 || search.compare("nickname") == 0)
		find_string("nickname", count, book);
	else
		return (1);
	return (0);
}

int			do_command(int ret, phonebook book[8], int count)
{
	if (ret == 0)
		std::cout << "ADD, SEARCH, EXIT commands only" << std::endl;
	else if (ret == 1)
	{
		if (count == 8)
		{
			put_full();
			return (0);
		}
		book[count].get_str();
		return (1);
	}
	else if (ret == 2)
	{
		if (count == 0)
		{
			put_empty();
			return (0);
		}
		if (do_search(count, book))
			do_command(ret, book, count);
	}
	return (0);
}

int			main(void)
{
	phonebook	book[8];
	int			ret;
	int			count;
	std::string	cmd;

	count = 0;
	while (1)
	{
		std::cout << "COMMAND(ex> ADD, SEARCH, EXIT) : ";
		std::cin >> cmd;
		ret = check_command(cmd);
		if (ret == -1)
			break ;
		count += do_command(ret, book, count);
	}
	return (0);
}

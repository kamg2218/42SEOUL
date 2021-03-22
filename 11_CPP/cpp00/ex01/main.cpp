#include "phonebook.hpp"

int			check_command(std::string cmd)
{
	if (cmd.compare("ADD") == 0 || cmd.compare("add") == 0)
		return (1);
	else if (cmd.compare("SEARCH") == 0 || cmd.compare("search") == 0)
		return (2);
	else if (cmd.compare("EXIT") == 0 || cmd.compare("exit") == 0)
		return (-1);
	return (0);
}

void		find_string(std::string search, int count, phonebook book[8])
{
	int			i;
	int			cnt;
	std::string	name;

	std::cout << search << " : ";
	std::cin >> name;
	cnt = 0;
	for (i = 0; i < count ; i++)
	{
		if (book[i].find_idx(search, name))
		{
			put_string(i, i, count, book);
			cnt++;
		}
	}
	if (cnt == 0)
		std::cout << "ERROR : IT DOES NOT EXIST : " << name << std::endl;
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
		if (idx >= count)
		{
			std::cout << "ERROR: IT DOES NOT EXIST" << std::endl;
			return (0);
		}
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
		std::cout << "ERROR: ADD, SEARCH, EXIT commands only" << std::endl;
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

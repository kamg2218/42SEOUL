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
	std::getline(std::cin, name, '\n');
	cnt = 0;
	for (i = 0; i < count ; i++)
	{
		if (book[i].find_idx(search, name))
		{
			put_char("-", 53);
			std::cout << std::endl;
			book[i].put_info();
			cnt++;
		}
	}
	if (cnt == 0)
		std::cout << "ERROR : IT DOES NOT EXIST : " << name << std::endl;
	else
	{
		put_char("-", 53);
		std::cout << std::endl;
	}
}

int			do_search(int count, phonebook book[8])
{
	int			idx;
	std::string	search;

	std::cout << "Search with (ex> index, firstname, lastname, nickname): ";
	std::getline(std::cin, search, '\n');
	if (search.compare("index") == 0)
	{
		std::cout << "index : ";
		std::cin >> idx;
		std::cin.ignore(1, '\n');
		if (idx >= count)
			std::cout << "ERROR: IT DOES NOT EXIST" << std::endl;
		else
		{
			put_char("-", 53);
			std::cout << std::endl;
			book[idx].put_info();
			put_char("-", 53);
			std::cout << std::endl;
		}
	}
	else if (search.compare("first") == 0 || search.compare("firstname") == 0)
		find_string("first_name", count, book);
	else if (search.compare("last") == 0 || search.compare("lastname") == 0)
		find_string("last_name", count, book);
	else if (search.compare("nick") == 0 || search.compare("nickname") == 0)
		find_string("nickname", count, book);
	else
		do_search(count, book);
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
		put_phonebook(0, count - 1, count, book);
		do_search(count, book);
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
		std::getline(std::cin, cmd, '\n');
		ret = check_command(cmd);
		if (ret == -1)
			break ;
		count += do_command(ret, book, count);
	}
	return (0);
}

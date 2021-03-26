#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class phonebook
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	login;
		std::string	postal_address;
		std::string	email_address;
		std::string	phone_number;
		std::string	birthday_date;
		std::string	favorite_meal;
		std::string	underwear_color;
		std::string	darkest_secret;
	public:
		void	put_str();
		void	put_info();
		void	put_ten(std::string name);
		int		get_str();
		int		find_idx(std::string name, std::string cnt);
};

//print.cpp
void	put_full(void);
void	put_empty(void);
void	put_char(std::string str, int cnt);
void	put_phonebook(int start, int end, int count, phonebook book[8]);

//main.cpp
int		check_command(std::string cmd);
int		do_search(int count, phonebook book[8]);
int		do_command(int ret, phonebook book[8], int count);
void	find_string(std::string search, int count, phonebook book[8]);

#endif

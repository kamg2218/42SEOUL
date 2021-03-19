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
		void get_str()
		{
			std::cout << "frist name : ";
			std::cin >> first_name;
			std::cout << "last name : ";
			std::cin >> last_name;
			std::cout << "nickname : ";
			std::cin >> nickname;
			std::cout << "login : ";
			std::cin >> login;
			std::cout << "postal address : ";
			std::cin >> postal_address;
			std::cout << "email address : ";
			std::cin >> email_address;
			std::cout << "phone number : ";
			std::cin >> phone_number;
			std::cout << "birthday date : ";
			std::cin >> birthday_date;
			std::cout << "favorite meal : ";
			std::cin >> favorite_meal;
			std::cout << "underwear color : ";
			std::cin >> underwear_color;
			std::cout << "darkest secret : ";
			std::cin >> darkest_secret;
		}

		void put_ten(std::string name)
		{
			if (name.size() < 10)
				std::cout << std::setw(10);
			std::cout << name.substr(0, 9);
			if (name.size() > 10)
				std::cout << ".";
		}

		void put_str()
		{
			put_ten(first_name);
			std::cout << " |   ";
			put_ten(last_name);
			std::cout << " |   ";
			put_ten(nickname);
		}

		int	find_idx(std::string name, std::string cnt)
		{
			if ((name.compare("first_name") == 0 && first_name.compare(cnt) == 0)
					|| (name.compare("last_name") == 0 && last_name.compare(cnt) == 0)
					|| (name.compare("nickname") == 0 && nickname.compare(cnt) == 0))
				return (1);
			return (0);
		}
};

#endif

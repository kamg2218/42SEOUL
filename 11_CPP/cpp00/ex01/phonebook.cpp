#include "phonebook.hpp"

void	phonebook::get_str()
{
	std::cout << "frist name : ";
	std::getline(std::cin, first_name, '\n');
	std::cout << "last name : ";
	std::getline(std::cin, last_name, '\n');
	std::cout << "nickname : ";
	std::getline(std::cin, nickname, '\n');
	std::cout << "login : ";
	std::getline(std::cin, login, '\n');
	std::cout << "postal address : ";
	std::getline(std::cin, postal_address, '\n');
	std::cout << "email address : ";
	std::getline(std::cin, email_address, '\n');
	std::cout << "phone number : ";
	std::getline(std::cin, phone_number, '\n');
	std::cout << "birthday date : ";
	std::getline(std::cin, birthday_date, '\n');
	std::cout << "favorite meal : ";
	std::getline(std::cin, favorite_meal, '\n');
	std::cout << "underwear color : ";
	std::getline(std::cin, underwear_color, '\n');
	std::cout << "darkest secret : ";
	std::getline(std::cin, darkest_secret, '\n');
}

void	phonebook::put_info()
{
	std::cout << "frist name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "login : " << login << std::endl;
	std::cout << "postal address : " << postal_address << std::endl;
	std::cout << "email address : " << email_address << std::endl;
	std::cout << "phone number : " << phone_number << std::endl;
	std::cout << "birthday date : " << birthday_date << std::endl;
	std::cout << "favorite meal : " << favorite_meal << std::endl;
	std::cout << "underwear color : " << underwear_color << std::endl;
	std::cout << "darkest secret : " << darkest_secret << std::endl;
}

void	phonebook::put_ten(std::string name)
{
	if (name.size() <= 10)
	{
		std::cout << std::setw(10);
		std::cout << name;
	}
	else
	{
		std::cout << name.substr(0, 9);
		std::cout << ".";
	}
}

void	phonebook::put_str()
{
	put_ten(first_name);
	std::cout << " | ";
	put_ten(last_name);
	std::cout << " | ";
	put_ten(nickname);
}

int		phonebook::find_idx(std::string name, std::string cnt)
{
	if ((name.compare("first_name") == 0 && first_name.compare(cnt) == 0)
			|| (name.compare("last_name") == 0 && last_name.compare(cnt) == 0)
			|| (name.compare("nickname") == 0 && nickname.compare(cnt) == 0))
		return (1);
	return (0);
}

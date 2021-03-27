#include "phonebook.hpp"

int		phonebook::get_str()
{
	std::cout << "frist name : ";
	if ((std::getline(std::cin, first_name, '\n')) == 0)
		return (1);
	std::cout << "last name : ";
	if ((std::getline(std::cin, last_name, '\n')) == 0)
		return (1);
	std::cout << "nickname : ";
	if ((std::getline(std::cin, nickname, '\n')) == 0)
		return (1);
	if (!first_name.compare("") && !last_name.compare("")
			&& !nickname.compare(""))
	{
		std::cout << "Please put the names more than one of them!" << std::endl;
		return (1);
	}
	std::cout << "login : ";
	if ((std::getline(std::cin, login, '\n')) == 0)
		return (1);
	std::cout << "postal address : ";
	if ((std::getline(std::cin, postal_address, '\n')) == 0)
		return (1);
	std::cout << "email address : ";
	if ((std::getline(std::cin, email_address, '\n')) == 0)
		return (1);
	std::cout << "phone number : ";
	if ((std::getline(std::cin, phone_number, '\n')) == 0)
		return (1);
	std::cout << "birthday date : ";
	if ((std::getline(std::cin, birthday_date, '\n')) == 0)
		return (1);
	std::cout << "favorite meal : ";
	if ((std::getline(std::cin, favorite_meal, '\n')) == 0)
		return (1);
	std::cout << "underwear color : ";
	if ((std::getline(std::cin, underwear_color, '\n')) == 0)
		return (1);
	std::cout << "darkest secret : ";
	if ((std::getline(std::cin, darkest_secret, '\n')) == 0)
		return (1);
	return (0);
}

void	phonebook::put_info()
{
	if (first_name.compare(""))
		std::cout << "frist name : " << first_name << std::endl;
	if (last_name.compare(""))
		std::cout << "last name : " << last_name << std::endl;
	if (nickname.compare(""))
		std::cout << "nickname : " << nickname << std::endl;
	if (login.compare(""))
		std::cout << "login : " << login << std::endl;
	if (postal_address.compare(""))
		std::cout << "postal address : " << postal_address << std::endl;
	if (email_address.compare(""))
		std::cout << "email address : " << email_address << std::endl;
	if (phone_number.compare(""))
		std::cout << "phone number : " << phone_number << std::endl;
	if (birthday_date.compare(""))
		std::cout << "birthday date : " << birthday_date << std::endl;
	if (favorite_meal.compare(""))
		std::cout << "favorite meal : " << favorite_meal << std::endl;
	if (underwear_color.compare(""))
		std::cout << "underwear color : " << underwear_color << std::endl;
	if (darkest_secret.compare(""))
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

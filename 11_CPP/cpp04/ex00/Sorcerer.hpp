#ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostram>
#include <string>

class	Sorcerer
{
	private:
		std::string		m_name;
		std::string		m_title;
	public:
		Sorcerer();
		Sorcerer(std::string name, std::string title);
		Sorcerer&	operator=(Sorcerer const &scr);
		~Sorcerer();
};

#endif

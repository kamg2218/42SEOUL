#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"

class	Sorcerer
{
	private:
		std::string		m_name;
		std::string		m_title;
		Sorcerer();
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer&	operator=(Sorcerer const &scr);
		void		introduce();
		void		polymorph(Victim const &vt);
		std::string	getName() const;
		std::string	getTitle() const;
		~Sorcerer();
};

std::ostream&	operator<<(std::ostream& os, Sorcerer const &scr);

#endif

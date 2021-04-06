#ifndef LABORER_HPP
# define LABORER_HPP

//#include <iostream>
//#include <string>
#include "Peon.hpp"

class	Laborer : public Peon
{
	private:
		std::string		m_name;
		Laborer();
	public:
		Laborer(std::string name);
		Laborer&	operator=(Laborer const &lb);
		void		introduce();
		void		getPolymorphed() const;
		std::string	getName() const;
		~Laborer();
};

std::ostream&	operator<<(std::ostream& os, Laborer const &lb);

#endif

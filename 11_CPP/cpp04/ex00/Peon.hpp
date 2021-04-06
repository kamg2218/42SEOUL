#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"

class	Peon : public Victim
{
	private:
		std::string		m_name;
		//Peon();
	public:
		Peon();
		Peon(std::string name);
		Peon&	operator=(Peon const &pn);
		void		introduce();
		void		getPolymorphed() const;
		std::string	getName() const;
		~Peon();
};

std::ostream&	operator<<(std::ostream& os, Peon const &pn);

#endif

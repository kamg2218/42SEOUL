#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>

class	Victim
{
	private:
		std::string		m_name;
	public:
		Victim();
		Victim(std::string name);
		Victim&	operator=(Victim const &vt);
		void		introduce();
		virtual void		getPolymorphed() const;
		std::string	getName() const;
		~Victim();
};

std::ostream&	operator<<(std::ostream& os, Victim const &vt);

#endif

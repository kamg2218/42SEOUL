#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>

class	Victim
{
	protected:
		std::string		m_name;
	private:
		Victim();
	public:
		Victim(std::string name);
		Victim&	operator=(Victim const &vt);
		virtual void		getPolymorphed() const;
		std::string	getName() const;
		~Victim();
};

std::ostream&	operator<<(std::ostream& os, Victim const &vt);

#endif

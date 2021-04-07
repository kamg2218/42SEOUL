#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class	Squad : public ISquad
{
	private:
		int				m_count;
		ISpaceMarine**	m_ispm;
	public:
		Squad();
		Squad(Squad const &sqd);
		Squad&	operator=(Squad const &sqd);
		virtual ~Squad();
		virtual int getCount() const;
		virtual ISpaceMarine* getUnit(int n) const;
		virtual int push(ISpaceMarine* ispm);
};

#endif

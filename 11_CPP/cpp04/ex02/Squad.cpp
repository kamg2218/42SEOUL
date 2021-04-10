#include "Squad.hpp"

Squad::Squad()
	: m_count(0), m_ispm(0)
{
}

Squad::Squad(Squad const &sqd)
{
	*this = sqd;
}

Squad&	Squad::operator=(Squad const &sqd)
{
	if (m_count && m_ispm)
	{
		for (int i = 0; i < m_count; i++)
			delete m_ispm[i];
		delete[] m_ispm;
	}
	this->m_count = sqd.m_count;
	this->m_ispm = new ISpaceMarine*[m_count];
	for (int i = 0; i < m_count; i++)
		m_ispm[i] = sqd.getUnit(i)->clone();
	return *this;
}

Squad::~Squad()
{
	for (int i = 0; i < m_count; i++)
		delete m_ispm[i];
	delete[] m_ispm;
}

int Squad::getCount() const { return m_count; }

ISpaceMarine*	Squad::getUnit(int n) const
{
	if (n >= m_count || m_ispm == NULL)
		return NULL;
	return m_ispm[n];
}

int		Squad::push(ISpaceMarine* ispm)
{
	ISpaceMarine** tmp;
	
	m_count += 1;
	tmp = new ISpaceMarine*[m_count];
	for (int i = 0; i < m_count - 1; i++)
		tmp[i] = m_ispm[i];
	tmp[m_count - 1] = ispm;
	if (m_ispm)
		delete[] m_ispm;
	m_ispm = tmp;
	return m_count;
}

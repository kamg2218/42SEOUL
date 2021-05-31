template <class T, class Container = std::deque<T> >
class	stack{
protected:
	Container									c;
public:
	typedef Container							container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	typedef typename Container::reference		reference;
	typedef typename Container::const_reference	const_reference;
	explicit stack(const Container& cont = Container()) {}
	stack(const stack& other) { *this = other; }
	stack&		operator=(stack const &st);
	~stack();
	const Container	getContainer() const;
	reference	top();
	bool		empty() const;
	size_type	size() const;
	void		push(const value_type& value);
	void		pop();
	void		swap(stack& other);
};
//#include "./stack.hpp"
//constructor
//template <class T, class Container = std::deque<T> >
//stack<T>(const Container& cont = Container()) { }

//template <class T, class Container = std::deque<T> >
//stack<T>(const stack<T>& other) { *this = other; }

template <class T, class Container = std::deque<T> >
stack<T>&		operator=(stack<T> const &st) {
	if (&st == this)
		return *this;
	this->c = st.c;
	return *this;
}

template <class T, class Container = std::deque<T> >
~stack<T>() {}

template <class T, class Container = std::deque<T> >
const Container	stack<T>::getContainer() const { return c; }

//access
template <class T, class Container = std::deque<T> >
reference	stack<T>::top() { return c.back(); }

//capacity
template <class T, class Container = std::deque<T> >
bool		stack<T>::empty() const { if (c.empty()) return true; else return false;}
template <class T, class Container = std::deque<T> >
size_type	stack<T>::size() const { return c.size(); }

//modifiers
template <class T, class Container = std::deque<T> >
void		stack<T>::push(const value_type& value) { c.push_back(value); }
template <class T, class Container = std::deque<T> >
void		stack<T>::pop() { c.pop_back(); }
template <class T, class Container = std::deque<T> >
void		stack<T>::swap(stack<T>& other) { c.swap(other.c); }

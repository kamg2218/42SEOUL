//constructor
template <class T, class Container = std::deque<T> >
ft::stack<T>(const Container& cont = Container()) { }

template <class T, class Container = std::deque<T> >
ft::stack<T>(const ft::stack<T>& other) { *this = other; }

template <class T, class Container = std::deque<T> >
ft::stack<T>&		operator=(ft::stack<T> const &st) {
	if (&st == this)
		return *this;
	this->c = st.c;
	return *this;
}

template <class T, class Container = std::deque<T> >
~ft::stack<T>() {}

template <class T, class Container = std::deque<T> >
const Container	ft::stack<T>::getContainer() const { return c; }

//access
template <class T, class Container = std::deque<T> >
reference	ft::stack<T>::top() { return c.back(); }

//capacity
template <class T, class Container = std::deque<T> >
bool		ft::stack<T>::empty() const { if (c.empty()) return true; else return false;}
template <class T, class Container = std::deque<T> >
size_type	ft::stack<T>::size() const { return c.size(); }

//modifiers
template <class T, class Container = std::deque<T> >
void		ft::stack<T>::push(const value_type& value) { c.push_back(value); }
template <class T, class Container = std::deque<T> >
void		ft::stack<T>::pop() { c.pop_back(); }
template <class T, class Container = std::deque<T> >
void		ft::stack<T>::swap(stack& other) { c.swap(other.c); }

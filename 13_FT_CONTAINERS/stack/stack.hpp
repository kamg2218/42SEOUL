//constructor
stack(const Container& cont = Container()) { }

stack(const stack& other) { *this = other; }

stack&	operator=(stack const &st) {
	if (&st == this)
		return *this;
	this->c = st.c;
	return *this;
}

~stack() {}

const Container		getContainer() const { return c; }

//access
reference	top() { return c.back(); }

//capacity
bool		empty() const { if (c.empty()) return true; else return false;}
size_type	size() const { return c.size(); }

//modifiers
void		push(const value_type& value) { c.push_back(value); }
void		pop() { c.pop_back(); }
void		swap(stack& other) { c.swap(other.c); }

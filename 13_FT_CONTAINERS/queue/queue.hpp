//constructor
explicit queue(const Container& cont = Container()) {}

queue(const queue& other) { *this = other; }

queue&		operator=(queue const &st) {
	if (&st == this)
		return *this;
	this->c = st.c;
	return *this;
}

~queue() {}

const Container	getContainer() const { return c; }

//access
reference	front() { return c.front(); }
reference	back() { return c.back(); }

//capacity
bool		empty() const { if (c.empty()) return true; else return false;}
size_type	size() const { return c.size(); }

//modifiers
void		push(const value_type& value) { c.push_back(value); }
void		pop() { c.pop_front(); }
void		swap(queue& other) { c.swap(other.c); }

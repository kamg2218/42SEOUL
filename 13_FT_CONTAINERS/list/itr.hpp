Iterator() : ptr(0) {}
Iterator(node<T>* const p) : ptr(p) {}
Iterator(Iterator const &it) { *this = it; }

Iterator&	operator=(Iterator const &it){
	if (&it == this)
		return *this;
	this->ptr = it.ptr;
	return *this;
}

~Iterator() {}

Iterator&		operator++(){
	this->ptr = this->ptr->next;
	return *this;
}

Iterator&		operator++(int){
	this->ptr = this->ptr->next;
	return *this;
}

Iterator&		operator--(){
	this->ptr = this->prt->prev;
	return *this;
}

Iterator&		operator--(int){
	this->ptr = this->prt->prev;
	return *this;
}

reference	operator*() const { return getValue(); }
reference	operator->() const { return getValue(); }
reference	getValue() const { return *(ptr->value); }

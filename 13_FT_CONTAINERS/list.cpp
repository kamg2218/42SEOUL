#include "ft.hpp"

template <class T, class Allocator>
template <typename InputIt>
typename ft::list<T, Allocator>::iterator ft::list<T, al>::name()
{
}

template <class T, class Allocator = std::allocator<T> >
{
	ft::list::list() : size(0) { head = al.allocate(0); }
	ft::list::list(const list& other) { *this = other; }

	list&	ft::list::operator=(list const &lst) {
		size = lst.size;
		head = al.allocate(size);
		for (size_type i = 0; i < size; i++)
			head[i] = lst.head[i];
		return *this;
	}

	explicit ft::list::list(const Allocator& alloc) : size(0) { 
		al = alloc;
		head = al.allocate(0);
	}

	explicit ft::list::list(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : size(count) {
		al = alloc;
		head = al.allocate(count);
		for (size_type i = 0; i < count; i++)
			head[i] = value;
	}

	template<class InputIt>
	ft::list::list(InputIt first, InputIt last, const Allocator& alloc = Allocator()) {
		size = last - first;
		al = alloc;
		head = al.allocate(size);
		for (InputIt i = first; i != last; i++)
			head[i - first] = *i;
}

ft::list::~list() { 
	std::cout << "destructor\n";
	al.deallocate(head, head[0]);
}

void	ft::list::assign(size_type count, const T& value){
	size = count;
	al.deallocate(head, head[0]);
	head = al.allocate(count);
	for (size_type i = 0; i < count; i++)
		head[i] = value;
}

template<class InputIt>
void	ft::list::assign(InputIt first, InputIt last){
	std::cout << "< last all >\n";
	size = last - first;
	al.deallocate(head, head[0]);
	head = al.allocate(size);
	for (size_type i = 0; i < size; i++)
		head[i] = first++;
}

template<>
void	ft::list::assign(typename std::list<T>::iterator first, typename std::list<T>::iterator last){
	std::cout << "< iterator >" << std::endl;
	size = 0;
	for (typename std::list<T>::iterator i = first; i != last; i++)
		size++;
	al.deallocate(head, head[0]);
	head = al.allocate(size);
	for (size_type i = 0; i < size; i++, first++)
		head[i] = *first;
}

template<>
void	ft::list::assign(T* first, T* last){
	std::cout << "< pointer >\n";
	size = last - first;
	al.deallocate(head, head[0]);
	head = al.allocate(size);
	for (size_type i = 0; i < size; i++, first++)
		head[i] = *first;
}
};

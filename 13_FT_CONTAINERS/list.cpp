#include "ft.hpp"
/*
template<class T, class Allocator>
ft::list<T, Allocator>::list() : size(0){
	head = al.allocate(0);
}

template<class T, class Allocator>
ft::list<T, Allocator>::list(const list& other) { *this = other; }

template<class T, class Allocator>
ft::list<T, Allocator>&	ft::list<T, Allocator>::operator=(list<T, Allocator> const &lst) {
	size = lst.size;
	head = al.allocate(size);
	for (size_type i = 0; i < size; i++)
		head[i] = lst.head[i];
	return *this;
}

template<class T, class Allocator>
ft::list<T, Allocator>::list(const Allocator& alloc) : size(0) { 
	al = alloc;
	head = al.allocate(0);
}

template<class T, class Allocator>
ft::list<T, Allocator>::list(size_type count, const T& value, const Allocator& alloc) : size(count) {
	al = alloc;
	head = al.allocate(count);
	for (size_type i = 0; i < count; i++)
		head[i] = value;
}

template <class T, class Allocator>
template<class InputIt>
ft::list<T, Allocator>::list(InputIt first, InputIt last, const Allocator& alloc) {
		size = last - first;
		al = alloc;
		head = al.allocate(size);
		for (InputIt i = first; i != last; i++)
			head[i - first] = *i;
}

template <class T, class Allocator>
ft::list<T, Allocator>::~list() { 
	std::cout << "destructor\n";
	al.deallocate(head, head[0]);
}

template <class T, class Allocator>
void	ft::list<T, Allocator>::assign(size_type count, const T& value){
	size = count;
	al.deallocate(head, head[0]);
	head = al.allocate(count);
	for (size_type i = 0; i < count; i++)
		head[i] = value;
}

template<class T, class Allocator>
template<class InputIt>
void	ft::list<T, Allocator>::assign(InputIt first, InputIt last){
	std::cout << "< last all >\n";
	size = last - first;
	al.deallocate(head, head[0]);
	head = al.allocate(size);
	for (size_type i = 0; i < size; i++)
		head[i] = first++;
}

template<class T, class Allocator>
void	ft::list<T, Allocator>::assign<std::list<T>::iterator>(typename std::list<T>::iterator first, typename std::list<T>::iterator last){
	std::cout << "< iterator >" << std::endl;
	size = 0;
	for (typename std::list<T>::iterator i = first; i != last; i++)
		size++;
	al.deallocate(head, head[0]);
	head = al.allocate(size);
	for (size_type i = 0; i < size; i++, first++)
		head[i] = *first;
}

template<class T, class Allocator>
void	ft::list<T, Allocator>::assign<T*>(T* first, T* last){
	std::cout << "< pointer >\n";
	size = last - first;
	al.deallocate(head, head[0]);
	head = al.allocate(size);
	for (size_type i = 0; i < size; i++, first++)
		head[i] = *first;
}*/

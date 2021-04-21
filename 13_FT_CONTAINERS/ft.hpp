#ifndef FT_HPP
# define FT_HPP

#include <iostream>
#include <memory>
#include <typeinfo>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class	list {
	public:
		Allocator							al;
		T*									head;
		size_t								size;
		typedef	T 							value_type;
		typedef Allocator					allocator_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename Allocator::const_reference	const_reference;
		//typedef bidirectionalIterator		iterator;
		//typedef bidirectionalIterator		const_iterator;
		//typedef bidirectionalIterator		reverse_iterator;
		//typedef bidirectionalIterator		const_reverse_iterator;
		//constructor
		list() : size(0) { head = al.allocate(0); }
		list(const list& other) { *this = other; }
		list&	operator=(list const &lst) {
			//if (size > 0)
			//	al.deallocate(head, head[0]);
			size = lst.size;
			head = al.allocate(size);
			for (size_type i = 0; i < size; i++)
				head[i] = lst.head[i];
			return *this;
		}
		explicit list(const Allocator& alloc) : size(0) { head = const_cast<Allocator&>(alloc).allocate(0); }
		explicit list(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) : size(count) {
			head = alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
				head[i] = value;
		}
		template<class InputIt> list(InputIt first, InputIt last, const Allocator& alloc = Allocator()) {
			size = last - first;
			head = const_cast<Allocator&>(alloc).allocate(size);
			for (InputIt i = first; i != last; i++)
				head[i - first] = *i;
		}
		~list() { std::cout << "destructor\n";
			al.deallocate(head, head[0]);}
		void	assign(size_type count, const T& value){
			size = count;
			al.deallocate(head, head[0]);
			head = al.allocate(count);
			for (size_type i = 0; i < count; i++)
				head[i] = value;
		}
		template<class InputIt>
		void	assign(InputIt first, InputIt last){
			std::cout << sizeof(first) << ", " << sizeof(int) << std::endl;
			al.deallocate(head, head[0]);
			//size = last - first;
			size = 0;
			for (InputIt i = first; i != last; i++)
				size++;
			head = const_cast<Allocator&>(al).allocate(size);
			std::cout << "typeid = " << typeid(first).name() << std::endl;
			if (typeid(size_type).name() == typeid(InputIt).name())
				std::cout << "size_type = " << typeid(size_type).name() << "\n";
			if (typeid(value_type).name() == typeid(InputIt).name())
				std::cout << "value_type = " << typeid(value_type).name() << "\n";
			else
				std::cout << "else = " << typeid(InputIt).name() << "\n";
	
			if (typeid(value_type).name() == typeid(InputIt).name()){
				std::cout << "same\n";
			}
			else{
				std::cout << "different\n";
				T*	tmp = head;
				for (InputIt i = first; i != last; i++, tmp++)
					*tmp = *i;
			}
		
		}
		//allocator_type	get_allocator() const {}
	};
}

#endif

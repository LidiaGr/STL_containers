//
// Created by Lidia Grigoreva on 03/02/2021.
//

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

	template <class T, class Container = vector<T> >
	class stack {

	public:
		/**** Member types ****/
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		container_type _ctnr;

	public:
		/**** Constructor ****/
		explicit stack (const container_type& ctnr = container_type()) :_ctnr(ctnr) {};

		/****  Member functions ****/
		bool empty() const { return _ctnr.empty(); };
		size_type size() const { return _ctnr.size(); };

		value_type& top() { return _ctnr.back(); };
		const value_type& top() const { return _ctnr.back(); };

		void push (const value_type& val) { _ctnr.push_back(val); };
		void pop() { _ctnr.pop_back(); };

		container_type getCtnr() const { return _ctnr; };

	}; //class vector

	/**** Non-member function overloads ****/
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.getCtnr() == rhs.getCtnr()); };

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.getCtnr() != rhs.getCtnr()); };

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.getCtnr() <  rhs.getCtnr()); };

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.getCtnr() <= rhs.getCtnr()); };

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.getCtnr() >  rhs.getCtnr()); };

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return (lhs.getCtnr() >= rhs.getCtnr()); };
} //namespace ft

#endif //STACK_HPP

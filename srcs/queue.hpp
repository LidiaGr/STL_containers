//
// Created by Lidia Grigoreva on 03/02/2021.
//

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

namespace ft 	{

	template <class T, class Container = list<T> >
	class queue {
	public:
		/**** Member types ****/
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	private:
		container_type _ctnr;

	public:
		/**** Constructor ****/
		explicit queue (const container_type& ctnr = container_type()) : _ctnr(ctnr) {};

		/****  Member functions ****/
		bool empty() const { return _ctnr.empty(); };
		size_type size() const { return _ctnr.size(); };

		value_type& front() { return _ctnr.front(); };
		const value_type& front() const { return _ctnr.front(); };
		value_type& back() { return _ctnr.back(); };
		const value_type& back() const { return _ctnr.back(); };

		void push (const value_type& val) { _ctnr.push_back(val); };
		void pop() { _ctnr.pop_front(); };

		container_type getCtnr() const { return _ctnr; };

	}; //class queue

		/**** Non-member function overloads ****/
	template <class T, class Container>
	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return (lhs.getCtnr() == rhs.getCtnr()); };

	template <class T, class Container>
	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return (lhs.getCtnr() != rhs.getCtnr()); };

	template <class T, class Container>
	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return (lhs.getCtnr() <  rhs.getCtnr()); };

	template <class T, class Container>
	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return (lhs.getCtnr() <= rhs.getCtnr()); };

	template <class T, class Container>
	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return (lhs.getCtnr() >  rhs.getCtnr()); };

	template <class T, class Container>
	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) { return (lhs.getCtnr() >= rhs.getCtnr()); };

} //namespace ft

#endif //QUEUE_HPP

//
// Created by Temple Tarsha on 1/11/21.
//

#ifndef LIST_HPP
#define LIST_HPP

#include "utils.hpp"

namespace ft {

	template<class T, class Alloc = std::allocator<T> >
	class list {
		/**** Private data fields ****/

	protected:
		struct _tNode {
			struct _tNode *next;
			struct _tNode *prev;
			T *_data;
		};

		_tNode *_endNode;
		size_t _size;

		typedef typename Alloc::template rebind<_tNode>::other Alloc_rebind;
		Alloc_rebind _allocNode;
		Alloc _allocData;

	public:
		/**** Member types ****/

		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		/**** Iterators ****/

		class const_iterator;
		class iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
		private:
			_tNode * _node;

		public:
			iterator() : _node(0) {};
			explicit iterator(_tNode *data) : _node(data) {}
			~iterator() {}
			iterator(iterator const &src) { *this = src; }
			iterator &operator=(const iterator &rhs) {
				if (this != &rhs){
					_node = rhs._node;
				}
				return *this;
			}

			bool operator==(const iterator &rhs) const {
				return _node == rhs._node;
			}
			bool operator!=(const iterator &rhs) const {
				return _node != rhs._node;
			}
			bool operator==(const const_iterator &rhs) const {
				return _node == rhs._node;
			}
			bool operator!=(const const_iterator &rhs) const {
				return _node != rhs._node;
			}

			T &operator*() {
				return *_node->_data;
			}
			T *operator->() const {
				return &(operator*());
			}

			iterator &operator++() {
				_node = _node->next;
				return *this;
			}
			iterator operator++(int) {
				iterator tmp(*this);
				operator++();
				return tmp;
			}

			iterator &operator--() {
				_node = _node->prev;
				return *this;
			}
			iterator operator--(int) {
				iterator tmp(*this);
				operator--();
				return tmp;
			}

			_tNode *getNode() const {
				return _node;
			}
		};

		class const_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type const> {
		private:
			_tNode *_data;

		public:
			const_iterator() : _data(0) {};
			const_iterator(_tNode *data) : _data(data) {}
			~const_iterator() {}
			const_iterator(const_iterator const &src) { *this = src; }
			const_iterator &operator=(const const_iterator &rhs) {
				if (this != &rhs) _data = rhs._data;
				return *this;
			}

			const_iterator(iterator const &src) { *this = src; }
			const_iterator &operator=(iterator const &rhs) {
				if (*this != rhs) _data = rhs.getNode();
				return *this;
			}

			bool operator==(const const_iterator &rhs) const {
				return _data == rhs._data;
			}
			bool operator!=(const const_iterator &rhs) const {
				return _data != rhs._data;
			}
			bool operator==(const iterator &rhs) const {
				return _data == rhs.getNode();
			}
			bool operator!=(const iterator &rhs) const {
				return _data != rhs.getNode();
			}

			const T &operator*() const {
				return *_data->_data;
			}
			const T *operator->() const {
				return &(operator*());
			}

			const_iterator &operator++() {
				_data = _data->next;
				return *this;
			}
			const_iterator operator++(int) {
				const_iterator tmp(*this);
				operator++();
				return tmp;
			}

			const_iterator &operator--() {
				_data = _data->prev;
				return *this;
			}
			const_iterator operator--(int) {
				const_iterator tmp(*this);
				operator--();
				return tmp;
			}

			_tNode *getNode() const {
				return this->_data;
			}
		};

		class const_reverse_iterator;
		class reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type> {
		private:
			_tNode *_data;

		public:
			reverse_iterator() : _data(0) {};
			reverse_iterator(_tNode *data) : _data(data) {}
			~reverse_iterator() {}
			reverse_iterator(reverse_iterator const &src) { *this = src; }
			reverse_iterator &operator=(reverse_iterator const &rhs) {
				if (this != &rhs) _data = rhs._data;
				return *this;
			}

			bool operator==(const reverse_iterator &rhs) const { return _data == rhs._data; }
			bool operator!=(const reverse_iterator &rhs) const { return _data != rhs._data; }
			bool operator==(const const_reverse_iterator &rhs) const { return _data == rhs._data; }
			bool operator!=(const const_reverse_iterator &rhs) const { return _data != rhs._data; }

			T &operator*() { return *_data->_data; }
			T *operator->() const { return &(operator*()); }

			reverse_iterator &operator--() {
				_data = _data->next;
				return *this;
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				operator--();
				return tmp;
			}

			reverse_iterator &operator++() {
				_data = _data->prev;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp(*this);
				operator++();
				return tmp;
			}

			_tNode *getNode() const { return this->_data; }
		};

		class const_reverse_iterator : public std::iterator<std::bidirectional_iterator_tag, value_type const> {
		private:
			_tNode *_data;

		public:
			const_reverse_iterator() : _data(0) {};
			const_reverse_iterator(_tNode *data) : _data(data) {}
			~const_reverse_iterator() {}
			const_reverse_iterator(const_reverse_iterator const &src) { *this = src; }
			const_reverse_iterator &operator=(const_reverse_iterator const &rhs) {
				if (this != &rhs) _data = rhs._data;
				return *this;
			}

			const_reverse_iterator(reverse_iterator const &src) { *this = src; }
			const_reverse_iterator &operator=(reverse_iterator const &rhs) {
				if (*this != rhs) _data = rhs.getNode();
				return *this;
			}

			bool operator==(const const_reverse_iterator &rhs) const {
				return _data == rhs._data;
			}
			bool operator!=(const const_reverse_iterator &rhs) const {
				return _data != rhs._data;
			}
			bool operator==(const reverse_iterator &rhs) const {
				return _data == rhs._data;
			}
			bool operator!=(const reverse_iterator &rhs) const {
				return _data != rhs.getNode();
			}

			const T &operator*() {
				return *_data->_data;
			}
			const T *operator->() const {
				return &(operator*());
			}

			const_reverse_iterator &operator--() {
				_data = _data->next;
				return *this;
			}
			const_reverse_iterator operator--(int) {
				const_reverse_iterator tmp(*this);
				operator--();
				return tmp;
			}

			const_reverse_iterator &operator++() {
				_data = _data->prev;
				return *this;
			}
			const_reverse_iterator operator++(int) {
				const_reverse_iterator tmp(*this);
				operator++();
				return tmp;
			}

			_tNode *getNode() const {
				return this->_data;
			}
		};


	protected:
		/**** Internal Help Functions ****/

		void _createEndNode() {
			_endNode = _allocNode.allocate(1);
			_allocNode.construct(_endNode);
			_endNode->next = _endNode;
			_endNode->prev = _endNode;
			_endNode->_data = _allocData.allocate(1);
			_allocData.construct(_endNode->_data, T());
		};

		_tNode *_createNode(const value_type& val, _tNode* prev, _tNode *next) {
			_tNode *_tmp = _allocNode.allocate(1);
			_allocNode.construct(_tmp);
			_tmp->prev = prev;
			_tmp->next = next;
			_tmp->_data = _allocData.allocate(1);
			_allocData.construct(_tmp->_data, val);
			return _tmp;
		};

		_tNode* _pullOutNode(_tNode *node){
			_tNode *tmpL = node->prev;
			_tNode *tmpR = node->next;

			tmpL->next = tmpR;
			tmpR->prev = tmpL;
			return node;
		}

		void _insertNode(_tNode *left, _tNode *right, _tNode *node){
			left->next = node;
			right->prev = node;

			node->next = right;
			node->prev = left;
		}

		void _swapNodes(_tNode *one, _tNode *two) {
			_tNode *tmp = _pullOutNode(one);
			_insertNode(two, two->next, tmp);
		}

		/**** Member functions ****/
	public:
			/**** Construct list ****/
		/* default (1) */
		explicit list(const allocator_type &alloc = allocator_type()) : _allocData(alloc) {
			_size = 0;
			_createEndNode();
		};

		/* fill (2) */
		explicit list (size_type n, const value_type& val = value_type(),
					   const allocator_type& alloc = allocator_type()) : _allocData(alloc) {
			_size = 0;
			_createEndNode();
			for (size_t i = 0; i < n; i++) {
				push_front(val);
			}
		};

		/* range (3) */
		template <class InputIterator>
		list (InputIterator first, InputIterator last,
			  const allocator_type& alloc = allocator_type(),
			  typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _allocData(alloc) {
			_size = 0;
			_createEndNode();
			for (; first != last; first++) {
				push_back(*first);
			}
		};

		/* copy (4) */
		list (const list& x) : _size(0) {
			_createEndNode();
			*this = x;
		};


			/**** List destructor ****/
		~list() {
			clear();
			_allocData.deallocate(_endNode->_data, 1);
			_allocNode.deallocate(_endNode, 1);
		}


			/**** Assign content ****/
		list & operator=(const list<T> & x) {
			if (this != &x) {
				clear();
				const_iterator it = x._endNode->next;
				const_iterator ite = x._endNode;
				while (it != ite) {
					push_back(*it);
					it++;
				}
				this->_size = x._size;
			}
			return *this;
		}


		/**** Iterators ****/
		iterator begin() { return iterator(_endNode->next); }
		const_iterator begin() const { return const_iterator(_endNode->next); };
		reverse_iterator rbegin() { return reverse_iterator(_endNode->prev); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_endNode->prev); };

		iterator end() { return iterator(_endNode); }
		const_iterator end() const { return const_iterator(_endNode); };
		reverse_iterator rend() { return reverse_iterator(_endNode); };
		const_reverse_iterator rend() const{ return const_reverse_iterator(_endNode); };


		/**** Capacity ****/
		size_type size() const {
			return _size;
		};
		bool empty() const {
			return _size == 0;
		};
		size_type max_size() const{
			return std::numeric_limits<size_type>::max() / sizeof(*this) ;
		};


		/**** Element access ****/
		reference front(){
			return (reference (*(_endNode->next)->_data));
		};
		const_reference front() const{
			return (const_reference (*(_endNode->next)->_data));
		};

		reference back(){
			return (reference (*(_endNode->prev)->_data));
		};
		const_reference back() const{
			return (const_reference (*(_endNode->prev)->_data));
		};


		/**** Modifiers ****/
		void assign (size_type n, const value_type& val){
			this->clear();
			for (size_type i = 0; i < n; i++){
				push_back(val);
			}
		};

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
			   typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			this->clear();
			for (; first != last; first++){
				push_back(*first);
			}
		};

		void push_front(const value_type& val) {
			insert(this->begin(), val);
		}
		void push_back (const value_type& val) {
			insert(this->end(), val);
		}

		void pop_front() {
			_tNode *tmp = _endNode->next;
			_endNode->next = tmp->next;
			(tmp->next)->prev = _endNode;
			_allocData.destroy(tmp->_data);
			_allocNode.destroy(tmp);
			_allocData.deallocate(tmp->_data, 1);
			_allocNode.deallocate(tmp, 1);
			_size--;
		};
		void pop_back() {
			_tNode *tmp = _endNode->prev;
			_endNode->prev = tmp->prev;
			(tmp->prev)->next = _endNode;
			_allocData.destroy(tmp->_data);
			_allocNode.destroy(tmp);
			_allocData.deallocate(tmp->_data, 1);
			_allocNode.deallocate(tmp, 1);
			_size--;
		};

		iterator insert (iterator position, const value_type& val) {
			iterator tmp = position;
			_tNode * prevN = (--tmp).getNode();
			_tNode * nextN = position.getNode();

			_tNode * node = _createNode(val, prevN, nextN);
			prevN->next = node;
			nextN->prev = node;
			iterator res(node);
			_size++;
			return res;
		};

		void insert (iterator position, size_type n, const value_type& val) {
			for (size_type i = 0; i < n; i++)
				insert(position, val);
		};

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					 typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			while (first != last){
				insert(position, *first);
				first++;
			}
		};

		iterator erase (iterator position) {
			_tNode *prevN = position.getNode();
			prevN = prevN->prev;
			_tNode *nextN = position.getNode();
			nextN = nextN->next;

			prevN->next = nextN;
			nextN->prev = prevN;

			_tNode *node = position.getNode();
			_allocData.destroy(node->_data);
			_allocNode.destroy(node);
			_allocData.deallocate(node->_data,1);
			_allocNode.deallocate(node,1);
			_size--;
			return iterator(nextN);
		};

		iterator erase (iterator first, iterator last){
			iterator tmp = first;
			_tNode * prevN = (--tmp).getNode();
			_tNode * nextN = last.getNode();
			prevN->next = nextN;
			nextN->prev = prevN;

			while(first != last){
				_tNode *node = first.getNode();
				first++;
				_allocData.destroy(node->_data);
				_allocNode.destroy(node);
				_allocData.deallocate(node->_data,1);
				_allocNode.deallocate(node,1);
				_size--;
			}
			return iterator(nextN);
		};

		void swap (list& x) {
			_tNode *tmp = _endNode;
			_endNode = x._endNode;
			x._endNode = tmp;

			size_t tmpSize = _size;
			_size = x._size;
			x._size = tmpSize;
		};

		void resize (size_type n, value_type val = value_type()) {
			if (this->size() > n){
				iterator rest = this->begin();
				for (size_type i = 0; i < n; i++) {
					rest++;
				}
				erase(rest, this->end());
			}
			else if (this->size() < n) {
				size_type i = this->size();
				for (; i < n; i++)
					this->push_back(val);
			}
		};

		void clear() {
			_tNode *tmp = _endNode->next;
			while (tmp != _endNode) {
				pop_front();
				tmp = _endNode->next;
			}
		};


		/**** Operations ****/
		void splice (iterator position, list& x) {
			this->_size += x.size();
			x._size = 0;

			iterator x_beginIt = x.begin();
			iterator x_endIt = --x.end();

			_tNode *x_beginN = x_beginIt.getNode();
			_tNode *x_endN = x_endIt.getNode();
			_tNode *prevN = position.getNode();

			prevN = prevN->prev;
			prevN->next = x_beginN;
			x_beginN->prev = prevN;

			_tNode *nextN = position.getNode();
			x_endN->next = nextN;
			nextN->prev = x_endN;
			x._endNode->next = x._endNode;
			x._endNode->prev = x._endNode;
		};

		void splice (iterator position, list& x, iterator i){
			this->_size++;
			x._size--;

			_tNode *elem = i.getNode();
			_tNode *befor_e = (--i).getNode();
			++i;
			_tNode *after_e = (++i).getNode();
			befor_e->next = after_e;
			after_e->prev = befor_e;

			_tNode *curN = position.getNode();
			_tNode *prevN = curN->prev;
			prevN->next = elem;
			curN->prev = elem;
			elem->prev = prevN;
			elem->next = curN;
		};

		void splice (iterator position, list& x, iterator first, iterator last) {
			for (; first != last; ) {
				splice(position, x, first++);
			}
		};

		void remove (const value_type& val){
			iterator it = this->begin();
			iterator ite = this->end();
			iterator tmp = it;

			while(it != ite) {
				if (*it == val){
					tmp = it;
					++tmp;
					erase(it);
					it = tmp;
				} else
					++it;
			}
		};

		template <class Predicate>
		void remove_if (Predicate pred){
			iterator it = this->begin();
			iterator ite = this->end();
			iterator tmp;

			while(it != ite) {
				if (pred(*it) == true){
					tmp = it;
					++tmp;
					erase(it);
					it = tmp;
				} else
					++it;
			}
		};

		void unique(){
			iterator it = this->begin();
			iterator ite = this->end();
			iterator tmp = it;
			++tmp;

			while(it != ite) {
				if (*it == *tmp){
					erase(tmp);
					tmp = it;
					++tmp;
				} else {
					++it;
					++tmp;
				}
			}
		};

		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred){
			iterator it = this->begin();
			iterator ite = this->end();
			iterator tmp = it;
			++tmp;

			while(it != ite) {
				if (binary_pred(*it,*tmp)) {
					erase(tmp);
					tmp = it;
					++tmp;
				} else {
					++it;
					++tmp;
				}
			}
		};

		void sort(){
			_tNode *begin = _endNode->next;
			_tNode *end = _endNode;
			_tNode *tmp;
			_tNode *cur;
			bool flag = false;

			while(begin != end){
				tmp = begin->next;
				while(tmp != end){
					if(*begin->_data > *tmp->_data){
						if (!flag){
							flag = true;
							cur = begin->prev;
						}
						_swapNodes(begin, tmp);
					}
					tmp = tmp->next;
				}
				if (flag){
					flag = false;
					begin = cur->next;
				} else {
					begin = begin->next;
				}
			}
		};

		template <class Compare>
		void sort (Compare comp) {
			_tNode *begin = _endNode->next;
			_tNode *end = _endNode;
			_tNode *tmp;
			_tNode *cur;
			bool flag = false;

			while(begin != end){
				tmp = begin->next;
				while(tmp != end){
					if(comp(*tmp->_data, *begin->_data)){
						if (!flag){
							flag = true;
							cur = begin->prev;
						}
						_swapNodes(begin, tmp);
					}
					tmp = tmp->next;
				}
				if (flag){
					flag = false;
					begin = cur->next;
				} else {
					begin = begin->next;
				}
			}
		};

		void reverse(){
			_tNode *begin = _endNode;
			_tNode *end = _endNode->prev;
			_tNode *tmp;

			if (_size == 0)
				return ;
			for (size_t i = 0; i < _size - 1; i++){
				_insertNode(begin, begin->next, (tmp = _pullOutNode(end)));
				begin = tmp;
				end = _endNode->prev;
			}
		};

		void merge (list& x){
			iterator tmp;
			iterator itt = this->begin();
			iterator itet = this->end();
			iterator itx = x.begin();
			if (&x == this)
				return ;
			while(itt != itet) {
				if (*itt > *itx){
					tmp = itx;
					++tmp;
					_insertNode(itt.getNode()->prev, itt.getNode(), _pullOutNode(itx.getNode()));
					itx = tmp;
					x._size--;
					this->_size++;
				} else {
					++itt;
				}
			}
			if (x._size != 0)
				this->splice(itt, x);
		};

		template <class Compare>
		void merge (list& x, Compare comp){
			iterator tmp;
			iterator itt = this->begin();
			iterator itet = this->end();
			iterator itx = x.begin();
			if (&x == this)
				return ;
			while(itt != itet && x._size != 0) {
				if (comp(*itx, *itt)){
					tmp = itx;
					++tmp;
					_insertNode(itt.getNode()->prev, itt.getNode(), _pullOutNode(itx.getNode()));
					itx = tmp;
					x._size--;
					this->_size++;
				} else {
					++itt;
				}
			}
			if (x._size != 0)
				this->splice(itt, x);
		};
	}; //class list


	/**** Non-member function overloads ****/
	/* relational operators */
	template <class T, class Alloc>
	bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		typename list<T, Alloc>::const_iterator l_it = lhs.begin();
		typename list<T, Alloc>::const_iterator r_it = rhs.begin();
		size_t size = lhs.size();
		if (size == rhs.size()) {
			for(size_t i = 0; i < size; i++) {
				if (*l_it == *r_it) {
					l_it++;
					r_it++;
				}
				else
					return false;
			}
			return true;
		}
		return false;
	};

	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		typename list<T, Alloc>::const_iterator l_it = lhs.begin();
		typename list<T, Alloc>::const_iterator r_it = rhs.begin();
		size_t size = lhs.size();
		if (size == rhs.size()) {
			for(size_t i = 0; i < size; i++) {
				if (*l_it == *r_it) {
					l_it++;
					r_it++;
				}
				else
					return true;
			}
			return false;
		}
		return true;
	};

	template <class T, class Alloc>
	bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		typename list<T, Alloc>::const_iterator l_it = lhs.begin();
		typename list<T, Alloc>::const_iterator r_it = rhs.begin();
		size_t l_size = lhs.size();
		size_t r_size = rhs.size();
		size_t size;
		if (l_size <= r_size)
			size = l_size;
		else
			size = r_size;
		for(size_t i = 0; i < size; i++) {
			if (*l_it < *r_it) {
				l_it++;
				r_it++;
			}
			else
				return false;
		}
		return true;
	};

	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		typename list<T, Alloc>::const_iterator l_it = lhs.begin();
		typename list<T, Alloc>::const_iterator r_it = rhs.begin();
		size_t l_size = lhs.size();
		size_t r_size = rhs.size();
		size_t size;
		if (l_size <= r_size)
			size = l_size;
		else
			size = r_size;
		for(size_t i = 0; i < size; i++) {
			if (*l_it <= *r_it) {
				l_it++;
				r_it++;
			}
			else
				return false;
		}
		return true;
	};

	template <class T, class Alloc>
	bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		typename list<T, Alloc>::const_iterator l_it = lhs.begin();
		typename list<T, Alloc>::const_iterator r_it = rhs.begin();
		size_t l_size = lhs.size();
		size_t r_size = rhs.size();
		size_t size;
		if (l_size <= r_size)
			size = l_size;
		else
			size = r_size;
		for(size_t i = 0; i < size; i++) {
			if (*l_it > *r_it) {
				l_it++;
				r_it++;
			}
			else
				return false;
		}
		return true;
	};

	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs){
		typename list<T, Alloc>::const_iterator l_it = lhs.begin();
		typename list<T, Alloc>::const_iterator r_it = rhs.begin();
		size_t l_size = lhs.size();
		size_t r_size = rhs.size();
		size_t size;
		if (l_size <= r_size)
			size = l_size;
		else
			size = r_size;
		for(size_t i = 0; i < size; i++) {
			if (*l_it >= *r_it) {
				l_it++;
				r_it++;
			}
			else
				return false;
		}
		return true;
	};

	/* swap */
	template <class T, class Alloc>
	void swap (list<T,Alloc>& x, list<T,Alloc>& y){
			x.swap(y);
	};

}; // namespace ft

#endif //LIST_HPP
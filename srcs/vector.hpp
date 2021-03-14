//
// Created by Temple Tarsha on 1/29/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector{
		/**** Private data fields ****/
	protected:
		T		*_firstElem;
		size_t	_size;
		size_t	_capacity;

		Alloc	_allocData;

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
		class iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
		private:
			T	*_data;
		public:
			iterator() : _data(nullptr) {};
			~iterator() {}
			explicit iterator(T *data) : _data(data) {}
			iterator(iterator const &src) { *this = src; }

			iterator &operator=(const iterator &rhs) { if (this != &rhs) { _data = rhs._data; } return *this; }

			bool operator==(iterator const &rhs) const { return(this->_data == rhs._data); }
			bool operator!=(iterator const &rhs) const { return(this->_data != rhs._data); }
			bool operator< (iterator const &rhs) const { return(this->_data <  rhs._data); }
			bool operator> (iterator const &rhs) const { return(this->_data >  rhs._data); }
			bool operator<=(iterator const &rhs) const { return(this->_data <= rhs._data); }
			bool operator>=(iterator const &rhs) const { return(this->_data >= rhs._data); }

			bool operator==(const_iterator const &rhs) const { return(this->_data == rhs.getData()); }
			bool operator!=(const_iterator const &rhs) const { return(this->_data != rhs.getData()); }
			bool operator< (const_iterator const &rhs) const { return(this->_data <  rhs.getData()); }
			bool operator> (const_iterator const &rhs) const { return(this->_data >  rhs.getData()); }
			bool operator<=(const_iterator const &rhs) const { return(this->_data <= rhs.getData()); }
			bool operator>=(const_iterator const &rhs) const { return(this->_data >= rhs.getData()); }

			iterator &operator++() { _data++; return *this; }
			iterator &operator--() { _data--; return *this; }
			iterator operator++(int) { iterator tmp(*this); operator++(); return tmp; }
			iterator operator--(int) { iterator tmp(*this); operator--(); return tmp; }

			iterator operator+ (int nb) { return iterator(_data + nb); }
			iterator operator- (int nb) { return iterator(_data - nb); }
			iterator operator+=(int nb) { _data = _data + nb; return iterator(_data); }
			iterator operator-=(int nb) { _data = _data - nb; return iterator(_data); }

			T &operator* () const { return *_data; }
			T *operator->() const { return  _data; }
			T &operator[](size_t index) const { return *(this->_data + index); }

			T *getData() const { return _data; }
		};

		class const_iterator : public std::iterator<std::random_access_iterator_tag, value_type const> {
		private:
			T	*_data;
		public:
			const_iterator() : _data(nullptr) {};
			~const_iterator() {}
			explicit const_iterator(T *data) : _data(data) {}
			const_iterator(const_iterator const &src) { *this = src; }
			const_iterator(iterator const &src) { *this = src; }

			const_iterator &operator=(const const_iterator &rhs) { if (this != &rhs) { _data = rhs._data; } return *this; }
			const_iterator &operator=(const iterator &rhs) { if (*this != rhs) { _data = rhs.getData(); } return *this; }

			bool operator==(iterator const &rhs) const { return(this->_data == rhs.getData()); }
			bool operator!=(iterator const &rhs) const { return(this->_data != rhs.getData()); }
			bool operator< (iterator const &rhs) const { return(this->_data <  rhs.getData()); }
			bool operator> (iterator const &rhs) const { return(this->_data >  rhs.getData()); }
			bool operator<=(iterator const &rhs) const { return(this->_data <= rhs.getData()); }
			bool operator>=(iterator const &rhs) const { return(this->_data >= rhs.getData()); }

			bool operator==(const_iterator const &rhs) const { return(this->_data == rhs._data); }
			bool operator!=(const_iterator const &rhs) const { return(this->_data != rhs._data); }
			bool operator< (const_iterator const &rhs) const { return(this->_data <  rhs._data); }
			bool operator> (const_iterator const &rhs) const { return(this->_data >  rhs._data); }
			bool operator<=(const_iterator const &rhs) const { return(this->_data <= rhs._data); }
			bool operator>=(const_iterator const &rhs) const { return(this->_data >= rhs._data); }

			const_iterator &operator++() { _data++; return *this; }
			const_iterator &operator--() { _data--; return *this; }
			const_iterator operator++(int) { const_iterator tmp(*this); operator++(); return tmp; }
			const_iterator operator--(int) { const_iterator tmp(*this); operator--(); return tmp; }

			const_iterator operator+ (int nb) { return iterator(_data + nb); }
			const_iterator operator- (int nb) { return iterator(_data - nb); }
			const_iterator operator+=(int nb) { _data = _data + nb; return iterator(_data); }
			const_iterator operator-=(int nb) { _data = _data - nb; return iterator(_data); }

			T &operator* () const { return *_data; }
			T *operator->() const { return  _data; }
			T &operator[](size_t index) const { return *(this->_data + index); }

			T *getData() const { return _data; }
		};

		class const_reverse_iterator;
		class reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type> {
		private:
			T	*_data;
		public:
			reverse_iterator() : _data(nullptr) {};
			~reverse_iterator() {}
			explicit reverse_iterator(T *data) : _data(data) {}
			reverse_iterator(reverse_iterator const &src) { *this = src; }

			reverse_iterator &operator=(const reverse_iterator &rhs) { if (this != &rhs) { _data = rhs._data; } return *this; }

			bool operator==(reverse_iterator const &rhs) const { return(this->_data == rhs._data); }
			bool operator!=(reverse_iterator const &rhs) const { return(this->_data != rhs._data); }
			bool operator< (reverse_iterator const &rhs) const { return(this->_data <  rhs._data); }
			bool operator> (reverse_iterator const &rhs) const { return(this->_data >  rhs._data); }
			bool operator<=(reverse_iterator const &rhs) const { return(this->_data <= rhs._data); }
			bool operator>=(reverse_iterator const &rhs) const { return(this->_data >= rhs._data); }

			bool operator==(const_reverse_iterator const &rhs) const { return(this->_data == rhs.getData()); }
			bool operator!=(const_reverse_iterator const &rhs) const { return(this->_data != rhs.getData()); }
			bool operator< (const_reverse_iterator const &rhs) const { return(this->_data <  rhs.getData()); }
			bool operator> (const_reverse_iterator const &rhs) const { return(this->_data >  rhs.getData()); }
			bool operator<=(const_reverse_iterator const &rhs) const { return(this->_data <= rhs.getData()); }
			bool operator>=(const_reverse_iterator const &rhs) const { return(this->_data >= rhs.getData()); }

			reverse_iterator &operator++() { _data--; return *this; }
			reverse_iterator &operator--() { _data++; return *this; }
			reverse_iterator operator++(int) { reverse_iterator tmp(*this); operator++(); return tmp; }
			reverse_iterator operator--(int) { reverse_iterator tmp(*this); operator--(); return tmp; }

			reverse_iterator operator+ (int nb) { return iterator(_data - nb); }
			reverse_iterator operator- (int nb) { return iterator(_data + nb); }
			reverse_iterator operator+=(int nb) { _data = _data - nb; return iterator(_data); }
			reverse_iterator operator-=(int nb) { _data = _data + nb; return iterator(_data); }

			T &operator* () const { return *_data; }
			T *operator->() const { return  _data; }
			T &operator[](size_t index) const { return *(this->_data + index); }

			T *getData() const { return _data; }
		};

		class const_reverse_iterator : public std::iterator<std::random_access_iterator_tag, value_type const> {
		private:
			T	*_data;
		public:
			const_reverse_iterator() : _data(nullptr) {};
			~const_reverse_iterator() {}
			explicit const_reverse_iterator(T *data) : _data(data) {}
			const_reverse_iterator(const_reverse_iterator const &src) { *this = src; }
			const_reverse_iterator(reverse_iterator const &src) { *this = src; }

			const_reverse_iterator &operator=(const const_reverse_iterator &rhs) { if (this != &rhs) { _data = rhs._data; } return *this; }
			const_reverse_iterator &operator=(const reverse_iterator &rhs) { if (*this != rhs) { _data = rhs.getData(); } return *this; }

			bool operator==(reverse_iterator const &rhs) const { return(this->_data == rhs.getData()); }
			bool operator!=(reverse_iterator const &rhs) const { return(this->_data != rhs.getData()); }
			bool operator< (reverse_iterator const &rhs) const { return(this->_data <  rhs.getData()); }
			bool operator> (reverse_iterator const &rhs) const { return(this->_data >  rhs.getData()); }
			bool operator<=(reverse_iterator const &rhs) const { return(this->_data <= rhs.getData()); }
			bool operator>=(reverse_iterator const &rhs) const { return(this->_data >= rhs.getData()); }

			bool operator==(const_reverse_iterator const &rhs) const { return(this->_data == rhs._data); }
			bool operator!=(const_reverse_iterator const &rhs) const { return(this->_data != rhs._data); }
			bool operator< (const_reverse_iterator const &rhs) const { return(this->_data <  rhs._data); }
			bool operator> (const_reverse_iterator const &rhs) const { return(this->_data >  rhs._data); }
			bool operator<=(const_reverse_iterator const &rhs) const { return(this->_data <= rhs._data); }
			bool operator>=(const_reverse_iterator const &rhs) const { return(this->_data >= rhs._data); }

			const_reverse_iterator &operator++() { _data--; return *this; }
			const_reverse_iterator &operator--() { _data++; return *this; }
			const_reverse_iterator operator++(int) { const_reverse_iterator tmp(*this); operator++(); return tmp; }
			const_reverse_iterator operator--(int) { const_reverse_iterator tmp(*this); operator--(); return tmp; }

			const_reverse_iterator operator+ (int nb) { return iterator(_data - nb); }
			const_reverse_iterator operator- (int nb) { return iterator(_data + nb); }
			const_reverse_iterator operator+=(int nb) { _data = _data - nb; return iterator(_data); }
			const_reverse_iterator operator-=(int nb) { _data = _data + nb; return iterator(_data); }

			T &operator* () const { return *_data; }
			T *operator->() const { return  _data; }
			T &operator[](size_t index) const { return *(this->_data + index); }

			T *getData() const { return _data; }
		};


	protected:
		/**** Internal Help Functions ****/
		void _clearAndDestroy(){
			clear();
			_allocData.deallocate(_firstElem, _capacity);
			_capacity = 0;
			_firstElem = nullptr;
		}

		void _reallocate(size_t capacity, size_t nbOfNewElem) {
			size_t size = _size;
			T *firstOld = _firstElem;
			T *newArr;

			if (nbOfNewElem > capacity) {
				newArr = _allocData.allocate(nbOfNewElem + _size);
				capacity = nbOfNewElem + _size;
			}
			else
				newArr = _allocData.allocate(capacity);
			size_t i = 0;
			for(; i < _size; i++) {
				_allocData.construct(&newArr[i], firstOld[i]);
			}
			while (_size < (_size + nbOfNewElem)) {
				_allocData.construct(&newArr[i++], T());
				nbOfNewElem--;
			}
			_clearAndDestroy();
			_size = size;
			_capacity = capacity;
			_firstElem = newArr;
		}

		size_t _findElemNbFromPositionIt(iterator position) {
			iterator it = this->begin();
			size_t index = 0;
			while(it != position) {index++; it++;}
			return index;
		}

		void _changeValues(value_type val, size_t fromIndex, size_t size) {
			T *cur = &_firstElem[fromIndex];
			T tmp;
			while(fromIndex < size) {
				tmp = *cur;
				*cur = val;
				val = tmp;
				cur++;
				fromIndex++;
			}
		}

		void _checkCapacity(size_t n) {
			if (_size + n > _capacity) {
				if (_capacity == 0)
					_capacity = 1;
				_reallocate(_capacity * 2, n);
			}
		}


	public:
		/**** Constructors ****/
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _allocData(alloc) {
			_firstElem = nullptr;
		};

		explicit vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _allocData(alloc) {
			_firstElem = _allocData.allocate(_capacity);
			T *tmp = _firstElem;
			for(size_t i = 0; i < n; i++) {
				_allocData.construct(tmp++, val);
			}
		};

		template <class InputIterator>
		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type(),
				typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) : _size(0), _allocData(alloc) {
			InputIterator tmp = first;
			for(; tmp != last; tmp++) { _size++; }
			_capacity = _size;
			_firstElem = _allocData.allocate(_capacity);
			T *tmpData = _firstElem;
			for(size_t i = 0; i < _size; i++) {
				_allocData.construct(tmpData++, *first++);
			}
		};

		vector (const vector& x) {
			_capacity = x._capacity;
			_firstElem = _allocData.allocate(_capacity);
			_size = x._size;
			T *tmpT = _firstElem;
			T *tmpX = x._firstElem;
			for(size_t i = 0; i < _size; i++) {
				_allocData.construct(tmpT++, *tmpX++);
			}
		};


		/**** Destructor ****/
		~vector() {
			clear();
			_allocData.deallocate(_firstElem, _capacity);
			_capacity = 0;
			_firstElem = nullptr;
		};

		/**** Assign content ****/
		vector& operator= (const vector& x) {
			if (this != &x) {
				clear();
				insert(this->begin(), x.begin(), x.end());
			}
			return *this;
		};


		/**** Iterators ****/
		iterator begin() { return iterator(_firstElem); }
		const_iterator begin() const { return const_iterator(_firstElem); }
		reverse_iterator rbegin() { return reverse_iterator(_firstElem + (_size - 1)); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_firstElem + (_size - 1)); };

		iterator end() { return iterator(_firstElem + _size); }
		const_iterator end() const {return const_iterator(_firstElem + _size); };
		reverse_iterator rend(){ return reverse_iterator(_firstElem - 1); };
		const_reverse_iterator rend() const { return const_reverse_iterator(_firstElem - 1); };


		/**** Capacity ****/
		size_type size() const { return this->_size; };
		size_type max_size() const { return std::numeric_limits<size_type>::max() / sizeof(T); };
		void resize (size_type n, value_type val = value_type()) {
			if (n <= _size)
				erase(iterator(_firstElem + n), this->end());
			else
				insert(iterator(_firstElem + _size), n - _size , val);
		};
		void reserve (size_type n) {
			if (_capacity < n)
				_reallocate(n, 0);
		};
		size_type capacity() const { return this->_capacity; };
		bool empty() const { return (_size == 0); };


		/**** Element access ****/
		reference operator[] (size_type n) { return *(_firstElem + n); };
		const_reference operator[] (size_type n) const { return *(_firstElem + n); };
		reference at (size_type n) {
			if(n >= _size || n < 0)
				throw std::out_of_range("Error: index is out of range");
			else
				return *(_firstElem + n);
		};
		const_reference at (size_type n) const {
			if(n >= _size || n < 0)
				throw std::out_of_range("Error: index is out of range");
			else
				return *(_firstElem + n);
		};
		reference front() { return *_firstElem; };
		const_reference front() const { return *_firstElem; };
		reference back() { return *(_firstElem + (_size - 1)); };
		const_reference back() const { return *(_firstElem + (_size - 1)); };

		/**** Modifiers ****/
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last,
			   typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			this->_clearAndDestroy();
			this->insert(this->begin(), first, last);
		};

		void assign (size_type n, const value_type& val){
			this->_clearAndDestroy();
			this->insert(this->begin(), n, val);
		};

		void pop_back() {
			T *tmp = _firstElem + (_size--);
			_allocData.destroy(tmp);
		};

		iterator insert (iterator position, const value_type& val) {
			size_t index = _findElemNbFromPositionIt(position);
			_checkCapacity(1);
			_changeValues(val, index, _size + 1);
			_size += 1;
			return iterator(_firstElem + index);
		};

		void insert (iterator position, size_type n, const value_type& val){
			size_t index = _findElemNbFromPositionIt(position);
			_checkCapacity(n);
			for (size_t i = 1; i <= n; i++)
				_changeValues(val, index, _size + i);
			_size += n;
		};

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last,
					 typename enable_if<std::__is_input_iterator<InputIterator>::value>::type* = 0) {
			size_t index = _findElemNbFromPositionIt(position);
			size_t n = 0;
			InputIterator tmp = first;
			while (tmp++ != last) { n++; }
			_checkCapacity(n);
			for (size_t i = 1; i <= n; i++) {
				_changeValues(*first, index, _size + i);
				first++;
			}
			_size += n;
		};

		void push_back (const value_type& val) {
			if (_capacity == 0)
				_reallocate(1, 1);
			insert(this->end(), val);
		};

		iterator erase (iterator position) {
			size_t id = _findElemNbFromPositionIt(position);
			T tmp;
			while (id != (_size - 1)) {
				tmp = _firstElem[id + 1];
				_firstElem[id] = tmp;
				id++;
			}
			_size -= 1;
			return iterator(_firstElem + id);
		};

		iterator erase (iterator first, iterator last) {
			size_t n = 0;
			iterator tmp = first;
			while (tmp++ != last) { n++; }

			size_t id = _findElemNbFromPositionIt(first);
			T tmpData;
			while (id != (_size - n)) {
				tmpData = _firstElem[id + n];
				_firstElem[id] = tmpData;
				id++;
			}
			_size -= n;
			return iterator(_firstElem + id);
		};

		void swap (vector& x) {
			size_t tmpSize = _size;
			_size = x._size;
			x._size = tmpSize;

			size_t tmpCap = _capacity;
			_capacity = x._capacity;
			x._capacity = tmpCap;

			T *tmpElem = _firstElem;
			_firstElem = x._firstElem;
			x._firstElem = tmpElem;
		};

		void clear() {
			T *tmp = _firstElem;
			for(; _size != 0; _size--) { _allocData.destroy(tmp++); }
		};
	}; //class vector

	/**** Non-member function overloads ****/
	/* relational operators */
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T, Alloc>::const_iterator l_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator r_it = rhs.begin();
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
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T, Alloc>::const_iterator l_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator r_it = rhs.begin();
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
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T, Alloc>::const_iterator l_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator r_it = rhs.begin();
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
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T, Alloc>::const_iterator l_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator r_it = rhs.begin();
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
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T, Alloc>::const_iterator l_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator r_it = rhs.begin();
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
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		typename vector<T, Alloc>::const_iterator l_it = lhs.begin();
		typename vector<T, Alloc>::const_iterator r_it = rhs.begin();
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
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	};

} //namespace ft

#endif //VECTOR_HPP

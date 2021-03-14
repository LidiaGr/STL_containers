//
// Created by Temple Tarsha on 12/27/20.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../srcs/list.hpp"
#include <list>
#include <cmath>

using stList = std::list<int>;
using ftList = ft::list<int>;

template < class T, class Alloc = std::allocator<T> >
void checkListsEQ(std::list<T, Alloc> &st, ft::list<T,Alloc> &ft){
	EXPECT_EQ(st.size(), ft.size());

	auto stIt = st.begin();

	typename ft::list<T, Alloc>::iterator ftIt = ft.begin();
	typename ft::list<T, Alloc>::iterator ftIte = ft.end();
	while(ftIt != ftIte){
		EXPECT_EQ(*stIt, *ftIt);
		ftIt++;
		stIt++;
	}
}

TEST(ListTests, constructors) {
	/* Default */
	stList st1;
	ftList ft1;
	std::cout << "✓ Default created" << std::endl << std::endl;

	/* Filled with one param */
	stList st2(10);
	ftList ft2(10);
	std::cout << "✓ Filled with one parameter created" << std::endl;
	std::list<int>::iterator stIt2 = st2.begin();
	std::list<int>::iterator stIte2= st2.end();

	ft::list<int>::iterator ftIt2 = ft2.begin();
	ft::list<int>::iterator ftIte2= ft2.end();


	std::cout << "Data in st::list : ";
	for (; stIt2 != stIte2; stIt2++){
		std::cout << *stIt2;
	}
	std::cout << std::endl;

	std::cout << "Data in ft::list : ";
	for (; ftIt2 != ftIte2; ftIt2++){
		std::cout << *ftIt2;
	}
	std::cout << std::endl << std::endl;


	/* Filled with two params */
	stList st3(7,8);
	ftList ft3(7,8);
	std::cout << "✓ Filled with two parameters created" << std::endl;

	std::list<int>::iterator stIt3 = st3.begin();
	std::list<int>::iterator stIte3= st3.end();

	ft::list<int>::iterator ftIt3 = ft3.begin();
	ft::list<int>::iterator ftIte3= ft3.end();


	std::cout << "Data in st::list : ";
	for (; stIt3 != stIte3; stIt3++){
		std::cout << *stIt3;
	}
	std::cout << std::endl;

	std::cout << "Data in ft::list : ";
	for (; ftIt3 != ftIte3; ftIt3++){
		std::cout << *ftIt3;
	}
	std::cout << std::endl << std::endl;


	/* ranged */
	std::list<int>::iterator stIt4 = st3.begin();
	std::list<int>::iterator stIte4 = st3.end();

	stIt4++;
	stIt4++;
	stIt4++;
	stIt4++;
	stList st4(stIt4, stIte4);
	ftList ft4(stIt4, stIte4);
	std::cout << "✓ Ranged created" << std::endl;

	std::list<int>::iterator stIt5 = st4.begin();
	std::list<int>::iterator stIte5 = st4.end();
	ft::list<int>::iterator ftIt5 = ft4.begin();
	ft::list<int>::iterator ftIte5 = ft4.end();

	std::cout << "Data in st::list : ";
	for (; stIt5 != stIte5; stIt5++){
		std::cout << *stIt5;
	}
	std::cout << std::endl;

	std::cout << "Data in ft::list : ";
	for (; ftIt5 != ftIte5; ftIt5++){
		std::cout << *ftIt5;
	}
	std::cout << std::endl << std::endl;


	/* copy */
	ft::list<int> ft_first(3);
	ft::list<int> ft_second(ft_first);

	std::list<int> st_first(3);
	std::list<int> st_second(st_first);

	EXPECT_EQ(ft_first.size(), st_first.size());
	EXPECT_EQ(ft_second.size(), st_second.size());

	std::cout << "✓ Copy created" << std::endl << std::endl;
};

TEST(ListTests, iterators_rbegin_rend) {
	ft::list<std::string> str;
	str.push_back("hello");
	str.push_back("world");
	str.push_back("today");

	ft::list<std::string>::iterator it = str.begin();
	for (; it != str.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	ft::list<std::string>::reverse_iterator r_it = str.rbegin();
	for (; r_it != str.rend(); r_it++){
		std::cout << *r_it << " ";
	}
	std::cout << std::endl;


	ft::list<float> flo;
	flo.push_back(1.9);
	flo.push_back(2.9);
	flo.push_back(3.9);
	flo.push_back(4.9);

	ft::list<float>::const_iterator c_it = flo.begin();
	for (; c_it != flo.end(); c_it++){
		std::cout << *c_it << " ";
	}
	std::cout << std::endl;

	ft::list<float>::const_reverse_iterator cr_it = flo.rbegin();
	for (; cr_it != flo.rend(); cr_it++){
		std::cout << *cr_it << " ";
	}
	std::cout << std::endl;

	ft::list<int> A;
	A.push_back(30);
	A.push_back(20);
	A.push_back(42);
	A.push_back(99);
	A.push_back(77);
	int k = 0;
	for (ft::list<int>::reverse_iterator test = A.rbegin(); test != A.rend(); ++test)
	{
		std::cout << ' ' << *test;
		k++;
	}
}

TEST (ListTests, iterators) {
	ft::list<std::string> str;
	str.push_back("hello");
	str.push_back("world");
	str.push_back("today");

	ft::list<std::string>::iterator it = str.begin();
	for (; it != str.end(); it++){
	std::cout << *it << " ";
	}
	std::cout << std::endl;

	ft::list<std::string>::reverse_iterator r_it = str.rbegin();
	for (; r_it != str.rend(); r_it++){
	std::cout << *r_it << " ";
	}
	std::cout << std::endl;

	std::list<std::string> str1;
	str1.push_back("hello");
	str1.push_back("world");
	str1.push_back("today");
	checkListsEQ(str1, str);

	ft::list<float> flo;
	flo.push_back(1.9);
	flo.push_back(2.9);
	flo.push_back(3.9);
	flo.push_back(4.9);

	ft::list<float>::const_iterator c_it = flo.begin();
	for (; c_it != flo.end(); c_it++){
	std::cout << *c_it << " ";
	}
	std::cout << std::endl;

	ft::list<float>::const_reverse_iterator cr_it = flo.rbegin();
	for (; cr_it != flo.rend(); cr_it++){
	std::cout << *cr_it << " ";
	}
	std::cout << std::endl;

	std::list<float> flo1;
	flo1.push_back(1.9);
	flo1.push_back(2.9);
	flo1.push_back(3.9);
	flo1.push_back(4.9);
	checkListsEQ(flo1, flo);
}

TEST(ListTests, assignOperator) {
	ft::list<int> ft_first (3);      // list of 3 zero-initialized ints
	ft::list<int> ft_second (5);     // list of 5 zero-initialized ints
	ft_second = ft_first;
	ft_first = ft::list<int>();

	std::list<int> st_first (3);      // list of 3 zero-initialized ints
	std::list<int> st_second (5);     // list of 5 zero-initialized ints
	st_second = st_first;
	st_first = std::list<int>();

	EXPECT_EQ(ft_first.size(), st_first.size());
	EXPECT_EQ(ft_second.size(), st_second.size());

	ft::list<int> one(21, 21);
	ft::list<int> two = one;
	ft::list<int>::iterator it = two.begin();
	ft::list<int>::iterator ite = two.end();
	for (; it != ite; it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

TEST(ListTests, size) {
	stList st2(10);
	ftList ft2(10);

	EXPECT_EQ(st2.size(), ft2.size());
	st2.push_back(4);
	st2.push_back(5);
	st2.push_back(6);
	ft2.push_back(4);
	ft2.push_back(5);
	ft2.push_back(6);
	EXPECT_EQ(st2.size(), ft2.size());
}

TEST(ListTests, empty) {
	stList st2(10);
	ftList ft2(10);
	EXPECT_EQ(st2.empty(), ft2.empty());

	st2.clear();
	ft2.clear();
	EXPECT_EQ(st2.empty(), ft2.empty());
}

TEST(ListTests, max_size) {
	stList st2(10);
	ftList ft2(10);
	EXPECT_EQ(st2.max_size(), ft2.max_size());
	stList st3;
	ftList ft3;
	EXPECT_EQ(st3.max_size(), ft3.max_size());
	std::cout << st3.max_size() << std::endl << ft3.max_size();
}

TEST(ListTests, clear) {
	stList st6(7,8);
	ftList ft6(7,8);

	EXPECT_EQ(st6.size(), ft6.size());
	ft6.clear();
	st6.clear();
	EXPECT_EQ(st6.size(), ft6.size());
}

TEST(ListTests, push_front) {
	ft::list<int> ft_intlist;
	ft_intlist.push_front(10);
	ft_intlist.push_front(12);
	ft_intlist.push_front(6);
	std::list<int> st_intlist;
	st_intlist.push_front(10);
	st_intlist.push_front(12);
	st_intlist.push_front(6);

	ft::list<int>::iterator ft_it = ft_intlist.begin();
	ft::list<int>::iterator ft_ite = ft_intlist.end();

	std::list<int>::iterator st_it = st_intlist.begin();
	while (ft_it != ft_ite) {
		EXPECT_EQ(*ft_it, *st_it);
		ft_it++;
		st_it++;
	}
	EXPECT_EQ(ft_intlist.size(), st_intlist.size());
}

TEST(ListTests, push_back) {
	ft::list<int> ft_intlist;
	ft_intlist.push_back(10);
	ft_intlist.push_back(12);
	ft_intlist.push_back(6);
	std::list<int> st_intlist;
	st_intlist.push_back(10);
	st_intlist.push_back(12);
	st_intlist.push_back(6);

	ft::list<int>::iterator ft_it = ft_intlist.begin();
	ft::list<int>::iterator ft_ite = ft_intlist.end();

	std::list<int>::iterator st_it = st_intlist.begin();
	while (ft_it != ft_ite) {
		EXPECT_EQ(*ft_it, *st_it);
		std::cout << *ft_it << ' ' << *st_it << std::endl;
		ft_it++;
		st_it++;
	}
	EXPECT_EQ(ft_intlist.size(), st_intlist.size());
}

TEST(ListTests, begin) {
	ft::list<int> ft_2;
	ft_2.push_back(10);
	ft_2.push_back(12);
	ft_2.push_back(6);
	std::list<int> st_2;
	st_2.push_back(10);
	st_2.push_back(12);
	st_2.push_back(6);
	EXPECT_EQ(*ft_2.begin(), *st_2.begin());

	ft::list<int> ft_1(10, 6);
	std::list<int> st_1(10, 6);
	EXPECT_EQ(*ft_2.begin(), *st_2.begin());

	ft::list<int> ft_3;
	EXPECT_EQ(0, *ft_3.begin());
}

TEST(ListTests, end) {
	ft::list<int> ft_2;
	ft_2.push_back(10);
	ft_2.push_back(12);
	ft_2.push_back(6);
	std::list<int> st_2;
	st_2.push_back(10);
	st_2.push_back(12);
	st_2.push_back(6);
	EXPECT_EQ(*--ft_2.end(), *--st_2.end());

	ft::list<int> ft_1(10, 6);
	std::list<int> st_1(10, 6);
	EXPECT_EQ(*--ft_2.end(), *--st_2.end());
}

TEST(ListTests, pop_front) {
//	std::list<int> seg;   //empty original segfaults
//	seg.pop_front();

	ft::list<int> ft_2;
	ft_2.push_back(10);
	ft_2.push_back(12);
	ft_2.push_back(6);
	std::list<int> st_2;
	st_2.push_back(10);
	st_2.push_back(12);
	st_2.push_back(6);

	EXPECT_EQ(*ft_2.begin(), *st_2.begin());
	EXPECT_EQ(ft_2.size(),st_2.size());
	ft_2.pop_front();
	st_2.pop_front();
	EXPECT_EQ(*ft_2.begin(), *st_2.begin());
	EXPECT_EQ(ft_2.size(),st_2.size());

	ft::list<std::string> B;
	B.push_back("hello word");
	ft::list<std::string>::iterator iter = B.begin();
	std::cout << *iter << std::endl;
	B.pop_front();
	std::cout << *(++iter) << std::endl;
	std::cout << B.size() << std::endl;
}

TEST(ListTests, pop_back) {
//	std::list<int> seg;   //empty original segfaults
//	seg.pop_front();

	ft::list<int> ft_2;
	ft_2.push_back(10);
	ft_2.push_back(12);
	ft_2.push_back(6);
	std::list<int> st_2;
	st_2.push_back(10);
	st_2.push_back(12);
	st_2.push_back(6);

	EXPECT_EQ(*ft_2.begin(), *st_2.begin());
	EXPECT_EQ(ft_2.size(),st_2.size());
	ft_2.pop_back();
	st_2.pop_back();
	EXPECT_EQ(*ft_2.begin(), *st_2.begin());
	EXPECT_EQ(ft_2.size(),st_2.size());
}

TEST(ListTests, front) {
	ft::list<int> ft_2;
	ft_2.push_back(10);
	ft_2.push_back(12);
	ft_2.push_back(6);
	std::list<int> st_2;
	st_2.push_back(10);
	st_2.push_back(12);
	st_2.push_back(6);

	std::cout << ft_2.front() << std::endl;
	std::cout << st_2.front() << std::endl;
}

TEST(ListTests, back) {
	ft::list<int> ft_2;
	ft_2.push_back(10);
	ft_2.push_back(12);
	ft_2.push_back(6);
	std::list<int> st_2;
	st_2.push_back(10);
	st_2.push_back(12);
	st_2.push_back(6);

	std::cout << ft_2.back() << std::endl;
	std::cout << st_2.back() << std::endl;
}

TEST(ListTests, swap) {
	ft::list<int> foo (3,100);   // three ints with a value of 100
	ft::list<int> bar (5,200);   // five ints with a value of 200

	ft::swap(foo,bar);

	std::cout << "foo contains:";
	for (ft::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (ft::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << '\n';

	std::list<int> st_foo (3,100);   // three ints with a value of 100
	std::list<int> st_bar (5,200);   // five ints with a value of 200

	std::swap(st_foo,st_bar);

	std::cout << "st_foo contains:";
	for (std::list<int>::iterator it = st_foo.begin(); it!=st_foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "st_bar contains:";
	for (std::list<int>::iterator it = st_bar.begin(); it!=st_bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

TEST(ListTests, relationalOperators) {
	std::list<int> a(10,5);
	std::list<int> b(10, 5);
	std::list<int> c(5,10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";


	ft::list<int> ft_a(10,5);
	ft::list<int> ft_b(10, 5);
	ft::list<int> ft_c(5,10);

	std::cout << "___________________" << std::endl;
	if (ft_a==ft_b) std::cout << "a and b are equal\n";
	if (ft_b!=ft_c) std::cout << "b and c are not equal\n";
	if (ft_b<ft_c) std::cout << "b is less than c\n";
	if (ft_c>ft_b) std::cout << "c is greater than b\n";
	if (ft_a<=ft_b) std::cout << "a is less than or equal to b\n";
	if (ft_a>=ft_b) std::cout << "a is greater than or equal to b\n";
}

TEST(ListTests, assign) {
	std::list<int> first;
	std::list<int> second;

	first.assign (7,100);
	second.assign (first.begin(),first.end());

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';


	std::cout << "___________________" << std::endl;

	ft::list<int> ft_first;
	ft::list<int> ft_second;

	ft_first.assign (7,100);

	ft::list<int>::const_iterator test_begin = ft_first.begin(); // const_iterator example
	ft::list<int>::const_iterator test_end = ft_first.end();
	ft_second.assign(test_begin, test_end);


	std::cout << "Size of first: " << int (ft_first.size()) << '\n';
	std::cout << "Size of second: " << int (ft_second.size()) << '\n';
}

TEST(ListTests, insert) {
	ftList mylist;

	mylist.push_back(10);
	mylist.push_back(2);

	/* single element */
	ft::list<int>::iterator it = mylist.begin();

	EXPECT_EQ(2, mylist.size());
	EXPECT_EQ(10, *it);
	EXPECT_EQ(2, *--mylist.end());

	ft::list<int>::iterator res = mylist.insert(it, 16);
	EXPECT_EQ(3, mylist.size());
	EXPECT_EQ(16, *mylist.begin());
	it = mylist.begin();
	for (; it!=mylist.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';
	std::cout << "Returned iterator points to " << *res << std::endl;

	/* fill */
	it = mylist.begin();
	it++;
	mylist.insert (it,3,20);
	EXPECT_EQ(6, mylist.size());
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	/* range */
	it = mylist.begin();
	it++;
	it++;
	std::list<int> ran(2,80);
	ran.push_back(154);
	mylist.insert (it, ran.begin(), ran.end());
	EXPECT_EQ(9, mylist.size());
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

TEST(ListTests, erase) {
//	std::list<int> seg;   //empty original segfaults
//	seg.pop_front();

	ftList mylist;
	for (int i = 0; i < 5; i++)
		mylist.push_back(i);
	std::cout << "size before remove: " << mylist.size() << std::endl;
	ft::list<int>::iterator it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	EXPECT_EQ(5, mylist.size());

	it = mylist.begin();
	++it;
	ft::list<int>::iterator res = mylist.erase(it);
	std::cout << "size after remove: " << mylist.size() << std::endl;
	std::cout << "Returned iterator points to " << *res << std::endl;
	EXPECT_EQ(4, mylist.size());
	it = mylist.begin();
	for (; it!=mylist.end(); ++it) {
		std::cout << ' ' << *it;
	}
	std::cout << '\n';

	/* ranged */
	ft::list<int>::iterator itb = mylist.begin();
	itb++;
	ft::list<int>::iterator ite = mylist.end();
	--ite;
	res = mylist.erase(itb, ite);
	std::cout << "size after remove: " << mylist.size() << std::endl;
	std::cout << "Returned iterator points to " << *res << std::endl;
	EXPECT_EQ(2, mylist.size());
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

TEST(ListTests, swap_member) {
	ft::list<int> first (3,100);   // three ints with a value of 100
	ft::list<int> second (5,200);  // five ints with a value of 200
	ft::list<int>::iterator it1 = first.begin();
	ft::list<int>::iterator ite1 = first.end();
	ft::list<int>::iterator it2 = second.begin();
	ft::list<int>::iterator ite2 = second.end();

	first.swap(second);

	std::cout << "first  contains:";
	for (; it1 != ite1; it1 ++)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	std::cout << "second contains:";
	for (; it2 != ite2; it2++)
		std::cout << ' ' << *it2;
	std::cout << '\n';


	it1 = first.begin();
	ite1 = first.end();
	it2 = second.begin();
	ite2 = second.end();
	std::cout << "first  contains:";
	for (; it1 != ite1; it1 ++)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	std::cout << "second contains:";
	for (; it2 != ite2; it2++)
		std::cout << ' ' << *it2;
	std::cout << '\n';

	std::cout << std::endl << "Empty and not empty: " << std::endl;
	ft::list<int> A;
	ft::list<int> B (5,200);
	for (ft::list<int>::iterator iter = A.begin(); iter!=A.end(); ++iter)
		std::cout << ' ' << *iter;
	std::cout << '\n';
	A.swap(B);
	for (ft::list<int>::iterator iter = A.begin(); iter!=A.end(); ++iter)
		std::cout << ' ' << *iter;
	std::cout << '\n';

}

TEST(ListTests, resize) {
	ft::list<int> mylist;

	for (int i=1; i<10; ++i) mylist.push_back(i);
	EXPECT_EQ(9, mylist.size());
	ft::list<int>::iterator it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.resize(5);
	EXPECT_EQ(5, mylist.size());
	std::cout << "new size: " << mylist.size() << std::endl;
	ft::list<int>::iterator itb = mylist.begin();
	for (; itb!=mylist.end(); ++itb)
		std::cout << ' ' << *itb;
	std::cout << '\n';

	mylist.resize(15);
	EXPECT_EQ(15, mylist.size());
	std::cout << "new size: " << mylist.size() << std::endl;
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.resize(18,100);
	EXPECT_EQ(18, mylist.size());
	std::cout << "new size: " << mylist.size() << std::endl;
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

TEST(ListTests, splice) {
	ft::list<int> mylist1;
	ft::list<int> mylist2;

	for (int i=1; i<=4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i=1; i<=3; ++i)
		mylist2.push_back(i*10);

	ft::list<int>::iterator it = mylist1.begin();
//	++it;                         // points to 2

	mylist1.splice (it, mylist2);

	it = mylist1.begin();
	for (; it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	it = mylist1.begin();
	++it;
	mylist2.splice (mylist2.begin(),mylist1, it);
	it = mylist2.begin();
	for (; it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	it = mylist1.begin();
	for (; it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "mylist1 size: "<< mylist1.size() << std::endl;


	it = mylist1.begin();
	++it;
	++it;
	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
	std::cout << "mylist1 contains:";
	for (it=mylist1.begin(); it!=mylist1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "mylist1 size: "<< mylist1.size() << std::endl;
}

TEST(ListTests, remove) {
	ftList mylist;

	mylist.push_back(10);
	mylist.push_back(123);
	mylist.push_back(101);
	mylist.push_back(10);

	EXPECT_EQ(4, mylist.size());
	mylist.remove(10);
	EXPECT_EQ(2, mylist.size());
	EXPECT_EQ(123, *mylist.begin());
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value % 2) == 1; }
};

TEST(ListTests, remove_if) {
	ftList mylist;

	for (int i = 0; i < 30; i++)
		mylist.push_back(i);

	EXPECT_EQ(30, mylist.size());
	mylist.remove_if(single_digit);
	EXPECT_EQ(20, mylist.size());

	mylist.remove_if (is_odd());
	EXPECT_EQ(10, mylist.size());
}

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

TEST(ListTests, unique) {
	ftList mylist(3, 5);

	mylist.push_back(10);
	mylist.push_back(123);
	mylist.push_back(101);
	mylist.push_back(10);

	EXPECT_EQ(7, mylist.size());
	mylist.unique();
	EXPECT_EQ(5, mylist.size());
	ft::list<int>::iterator it = mylist.begin();
	std::cout << "mylist after remove: ";
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	/* =======std====== */
	stList mylist1(3, 5);

	mylist1.push_back(10);
	mylist1.push_back(123);
	mylist1.push_back(101);
	mylist1.push_back(10);

	EXPECT_EQ(7, mylist1.size());
	mylist1.unique();
	EXPECT_EQ(5, mylist1.size());
	std::list<int>::iterator it1 = mylist1.begin();
	std::cout << "stlist after remove: ";
	for (; it1!=mylist1.end(); ++it1)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	/* BinaryPredicate */
	ft::list<double> list;

	list.push_back(12.4);
	list.push_back(12.2);
	list.push_back(16.11);
	list.push_back(89.4);
	list.push_back(89.7);

	list.unique(same_integral_part);
	EXPECT_EQ(3, list.size());
	ft::list<double>::iterator itf = list.begin();
	std::cout << "binaryPredicate after remove: ";
	for (; itf!=list.end(); ++itf)
		std::cout << ' ' << *itf;
	std::cout << '\n';


	ft::list<int> ls;

	ls.push_back(5);
	ls.push_back(5);
	ls.push_back(4);
	ls.push_back(3);
	ls.push_back(5);
	ls.push_back(5);

	ls.unique();
	EXPECT_EQ(4, ls.size());
	it = ls.begin();
	std::cout << "list after remove: ";
	for (; it!=ls.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "From cplusplus: " << std::endl;
	double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
						 12.77, 73.35, 72.25, 15.3,  72.25 };
	ft::list<double> mylist4(mydoubles, mydoubles+10);

	mylist4.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
	// 15.3,  72.25, 72.25, 73.0,  73.35

	mylist4.unique();           //  2.72,  3.14, 12.15, 12.77
	// 15.3,  72.25, 73.0,  73.35

	mylist4.unique (same_integral_part);  //  2.72,  3.14, 12.15
	// 15.3,  72.25, 73.0

	mylist4.unique (is_near());           //  2.72, 12.15, 72.25

	std::cout << "mylist contains:";
	for (ft::list<double>::iterator iter=mylist4.begin(); iter!=mylist4.end(); ++iter)
		std::cout << ' ' << *iter;
	std::cout << '\n';
}

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

bool compare_int(const int& x, const int& y) {return x < y;}

TEST(ListTests, sort) {
	ftList mylist(1, 5);

	mylist.push_back(10);
	mylist.push_back(123);
	mylist.push_back(101);
	mylist.push_back(10);

	std::cout << "list before sort: ";
	ft::list<int>::iterator it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.sort();
	std::cout << "list  after sort: ";
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.sort();
	std::cout << "list  after next sort: ";
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.sort();
	std::cout << "list  after next sort: ";
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist.sort();
	std::cout << "list  after next sort: ";
	it = mylist.begin();
	for (; it!=mylist.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ftList mylist2;
	mylist2.push_back(5);
	mylist2.push_back(8);
	mylist2.push_back(1);
	mylist2.push_back(1);
	std::cout << std::endl << "another list before sort: ";
	it = mylist2.begin();
	for (; it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	mylist2.sort();
	std::cout << "another list  after sort: ";
	it = mylist2.begin();
	for (; it!=mylist2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	/* string */
	ft::list<std::string> str;

	str.push_back("one");
	str.push_back("two");
	str.push_back("Three");

	str.sort();
	std::cout << "mylist contains:";
	ft::list<std::string>::iterator itd = str.begin();
	for (; itd!=str.end(); ++itd)
		std::cout << ' ' << *itd;
	std::cout << '\n';
	EXPECT_EQ(3,str.size());

	str.sort(compare_nocase);

	std::cout << "mylist contains:";
	itd = str.begin();
	for (itd=str.begin(); itd!=str.end(); ++itd)
		std::cout << ' ' << *itd;
	std::cout << '\n';


	ft::list<int> A;
	A.push_front(2);
	A.push_front(3400);
	A.push_front(400);
	A.push_front(230);
	A.push_front(3);
	A.push_front(450);
	A.push_front(23);
	A.push_front(34);
	A.push_front(4);

	std::list<int> B;
	B.push_front(2);
	B.push_front(3400);
	B.push_front(400);
	B.push_front(230);
	B.push_front(3);
	B.push_front(450);
	B.push_front(23);
	B.push_front(34);
	B.push_front(4);

	A.sort(compare_int);
	std::cout << "FT list  after sort: ";
	ft::list<int>::iterator iter = A.begin();
	for (; iter != A.end(); ++iter)
		std::cout << ' ' << *iter;
	std::cout << '\n';
	B.sort(compare_int);
	std::cout << "ST list  after sort: ";
	std::list<int>::iterator itera = B.begin();
	for (; itera != B.end(); ++itera)
		std::cout << ' ' << *itera;
	std::cout << '\n';
}

TEST(ListTests, reverse) {
	ftList list;

	for(int i = 1; i < 10; i++){
		list.push_back(i);
	}
	ft::list<int>::iterator it = list.begin();
	std::cout << "mylist before reverse: ";
	for (; it!=list.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	ft::list<int>::iterator test = list.begin();
	test++;
	std::cout << "it before: " << *test << std::endl;

	list.reverse();

	std::cout << "mylist  after reverse: ";
	it = list.begin();
	for (; it!=list.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "it after: " << *test << std::endl;

}

bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

TEST(ListTests, merge) {
	ft::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	first.merge(second);
	EXPECT_EQ(0, second.size());
	EXPECT_EQ(6, first.size());
	ft::list<double>::iterator it = first.begin();
	for (; it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	second.push_back (2.1);
	first.merge(second, mycomparison);

	it = first.begin();
	for (; it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	/* unsorted */
	second.push_back (15.8);
	second.push_back (7.9);
	second.push_back (12.4);
	second.push_back (2.3);
	first.merge(second);
	std::cout << std::endl << "mio with unsorted: ";
	 it = first.begin();
	for (; it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::list<double> sam;
	std::list<double> samFirst = {1.4, 2.2, 2.9, 2.1, 3.1, 3.7, 7.1};
	sam.push_back (15.8);
	sam.push_back (7.9);
	sam.push_back (12.4);
	sam.push_back (2.3);
	samFirst.merge(sam);
	std::cout << "std with unsorted: ";
	std::list<double>::iterator its = samFirst.begin();
	for (; its!=samFirst.end(); ++its)
		std::cout << ' ' << *its;
	std::cout << '\n';

	//------------------
	ft::list<double> fir;
	ft::list<double> sec;
	fir.push_back(19.8);
	fir.push_back(9.0);
	fir.push_back(9.1);
	sec.push_back (15.8);
	sec.push_back (7.9);
	sec.push_back (20.4);
	sec.push_back (2.3);
	fir.merge(sec);
	std::cout << std::endl << "mio with unsorted: ";
	ft::list<double>::iterator it5 = fir.begin();
	for (; it5!=fir.end(); ++it5)
		std::cout << ' ' << *it5;
	std::cout << '\n';

	std::list<double> sam1;
	std::list<double> samFirst1;
	sam1.push_back(19.8);
	sam1.push_back(9.0);
	sam1.push_back(9.1);
	samFirst1.push_back (15.8);
	samFirst1.push_back (7.9);
	samFirst1.push_back (20.4);
	samFirst1.push_back (2.3);
	sam1.merge(samFirst1);
	std::cout << "std with unsorted: ";
	std::list<double>::iterator it8 = sam1.begin();
	for (; it8!=sam1.end(); ++it8)
		std::cout << ' ' << *it8;
	std::cout << '\n';
}

//TEST(ListTests, leaks) {
//	while(1);
//}

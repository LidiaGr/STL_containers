//
// Created by Lidia Grigoreva on 05/02/2021.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../srcs/set.hpp"
#include <set>
#include <string>

class myTestSetFixture: public ::testing::Test {
public:
	myTestSetFixture( ) {
		stSet = new std::set<int>;
		ftSet = new ft::set<int>;
		// код инициализации
	}

	void SetUp( ) {
		for(size_t i = 1; i < 16; i++) {
			stSet->insert(i);
			ftSet->insert(i);
		}

		itFT = ftSet->begin();
		iteFT = ftSet->end();

		itST = stSet->begin();
		iteST = stSet->end();
		// код, который будет выполнен перед началом теста
	}

	void TearDown( ) {
		// код, который будет выполнен сразу по завершении теста
		// при необходимости здесь можно вызывать исключения
	}

	~myTestSetFixture( )  {
		delete stSet;
		delete ftSet;
		// очистка всех ресурсов, вызов исключений не допускается
	}
	std::set<int> *stSet;
	ft::set<int> *ftSet;

	ft::set<int>::iterator itFT;
	ft::set<int>::iterator iteFT;

	std::set<int>::iterator itST;
	std::set<int>::iterator iteST;
};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>> >
void checkSetsEQ(std::set<Key, T> &st, ft::set<Key, T> &ft) {
	EXPECT_EQ(st.size(), ft.size());

	auto stIt = st.begin();

	typename ft::set<Key, T>::iterator ftIt = ft.begin();
	typename ft::set<Key, T>::iterator ftIte = ft.end();
	while(ftIt != ftIte){
		EXPECT_EQ(*stIt, *ftIt);
		ftIt++;
		stIt++;
	}
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>> >
void printContentFT(std::string str, ft::set<Key, T> &ft) {
	std::cout << str << " ";
	typename ft::set<Key, T>::iterator it = ft.begin();
	typename ft::set<Key, T>::iterator ite = ft.end();
	while (it != ite){
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>> >
void printContentST(std::string str, std::set<Key, T> &st) {
	std::cout << str << " ";
	typename std::set<Key, T>::iterator it = st.begin();
	typename std::set<Key, T>::iterator ite = st.end();
	while (it != ite){
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

TEST(SetTest, insert) {
	std::set<char>stSet;
	ft::set<char>ftSet;
	stSet.insert('a');
	stSet.insert('g');
	ftSet.insert('a');
	ftSet.insert('g');

	// insert (single parameter):
	std::pair<std::set<char>::iterator,bool> retst;
	std::pair<ft::set<char>::iterator,bool> retft;
	retst = stSet.insert('g');
	retft = ftSet.insert('g');
	if (retst.second == false) {
		std::cout << "element 'g' already existed";
		std::cout << " with a value of " << *retst.first << '\n';
	}
	if (retft.second == false) {
		std::cout << "element 'g' already existed";
		std::cout << " with a value of " << *retft.first<< '\n';
	}
	printContentFT("FT set contains: ", ftSet);
	checkSetsEQ(stSet, ftSet);

	// position (hint)
	std::set<char>::iterator it = stSet.begin();
	stSet.insert (it, 'b');  // max efficiency inserting
	stSet.insert (it, 'c');

	ft::set<char>::iterator itf = ftSet.begin();
	ftSet.insert (itf, 'b');  // max efficiency inserting
	ftSet.insert (itf, 'c');

	// ranged
	std::set<char> stSet1;
	ft::set<char> ftSet1;
	stSet1.insert('f');
	ftSet1.insert('f');

	stSet1.insert(stSet.begin(), stSet.end());
	ftSet1.insert(ftSet.begin(), ftSet.end());
	checkSetsEQ(stSet1, ftSet1);

	std::cout << std::endl;
	printContentST("ST set after ranged insert:", stSet1);
	printContentFT("FT set after ranged insert:", ftSet1);
}

TEST_F(myTestSetFixture, begin) {
	ftSet->insert(1);
	stSet->insert(1);
	EXPECT_EQ(*ftSet->begin(), *stSet->begin());
	std::cout << "Begin Key: " << *ftSet->begin() << std::endl;
	printContentFT("FT set Content: ", *ftSet);
	printContentST("ST set Content: ", *stSet);

	ftSet->insert(-7);
	stSet->insert(-7);
	EXPECT_EQ(*ftSet->begin(), *stSet->begin());
	std::cout << "Begin Key: " << *ftSet->begin() << std::endl;
	printContentFT("FT set Content: ", *ftSet);
	printContentST("ST set Content: ", *stSet);
	checkSetsEQ(*stSet, *ftSet);
}

TEST_F(myTestSetFixture, end) {
	typename ft::set<int>::iterator it = ftSet->begin();
	typename ft::set<int>::iterator ite = ftSet->end();
	ite--;
	while (it != ite){
		std::cout << *ite << " ";
		ite--;
	}
	std::cout << *ite << " ";
	std::cout << std::endl;

	typename std::set<int>::iterator its = stSet->begin();
	typename std::set<int>::iterator ites = stSet->end();
	ites--;
	while (its != ites){
		std::cout << *ites << " ";
		ites--;
	}
	std::cout << *ites << " ";
	std::cout << std::endl;
	EXPECT_EQ(*(--ftSet->end()), *(--stSet->end()));

//	ites = stSet->end();               //no segfault
//	std::cout << ites << " ";
//	ite = ftSet->end();
//	std::cout << ite;
}

TEST(SetTest, iterators) {
	ft::set<std::string> str;
	str.insert("world");
	str.insert("today");
	str.insert("hello");

	ft::set<std::string>::iterator it = str.begin();
	for (; it != str.end(); it++){
		std::cout << *it << " |  ";
	}
	std::cout << std::endl;

	ft::set<std::string>::reverse_iterator r_it = str.rbegin();
	for (; r_it != str.rend(); r_it++){
		std::cout << *r_it << " |  ";
	}
	std::cout << std::endl;

	std::set<std::string> str1;
	str1.insert("hello");
	str1.insert("today");
	str1.insert("world");
	checkSetsEQ(str1, str);

	ft::set<float> flo;
	flo.insert(1.9);
	flo.insert(4.9);
	flo.insert(2.9);
	flo.insert(3.9);

	ft::set<float>::const_iterator c_it = flo.begin();
	for (; c_it != flo.end(); c_it++){
		std::cout << *c_it  << " |  ";
	}
	std::cout << std::endl;

	ft::set<float>::const_reverse_iterator cr_it = flo.rbegin();
	for (; cr_it != flo.rend(); cr_it++){
		std::cout << *cr_it << " |  ";
	}
	std::cout << std::endl;

	std::set<float> flo1;
	flo1.insert(2.9);
	flo1.insert(3.9);
	flo1.insert(1.9);
	flo1.insert(4.9);
	checkSetsEQ(flo1, flo);
}

TEST_F(myTestSetFixture, begin_rbegin) {
	EXPECT_EQ(*ftSet->begin(), *stSet->begin());
	ftSet->insert(-10);
	stSet->insert(-10);
	EXPECT_EQ(*ftSet->begin(), *stSet->begin());

	EXPECT_EQ(*ftSet->rbegin(), *stSet->rbegin());
	ftSet->insert(100);
	stSet->insert(100);
	EXPECT_EQ(*ftSet->rbegin(), *stSet->rbegin());
	checkSetsEQ(*stSet, *ftSet);
}

TEST_F(myTestSetFixture, end_rend) {
	EXPECT_EQ(*--ftSet->end(), *--stSet->end());
	ftSet->insert(100);
	stSet->insert(100);
	EXPECT_EQ(*--ftSet->end(), *--stSet->end());

	EXPECT_EQ(*--ftSet->rend(), *--stSet->rend());
	ftSet->insert(-10);
	stSet->insert(-10);
	EXPECT_EQ(*--ftSet->rend(), *--stSet->rend());
	checkSetsEQ(*stSet, *ftSet);
}

TEST(SetTest, constructors) {
	// default
	std::set<int> st1;
	ft::set<int>  ft1;
	checkSetsEQ(st1, ft1);

	// ranged
	st1.insert(5);
	st1.insert(1);
	st1.insert(50);
	ft1.insert(5);
	ft1.insert(1);
	ft1.insert(50);

	std::set<int>::iterator stIt1 = st1.begin();
	std::set<int>::iterator stIte1 = st1.end();
	ft::set<int>::iterator ftIt1 = ft1.begin();
	ft::set<int>::iterator ftIte1 = ft1.end();
	stIt1++;
	stIte1--;
	ftIt1++;
	ftIte1--;

	std::set<int> st3(stIt1, stIte1);
	ft::set<int>  ft3(ftIt1, ftIte1);
	checkSetsEQ(st3, ft3);

	//copy
	std::set<int> st4(st3);
	ft::set<int>  ft4(ft3);
	checkSetsEQ(st4, ft4);


	// default
	std::set<double> st1Cl;
	ft::set<double>  ft1Cl;
	checkSetsEQ(st1Cl, ft1Cl);

	// ranged
	st1Cl.insert(5.3);
	st1Cl.insert(1.8);
	ft1Cl.insert(5.3);
	ft1Cl.insert(1.8);

	std::set<double>::iterator stIt2 = st1Cl.begin();
	std::set<double>::iterator stIte2 = st1Cl.end();
	ft::set<double>::iterator ftIt2 = ft1Cl.begin();
	ft::set<double>::iterator ftIte2 = ft1Cl.end();
	stIt2++;
	stIte2--;
	ftIt2++;
	ftIte2--;

	std::set<double> st4Str(stIt2, stIte2);
	ft::set<double>  ft4Str(ftIt2, ftIte2);
	checkSetsEQ(st4Str, ft4Str);

	//copy
	std::set<double> st5(st4Str);
	ft::set<double>   ft5(ft4Str);
	checkSetsEQ(st5, ft5);
}

TEST_F(myTestSetFixture, size) {
	EXPECT_EQ(ftSet->size(), stSet->size());
	ftSet->insert(-10);
	stSet->insert(-10);
	EXPECT_EQ(stSet->size(), ftSet->size());

	std::set<int> st1;
	ft::set<int>  ft1;

	st1.insert(5);
	st1.insert(1);
	st1.insert(50);
	ft1.insert(5);
	ft1.insert(1);
	ft1.insert(50);
	EXPECT_EQ(st1.size(), ft1.size());
}

TEST_F(myTestSetFixture, empty) {
	EXPECT_EQ(ftSet->empty(), stSet->empty());

	std::set<char> st;
	ft::set<char> ft;
	EXPECT_EQ(st.empty(), ft.empty());
}

TEST_F(myTestSetFixture, max_size) {
	int i;
	ft::set<int> myset;

	if (myset.max_size()>1000)
	{
		for (i=0; i<1000; i++) myset.insert(i);
		std::cout << "The set contains 1000 elements.\n";
	}
	else std::cout << "The set could not hold 1000 elements.\n";
}

TEST_F(myTestSetFixture, erase) {
	ft::set<int> sega;
	for(size_t i = 1; i < 9; i++)
		sega.insert(i);
	printContentFT("Before: ", sega);
	sega.erase(1);
	printContentFT("After : ", sega);

	ftSet->erase(itFT);
	stSet->erase(itST);
	printContentFT("FT after erase", *ftSet);
	printContentST("ST after erase", *stSet);
	checkSetsEQ(*stSet, *ftSet);

	itFT = ftSet->begin();
	itST = stSet->begin();
	itFT++;
	itFT++; // should remove 4
	itST++;
	itST++;
	ftSet->erase(itFT);
	stSet->erase(itST);
	printContentFT("FT after second erase", *ftSet);
	printContentST("ST after second erase", *stSet);
	checkSetsEQ(*stSet, *ftSet);

	// key of the element
	ftSet->erase(8);
	stSet->erase(8);
	printContentFT("FT after KEY erase", *ftSet);
	printContentST("ST after KEY erase", *stSet);
	checkSetsEQ(*stSet, *ftSet);

	//ranged
//	ftSet->print();
	itFT = ftSet->begin();
	itST = stSet->begin();
	for (int i = 1; i < 3; i++) { itFT++; itST++; };
	ft::set<int>::iterator firstft = itFT;
	std::set<int>::iterator firstst = itST;
	for (int i = 1; i < 2; i++) { itFT++; itST++; };
	ftSet->erase(firstft, itFT);
	stSet->erase(firstst, itST);
//	ftSet->print();
	printContentFT("FT after ranged erase", *ftSet);
	printContentST("ST after ranged erase", *stSet);
	checkSetsEQ(*stSet, *ftSet);

	std::set<int>::iterator it_std_first = ++stSet->begin();
	std::set<int>::iterator it_std_second = --stSet->end();
	ft::set<int>::iterator it_ft_first = ++ftSet->begin();
	ft::set<int>::iterator it_ft_second = --ftSet->end();

//	std::cout << std::endl << std::endl;
//	ftSet->print();
	std::cout << std::endl;
	for (int i = 0; i < 2; i++) {
		++it_std_first;
		++it_ft_first;
		--it_std_second;
		--it_ft_second;
	}
	std::cout << *it_ft_first << " " << *it_ft_second << "\n";
	stSet->erase(it_std_first, it_std_second);
	ftSet->erase(it_ft_first, it_ft_second);
//	ftSet->print();
}

TEST_F(myTestSetFixture, find) {
	int k = 14;
	itFT = ftSet->find(k);
	std::cout << *itFT << std::endl;
	EXPECT_EQ(14, *itFT);

	k = 20;
	itFT = ftSet->find(k);
	if (itFT == ftSet->end())
		std::cout << "No such Key \"" << k << "\" in the set Container" << std::endl;
}

TEST_F(myTestSetFixture, count) {
	int k = 14;
	size_t i = ftSet->count(k);
	EXPECT_EQ(1, i);

	k = 20;
	i = ftSet->count(k);
	EXPECT_EQ(0, i);
}

TEST_F(myTestSetFixture, clear) {
	ftSet->clear();
	stSet->clear();
	printContentFT("FT after clear: ", *ftSet);
	printContentST("ST after clear: ", *stSet);
	EXPECT_EQ(0, ftSet->size());
}

TEST(SetTest, assignOperator) {
	std::set<int> st7;
	ft::set<int> ft7;

	st7.insert(12);
	st7.insert(5);
	ft7.insert(12);
	ft7.insert(5);

	std::set<int> st8(st7);
	ft::set<int> ft8(ft7);
	checkSetsEQ(st8, ft7);

	st8.insert(14);
	st8.insert(3);
	ft8.insert(14);
	ft8.insert(3);

	st7 = st8;
	ft7 = ft8;
	printContentFT("FT contents ", ft7);
	printContentST("ST contents ", st7);
	checkSetsEQ(st7, ft7);
}

TEST(SetTest, swapMember) {
	int myints[]={12,75,10,32,20,25};
	ft::set<int> first (myints,myints+3);     // 10,12,75
	ft::set<int> second (myints+3,myints+6);  // 20,25,32

	first.swap(second);

	std::cout << "first contains:";
	for (ft::set<int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (ft::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

TEST(SetTest, keyCompare) {
	ft::set<int> myset;
	int highest;

	ft::set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	highest=*myset.rbegin();
	ft::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
}

TEST(SetTest, valueCompare) {
	ft::set<int> myset;

	ft::set<int>::value_compare mycomp = myset.value_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	int highest=*myset.rbegin();
	ft::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
}

TEST(SetTest, lowerBound_upperBound) {
	ft::set<int> myset;
	ft::set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

	itlow=myset.lower_bound (30);                //       ^
	itup=myset.upper_bound (60);                 //                   ^

	myset.erase(itlow,itup);                     // 10 20 70 80 90

	std::cout << "myset contains:";
	for (ft::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

TEST(SetTest, equal_range) {
	std::set<int> myset;

	for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

	std::pair<std::set<int>::const_iterator,std::set<int>::const_iterator> ret;
	ret = myset.equal_range(30);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
}

//TEST(LEAKS, leaks) {
//	while(1);
//}
//
// Created by Lidia Grigoreva on 05/02/2021.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../srcs/map.hpp"
#include <map>
#include <string>

class myTestMapFixture: public ::testing::Test {
public:
	myTestMapFixture( ) {
		stMap = new std::map<int, std::string>;
		ftMap = new ft::map<int, std::string>;
		// код инициализации
	}

	void SetUp( ) {
		for(size_t i = 1; i < 16; i++) {
			stMap->insert(std::pair<int, std::string>(i, "a"));
			ftMap->insert(std::pair<int, std::string>(i, "a"));
		}

		itFT = ftMap->begin();
		iteFT = ftMap->end();

		itST = stMap->begin();
		iteST = stMap->end();
		// код, который будет выполнен перед началом теста
	}

	void TearDown( ) {
		// код, который будет выполнен сразу по завершении теста
		// при необходимости здесь можно вызывать исключения
	}

	~myTestMapFixture( )  {
		delete stMap;
		delete ftMap;
		// очистка всех ресурсов, вызов исключений не допускается
	}
	std::map<int, std::string> *stMap;
	ft::map<int, std::string> *ftMap;

	ft::map<int, std::string>::iterator itFT;
	ft::map<int, std::string>::iterator iteFT;

	std::map<int, std::string>::iterator itST;
	std::map<int, std::string>::iterator iteST;
};

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>> >
void checkMapsEQ(std::map<Key, T> &st, ft::map<Key, T> &ft) {
	EXPECT_EQ(st.size(), ft.size());

	auto stIt = st.begin();

	typename ft::map<Key, T>::iterator ftIt = ft.begin();
	typename ft::map<Key, T>::iterator ftIte = ft.end();
	while(ftIt != ftIte){
		EXPECT_EQ(stIt->first, ftIt->first);
		ftIt++;
		stIt++;
	}
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>> >
void printContentFT(std::string str, ft::map<Key, T> &ft) {
	std::cout << str << " ";
	typename ft::map<Key, T>::iterator it = ft.begin();
	typename ft::map<Key, T>::iterator ite = ft.end();
	while (it != ite){
		std::cout << it->first << " ";
		it++;
	}
	std::cout << std::endl;
}

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T>> >
void printContentST(std::string str, std::map<Key, T> &st) {
	std::cout << str << " ";
	typename std::map<Key, T>::iterator it = st.begin();
	typename std::map<Key, T>::iterator ite = st.end();
	while (it != ite){
		std::cout << it->first << " ";
		it++;
	}
	std::cout << std::endl;
}

TEST(MapTest, insert) {
	std::map<char, int> stMap;
	ft::map<char, int> ftMap;
	stMap.insert(std::pair<char, int>('a', 1));
	stMap.insert(std::pair<char, int>('g', 2));
	ftMap.insert(std::pair<char, int>('a', 1));
	ftMap.insert(std::pair<char, int>('g', 2));

	// insert (single parameter):
	std::pair<std::map<char,int>::iterator,bool> retst;
	std::pair<ft::map<char,int>::iterator,bool> retft;
	retst = stMap.insert ( std::pair<char,int>('g', 20) );
	retft = ftMap.insert ( std::pair<char,int>('g', 20) );
	if (retst.second == false) {
		std::cout << "element 'g' already existed";
		std::cout << " with a value of " << retst.first->second << '\n';
	}
	if (retft.second == false) {
		std::cout << "element 'g' already existed";
		std::cout << " with a value of " << retft.first->second << '\n';
	}
	printContentFT("FT map contains: ", ftMap);
	checkMapsEQ(stMap, ftMap);

	// position (hint)
	std::map<char,int>::iterator it = stMap.begin();
	stMap.insert (it, std::pair<char,int>('b', 300));  // max efficiency inserting
	stMap.insert (it, std::pair<char,int>('c', 400));

	ft::map<char,int>::iterator itf = ftMap.begin();
	ftMap.insert (itf, std::pair<char,int>('b',300));  // max efficiency inserting
	ftMap.insert (itf, std::pair<char,int>('c',400));

	// ranged
	std::map<char, int> stMap1;
	ft::map<char, int> ftMap1;
	stMap1.insert(std::pair<char, int>('f', 8));
	ftMap1.insert(std::pair<char, int>('f', 8));

	stMap1.insert(stMap.begin(), stMap.end());
	ftMap1.insert(ftMap.begin(), ftMap.end());
	checkMapsEQ(stMap1, ftMap1);

	std::cout << std::endl;
	printContentST("ST map after ranged insert:", stMap1);
	printContentFT("FT map after ranged insert:", ftMap1);
}

TEST_F(myTestMapFixture, begin) {
	ftMap->insert(std::pair<int, std::string>(1, "a"));
	stMap->insert(std::pair<int, std::string>(1, "a"));
	EXPECT_EQ(ftMap->begin()->first, stMap->begin()->first);
	std::cout << "Begin Key: " << ftMap->begin()->first << std::endl;
	printContentFT("FT map Content: ", *ftMap);
	printContentST("ST map Content: ", *stMap);

	ftMap->insert(std::pair<int, std::string>(-7, "a"));
	stMap->insert(std::pair<int, std::string>(-7, "a"));
	EXPECT_EQ(ftMap->begin()->first, stMap->begin()->first);
	std::cout << "Begin Key: " << ftMap->begin()->first << std::endl;
	printContentFT("FT map Content: ", *ftMap);
	printContentST("ST map Content: ", *stMap);
	checkMapsEQ(*stMap, *ftMap);
}

TEST_F(myTestMapFixture, end) {
	typename ft::map<int, std::string>::iterator it = ftMap->begin();
	typename ft::map<int, std::string>::iterator ite = ftMap->end();
	ite--;
	while (it != ite){
		std::cout << ite->first << " ";
		ite--;
	}
	std::cout << ite->first << " ";
	std::cout << std::endl;

	typename std::map<int, std::string>::iterator its = stMap->begin();
	typename std::map<int, std::string>::iterator ites = stMap->end();
	ites--;
	while (its != ites){
		std::cout << ites->first << " ";
		ites--;
	}
	std::cout << ites->first << " ";
	std::cout << std::endl;
	EXPECT_EQ((--ftMap->end())->first, (--stMap->end())->first);

//	ites = stMap->end();               //no segfault
//	std::cout << ites->first << " ";
//	ite = ftMap->end();
//	std::cout << ite->first;
}

TEST(MapTest, iterators) {
	ft::map<int, std::string> str;
	str.insert(std::pair<int, std::string>(2, "world"));
	str.insert(std::pair<int, std::string>(3, "today"));
	str.insert(std::pair<int, std::string>(1, "hello"));

	ft::map<int, std::string>::iterator it = str.begin();
	for (; it != str.end(); it++){
		std::cout << it->first << ", " << it->second << " |  ";
	}
	std::cout << std::endl;

	ft::map<int, std::string>::reverse_iterator r_it = str.rbegin();
	for (; r_it != str.rend(); r_it++){
		std::cout << r_it->first << ", " << r_it->second << " |  ";
	}
	std::cout << std::endl;

	std::map<int, std::string> str1;
	str1.insert(std::pair<int, std::string>(1, "hello"));
	str1.insert(std::pair<int, std::string>(3, "today"));
	str1.insert(std::pair<int, std::string>(2, "world"));
	checkMapsEQ(str1, str);

	ft::map<char, float> flo;
	flo.insert(std::pair<char, float> ('a', 1.9));
	flo.insert(std::pair<char, float> ('d', 4.9));
	flo.insert(std::pair<char, float> ('b', 2.9));
	flo.insert(std::pair<char, float> ('c', 3.9));

	ft::map<char, float>::const_iterator c_it = flo.begin();
	for (; c_it != flo.end(); c_it++){
		std::cout << c_it->first << ", " << c_it->second << " |  ";
	}
	std::cout << std::endl;

	ft::map<char, float>::const_reverse_iterator cr_it = flo.rbegin();
	for (; cr_it != flo.rend(); cr_it++){
		std::cout << cr_it->first << ", " << cr_it->second << " |  ";
	}
	std::cout << std::endl;

	std::map<char, float> flo1;
	flo1.insert(std::pair<char, float> ('b', 2.9));
	flo1.insert(std::pair<char, float> ('c', 3.9));
	flo1.insert(std::pair<char, float> ('a', 1.9));
	flo1.insert(std::pair<char, float> ('d', 4.9));
	checkMapsEQ(flo1, flo);
}

TEST_F(myTestMapFixture, begin_rbegin) {
	EXPECT_EQ(*ftMap->begin(), *stMap->begin());
	ftMap->insert(std::pair<int, std::string>(-10, "new"));
	stMap->insert(std::pair<int, std::string>(-10, "new"));
	EXPECT_EQ(*ftMap->begin(), *stMap->begin());

	EXPECT_EQ(*ftMap->rbegin(), *stMap->rbegin());
	ftMap->insert(std::pair<int, std::string>(100, "new"));
	stMap->insert(std::pair<int, std::string>(100, "new"));
	EXPECT_EQ(*ftMap->rbegin(), *stMap->rbegin());
	checkMapsEQ(*stMap, *ftMap);
}

TEST_F(myTestMapFixture, end_rend) {
	EXPECT_EQ(*--ftMap->end(), *--stMap->end());
	ftMap->insert(std::pair<int, std::string>(100, "new"));
	stMap->insert(std::pair<int, std::string>(100, "new"));
	EXPECT_EQ(*--ftMap->end(), *--stMap->end());

	EXPECT_EQ(*--ftMap->rend(), *--stMap->rend());
	ftMap->insert(std::pair<int, std::string>(-10, "new"));
	stMap->insert(std::pair<int, std::string>(-10, "new"));
	EXPECT_EQ(*--ftMap->rend(), *--stMap->rend());
	checkMapsEQ(*stMap, *ftMap);

	ft::map<int, int> A;
	A.insert(std::pair<int, int>(30, 1));
	A.insert(std::pair<int, int>(20, 1));
	A.insert(std::pair<int, int>(42, 1));
	A.insert(std::pair<int, int>(99, 1));
	A.insert(std::pair<int, int>(77, 1));
	int k = 0;
	for (ft::map<int, int>::reverse_iterator test = A.rbegin(); test != A.rend(); ++test)
	{
		std::cout << ' ' << test->first;
		k++;
	}
}

TEST(MapTest, constructors) {
	// default
	std::map<int, int> st1;
	ft::map<int, int>  ft1;
	checkMapsEQ(st1, ft1);

	// ranged
	st1.insert(std::pair<int, int>(5,1));
	st1.insert(std::pair<int, int>(1,1));
	st1.insert(std::pair<int, int>(50,1));
	ft1.insert(std::pair<int, int>(5,1));
	ft1.insert(std::pair<int, int>(1,1));
	ft1.insert(std::pair<int, int>(50,1));

	std::map<int, int>::iterator stIt1 = st1.begin();
	std::map<int, int>::iterator stIte1 = st1.end();
	ft::map<int, int>::iterator ftIt1 = ft1.begin();
	ft::map<int, int>::iterator ftIte1 = ft1.end();
	stIt1++;
	stIte1--;
	ftIt1++;
	ftIte1--;

	std::map<int, int> st3(stIt1, stIte1);
	ft::map<int, int>  ft3(ftIt1, ftIte1);
	checkMapsEQ(st3, ft3);

	//copy
	std::map<int, int> st4(st3);
	ft::map<int, int>  ft4(ft3);
	checkMapsEQ(st4, ft4);


	// default
	std::map<double, std::string> st1Cl;
	ft::map<double, std::string>  ft1Cl;
	checkMapsEQ(st1Cl, ft1Cl);

	// ranged
	st1Cl.insert(std::pair<double, std::string>(5.3,"HELLO"));
	st1Cl.insert(std::pair<double, std::string>(1.8,"HELLO"));
	ft1Cl.insert(std::pair<double, std::string>(5.3,"HELLO"));
	ft1Cl.insert(std::pair<double, std::string>(1.8,"HELLO"));

	std::map<double, std::string>::iterator stIt2 = st1Cl.begin();
	std::map<double,std::string>::iterator stIte2 = st1Cl.end();
	ft::map<double, std::string>::iterator ftIt2 = ft1Cl.begin();
	ft::map<double, std::string>::iterator ftIte2 = ft1Cl.end();
	stIt2++;
	stIte2--;
	ftIt2++;
	ftIte2--;

	std::map<double, std::string> st4Str(stIt2, stIte2);
	ft::map<double, std::string>  ft4Str(ftIt2, ftIte2);
	checkMapsEQ(st4Str, ft4Str);

	//copy
	std::map<double, std::string> st5(st4Str);
	ft::map<double, std::string>   ft5(ft4Str);
	checkMapsEQ(st5, ft5);
}

TEST_F(myTestMapFixture, size) {
	EXPECT_EQ(ftMap->size(), stMap->size());
	ftMap->insert(std::pair<int, std::string>(-10, "new"));
	stMap->insert(std::pair<int, std::string>(-10, "new"));
	EXPECT_EQ(stMap->size(), ftMap->size());

	std::map<int, int> st1;
	ft::map<int, int>  ft1;

	st1.insert(std::pair<int, int>(5,1));
	st1.insert(std::pair<int, int>(1,1));
	st1.insert(std::pair<int, int>(50,1));
	ft1.insert(std::pair<int, int>(5,1));
	ft1.insert(std::pair<int, int>(1,1));
	ft1.insert(std::pair<int, int>(50,1));
	EXPECT_EQ(st1.size(), ft1.size());
}

TEST_F(myTestMapFixture, empty) {
	EXPECT_EQ(ftMap->empty(), stMap->empty());

	std::map<char, int> st;
	ft::map<char, int> ft;
	EXPECT_EQ(st.empty(), ft.empty());
}

TEST_F(myTestMapFixture, max_size) {
	std::map<char, int> st;
	ft::map<char, int> ft;
	EXPECT_EQ(st.max_size(), ft.max_size());
	std::cout << st.max_size() << std::endl << ft.max_size() << std::endl ;
}

TEST_F(myTestMapFixture, erase) {
	ft::map<int, int> sega;
	for(size_t i = 1; i < 9; i++)
		sega.insert(std::pair<int, int>(i, 1));
	printContentFT("Before: ", sega);
	sega.erase(1);
	printContentFT("After : ", sega);

	ftMap->erase(itFT);
	stMap->erase(itST);
	printContentFT("FT after erase", *ftMap);
	printContentST("ST after erase", *stMap);
	checkMapsEQ(*stMap, *ftMap);

	itFT = ftMap->begin();
	itST = stMap->begin();
	itFT++;
	itFT++; // should remove 4
	itST++;
	itST++;
	ftMap->erase(itFT);
	stMap->erase(itST);
	printContentFT("FT after second erase", *ftMap);
	printContentST("ST after second erase", *stMap);
	checkMapsEQ(*stMap, *ftMap);

	// key of the element
	ftMap->erase(8);
	stMap->erase(8);
	printContentFT("FT after KEY erase", *ftMap);
	printContentST("ST after KEY erase", *stMap);
	checkMapsEQ(*stMap, *ftMap);

	//ranged
//	ftMap->print();
	itFT = ftMap->begin();
	itST = stMap->begin();
	for (int i = 1; i < 3; i++) { itFT++; itST++; };
	ft::map<int, std::string>::iterator firstft = itFT;
	std::map<int, std::string>::iterator firstst = itST;
	for (int i = 1; i < 2; i++) { itFT++; itST++; };
	ftMap->erase(firstft, itFT);
	stMap->erase(firstst, itST);
//	ftMap->print();
	printContentFT("FT after ranged erase", *ftMap);
	printContentST("ST after ranged erase", *stMap);
	checkMapsEQ(*stMap, *ftMap);

	std::map<int, std::string>::iterator it_std_first = ++stMap->begin();
	std::map<int, std::string>::iterator it_std_second = --stMap->end();
	ft::map<int, std::string>::iterator it_ft_first = ++ftMap->begin();
	ft::map<int, std::string>::iterator it_ft_second = --ftMap->end();

	std::cout << std::endl << std::endl;
//	ftMap->print();
	std::cout << std::endl;
	for (int i = 0; i < 2; i++) {
		++it_std_first;
		++it_ft_first;
		--it_std_second;
		--it_ft_second;
	}
//	std::cout << it_ft_first->first << " " << it_ft_second->first << "\n";
	stMap->erase(it_std_first, it_std_second);
	ftMap->erase(it_ft_first, it_ft_second);
//	ftMap->print();
}

TEST_F(myTestMapFixture, find) {
	int k = 14;
	itFT = ftMap->find(k);
	std::cout << itFT->first << std::endl;
	EXPECT_EQ(14, itFT->first);

	k = 20;
	itFT = ftMap->find(k);
	if (itFT == ftMap->end())
		std::cout << "No such Key \"" << k << "\" in the map Container" << std::endl;
}

TEST_F(myTestMapFixture, count) {
	int k = 14;
	size_t i = ftMap->count(k);
	EXPECT_EQ(1, i);

	k = 20;
	i = ftMap->count(k);
	EXPECT_EQ(0, i);
}

TEST_F(myTestMapFixture, clear) {
	ftMap->clear();
	stMap->clear();
	printContentFT("FT after clear: ", *ftMap);
	printContentST("ST after clear: ", *stMap);
	EXPECT_EQ(0, ftMap->size());
}

TEST(MapTest, operatorAccessElem) {
	ft::map<char,std::string> mymap;

	mymap['a']="an element";
	mymap['b']="another element";
	mymap['c']=mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
}

TEST(MapTest, assignOperator) {
	std::map<int, int> st7;
	ft::map<int, int> ft7;

	st7.insert(std::pair<int, int>(12, 1));
	st7.insert(std::pair<int, int>(5, 2));
	ft7.insert(std::pair<int, int>(12, 1));
	ft7.insert(std::pair<int, int>(5, 2));

	std::map<int, int> st8(st7);
	ft::map<int, int> ft8(ft7);
	checkMapsEQ(st8, ft7);

	st8.insert(std::pair<int, int>(14, 1));
	st8.insert(std::pair<int, int>(3, 2));
	ft8.insert(std::pair<int, int>(14, 1));
	ft8.insert(std::pair<int, int>(3, 2));

	st7 = st8;
	ft7 = ft8;
	printContentFT("FT contents ", ft7);
	printContentST("ST contents ", st7);
	checkMapsEQ(st7, ft7);
}

TEST(MapTest, swapMember) {
	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::map<int, std::string> stStr;
	ft::map<int, std::string>  ftStr;
	std::map<int, std::string> stStr1;
	ft::map<int, std::string>  ftStr1;

	stStr.insert(std::pair<int, std::string>(2, "world"));
	ftStr.insert(std::pair<int, std::string>(2, "world"));

	stStr.swap(stStr1);
	ftStr.swap(ftStr1);
	checkMapsEQ(stStr, ftStr);
	checkMapsEQ(stStr1, ftStr1);
}

TEST(MapTest, keyCompare) {
	ft::map<char,int> mymap;

	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';
}

TEST(MapTest, valueCompare) {
	ft::map<char,int> mymap;

	mymap['x']=1001;
	mymap['y']=2002;
	mymap['z']=3003;

	std::cout << "mymap contains:\n";

	std::pair<char,int> highest = *mymap.rbegin();          // last element

	ft::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
}

TEST(MapTest, lowerBound_upperBound) {
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow = mymap.lower_bound ('b');  // itlow points to b
	itup = mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

TEST(MapTest, equal_range) {
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
}

//TEST(LEAKS, leaks) {
//	while(1);
//}
//
// Created by Temple Tarsha on 1/30/21.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../srcs/vector.hpp"
#include <vector>
#include <string>

class myTestVectorFixture: public ::testing::Test {
public:
	myTestVectorFixture( ) {
		stIntV = new std::vector<int>;
		ftIntV = new ft::vector<int>;
		// код инициализации
	}

	void SetUp( ) {
		for(size_t i = 1; i < 6; i++) {
			stIntV->push_back(i);
			ftIntV->push_back(i);
		}

		itFT = ftIntV->begin();
		iteFT = ftIntV->end();

		itST = stIntV->begin();
		iteST = stIntV->end();


		// код, который будет выполнен перед началом теста
	}

	void TearDown( ) {
		// код, который будет выполнен сразу по завершении теста
		// при необходимости здесь можно вызывать исключения
	}

	~myTestVectorFixture( )  {
		delete stIntV;
		delete ftIntV;
		// очистка всех ресурсов, вызов исключений не допускается
	}
	std::vector<int> *stIntV;
	ft::vector<int> *ftIntV;

	ft::vector<int>::iterator itFT;
	ft::vector<int>::iterator iteFT;

	std::vector<int>::iterator itST;
	std::vector<int>::iterator iteST;

};

template < class T, class Alloc = std::allocator<T> >
void checkVectorsEQ(std::vector<T, Alloc> &st, ft::vector<T,Alloc> &ft){
	EXPECT_EQ(st.size(), ft.size());
	EXPECT_EQ(st.capacity(), ft.capacity());
	EXPECT_EQ(st.empty(), ft.empty());

	auto stIt = st.begin();

	typename ft::vector<T, Alloc>::iterator ftIt = ft.begin();
	typename ft::vector<T, Alloc>::iterator ftIte = ft.end();
	while(ftIt != ftIte){
		EXPECT_EQ(*stIt, *ftIt);
		ftIt++;
		stIt++;
	}
}

void printContentFT(std::string str, ft::vector<int>::iterator begin, ft::vector<int>::iterator end) {
	std::cout << str << " ";
	ft::vector<int>::iterator tmp = begin;
	while (tmp != end){
		std::cout << *tmp++ << " ";
	}
	std::cout << std::endl;
}

void printContentST(std::string str, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::cout << str << " ";
	std::vector<int>::iterator tmp = begin;
	while (tmp != end){
		std::cout << *tmp++ << " ";
	}
	std::cout << std::endl;
}

TEST(VectorTest, constructors) {
	// default
	std::vector<int> st1;
	ft::vector<int>  ft1;
	checkVectorsEQ(st1, ft1);

	// parametric
	std::vector<int> st2(5, 16);
	ft::vector<int>  ft2(5, 16);
	checkVectorsEQ(st2, ft2);

	// ranged
	std::vector<int>::iterator stIt1 = st2.begin();
	std::vector<int>::iterator stIte1 = st2.end();
	ft::vector<int>::iterator ftIt1 = ft2.begin();
	ft::vector<int>::iterator ftIte1 = ft2.end();
	stIt1++;
	stIte1--;
	ftIt1++;
	ftIte1--;

	std::vector<int> st3(stIt1, stIte1);
	ft::vector<int>  ft3(ftIt1, ftIte1);
	checkVectorsEQ(st3, ft3);

	//copy
	std::vector<int> st4(st3);
	ft::vector<int>  ft4(ft3);
	checkVectorsEQ(st4, ft4);


	// default
	std::vector<double> st1Cl;
	ft::vector<double>  ft1Cl;
	checkVectorsEQ(st1Cl, ft1Cl);

	// parametric
	std::vector<float> st2Fl(15, 1.6);
	ft::vector<float>  ft2Fl(15, 1.6);
	checkVectorsEQ(st2Fl, ft2Fl);

	// ranged
	std::vector<std::string> st3Str(3, "hello");
	ft::vector<std::string>  ft3Str(3, "hello");

	std::vector<std::string>::iterator stIt2 = st3Str.begin();
	std::vector<std::string>::iterator stIte2 = st3Str.end();
	ft::vector<std::string>::iterator ftIt2 = ft3Str.begin();
	ft::vector<std::string>::iterator ftIte2 = ft3Str.end();
	stIt2++;
	stIte2--;
	ftIt2++;
	ftIte2--;

	std::vector<std::string> st4Str(stIt2, stIte2);
	ft::vector<std::string>  ft4Str(ftIt2, ftIte2);
	checkVectorsEQ(st4Str, ft4Str);

	//copy
	std::vector<float> st5(st2Fl);
	ft::vector<float>  ft5(ft2Fl);
	checkVectorsEQ(st5, ft5);
}

TEST(VectorTest, assignOperator) {
	std::vector<int> st7(10, 1);
	ft::vector<int> ft7(10, 1);

	std::vector<int> st8(st7);
	ft::vector<int>  ft8(ft7);
	checkVectorsEQ(st8, ft7);

	st7.push_back(2);
	st7.push_back(2);
	ft7.push_back(2);
	ft7.push_back(2);
	checkVectorsEQ(st7, ft7);

	std::cout << "st size before: " << st7.size() << " capacity " << st7.capacity() << std::endl;
	std::cout << "ft size before: " << ft7.size() << " capacity " << st7.capacity() << std::endl;
	st7 = st8;
	ft7 = ft8;
	std::cout << "st size  after: " << st7.size() << " capacity " << st7.capacity() << std::endl;
	std::cout << "ft size  after: " << ft7.size() << " capacity " << ft7.capacity() << std::endl;
	checkVectorsEQ(st7, ft7);

	std::vector<int> st9(20, 3);
	ft::vector<int> ft9(20, 3);
	st8 = st9;
	ft8 = ft9;
	checkVectorsEQ(st8, ft8);
}

TEST(VectorTest, iterators) {
	ft::vector<std::string> str;
	str.push_back("hello");
	str.push_back("world");
	str.push_back("today");

	ft::vector<std::string>::iterator it = str.begin();
	for (; it != str.end(); it++){
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	ft::vector<std::string>::reverse_iterator r_it = str.rbegin();
	for (; r_it != str.rend(); r_it++){
		std::cout << *r_it << " ";
	}
	std::cout << std::endl;

	std::vector<std::string> str1;
	str1.push_back("hello");
	str1.push_back("world");
	str1.push_back("today");
	checkVectorsEQ(str1, str);

	ft::vector<float> flo;
	flo.push_back(1.9);
	flo.push_back(2.9);
	flo.push_back(3.9);
	flo.push_back(4.9);

	ft::vector<float>::const_iterator c_it = flo.begin();
	for (; c_it != flo.end(); c_it++){
		std::cout << *c_it << " ";
	}
	std::cout << std::endl;

	ft::vector<float>::const_reverse_iterator cr_it = flo.rbegin();
	for (; cr_it != flo.rend(); cr_it++){
		std::cout << *cr_it << " ";
	}
	std::cout << std::endl;

	std::vector<float> flo1;
	flo1.push_back(1.9);
	flo1.push_back(2.9);
	flo1.push_back(3.9);
	flo1.push_back(4.9);
	checkVectorsEQ(flo1, flo);
}

TEST_F(myTestVectorFixture, begin_rbegin) {
	EXPECT_EQ(*ftIntV->begin(), *stIntV->begin());
	ftIntV->insert(ftIntV->begin(), 0);
	stIntV->insert(stIntV->begin(), 0);
	EXPECT_EQ(*ftIntV->begin(), *stIntV->begin());

	EXPECT_EQ(*ftIntV->rbegin(), *stIntV->rbegin());
	ftIntV->push_back(100);
	stIntV->push_back(100);
	EXPECT_EQ(*ftIntV->rbegin(), *stIntV->rbegin());
}

TEST_F(myTestVectorFixture, end_rend) {
	EXPECT_EQ(*--ftIntV->end(), *--stIntV->end());
	ftIntV->push_back(100);
	stIntV->push_back(100);
	EXPECT_EQ(*--ftIntV->end(), *--stIntV->end());

	EXPECT_EQ(*--ftIntV->rend(), *--stIntV->rend());
	ftIntV->insert(ftIntV->begin(), 0);
	stIntV->insert(stIntV->begin(), 0);
	EXPECT_EQ(*--ftIntV->rend(), *--stIntV->rend());

	ft::vector<int> A;
	A.push_back(30);
	A.push_back(20);
	A.push_back(42);
	A.push_back(99);
	A.push_back(77);
	int k = 0;
	for (ft::vector<int>::reverse_iterator test = A.rbegin(); test != A.rend(); ++test)
	{
		std::cout << ' ' << *test;
		k++;
	}
}

TEST_F(myTestVectorFixture, size) {
	EXPECT_EQ(ftIntV->size(), stIntV->size());

	std::vector<int> stvector (3,100);
	ft::vector<int> ftvector (3,100);

	std::vector<int>::iterator st1 = stvector.begin();
	ft::vector<int>::iterator ft1 = ftvector.begin();

	stIntV->insert(stIntV->begin(), st1, st1 + 3);
	ftIntV->insert(ftIntV->begin(), ft1, ft1 + 3);
	EXPECT_EQ(stIntV->size(), ftIntV->size());

	stIntV->push_back(9);
	ftIntV->push_back(9);
	EXPECT_EQ(stIntV->size(), ftIntV->size());
}

TEST(VectorTest, max_size) {
	std::vector<int> st2(10);
	ft::vector<int> ft2(10);
	EXPECT_EQ(st2.max_size(), ft2.max_size());
	std::vector<double> st3;
	ft::vector<double> ft3;
	EXPECT_EQ(st3.max_size(), ft3.max_size());
	std::cout << st3.max_size() << std::endl << ft3.max_size();
	std::vector<std::string> st4;
	ft::vector<std::string> ft4;
	EXPECT_EQ(st4.max_size(), ft4.max_size());
}

TEST_F(myTestVectorFixture, resize) {
	stIntV->resize(3);
	ftIntV->resize(3);
	checkVectorsEQ(*stIntV, *ftIntV);

	stIntV->resize(3);
	ftIntV->resize(3);
	checkVectorsEQ(*stIntV, *ftIntV);

	stIntV->resize(13, 13);
	ftIntV->resize(13, 13);
	checkVectorsEQ(*stIntV, *ftIntV);

	stIntV->resize(0);
	ftIntV->resize(0);
	checkVectorsEQ(*stIntV, *ftIntV);
}

TEST_F(myTestVectorFixture, capacity) {
	EXPECT_EQ(ftIntV->capacity(), stIntV->capacity());
	stIntV->insert(itST, 100, 10);
	ftIntV->insert(itFT, 100, 10);
	EXPECT_EQ(stIntV->capacity(), ftIntV->capacity());

	stIntV->resize(13);
	ftIntV->resize(13);
	EXPECT_EQ(stIntV->capacity(), ftIntV->capacity());

}

TEST_F(myTestVectorFixture, empty) {
	EXPECT_EQ(ftIntV->empty(), stIntV->empty());
	ftIntV->resize(0);
	stIntV->resize(0);
	EXPECT_EQ(ftIntV->empty(), stIntV->empty());
	checkVectorsEQ(*stIntV, *ftIntV);

	ftIntV->clear();
	stIntV->clear();
	EXPECT_EQ(ftIntV->empty(), stIntV->empty());

	std::vector<double> st;
	ft::vector<double> ft;
	EXPECT_EQ(st.empty(), ft.empty());
}

TEST_F(myTestVectorFixture, reserve) {
	ftIntV->reserve(20);
	stIntV->reserve(20);
	checkVectorsEQ(*stIntV, *ftIntV);

	ftIntV->reserve(2000);
	stIntV->reserve(2000);
	std::cout << "ft capacity is " << ftIntV->capacity() << " and st capacity is " << stIntV->capacity() << std::endl;
	checkVectorsEQ(*stIntV, *ftIntV);
}

TEST_F(myTestVectorFixture, operator_elementAccess) {
	EXPECT_EQ((*ftIntV)[2], (*stIntV)[2]);
	EXPECT_EQ((*ftIntV)[0], (*stIntV)[0]);
	EXPECT_EQ((*ftIntV)[ftIntV->size() - 1], (*stIntV)[stIntV->size() - 1]);
}

TEST_F(myTestVectorFixture, operator_elementAccessAT) {
	EXPECT_EQ(ftIntV->at(3), stIntV->at(3));
	EXPECT_EQ(ftIntV->at(0), stIntV->at(0));
//	ftIntV->at(-3) = 8;
//	stIntV->at(-3) = 8;                                             //should throw an exception and fail test
//	EXPECT_EQ(ftIntV->at(ftIntV->size()), stIntV->at(stIntV->size()));
}

TEST_F(myTestVectorFixture, front_back) {
	EXPECT_EQ(ftIntV->front(), stIntV->front());
	EXPECT_EQ(ftIntV->back(), stIntV->back());
	for(size_t i = 100; i < 500; i++) {
		stIntV->push_back(i);
		ftIntV->push_back(i);
	}
	EXPECT_EQ(ftIntV->front(), stIntV->front());
	EXPECT_EQ(ftIntV->back(), stIntV->back());
}

TEST_F(myTestVectorFixture, assign){
	ftIntV->assign(14, 7);
	stIntV->assign(14, 7);
	checkVectorsEQ(*stIntV, *ftIntV);

	// ranged
	std::vector<int> stvector (3,100);
	ft::vector<int> ftvector (3,100);

	std::vector<int>::iterator st1 = stvector.begin();
	ft::vector<int>::iterator ft1 = ftvector.begin();

	stIntV->insert(stIntV->begin(), st1, st1 + 3);
	ftIntV->insert(ftIntV->begin(), ft1, ft1 + 3);
	checkVectorsEQ(*stIntV, *ftIntV);
}

TEST_F(myTestVectorFixture, pop_back) {
	ftIntV->pop_back();
	stIntV->pop_back();
	checkVectorsEQ(*stIntV, *ftIntV);

	ftIntV->push_back(150);
	ftIntV->push_back(151);
	stIntV->push_back(150);
	stIntV->push_back(151);
	checkVectorsEQ(*stIntV, *ftIntV);
}

TEST_F(myTestVectorFixture, insert) {
	printContentFT("FT Vector before insert:", itFT, iteFT);
	ft::vector<int>::iterator tmp = itFT;
	tmp = ftIntV->insert(tmp, 0);
	EXPECT_EQ(6, ftIntV->size());
	EXPECT_EQ(0, *tmp);
	itFT = ftIntV->begin();
	iteFT = ftIntV->end();
	printContentFT("FT Vector  after insert:", itFT, iteFT);

	std::cout << std::endl;

	printContentST("ST Vector before insert:", itST, iteST);
	std::vector<int>::iterator tm = itST;
	tm = stIntV->insert(tm, 0);
	EXPECT_EQ(6, stIntV->size());
	EXPECT_EQ(0, *tm);
	itST = stIntV->begin();
	iteST = stIntV->end();
	printContentST("ST Vector  after insert:", itST, iteST);

	checkVectorsEQ(*stIntV, *ftIntV);

	// single element
	stIntV->insert(iteST - 1, 200);
	ftIntV->insert(iteFT - 1, 200);
	checkVectorsEQ(*stIntV, *ftIntV);

	// fill
	stIntV->insert(itST + 4, 3, 12);
	ftIntV->insert(itFT + 4, 3, 12);
	checkVectorsEQ(*stIntV, *ftIntV);

	// ranged
	std::vector<int> stvector (3,100);
	ft::vector<int> ftvector (3,100);

	std::vector<int>::iterator st1 = stvector.begin();
	ft::vector<int>::iterator ft1 = ftvector.begin();

	stIntV->insert(stIntV->begin(), st1, st1 + 3);
	ftIntV->insert(ftIntV->begin(), ft1, ft1 + 3);
	checkVectorsEQ(*stIntV, *ftIntV);

	std::cout << std::endl;
	itST = stIntV->begin();
	iteST = stIntV->end();
	printContentST("ST Vector  after ranged insert:", itST, iteST);

	itFT = ftIntV->begin();
	iteFT = ftIntV->end();
	printContentFT("FT Vector  after ranged insert:", itFT, iteFT);

}

TEST_F(myTestVectorFixture, push_back) {
	ftIntV->push_back(89);
	stIntV->push_back(89);
	checkVectorsEQ(*stIntV, *ftIntV);

	for(size_t i = 100; i < 500; i++) {
		stIntV->push_back(i);
		ftIntV->push_back(i);
	}
	checkVectorsEQ(*stIntV, *ftIntV);

	std::vector<std::string> stStr;
	ft::vector<std::string> ftStr;
	stStr.push_back("test1");
	stStr.push_back("test2");
	ftStr.push_back("test1");
	ftStr.push_back("test2");
	checkVectorsEQ(stStr, ftStr);
}

TEST_F(myTestVectorFixture, erase) {
	printContentST("ST Vector before erase", itST, iteST);
	printContentFT("FT Vector before erase", itFT, iteFT);
	std::cout << "old st vector size " << stIntV->size() << std::endl;
	std::cout << "old ft vector size " << ftIntV->size() << std::endl;
	ftIntV->erase(itFT + 2);
	stIntV->erase(itST + 2);
	iteST = stIntV->end();
	iteFT = ftIntV->end();
	std::cout << "new st vector size " << stIntV->size() << std::endl;
	std::cout << "new ft vector size " << ftIntV->size() << std::endl;
	printContentST("ST Vector  after erase", itST, iteST);
	printContentFT("FT Vector  after erase", itFT, iteFT);

	checkVectorsEQ(*stIntV, *ftIntV);

	// ranged
	ftIntV->erase(itFT + 1, iteFT - 1);
	stIntV->erase(itST + 1, iteST - 1);
	iteST = stIntV->end();
	iteFT = ftIntV->end();
	std::cout << "new st vector size " << stIntV->size() << std::endl;
	std::cout << "new ft vector size " << ftIntV->size() << std::endl;
	printContentST("ST Vector  after erase", itST, iteST);
	printContentFT("FT Vector  after erase", itFT, iteFT);
	checkVectorsEQ(*stIntV, *ftIntV);
}

TEST_F(myTestVectorFixture, swap_member) {
	std::vector<int> st2(5, 16);
	ft::vector<int>  ft2(5, 16);
	ftIntV->swap(ft2);
	stIntV->swap(st2);
	checkVectorsEQ(*stIntV, *ftIntV);
	checkVectorsEQ(st2, ft2);

	std::vector<std::string> stStr(3, "hello");
	ft::vector<std::string>  ftStr(3, "hello");
	std::vector<std::string> stStr1(7, "world");
	ft::vector<std::string>  ftStr1(7, "world");

	stStr.swap(stStr1);
	ftStr.swap(ftStr1);
	checkVectorsEQ(stStr, ftStr);
	checkVectorsEQ(stStr1, ftStr1);
}

TEST_F(myTestVectorFixture, swap) {
	std::vector<int> st2(5, 16);
	ft::vector<int>  ft2(5, 16);
	ft::swap(*ftIntV, ft2);
	std::swap(*stIntV, st2);
	checkVectorsEQ(*stIntV, *ftIntV);
	checkVectorsEQ(st2, ft2);

	std::vector<std::string> stStr(3, "hello");
	ft::vector<std::string>  ftStr(3, "hello");
	std::vector<std::string> stStr1(7, "world");
	ft::vector<std::string>  ftStr1(7, "world");

	std::swap(stStr1, stStr);
	ft::swap(ftStr1, ftStr);
	checkVectorsEQ(stStr, ftStr);
	checkVectorsEQ(stStr1, ftStr1);
}

TEST(VectorTest, relationalOperator) {
	std::vector<int> a(10,5);
	std::vector<int> b(10, 5);
	std::vector<int> c(5,10);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";


	ft::vector<int> ft_a(10,5);
	ft::vector<int> ft_b(10, 5);
	ft::vector<int> ft_c(5,10);

	std::cout << "___________________" << std::endl;
	if (ft_a==ft_b) std::cout << "a and b are equal\n";
	if (ft_b!=ft_c) std::cout << "b and c are not equal\n";
	if (ft_b<ft_c) std::cout << "b is less than c\n";
	if (ft_c>ft_b) std::cout << "c is greater than b\n";
	if (ft_a<=ft_b) std::cout << "a is less than or equal to b\n";
	if (ft_a>=ft_b) std::cout << "a is greater than or equal to b\n";


	std::cout << std::endl;
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (2,200);   // two ints with a value of 200

	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << "___________________" << std::endl;
	ft::vector<int> foo1 (3,100);   // three ints with a value of 100
	ft::vector<int> bar1 (2,200);   // two ints with a value of 200

	if (foo1==bar1) std::cout << "foo1 and bar are equal\n";
	if (foo1!=bar1) std::cout << "foo1 and bar are not equal\n";
	if (foo1< bar1) std::cout << "foo1 is less than bar\n";
	if (foo1> bar1) std::cout << "foo1 is greater than bar\n";
	if (foo1<=bar1) std::cout << "foo1 is less than or equal to bar\n";
	if (foo1>=bar1) std::cout << "foo1 is greater than or equal to bar\n";

}

//TEST_F(myTestVectorFixture, leaks) {
//	while(1);
//}

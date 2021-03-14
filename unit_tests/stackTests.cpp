//
// Created by Lidia Grigoreva on 03/02/2021.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../srcs/stack.hpp"
#include <stack>
#include <vector>

class myTestStackFixture: public ::testing::Test {
public:
	myTestStackFixture( ) {
		std::vector<int> stvector(15, 1);
		stStack = new std::stack<int, std::vector<int>>(stvector);

		ft::vector<int> ftvector(15, 1);
		ftStack = new ft::stack<int, ft::vector<int>>(ftvector);
		// код инициализации
	}

	~myTestStackFixture( ) {
		delete stStack;
		delete ftStack;
	}

	std::stack<int,std::vector<int>> *stStack;
	ft::stack<int,ft::vector<int>> *ftStack;
};

TEST(StackTests, constructor) {
	std::vector<int> mylist(2, 200);
	std::stack<int> first;
	std::stack<int,std::vector<int>> second(mylist);

	ft::vector<int> myListft(2, 200);
	ft::stack<int> firstft;
	ft::stack<int,ft::vector<int>> secondft(myListft);

	EXPECT_EQ(first.size(), firstft.size());
	EXPECT_EQ(second.size(), secondft.size());
	std::cout << secondft.top() << std::endl;
}

TEST(StackTests, relationalOperators) {
	std::vector<int> sa(10,5);
	std::vector<int> sb(10, 5);
	std::vector<int> sc(5,10);
	std::stack<int, std::vector<int>> stackA(sa);
	std::stack<int, std::vector<int>> stackB(sb);
	std::stack<int, std::vector<int>> stackC(sc);

	if (stackA==stackB) std::cout << "stackA and stackB are equal\n";
	if (stackB!=stackC) std::cout << "stackB and stackC are not equal\n";
	if (stackB< stackC) std::cout << "stackB is less than stackC\n";
	if (stackC> stackB) std::cout << "stackC is greater than stackB\n";
	if (stackA<=stackB) std::cout << "stackA is less than or equal to stackB\n";
	if (stackA>=stackB) std::cout << "stackA is greater than or equal to stackB\n";


	ft::vector<int> fft_a(10,5);
	ft::vector<int> fft_b(10, 5);
	ft::vector<int> fft_c(5,10);
	ft::stack<int> ftStackA(fft_a);
	ft::stack<int> ftStackB(fft_b);
	ft::stack<int> ftStackC(fft_c);

	std::cout << "___________________" << std::endl;
	if (ftStackA==ftStackB) std::cout << "stackA and stackB are equal\n";
	if (ftStackB!=ftStackC) std::cout << "stackB and stackC are not equal\n";
	if (ftStackB< ftStackC) std::cout << "stackB is less than stackC\n";
	if (ftStackC> ftStackB) std::cout << "stackC is greater than stackB\n";
	if (ftStackA<=ftStackB) std::cout << "stackA is less than or equal to stackB\n";
	if (ftStackA>=ftStackB) std::cout << "stackA is greater than or equal to stackB\n";
}

TEST_F(myTestStackFixture, empty) {
	EXPECT_EQ(ftStack->empty(), stStack->empty());

	std::stack<int> first;
	ft::stack<int> firstft;
	EXPECT_EQ(first.empty(), firstft.empty());
}

TEST_F(myTestStackFixture, size) {
	EXPECT_EQ(ftStack->size(), stStack->size());

	ftStack->push(4);
	ftStack->push(5);
	ftStack->push(6);
	stStack->push(4);
	stStack->push(5);
	stStack->push(6);
	EXPECT_EQ(ftStack->size(), stStack->size());

	std::stack<int> first;
	ft::stack<int> firstft;
	EXPECT_EQ(first.size(), firstft.size());
}

TEST_F(myTestStackFixture, top) {
	EXPECT_EQ(ftStack->top(), stStack->top());
	ftStack->pop();
	stStack->pop();
	EXPECT_EQ(ftStack->top(), stStack->top());
	ftStack->push(4);
	ftStack->push(5);
	ftStack->push(6);
	stStack->push(4);
	stStack->push(5);
	stStack->push(6);
	EXPECT_EQ(ftStack->top(), stStack->top());
}

TEST_F(myTestStackFixture, push) {
	size_t ftSize = ftStack->size();
	size_t stSize = stStack->size();

	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;

	std::cout << "ft container before function: ";
	for (size_t i = 0; i < ftSize; i++){
		std::cout << ftStack->top() << " ";
		ftStack->pop();
	}
	std::cout << std::endl;

	std::cout << "st container before function: ";
	for (size_t i = 0; i < stSize; i++){
		std::cout << stStack->top() << " ";
		stStack->pop();
	}
	std::cout << std::endl;

	ftStack->push(4);
	ftStack->push(5);
	ftStack->push(6);
	stStack->push(4);
	stStack->push(5);
	stStack->push(6);

	ftSize = ftStack->size();
	stSize = stStack->size();

	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;

	std::cout << "ft container  after function: ";
	for (size_t i = 0; i < ftSize; i++){
		std::cout << ftStack->top() << " ";
		ftStack->pop();
	}
	std::cout << std::endl;

	std::cout << "st container  after function: ";
	for (size_t i = 0; i < stSize; i++){
		std::cout << stStack->top() << " ";
		stStack->pop();
	}
	std::cout << std::endl;

}

TEST_F(myTestStackFixture, pop) {
	size_t ftSize = ftStack->size();
	size_t stSize = stStack->size();

	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;

	std::cout << "ft container before function: ";
	for (size_t i = 0; i < ftSize; i++){
		std::cout << ftStack->top() << " ";
		ftStack->pop();
	}
	std::cout << std::endl;

	std::cout << "st container before function: ";
	for (size_t i = 0; i < stSize; i++){
		std::cout << stStack->top() << " ";
		stStack->pop();
	}
	std::cout << std::endl;

	ftSize = ftStack->size();
	stSize = stStack->size();
	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;
}

//TEST_F(myTestStackFixture, leaks) {
//	while(1);
//}

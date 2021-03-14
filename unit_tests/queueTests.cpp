//
// Created by Lidia Grigoreva on 03/02/2021.
//

#include <gtest/gtest.h>
#include <iostream>
#include "../srcs/queue.hpp"
#include <queue>
#include <list>

class myTestQueueFixture: public ::testing::Test {
public:
	myTestQueueFixture( ) {
		std::list<int> stlist(5, 16);
		stQL = new std::queue<int, std::list<int>>(stlist);

		ft::list<int> ftlist(5, 16);
		ftQL = new ft::queue<int, ft::list<int>>(ftlist);
		// код инициализации
	}

	void SetUp( ) {
		// код, который будет выполнен перед началом теста
	}

	void TearDown( ) {
		// код, который будет выполнен сразу по завершении теста
		// при необходимости здесь можно вызывать исключения
	}

	~myTestQueueFixture( ) {
		delete stQL;
		delete ftQL;
	}

	std::queue<int,std::list<int>> *stQL;
	ft::queue<int,ft::list<int>> *ftQL;
};

TEST(QueueTests, constructor) {
	std::list<int> mylist(2, 200);
	std::queue<int> first;
	std::queue<int,std::list<int>> second(mylist);

	ft::list<int> myListft(2, 200);
	ft::queue<int> firstft;
	ft::queue<int,ft::list<int>> secondft(myListft);

	EXPECT_EQ(first.size(), firstft.size());
	EXPECT_EQ(second.size(), secondft.size());
	std::cout << secondft.front() << std::endl;
}

TEST_F(myTestQueueFixture, empty) {
	EXPECT_EQ(ftQL->empty(), stQL->empty());

	std::queue<int> first;
	ft::queue<int> firstft;
	EXPECT_EQ(first.empty(), firstft.empty());
}

TEST_F(myTestQueueFixture, size) {
	EXPECT_EQ(ftQL->size(), stQL->size());

	ftQL->push(4);
	ftQL->push(5);
	ftQL->push(6);
	stQL->push(4);
	stQL->push(5);
	stQL->push(6);
	EXPECT_EQ(ftQL->size(), stQL->size());

	std::queue<int> first;
	ft::queue<int> firstft;
	EXPECT_EQ(first.size(), firstft.size());
}

TEST_F(myTestQueueFixture, front) {
	EXPECT_EQ(ftQL->front(), stQL->front());
	ftQL->pop();
	stQL->pop();
	EXPECT_EQ(ftQL->front(), stQL->front());
}

TEST_F(myTestQueueFixture, back) {
	EXPECT_EQ(ftQL->back(), stQL->back());
	ftQL->push(4);
	ftQL->push(5);
	ftQL->push(6);
	stQL->push(4);
	stQL->push(5);
	stQL->push(6);
	EXPECT_EQ(ftQL->back(), stQL->back());
}

TEST_F(myTestQueueFixture, push) {
	size_t ftSize = ftQL->size();
	size_t stSize = stQL->size();

	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;

	std::cout << "ft container before function: ";
	for (size_t i = 0; i < ftSize; i++){
		std::cout << ftQL->front() << " ";
		ftQL->pop();
	}
	std::cout << std::endl;

	std::cout << "st container before function: ";
	for (size_t i = 0; i < stSize; i++){
		std::cout << stQL->front() << " ";
		stQL->pop();
	}
	std::cout << std::endl;

	ftQL->push(4);
	ftQL->push(5);
	ftQL->push(6);
	stQL->push(4);
	stQL->push(5);
	stQL->push(6);

	ftSize = ftQL->size();
	stSize = stQL->size();

	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;

	std::cout << "ft container  after function: ";
	for (size_t i = 0; i < ftSize; i++){
		std::cout << ftQL->front() << " ";
		ftQL->pop();
	}
	std::cout << std::endl;

	std::cout << "st container  after function: ";
	for (size_t i = 0; i < stSize; i++){
		std::cout << stQL->front() << " ";
		stQL->pop();
	}
	std::cout << std::endl;

}

TEST_F(myTestQueueFixture, pop) {
	size_t ftSize = ftQL->size();
	size_t stSize = stQL->size();

	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;

	std::cout << "ft container before function: ";
	for (size_t i = 0; i < ftSize; i++){
		std::cout << ftQL->front() << " ";
		ftQL->pop();
	}
	std::cout << std::endl;

	std::cout << "st container before function: ";
	for (size_t i = 0; i < stSize; i++){
		std::cout << stQL->front() << " ";
		stQL->pop();
	}
	std::cout << std::endl;

	ftSize = ftQL->size();
	stSize = stQL->size();
	std::cout << "ft size: " << ftSize << std::endl;
	std::cout << "st size: " << stSize << std::endl;

}

TEST(QueueTests, relationalOperators) {
	std::list<int> sa(10,5);
	std::list<int> sb(10, 5);
	std::list<int> sc(5,10);
	std::queue<int, std::list<int>> a(sa);
	std::queue<int, std::list<int>> b(sb);
	std::queue<int, std::list<int>> c(sc);

	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";


	ft::list<int> fft_a(10,5);
	ft::list<int> fft_b(10, 5);
	ft::list<int> fft_c(5,10);
	ft::queue<int> ft_a(fft_a);
	ft::queue<int> ft_b(fft_b);
	ft::queue<int> ft_c(fft_c);

	std::cout << "___________________" << std::endl;
	if (ft_a==ft_b) std::cout << "a and b are equal\n";
	if (ft_b!=ft_c) std::cout << "b and c are not equal\n";
	if (ft_b<ft_c) std::cout << "b is less than c\n";
	if (ft_c>ft_b) std::cout << "c is greater than b\n";
	if (ft_a<=ft_b) std::cout << "a is less than or equal to b\n";
	if (ft_a>=ft_b) std::cout << "a is greater than or equal to b\n";
}

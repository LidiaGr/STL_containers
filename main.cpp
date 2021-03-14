//
// Created by Lidia Grigoreva on 03/02/2021.
//

#include <iostream>
#include "./srcs/list.hpp"
#include "./srcs/vector.hpp"
#include "./srcs/queue.hpp"
#include "./srcs/stack.hpp"
#include "./srcs/map.hpp"
#include "./srcs/set.hpp"

class ExampleClass { };

int		main(void) {
	ft::list<std::string> listStr;
	ft::list<ExampleClass> ListClass;
	std::cout << "LIST   compiles!" << std::endl;

	ft::vector<std::string> vectorStr;
	ft::vector<ExampleClass> vectorClass;
	std::cout << "VECTOR compiles!" << std::endl;

	ft::stack<std::string> stackStr;
	ft::stack<ExampleClass> stackClass;
	std::cout << "STACK  compiles!" << std::endl;

	ft::queue<std::string> queueStr;
	ft::queue<ExampleClass> queueClass;
	std::cout << "QUEUE  compiles!" << std::endl;

	ft::map<int, std::string> mapStr;
	ft::map<ExampleClass, ExampleClass> mapClass;
	std::cout << "MAP    compiles!" << std::endl;

	ft::set<std::string> setStr;
	ft::set<ExampleClass> setClass;
	std::cout << "SET    compiles!" << std::endl;

	std::cout << std::endl << "Let's check google unit tests!" << std::endl;
//	while(1);

	return 0;
} //main end

//
// Created by Lidia Grigoreva on 04/02/2021.
//

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <iomanip>

namespace ft {

	template<bool Cond, class T = void> struct enable_if {};
	template<class T> struct enable_if<true, T> { typedef T type; };

}

#endif //UTILS_HPP

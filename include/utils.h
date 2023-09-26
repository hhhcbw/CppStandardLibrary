#include <iostream>
#include <utility> // pair is defined in <utility>
#include <tuple> // tuple is defined in <tuple>

template <typename T1, typename T2>
std::ostream& operator << (std::ostream& strm, const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]"; // print two elements in pair p
}

template <typename T>
void print(const T& value)
{
	std::cout << value << std::endl;
}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
	print(firstArg);
	print(args...);
}

template <typename T>
void print(const char* msg, const T& value)
{
	std::cout << msg << value << std::endl;
}

template <typename T, typename... Types>
void print(const char* msg, const T& firstArg, const Types&... args)
{
	print(msg, firstArg);
	print(msg, args...);
}
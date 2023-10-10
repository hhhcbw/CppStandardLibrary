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

// helper: print element with index IDX of tuple with MAX elements
template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
	static void print(std::ostream& strm, const std::tuple<Args...>& t) {
		strm << std::get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
		PRINT_TUPLE<IDX + 1, MAX, Args...>::print(strm, t);
	}
};
// partial specialization to end the recursion
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
	static void print(std::ostream& strm, const std::tuple<Args...>& t) {
	}
};
// output operator for tuples
template <typename... Args>
std::ostream& operator << (std::ostream& strm,
	const std::tuple<Args...>& t)
{
	strm << "[";
	PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
	return strm << "]";
}
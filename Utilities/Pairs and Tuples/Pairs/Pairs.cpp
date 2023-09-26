#include "utils.h"

class Foo {
public:
	Foo(std::tuple<int, float> tuple) {
		x = std::get<0>(tuple);
		y = std::get<1>(tuple);
		print("Foo::Foo(tuple)");
	}

	template<typename... Args>
	void setVals(float val, Args... args) {
		y = val;
	}

	template <typename... Args>
	Foo(int val, Args... args) {
		x = val;
		setVals(args...);
		print("Foo::Foo(args...)");
	}
	
	friend std::ostream& operator << (std::ostream& strm, Foo foo) {
		return strm << "[" << foo.x << "," << foo.y << "]";
	}
public:
	int x;
	float y;
};

void elementAccess()
{
	print("1. Element Access");
	std::pair<int, int> p1(3, 5);
	print("p1: ", p1);
	print("p1.first/p1.second: ", std::get<0>(p1), std::get<1>(p1)); // yields p.first and p.second 
	typedef std::pair<int, float> IntFloatPair;
	print("IntFloatPair tuple_size value: ", std::tuple_size<IntFloatPair>::value); // yields 2
	print("Type of first element in IntFloatPair: ", typeid(std::tuple_element<0, IntFloatPair>::type).name()); // yields int
	print("===============================================");
}

void coAndAsOp()
{
	print("2. Constructors and Assignment Operators");
	std::pair<int, float> p; // initialize p.first and p.second with zero
	print("p: ", p);
	print("===============================================");
}

void piConstruction()
{
	// create tuple t:
	std::tuple<int, float> t(1, 2.22);
	// pass the tuple as a whole to the constructor of Foo:
	std::pair<int, Foo> p1(42, t);
	print("p1: ", p1);
	// pass the elements of the tuple to the constructor of Foo:
	std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), t);
	print("p2: ", p2);
	std::pair<int, int> p3(std::piecewise_construct, std::make_tuple(4), std::make_tuple(5));
	print("p3: ", p3);
}

int main()
{
	// 1. Element Access
	elementAccess();

	// 2. Constructors and Assignment Operators
	coAndAsOp();

	// 3. Piecewise Constuction
	piConstruction();
}
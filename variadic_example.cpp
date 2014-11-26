#include <tuple>
#include <iostream>
#include <type_traits>

using namespace std;

void write() {
	// no argument => nothing to do
}

template<typename Arg1, typename ... Args>
void write(const Arg1 &firstArg, const Args & ... remainingArguments) {
	cout << firstArg;
	write(remainingArguments ...);
}

void test1() {
	write("Here is an int : ", 8, "\nHere is a float : ", 5.9F);
}

/// Tuples

template<size_t I = 0, typename Func, typename ... TupleTypes, typename ... CallArgumentTypes>
typename std::enable_if<I == sizeof... (TupleTypes)>::type
for_each_in_tuple(std::tuple<TupleTypes ...> &tpl, Func func, CallArgumentTypes & ... args)
{
}

template<size_t I = 0, typename Func, typename ... TupleTypes, typename ... CallArgumentTypes>
typename std::enable_if<I < sizeof... (TupleTypes)>::type
for_each_in_tuple(std::tuple<TupleTypes ...> &tpl, Func func, CallArgumentTypes & ... args)
{
	func(std::get<I>(tpl), args ...);
	for_each_in_tuple<I + 1>(tpl, func, args ...);
}

/**
 * Template class containing members given as variadic template list
 */
template<typename ... Args>
struct MyContainerClass {

	struct doSomethingFunctor {
		template<typename T>
		void operator()(T && t) {
			t.doSomething();
		}
	};

	/**
	 * Call doSomething() on all the members
	 */
	void doSomething() {
		for_each_in_tuple(m_members, doSomethingFunctor());
	}

	std::tuple<Args ...> m_members;

};

struct Class1 {
	void doSomething() {
		cout << "doSomething Class1" << endl;
	}
};

struct Class2 {
	void doSomething() {
		cout << "doSomething Class2" << endl;
	}
};

void test2() {
	MyContainerClass<Class1, Class2> c;
	c.doSomething();
}

int main(int argc, const char * *argv) {
	test1();
	cout << endl;

	test2();
	cout << endl;
}

// https://github.com/Pelagicore/ivi-logging/blob/master/include/ivi-logging.h

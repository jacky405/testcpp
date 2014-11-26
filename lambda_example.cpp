#include <tuple>
#include <iostream>
#include <functional>

using namespace std;

void callFunction(std::function<void(int)> f) {
	f(5);
}

void test1() {

	auto f = [] (int param) {
		cout << "param=" << param << endl;
	};

	callFunction(f);
}

class MyClass {
public:
	MyClass() {
		cout << "constructor" << endl;
	}

	MyClass(const MyClass &other) {
		cout << "copy constructor" << endl;
	}
};

void test2() {

	MyClass object1;
	int i = 6;

	auto lambdaWithCapture = [object1, i](int param) {
		cout << "param=" << param << "; i=" << i << endl;
	};

	i = 10;

	callFunction(lambdaWithCapture);

	auto lambdaWithReferenceCapture = [&object1, &i](int param) {
		cout << "param=" << param << "; i=" << i << endl;
	};

	i = 15;

	callFunction(lambdaWithReferenceCapture);

}

int main(int argc, const char * *argv) {
	test1();
	test2();
}

#include <tuple>
#include <iostream>

using namespace std;

template<typename Function>
void callFunction(Function f) {
	f(5);
}

void test1() {

	auto f = [](int param) {
		cout << param << endl;
	};

	callFunction(f);
}

int main(int argc, const char** argv) {
	test1();
}

#include <tuple>
#include <iostream>

using namespace std;

void write() {
	// no argument => nothing to do
}

template<typename Arg1, typename ... Args>
void write(const Arg1& firstArg, const Args& ... remainingArguments) {
	cout << firstArg;
	write(remainingArguments ...);
}

void test1() {
	write("Here is an int : ", 8, "\nHere is a float : " , 5.9F);
}

int main(int argc, const char** argv) {
	test1();
	cout << endl;
}

// https://github.com/Pelagicore/ivi-logging/blob/master/include/ivi-logging.h

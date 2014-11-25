#include <tuple>
#include <iostream>

using namespace std;

void write() {
	// nothing to do
}

template<typename Arg1, typename ... Args>
void write(const Arg1& firstArg, const Args& ... remainingArguments) {
	cout << firstArg;
	write(remainingArguments ...);
}

int main(int argc, const char** argv) {
	write("Here is an int :", 8);
	cout << endl;
}

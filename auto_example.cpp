#include <tuple>
#include <iostream>
#include <vector>

using namespace std;

void test1() {

	vector<int> arrayOfInts = { 5, 3, 2, 6 };

	// iteration using auto (copy)
	for (auto i : arrayOfInts) {
		cout << i << " ; ";
	}

	cout << endl;
}

void test2() {
	vector<string> arrayOfString = { "String 1", "String 2" };

	// iteration using auto reference
	for (auto &i : arrayOfString) {
		cout << i << " ; ";
	}

	cout << endl;
}

int getValue(int t) {
	return 45;
}

float getValue(const char *s) {
	return 6.87F;
}

template<typename Type>
void doSomething(Type v) {
	auto returnValue = getValue(v);
	returnValue *= 2;
	cout << returnValue << endl;
}

void test3() {
	doSomething(6);
	doSomething("A string");
}

int main(int argc, const char * *argv) {
	test1();

	test2();
	test3();

	cout << endl;
}

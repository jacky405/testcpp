#include <iostream>

using namespace std;

enum class Color {
	YELLOW, BLUE, ORANGE
};

enum class Fruit {
	ORANGE,   // No clash with the orange color
	APPLE,
};

void test1() {
	Color color = Color::YELLOW;
	auto fruit = Fruit::ORANGE;
}

void test2() {
}

struct MyClass {
	static constexpr const char* A_CONSTANT_STRING = "This is a constant string";
	static constexpr auto CONSTANT_AS_AUTO = "Constant string";
};

int main(int argc, const char** argv) {

	test1();
	test2();

	cout << endl;
}


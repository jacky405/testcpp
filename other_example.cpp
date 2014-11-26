#include <iostream>
#include <vector>

using namespace std;

// Scoped enums

enum class Color {
	YELLOW, BLUE, ORANGE
};

enum class Fruit {
	ORANGE,       // No clash with the orange color
	APPLE,
};

void test1() {
	Color color = Color::YELLOW;
	auto fruit = Fruit::ORANGE;
}

// initializer list
vector<string> arrayOfString = { "String 1", "String 2" };

// member initialization
struct MyClass {
	static constexpr const char *A_CONSTANT_STRING = "This is a constant string";
	static constexpr auto CONSTANT_AS_AUTO = "Constant string";

	int m_member = 1234;

	vector<int> arrayOfInt = { 4, 7, 8 };
};

int main(int argc, const char * *argv) {
	test1();
	cout << endl;
}

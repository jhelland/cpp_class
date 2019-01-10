#include <iostream>


using namespace std;


template<typename T>
void fn(T i, T j) {
	cout << i << " " << j << endl;
}

int main() {
	void(*ptr)(int, int) = fn;

	ptr(1, 2);

	int ret;
	cin >> ret;

	return 0;
}
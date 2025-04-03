#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = n + 1; i <= 2 * n; i++) {
		bool is_prime = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}
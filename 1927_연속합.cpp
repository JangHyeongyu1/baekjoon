#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	

	int max_sum = arr[0];
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum = arr[i];
		for (int j = i + 1; j < n; j++) {
			sum += arr[j];
			if (sum > max_sum) {
				max_sum = sum;
			}
		}
	}

	cout << max_sum << "\n";

	return 0;
}

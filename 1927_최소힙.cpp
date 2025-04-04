#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int N;	
	cin >> N;
	vector<int> input(N, -1);
	int x;
	int min;
	vector<int> result(N);
	int result_index = 0;
	int min_index;

	for (int i = 0; i < N; i++) {
		cin >> x;
		min = INT_MAX;

		if (x == 0) {
			for (int j = 0; j < N; j++) {
				if (input[j] < min && input[j] != -1) {
					min = input[j];
					min_index = j;
				}
			}
			result[result_index++] = min;
			input[min_index] = -1;	
		}
		else {
			input[i] = x;
		}
		
	}

	for (int i = 0; i < result_index; i++) {
		cout << result[i] << endl;
	}
	
	return 0;
}
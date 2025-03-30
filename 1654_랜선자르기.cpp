#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countCable(const vector<int>& num, int len) {
	int cnt = 0;
	for (int i: num) {
		cnt += i / len;
	}
	return cnt;
}

int binary_search(const vector<int>&num, int N) {
	int left = 1;
	int right = *max_element(num.begin(), num.end());
	int mid = (left + right) / 2;
	int ans = 0;
	while (left <= right) {
		if (countCable(num,mid)>=N) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
		mid = (left + right) / 2;
	}
	return ans;
}

int main() {
	int K, N;
	int res;
	cin >> K >> N;

	vector<int> num(K);
	for (int i = 0; i < K; i++) {
		cin >> num[i];
	}
	

	cout << binary_search(num, N) << "\n";
		
	return 0;
}
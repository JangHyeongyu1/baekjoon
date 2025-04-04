#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> result;

    // �ּ� ���� ���� priority_queue, �⺻������ �ִ� ���̹Ƿ� �켱���� �ݴ�� ����.
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (minHeap.empty()) {
                result.push_back(0);
            }
            else {
                result.push_back(minHeap.top());
                minHeap.pop();
            }
        }
        else {
            minHeap.push(x);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}
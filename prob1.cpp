#include <iostream>
#include <vector>
using namespace std;

bool canDivide(vector<int>& arr, int k) {
    vector<int> freq(k, 0);

    for (int x : arr)
        freq[x % k]++;

    if (freq[0] % 2 != 0) return false;

    for (int i = 1; i < k; i++) {
        if (freq[i] != freq[k - i])
            return false;
    }

    return true;
}

void printPairs(vector<int>& arr, int k) {
    vector<bool> used(arr.size(), false);

    for (int i = 0; i < arr.size(); i++) {
        if (used[i]) continue;

        for (int j = i + 1; j < arr.size(); j++) {
            if (!used[j] && (arr[i] + arr[j]) % k == 0) {
                cout << "(" << arr[i] << ", " << arr[j] << ") ";
                used[i] = used[j] = true;
                break;
            }
        }
    }
}

int main() {
    vector<int> arr = {92, 75, 65, 48, 45, 35};
    int k = 10;

    if (canDivide(arr, k)) {
        cout << "True\nPairs: ";
        printPairs(arr, k);
    } else {
        cout << "False";
    }
}
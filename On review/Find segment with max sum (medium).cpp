#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, -3, -12, 8, 42, 1, -7, 0, 3};
    int temp = arr[0], leftIndex = 0, rightIndex = 0, sum = 0, pos = -1;

    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        sum += arr[i];

        if (sum > temp) {
            temp = sum;
            leftIndex = pos + 1;
            rightIndex = i;
        }

        if (sum < 0) {
            sum = 0;
            pos = i;
        }
    }
    cout << "[" << leftIndex << "," << rightIndex << "]";
    return 0;
}
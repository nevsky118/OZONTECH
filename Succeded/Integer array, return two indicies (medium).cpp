#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> list = { 3, 3 };
    int target = 6;
    int size = list.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] + list[j] == target) {
                cout << "[" << i << "," << j << "]";
            }
        }
    }
}
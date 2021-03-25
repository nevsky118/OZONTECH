#include <iostream>
#include <math.h>
using namespace std;

void Output(int* A, int n) {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n; //����� ������
    int maxNumber = pow(2, 28); // ������������ �������� ���������� ����� � ������
    int temp; //��������� ����������

    cout << "������� ������ ������: \n";
    cin >> n;

    auto A = new int[n];

    for (int i = 0; i < n; i++) {
        A[i] = rand() % maxNumber;
    }

    cout << "������ �� ����������: \n";
    Output(A, n);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                // ������ �������� �������
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    cout << "\n ������ ����� ����������: \n";
    Output(A, n);
    delete[] A;
    return 0;
}
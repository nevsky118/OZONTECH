#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Output(vector<int> vector) {
    int vector_size = vector.size();
    for (int i = 0; i < vector_size; i++) {
        cout << vector[i] << " \t";
    }
}

int findMinimumMissingPositive(vector<int> userDB) {
    sort(userDB.begin(), userDB.end());
    int mex = 0;
    for (int i = 0; i < userDB.size(); i++) {
        if (userDB[i] < 0)
            continue;
        if (userDB[i] == mex)
            mex++;
        else return mex;
    }
    return mex;
}

vector<int> Encrypt(vector<int> userDB) {
    int userDB_size = userDB.size();
    for (int i = 0; i < userDB_size; i++) {
        userDB[i] = userDB[i] ^ 1;
    }
    return userDB;
}

vector<int> RegisterUser(vector<int> userDB, int mex) {
    userDB.insert(userDB.end(), mex); // ����������� ������������

    cout << "\n���� ������ �� ����������:\n";
    Output(userDB);

    return userDB;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> userDB = { 1, 3 };
    int userID;

    cout << "\n������� ��� ������� �������: \n";
    cout << "1 - ���������������� ������ ������������ \n";
    cout << "2 - ����������� ������ \n";

    while (true)
    {
        int commandNumber;
        cin >> commandNumber;
        switch (commandNumber) {
        case 1:
            cout << "���� ������ �� ����������� ������ ������������:\n";
            Output(userDB);

            userID = findMinimumMissingPositive(userDB);
            userDB = RegisterUser(userDB, userID);
            cout << "\n��� ID: " << userID << "\n";
            cout << "\n������� 1 ��� 2 ��� ��������� �������: \n";
            break;
        case 2:
            userDB = Encrypt(userDB); // ����������

            cout << "\n���� ������ ����� ����������:\n";
            Output(userDB); cout << "\n";
            cout << "\n������� 1 ��� 2 ��� ��������� �������: \n";
            break;
        default:
            return 0;
        }
    }
}
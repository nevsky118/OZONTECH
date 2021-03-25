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
    userDB.insert(userDB.end(), mex); // Регистрация пользователя

    cout << "\nБаза данных до шифрования:\n";
    Output(userDB);

    return userDB;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> userDB = { 1, 3 };
    int userID;

    cout << "\nВведите для запуска команды: \n";
    cout << "1 - Зарегистрировать нового пользователя \n";
    cout << "2 - Зашифровать данные \n";

    while (true)
    {
        int commandNumber;
        cin >> commandNumber;
        switch (commandNumber) {
        case 1:
            cout << "База данных до регистрации нового пользователя:\n";
            Output(userDB);

            userID = findMinimumMissingPositive(userDB);
            userDB = RegisterUser(userDB, userID);
            cout << "\nВаш ID: " << userID << "\n";
            cout << "\nВведите 1 или 2 для следующей команды: \n";
            break;
        case 2:
            userDB = Encrypt(userDB); // Шифрование

            cout << "\nБаза данных после шифрования:\n";
            Output(userDB); cout << "\n";
            cout << "\nВведите 1 или 2 для следующей команды: \n";
            break;
        default:
            return 0;
        }
    }
}

#include <iostream>
#include <string>
using namespace std;

auto removeSpaces(string str)
    {
        int i = 0;

        if (str[i] == ' ') { // проверяет на наличие пробела в начале
            str.erase(i, 1); //удаляет лишний пробел
        }

        int n = str.length();

        for (i = 0; i < n-1; i++) {
                if (str[i] == ' ' && str[i + 1] == ' ') {
                    str.erase(i,1); //удаляет лишний пробел
            }
        }
        return str;
    }

    int main()
    {
        auto str = new string(" On  my   home world");

        cout << removeSpaces(removeSpaces(*str));

        delete str;
        return 0;
    }

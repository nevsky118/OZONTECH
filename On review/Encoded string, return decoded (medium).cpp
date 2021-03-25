#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    cout << "¬ведите строку: \n";
    cin >> str;

    string decodedStr;
    string temp;
    int k = 0;
    stack<string> charStack;

    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i])) {
            temp = str[i];
            k = stoi(temp);
            temp.clear();
        }

        else if (str[i] == '[') {
            charStack.push(decodedStr);

            charStack.push(to_string(k));
            decodedStr.clear();
            k = 0;
        }
        else if (isalpha(str[i])) {
            decodedStr += str[i];
        }
        else if (str[i] == ']') {
            int pre_num = atoi((charStack.top()).c_str());
            charStack.pop();

            auto pre_string = charStack.top();
            charStack.pop();

            for (int i = 0; i < pre_num; i++) {
                temp += decodedStr;
            }

            decodedStr = pre_string + temp;
            temp.clear();
        }
    }
    cout << "Result: " << decodedStr;
}
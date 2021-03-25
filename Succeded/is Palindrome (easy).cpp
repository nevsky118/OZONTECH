#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
	int strLength = str.length();
	for (int i = 0; i < strLength / 2; i++) {
		if (str[i] != str[strLength - i - 1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	cout << "������� �����: ";
	cin >> str;
	if (isPalindrome(str)) {
		cout << "���������.";
	} else {
		cout << "�� ���������.";
	}
	return 0;
}
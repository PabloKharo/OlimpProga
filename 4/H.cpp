#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

// структура, в которой хранится пароль пользователя
// и вошел ли он в аккаунт
struct passlog
{
	string password;
	int logged;
};

int main()
{
	ios::sync_with_stdio(false);
	map<string, passlog> data;
	string type, login, password;

	while (cin >> type)
	{
		// парсинг по комманде
		if (type == "register") 
		{
			cin >> login >> password;
			// проверка существует ли акканут и добавление в бд
			if (data.count(login) == 1)
				cout << "login already in use \n";
			else
			{
				data[login] = { password, 0 };
				cout << "account created \n";
			}
		}
		else if (type == "login")
		{
			cin >> login >> password;
			// проверка пароля и зашел ли пользователь в аккаунт
			if (data.find(login)->second.password != password)
			{
				cout << "wrong account info \n";
			}
			else if (data.find(login)->second.logged == 1)
				cout << "already logged in \n";
			else
			{
				data[login].logged = 1;
				cout << "logged in \n";
			}
		}
		else
		{
			// проверка зашел ли пользователь в аккаунт и выход его
			cin >> login;
			if (data.find(login)->second.logged != 1)
				cout << "incorrect operation \n";
			else
			{
				data[login].logged = 0;
				cout << "logged out \n";
			}
		}


	}


}


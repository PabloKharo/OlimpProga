#include <iostream>
using namespace std;


int main()
{
	int X1, Y1, R1, X2, Y2, R2;

	cin >> X1 >> Y1 >> R1;
	cin >> X2 >> Y2 >> R2;

	//проверка, удалены ли окружности на расстояние больше, чем сумма радиусов
	if ((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2)
						> (R1 + R2) * (R1 + R2))
		cout << "NO";
	//проверка, находится ли одна окружность в другой
	else if ((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2)
		< (R1 - R2) * (R1 - R2))
		cout << "NO";
	else
		cout << "YES";

}



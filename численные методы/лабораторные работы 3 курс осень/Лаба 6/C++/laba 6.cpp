#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
// Вариант 10
double findH(double a, double b, int n) {
	return (b - a) / n;
}

void Zadanie11() { // работа 1 задание 1
	const int n = 10;
	double a = 1.2;
	double b = 2.6;
	double h = findH(a, b, n);
	double x[n + 1];
	double y[n + 1];
	for (int i = 0; i < n + 1; i++) {
		x[i] = a + i * h;
		y[i] = (sqrt(0.4 * pow(x[i], 1) + 1.7)) / (1.5 * pow(x[i], 1) + sqrt(pow(x[i], 2) + 1.3));
	}
	double I1 = 0;
	double I2 = 0;
	for (int i = 0; i < n; i++) {
		I1 += y[i];
		I2 += y[i + 1];
	}
	I1 = I1 * h;
	I2 = I2 * h;

	cout << "По формуле левых прямоугольников: " << I1 << "\n";
	cout << "По формуле правых прямоугольников: " << I2 << "\n";
	cout << "Усреднённое значение интеграла: " << (I1 + I2) / 2 << "\n";
}

void Zadanie12() { // работа 1 задание 2
	const int n1 = 8;
	const int n2 = 10;
	double a = 0.3;
	double b = 1.3;
	double h1 = findH(a, b, n1);
	double h2 = findH(a, b, n2);
	double x1[n1 + 1];
	double sum1 = 0;
	double x2[n2 + 1];
	double sum2 = 0;
	for (int i = 0; i < n1; i++) {
		x1[i] = a + i * h1 + h1 / 2;
		cout << x1[i] << endl;
		sum1 += (sin(0.3 * pow(x1[i], 1) + 1.2)) / (1.3 + pow(cos(0.5 * x1[i] + 1), 2));
		//cout << sum1;
	}
	for (int i = 0; i < n2; i++) {
		x2[i] = a + i * h2 + h2 / 2;
		sum2 += (sin(0.3 * pow(x2[i], 1) + 1.2)) / (1.3 + pow(cos(0.5 * x2[i] + 1), 2));
	}
	cout << "приближенное значение интеграла при n = 10: " << sum1 * h1 << "\n";
	cout << "приближенное значение интеграла при n = 8: " << sum2 * h2 << "\n";

}
// работа 2 задание 1

void Zadanie21() {
	double a = 1.4;
	double b = 2.1;

	int n = 1000; // Выбираем достаточно большое значение n для высокой точности

	double h = (b - a) / n; // Шаг

	double sum = 0;

	// Считаем значения функции в узлах и суммируем
	for (int i = 0; i <= n; i++) {
		double x = a + i * h;
		if (i == 0 || i == n) { // Если конечный узел
			sum += 1 / sqrt(3 * x * x - 1);
		}
		else { // В противном случае
			sum += 2 / sqrt(3 * x * x - 1);
		}
	}

	// Умножаем сумму на половину шага
	sum *= h / 2;

	cout << "Приближенное значение: " << fixed << setprecision(3) << sum << "\n";
}

void Zadanie22() { // работа 2 задание 2
	const int n = 8;
	double a = 0.8;
	double b = 1.6;
	double h = findH(a, b, n);
	double x[n + 1];
	double y[n + 1];
	for (int i = 0; i < n + 1; i++) {
		x[i] = a + i * h;
		cout << log(pow(x[i], 2) + 1) << endl;
		y[i] = log(x[i] * x[i] + 1) / pow(x[i], 1);
		//cout << y[i] << endl;
	}
	double I = (h / 3) * (y[0] + 4 * y[1] + 2 * y[2] + 4 * y[3] + 2 * y[4] + 4 * y[5] + 2 * y[6] + 4 * y[7] + y[8]);
	cout << "Приближённое значение: " << I << "\n";
	double tr[n + 1][5];
	for (int i = 0; i < n + 1; i++) {
		tr[i][0] = y[i];
	}
	int k = 1;
	for (int i = 8; i > 4; i--) {
		for (int j = 0; j < i; j++) {
			tr[j][k] = tr[j + 1][k - 1] - tr[j][k - 1];
		}
		k++;
	}
	double maxi = abs(tr[0][4]);
	for (int i = 0; i < 5; i++) {

		if (abs(tr[i][4]) > maxi) maxi = abs(tr[i][4]);
	}
	double R = ((b - a) * maxi) / 180;
	cout << "R = " << R << "\n";
	double delI = (b - a) * maxi;
	//cout << "dI = " << delI << "\n";
	if (delI < 0.00005) cout << "Полученные знаки верны!\n";
}

void Zadanie31() {
	const int n1 = 9;
	const int n2 = 12;
	double a = 0.7;
	double b = 2.5;
	double h1 = findH(a, b, n1);
	double h2 = findH(a, b, n2);
	double x1[n1 + 1];
	double sum1 = 0, sum2 = 0, sum3 = 0;

	// Вычисление сумм для n1
	for (int i = 0; i < n1 + 1; i++) {
		x1[i] = a + i * h1;
		if (i % 3 == 0 && i > 0 && i < n1) {
			sum3 += (1 + 1.5 * pow(x1[i], 2)) / (0.5 + sqrt(pow(x1[i], 2) + 0.8));
		}
		if (i % 3 != 0 && i > 0 && i < n1) {
			sum2 += (1 + 1.5 * pow(x1[i], 2)) / (0.5 + sqrt(pow(x1[i], 2) + 0.8));
		}
		if (i == 0 || i == n1) {
			sum1 += (1 + 1.5 * pow(x1[i], 2)) / (0.5 + sqrt(pow(x1[i], 2) + 0.8));
		}
	}

	double I1 = h1 * (3.0 / 8.0) * (sum1 + 3 * sum2 + 2 * sum3);

	double x2[n2 + 1];
	sum1 = 0, sum2 = 0, sum3 = 0;

	// Вычисление сумм для n2
	for (int i = 0; i < n2 + 1; i++) {
		x2[i] = a + i * h2;
		if (i % 3 == 0 && i > 0 && i < n2) {
			sum3 += (1 + 1.5 * pow(x2[i], 2)) / (0.5 + sqrt(pow(x2[i], 2) + 0.8));
		}
		if (i % 3 != 0 && i > 0 && i < n2) {
			sum2 += (1 + 1.5 * pow(x2[i], 2)) / (0.5 + sqrt(pow(x2[i], 2) + 0.8));
		}
		if (i == 0 || i == n2) {
			sum1 += (1 + 1.5 * pow(x2[i], 2)) / (0.5 + sqrt(pow(x2[i], 2) + 0.8));
		}
	}

	double I2 = h2 * (3.0 / 8.0) * (sum1 + 3 * sum2 + 2 * sum3);

	cout << "Приближённое значение при n=9 I1 = " << I1 << "\n";
	cout << "Приближённое значение при n=12 I2 = " << I2 << "\n";
}


void Zadanie41() { // Работа 4 задание 1
	const int n1 = 3;
	const int n2 = 6;
	double a = 0.1 * 7;
	double b = a + 3;
	double c = 4 - 0.1 * 7;
	double h1 = findH(a, b, n1);
	double h2 = findH(a, b, n2);
	double x[n2 + 1];
	double y[n2 + 1];
	double sum = 0;
	for (int i = 0; i < n2 + 1; i++) {
		x[i] = a + i * h2;
		y[i] = (sqrt(x[i] * x[i] + c));
		if (i > 0 && i < n2) sum += (sqrt(x[i] * x[i] + c));
	}
	double I1 = h1 * (((y[0] + y[n2]) / 2) + y[2] + y[4]);
	double I2 = h2 * (((y[0] + y[n2]) / 2) + sum);
	cout << "По формуле трапеции\nI1 = " << I1 << "\n";
	cout << "I2 = " << I2 << "\n";
	cout << "Приближённое значение: \n";
	cout << I2 + ((pow(n1, 2)) / (pow(n2, 2) - pow(n1, 2))) * (I2 - I1) << "\n";
}

void Zadanie42() { //Работа 4 задание 2
	const int n1 = 2;
	const int n2 = 4;
	double c = 3 - 0.1 * 7;
	double a = c;
	double b = c + 4;
	double h1 = findH(a, b, n1);
	double h2 = findH(a, b, n2);
	double x[n2 + 1];
	double y[n2 + 1];
	for (int i = 0; i < n2 + 1; i++) {
		x[i] = a + i * h2;
		y[i] = log10(pow(x[i], 2) + 2);
	}
	double I1 = (h1 / 3.0) * (y[0] + 4 * y[2] + y[4]);
	double I2 = (h2 / 3.0) * (y[0] + 4 * y[1] + 2 * y[2] + 4 * y[3] + y[4]);
	cout << "По формуле Симпсона\nI1 = " << I1 << "\n";
	cout << "I2 = " << I2 << "\n";
	cout << "Приближённое значение: \n";
	cout << I2 + ((pow(n1, 4)) / (pow(n2, 4) - pow(n1, 4))) * (I2 - I1) << "\n";
}

void Zadanie51() { //Работа 5
	const int n1 = 4;
	const int n2 = 5;
	double a = 0.2;
	double b = 2.4;
	double h1 = findH(a, b, n1);
	double h2 = findH(a, b, n2);
	double c4[n1] = { 0.34785, 0.65215, 0.65215, 0.34785 };
	double t4[n1] = { -0.86114, -0.33998, 0.33998, 0.86114 };
	double x1[n1];
	double sum = 0;
	for (int i = 0; i < n1; i++) {
		x1[i] = ((b + a) / 2.0) + ((b - a) / 2.0) * t4[i];
		sum += c4[i] * ((sqrt(pow(x1[i], 2.0) + 1.0)) / (x1[i] + 2.0));
		cout << ((sqrt(pow(x1[i], 2.0) + 1.0)) / (x1[i] + 2.0)) << endl;
	}

	double I1 = ((b - a) / 2) * sum;
	double c5[n2] = { 0.23693, 0.47863, 0.56889, 0.47863, 0.23693 };
	double t5[n2] = { -0.90618, -0.538469, 0, 0.538469, 0.90618 };
	double x2[n2];
	sum = 0;
	for (int i = 0; i < n2; i++) {
		x2[i] = ((b + a) / 2) + ((b - a) / 2) * t5[i];
		sum += c5[i] * ((sqrt(pow(x2[i], 2.0) + 1.0)) / (x2[i] + 2.0));
	}
	double I2 = ((b - a) / 2) * sum;
	cout << "Приближённое значение I1 = " << I1 << "\n";
	cout << "Приближённое значение I2 = " << I2 << "\n";
}

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите номер работы(1,2,3,4,5)\n";
	cout << "Для выхода введите любое число, не равное номеру задания\n";
	int input;
	cin >> input;
	while (input == 1 || input == 2 || input == 3 || input == 4 || input == 5) {
		switch (input) {
		case 1:
			cout << "вывод первого задания: \n";
			Zadanie11();
			cout << "вывод второго задания: \n";
			Zadanie12();
			break;
		case 2:
			cout << "вывод первого задания: \n";
			Zadanie21();
			cout << "вывод второго задания: \n";
			Zadanie22();
			break;
		case 3:
			cout << "вывод:\n";
			Zadanie31();
			break;
		case 4:
			cout << "вывод первого задания: \n";
			Zadanie41();
			cout << "вывод второго задания: \n";
			Zadanie42();
			break;
		case 5:
			cout << "вывод:\n";
			Zadanie51();
			break;
		}
		cout << "для выхода введите любое число, не равное номеру задания\n";
		cin >> input;

	}
}

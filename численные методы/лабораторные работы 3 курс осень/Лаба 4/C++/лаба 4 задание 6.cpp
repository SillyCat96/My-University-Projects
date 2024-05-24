#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;
double fun11(double x) {
    return exp(-2 * x) - 2 * x + 1;
}

double fun12(double x) {
    return pow(x, 4) + 4 * pow(x, 3) - 8 * pow(x, 2) - 17;
}

double fun13(double x) {
    return pow(0.5, x) - 1 - (x + 2);
}

double fun14(double x) {
    return pow(x, 2) * cos(2 * x) + 1;
}
double method_prob(double a, double b, double e, double f(double)) {
    if (f(a) * f(b) >= 0) {
        cout << "В этом промежутке нет корня";
        return 0;
    }
    double x = a;
    do {
        x = (a + b) / 2;
        if (f(x) == 0.0)
            break;
        else if (f(x) * f(a) < 0)
            b = x;
        else
            a = x;
    } while (fabs(f(x)) >= e);
    return x;
}
double fun21(double x) {
    return 3 * x - cos(x) - 1;
}
double fun22(double x) {
    return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2;
}
double fun31(double x) {
    return 3 * x - cos(x) - 1;
}
double dfun31(double x) {
    return 3 + sin(x);
}
double fun32(double x) {
    return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2;
}
double dfun32(double x) {
    return 3 * pow(x, 2) + 0.4 * x + 0.5;
}
double method_kasatelnih(double x0, double e, double f(double), double df(double)) {
    double x = x0 - f(x0) / df(x0);
    cout << x << endl;
    do {
        x0 = x;
        x = x0 - f(x0) / df(x0);
        cout << x << endl;
    } while (fabs(f(x)) > e);
    return x;
}
double fun41(double x) {
    return 2 * pow(x, 3) + 9 * pow(x, 2) - 21;
}
double dfun41(double x) {
    return 6 * pow(x, 2) + 18 * x;
}
double ddfun41(double x) {
    return 12 * x + 18;
}
double fun51(double x) {
    return 2 - x - log(x);
}

double fun52(double x) {
    return pow(x, 3) - 0.2 * pow(x, 2) + 0.4 * x - 1.4;
}

double method_iteracii(double x, double e, double f(double), double k) {
    do {
        x = x - f(x) / k;
        cout << x << endl;
    } while (fabs(f(x)) > e);
    return x;
}
// Функция f(x, y) = tg(xy) - x^2
double f62(double x, double y) {
    return tan(x * y) - pow(x, 2);
}

// Функция g(x, y) = 0.8x^2 + 2y^2 - 1
double g62(double x, double y) {
    return 0.8 * pow(x, 2) + 2 * pow(y, 2) - 1;
}

// Производная f по x
double f62x(double x, double y) {
    return y / (pow(cos(x * y), 2)) - 2 * x;
}

// Производная f по y
double f62y(double x, double y) {
    return x / (pow(cos(x * y), 2));
}

// Производная g по x
double g62x(double x, double y) {
    return 1.6 * x;
}

// Производная g по y
double g62y(double x, double y) {
    return 4 * y;
}
void method_newton(double x0, double y0, double& x, double& y, double e) {
    x = x0;
    y = y0;
    do {
        x0 = x;
        y0 = y;
        double d = f62x(x0, y0) * g62y(x0, y0) - f62y(x0, y0) * g62x(x0, y0);
        cout << "d " << d << endl;
        double deltahn = f62y(x0, y0) * g62(x0, y0) - f62(x0, y0) * g62y(x0, y0);
        cout << "deltahn " << deltahn << endl;
        double deltakn = g62x(x0, y0) * f62(x0, y0) - g62(x0, y0) * f62x(x0, y0);
        cout << "deltakn " << deltakn << endl;
        x = x0 + deltahn / d;
        y = y0 + deltakn / d;
        cout << "x = " << x << "; y = " << y << " " << endl;
    } while ((fabs(x - x0) > e) || (fabs(y - y0) > e));
}
double graph(double a, double b, double graphic(double)) {
    float x;
    // Получаем контекст устройства консоли
    HDC hDC = GetDC(GetConsoleWindow());
    // Создаем перо для рисования линий
    HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
    // Выбираем созданное перо
    SelectObject(hDC, Pen);
    // Рисуем оси координат
    MoveToEx(hDC, 0, a, NULL);
    LineTo(hDC, 200, a);
    MoveToEx(hDC, 100, b, NULL);
    LineTo(hDC, 100, b + 200);
    for (x = -8.0f; x <= 8.0f; x += 0.01f) // O(100,85) - центр
    {
        // Рисуем график
        MoveToEx(hDC, 10 * x + 100, -10 * graphic(x) + a, NULL); // 10 - масштаб
        LineTo(hDC, 10 * x + 100, -10 * graphic(x) + a);
    }
    // Удаляем перо
    DeleteObject(Pen);
    ReleaseDC(GetConsoleWindow(), hDC);
    getchar();  // Ожидание нажатия клавиши
    return 0;
}
int main() {
    setlocale(LC_ALL, "RUS");
    cout << fixed << setprecision(6);
    int task;
    cout << "Выберите номер работы от 1 до 6: ";
    cin >> task;
    if (task < 1 || task > 6) {
        cout << "Такой работы нет. Попробуйте еще раз" << endl;
        return 0;
    }
    int chase;
    switch (task) {
    case 1:
        cout << "Работа 1 состоит из 4 заданий" << endl;
        cout << "Выберите задание, которое нужно решить:" << endl;
        cout << "1. Отделить корни уравнения графически и уточнить один из них методом хорд с точностью 0,001: e^(-2x) - 2x + 1 = 0" << endl;
        cout << "2. Отделить корни уравнения аналитически и уточнить один из них методом хорд с точностью 0,001: x^4 + 4x^3 - 8x^2 - 17 = 0" << endl;
        cout << "3. Отделить корни уравнения графически: 0.5^x - 1 = (x + 2)" << endl;
        cout << "4. Отделить корни уравнения графически и уточнить один из них методом проб с точностью до 0,01: x^2 * cos(2x) + 1 = 0" << endl;
        cout << "Задание: ";
        cin >> chase;
        if (chase == 1 or chase == 3) {
            switch (chase) {
            case 1:
                cout << "Построение графика исходной функции" << endl;
                graph(400, 300, fun11);
                getchar();
                break;
            case 3:
                cout << "Построение графика исходной функции" << endl;
                graph(400, 300, fun13);
                getchar();
                break;
            }
        }
        else if (chase == 2 or chase == 4) {
            double e, a, b, x1;
            cout << "Введите нужную точность: ";
            while (!(cin >> e) || e >= 1 || e <= 0) {
                if (cin.fail()) { // проверяем на ошибку ввода
                    cin.clear();
                }
                cout << "Ошибка! Пожалуйста, введите положительное число, меньше 1: ";
            }
            cout << "Вы ввели точность: " << e << endl;
            cout << "Введите левую границу интервала: ";
            while (!(cin >> a)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Левая граница интервала равна: " << a << endl;
            cout << "Введите правую границу интервала: ";
            while (!(cin >> b)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Правая граница интервала равна: " << b << endl;
            cout << "Уточняем корень методом проб: " << endl;
            switch (chase) {
            case 2:
                x1 = method_prob(a, b, e, fun12);
                cout << "Ответ: x = " << x1 << endl;
                cout << "Построение графика исходной функции" << endl;
                graph(500, 400, fun12);
                getchar();
                break;
            case 4:
                x1 = method_prob(a, b, e, fun14);
                cout << "Ответ: x = " << x1 << endl;
                cout << "Построение графика исходной функции" << endl;
                graph(500, 400, fun14);
                getchar();
                break;
            }
        }
        else {
            cout << "Такого задания в этой работе нет, попробуйте еще раз." << endl;
        }
        return 0;
        break;
    case 2:
        cout << "Работа 2 состоит из 2 заданий" << endl;
        cout << "Выберите задание, которое нужно решить:" << endl;
        cout << "1. Отделить корни уравнения графически и уточнить один из них методом хорд с точностью 0,001: 3x - cos(x) - 1 = 0" << endl;
        cout << "2. Отделить корни уравнения аналитически и уточнить один из них методом хорд с точностью 0,001: x^3 + 0.2x^2 + 0.5x - 1.2 = 0" << endl;
        cout << "Задание: ";
        cin >> chase;
        if (chase == 1 or chase == 2) {
            double e, a, b, x;
            cout << "Введите нужную точность: ";
            while (!(cin >> e) || e >= 1 || e <= 0) {
                if (cin.fail()) { // проверяем на ошибку ввода
                    cin.clear();
                }
                cout << "Ошибка! Пожалуйста, введите положительное число, меньше 1: ";
            }

            // Определяем интервал [a, b], на котором ищем корень уравнения
            // Например, можно взять отрезок [-10, 10]
            a = -10.0;
            b = 10.0;

            // Теперь вызываем функцию method_prob для уточнения корня с заданной точностью
            if (chase == 1) {
                // Уравнение: 3x - cos(x) - 1 = 0
                x = method_prob(a, b, e, fun21);
            }
            else if (chase == 2) {
                // Уравнение: x^3 + 0.2x^2 + 0.5x - 1.2 = 0
                x = method_prob(a, b, e, fun22);
            }

            cout << "Приближенный корень уравнения: " << x << endl;
        }
        else {
            cout << "Такого задания в этой работе нет, попробуйте еще раз." << endl;
        }
        return 0;
        break;

    case 3:
        cout << "Работа 3 состоит из 2 заданий" << endl;
        cout << "Выберите задание, которое нужно решить:" << endl;
        cout << "1.Отделить корни уравнения графически и уточнить один из них методом касательных с точностью 0,001: 3x - cos(x) - 1 = 0 " << endl;
        cout << "2.Отделить корни уравнения аналитически и уточнить один из них методом касательных с точностью 0,001:  x^3 + 0.2x^2 + 0.5x - 1.2 = 0 " << endl;
        cout << "Задание: ";
        cin >> chase;
        if (chase == 1 or chase == 2) {
            double e, x0, x, dffix;
            cout << "Введите нужную точность: ";
            while (!(cin >> e) || e >= 1 || e <= 0) {
                if (cin.fail()) { // проверяем на ошибку ввода
                    cin.clear();
                }
                cout << "Ошибка! Пожалуйста, введите положительное число, меньше 1: ";
            }
            cout << "Вы ввели точность: " << e << endl;
            cout << "Введите начальное приближение: ";
            while (!(cin >> x0)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Начальное приближение равно: " << x0 << endl;
            cout << "Уточняем корень методом касательных: " << endl;
            switch (chase) {
            case 1:
                dffix = x0;
                x = x0 - fun31(x0) / dfun31(dffix);
                cout << x << endl;
                do {
                    x0 = x;
                    x = x0 - fun31(x0) / dfun31(dffix);
                    cout << x << endl;
                } while (fabs(fun31(x)) > e);
                cout << "Ответ: x = " << x << endl;
                cout << "Построение графика исходной функции" << endl;
                graph(500, 400, fun31);
                getchar();
                break;
            case 2:
                x = method_kasatelnih(x0, e, fun32, dfun32);
                cout << "Ответ: x = " << x << endl;
                cout << "Построение графика исходной функции" << endl;
                graph(450, 350, fun32);
                getchar();
                break;
            }
        }
        else {
            cout << "Такого задания в этой работе нет, попробуйте еще раз." << endl;
        }
        return 0;
        break;
    case 4:
        cout << "Работа 4 состоит из 1 задания" << endl;
        cout << "Задание: Комбинированным методом хорд и касательных решить уравнение третьей степени, вычислив корни с точностью до 0,001: 2x^3 + 9x^2 - 21 = 0 " << endl;
        double e, xn, x1n;
        cout << "Введите нужную точность: ";
        while (!(cin >> e) || e >= 1 || e <= 0) {
            if (cin.fail()) { // проверяем на ошибку ввода
                cin.clear();
            }
            cout << "Ошибка! Пожалуйста, введите положительное число, меньше 1: ";
        }
        cout << "Вы ввели точность: " << e << endl;
        for (int i = 1; i <= 3; i++)
        {
            cout << "Введите левую границу для интервала " << i << ": ";
            while (!(cin >> xn)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Левая граница для интервала " << i << " равна " << xn << endl;
            cout << "Введите правую границу для интервала " << i << ": ";
            while (!(cin >> x1n)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Правая граница для интервала " << i << " равна " << x1n << endl;
            cout << "Уточняем корень комбинированным методом хорд и касательных: " << endl;
            do {
                if (fun41(xn) * ddfun41(xn) > 0) {
                    xn = xn - fun41(xn) / dfun41(xn);
                    x1n = x1n - fun41(xn) * (x1n - xn) / (dfun41(x1n) - fun41(xn));
                }
                else {
                    xn = xn - fun41(xn) * (x1n - xn) / (dfun41(x1n) - fun41(xn));
                    x1n = x1n - fun41(x1n) / dfun41(x1n);
                }
            } while (fabs(fun41(xn)) > e);
            cout << "Ответ: x" << i << " = " << xn << endl;
        }
        cout << "Построение графика исходной функции" << endl;
        graph(700, 600, fun41);
        getchar();
        return 0;
        break;
    case 5:
        cout << "Работа 5 состоит из 2 заданий" << endl;
        cout << "Выберите задание, которое нужно решить:" << endl;
        cout << "1.Отделить корни уравнения графически и уточнить один из них методом итераций с точностью 0,001: 2 - ln(x) = x" << endl;
        cout << "2.Отделить корни уравнения аналитически и уточнить один из них методом итераций с точностью 0,001:  x^3 - 0.2*x^2 + 0.4*x - 1.4 = 0" << endl;
        cout << "Задание: ";
        cin >> chase;
        if (chase == 1 or chase == 2) {
            double e, x0, x, dffix;
            cout << "Введите нужную точность: ";
            while (!(cin >> e) || e >= 1 || e <= 0) {
                if (cin.fail()) { // проверяем на ошибку ввода
                    cin.clear();
                }
                cout << "Ошибка! Пожалуйста, введите положительное число, меньше 1: ";
            }
            cout << "Вы ввели точность: " << e << endl;
            cout << "Введите начальное приближение: ";
            while (!(cin >> x0)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Начальное приближение равно: " << x0 << endl;
            cout << "Уточняем корень методом итераций: " << endl;
            switch (chase) {
            case 1:
                x = method_iteracii(x0, e, fun51, 2);
                cout << "Ответ: x = " << x << endl;
                cout << "Построение графика исходной функции" << endl;
                graph(500, 400, fun51);
                getchar();
                break;
            case 2:
                x = method_iteracii(x0, e, fun52, 3);
                cout << "Ответ: x = " << x << endl;
                cout << "Построение графика исходной функции" << endl;
                graph(500, 400, fun52);
                getchar();
                break;
            }
        }
        else {
            cout << "Такого задания в этой работе нет, попробуйте еще раз." << endl;
        }
        return 0;
        break;
    case 6:
        cout << "Работа 6 состоит из 2 заданий" << endl;
        cout << "Выберите задание, которое нужно решить:" << endl;
        cout << "1. Используя метод итераций, решить систему нелинейных уравнений с точностью до 0,001: 1) sin(x-1) = 1.3 - y; 2) x - sin(y+1) = 0.8" << endl;
        cout << "2. Используя метод Ньютона, решить систему нелинейных уравнений с точностью 0,001: 1) tg(xy) = x^2; 2) 0.8*x^2 + 2*y^2 = 1" << endl;
        cout << "Задание: ";
        cin >> chase;
        if (chase == 1 or chase == 2) {
            double e, x0, y0, x, y;
            cout << "Введите нужную точность: ";
            while (!(cin >> e) || e >= 1 || e <= 0) {
                if (cin.fail()) { // проверяем на ошибку ввода
                    cin.clear();
                }
                cout << "Ошибка! Пожалуйста, введите положительное число, меньше 1: ";
            }
            cout << "Вы ввели точность: " << e << endl;
            cout << "Введите начальное приближение для x: ";
            while (!(cin >> x0)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Начальное приближение равно: " << x0 << endl;
            cout << "Введите начальное приближение для y: ";
            while (!(cin >> y0)) {
                cout << "Ошибка! Пожалуйста, введите число: ";
                cin.clear();
            }
            cout << "Начальное приближение равно: " << y0 << endl;
            switch (chase) {
            case 1:
                cout << "Уточняем корни методом итераций: " << endl;
                x = x0; y = y0;
                do {
                    x0 = x;
                    y0 = y;
                    x = 0.8 + sin(y0 + 1);
                    y = 1.3 - sin(x0 - 1);
                    cout << "x = " << x << "; y = " << y << " " << endl;
                } while (fabs(x - x0) > e || fabs(y - y0) > e);
                cout << "Достигнута заданная точность" << endl;
                cout << "Ответ: x = " << x << "; y = " << y << " " << endl;
                break;
            case 2:
                cout << "Уточняем корни методом Ньютона: " << endl;
                method_newton(x0, y0, x, y, e);
                cout << "Ответ: x = " << x << "; y = " << y << " " << endl;
                break;
            }
        }
        else {
            cout << "Такого задания в этой работе нет, попробуйте еще раз." << endl;
        }
        return 0;
        break;
    default:
        cout << "Что-то пошло не так. Попробуйте еще раз." << endl;
        break;
    }
    return 0;
}
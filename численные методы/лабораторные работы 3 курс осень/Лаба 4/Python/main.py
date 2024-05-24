import math

# Заданные функции для работы 1
def fun11(x):
    return pow(x, 4) + 4 * pow(x, 3) - 8 * pow(x, 2) - 17

def fun12(x):
    return pow(x, 2) * math.cos(2 * x) + 1

# Заданные функции для работы 2
def fun21(x):
    return 3 * x - math.cos(x) - 1

def fun22(x):
    return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2

# Заданные функции для работы 3
def fun31(x):
    return 3 * x - math.cos(x) - 1

def dfun31(x):
    return 3 + math.sin(x)

def fun32(x):
    return pow(x, 3) + 0.2 * pow(x, 2) + 0.5 * x - 1.2

def dfun32(x):
    return 3 * pow(x, 2) + 0.4 * x + 0.5

# Заданные функции для работы 4
def fun41(x):
    return 2 * pow(x, 3) + 9 * pow(x, 2) - 21

def dfun41(x):
    return 6 * pow(x, 2) + 18 * x

def ddfun41(x):
    return 12 * x + 18
    
def f62(x, y):
    return math.tan(x * y) - x**2

def g62(x, y):
    return 0.8 * x**2 + 2 * y**2 - 1

def f62x(x, y):
    return y / (math.cos(x * y)**2) - 2 * x

def f62y(x, y):
    return x / (math.cos(x * y)**2)

def g62x(x, y):
    return 1.6 * x

def g62y(x, y):
    return 4 * y

def method_newton(x0, y0, e):
    x = x0
    y = y0
    while True:
        x0 = x
        y0 = y
        d = f62x(x0, y0) * g62y(x0, y0) - f62y(x0, y0) * g62x(x0, y0)
        deltahn = f62y(x0, y0) * g62(x0, y0) - f62(x0, y0) * g62y(x0, y0)
        deltakn = g62x(x0, y0) * f62(x0, y0) - g62(x0, y0) * f62x(x0, y0)
        x = x0 + deltahn / d
        y = y0 + deltakn / d
        if abs(x - x0) <= e and abs(y - y0) <= e:
            break
    return x, y

# Метод половинного деления (метод проб)
def method_prob(a, b, e, f):
    if f(a) * f(b) >= 0:
        print("В этом промежутке нет корня")
        return 0
    x = a
    while True:
        x = (a + b) / 2
        if f(x) == 0.0:
            break
        elif f(x) * f(a) < 0:
            b = x
        else:
            a = x
        if abs(f(x)) < e:
            break
    return x

# Метод хорд
def method_chords(a, b, e, f):
    while abs(b - a) > e:
        a = b - (b - a) * f(b) / (f(b) - f(a))
        b = a + (a - b) * f(a) / (f(a) - f(b))
    return b

# Метод касательных (метод Ньютона)
def method_tangents(x0, e, f, df):
    x = x0 - f(x0) / df(x0)
    while abs(f(x)) > e:
        x0 = x
        x = x0 - f(x0) / df(x0)
    return x

# Метод итераций
def method_iteracii(x, e, phi, max_iter=1000):
    iter_count = 0
    while iter_count < max_iter:
        next_x = phi(x)
        if abs(next_x - x) < e:
            return next_x
        x = next_x
        iter_count += 1
    raise ValueError("Метод итераций не сошелся после {} итераций".format(max_iter))

# Подходящие функции phi(x) для каждой из функций f(x)
def phi51(x):
    return math.log(x) + 2

def phi52(x):
    return pow((0.2 * pow(x, 2) - 0.4 * x + 1.4), 1/3)

def main():
    while True:
        print("Выберите номер работы от 1 до 6 (для выхода введите любое другое число): ")
        task = int(input())
        if task < 1 or task > 6:
            print("Выход из программы.")
            break

        if task == 1:
            print("Работа 1 состоит из 2 заданий")
            print("Выберите задание, которое нужно решить:")
            print("1.Отделить корни уравнения аналитически и уточнить один из них методом проб с точностью до 0,01: x^4 + 4x^3 - 8x^2 - 17 = 0")
            print("2.Отделить корни уравнения аналитически и уточнить один из них методом проб с точностью до 0,01: x^2 * cos(2x) = -1")
            chase = int(input("Задание: "))
            
            if chase == 1:
                e = float(input("Введите нужную точность: "))
                a = float(input("Введите левую границу интервала: "))
                b = float(input("Введите правую границу интервала: "))
                print("Уточняем корень методом проб:")
                x1 = method_prob(a, b, e, fun11)
                print("Ответ: x =", x1)
            elif chase == 2:
                e = float(input("Введите нужную точность: "))
                a = float(input("Введите левую границу интервала: "))
                b = float(input("Введите правую границу интервала: "))
                print("Уточняем корень методом проб:")
                x1 = method_prob(a, b, e, fun12)
                print("Ответ: x =", x1)
            else:
                print("Такого задания в этой работе нет, попробуйте еще раз.")

        elif task == 2:
            print("Работа 2 состоит из 2 заданий")
            print("Выберите задание, которое нужно решить:")
            print("1. Отделить корни уравнения аналитически и уточнить один из них методом хорд с точностью 0,001: 3x - cos(x) - 1 = 0")
            print("2. Отделить корни уравнения аналитически и уточнить один из них методом хорд с точностью 0,001: x^3 + 0.2x^2 + 0.5x - 1.2 = 0")
            chase = int(input("Задание: "))
            
            if chase == 1:
                e = 0.001
                a = -10.0
                b = 10.0
                print("Уточняем корень методом хорд:")
                x1 = method_chords(a, b, e, fun21)
                print("Ответ: x =", x1)
            elif chase == 2:
                e = 0.001
                a = -10.0
                b = 10.0
                print("Уточняем корень методом хорд:")
                x1 = method_chords(a, b, e, fun22)
                print("Ответ: x =", x1)
            else:
                print("Такого задания в этой работе нет, попробуйте еще раз.")

        elif task == 3:
            print("Работа 3 состоит из 2 заданий")
            print("Выберите задание, которое нужно решить:")
            print("1.Отделить корни уравнения графически и уточнить один из них методом касательных с точностью 0,001: 3x - cos(x) - 1 = 0 ")
            print("2.Отделить корни уравнения аналитически и уточнить один из них методом касательных с точностью 0,001:  x^3 + 0.2x^2 + 0.5x - 1.2 = 0 ")
            chase = int(input("Задание: "))
            
            if chase == 1:
                e = 0.001
                x0 = float(input("Введите начальное приближение: "))
                print("Уточняем корень методом касательных: ")
                x1 = method_tangents(x0, e, fun31, dfun31)
                print("Ответ: x =", x1)
            elif chase == 2:
                e = 0.001
                x0 = float(input("Введите начальное приближение: "))
                print("Уточняем корень методом касательных: ")
                x1 = method_tangents(x0, e, fun32, dfun32)
                print("Ответ: x =", x1)
            else:
                print("Такого задания в этой работе нет, попробуйте еще раз.")

        elif task == 4:
            print("Работа 4 состоит из 1 задания")
            print("Задание: Комбинированным методом хорд и касательных решить уравнение третьей степени, вычислив корни с точностью до 0,001: 2x^3 + 9x^2 - 21 = 0 ")
            e = float(input("Введите нужную точность: "))
            for i in range(1, 4):
                a = float(input(f"Введите левую границу для интервала {i}: "))
                b = float(input(f"Введите правую границу для интервала {i}: "))
                print(f"Уточняем корень для интервала {i} комбинированным методом хорд и касательных:")
                xn = a
                x1n = b
                while abs(fun41(xn)) > e:
                    if fun41(xn) * ddfun41(xn) > 0:
                        xn = xn - fun41(xn) / dfun41(xn)
                        x1n = x1n - fun41(xn) * (x1n - xn) / (dfun41(x1n) - fun41(xn))
                    else:
                        xn = xn - fun41(xn) * (x1n - xn) / (dfun41(x1n) - fun41(xn))
                        x1n = x1n - fun41(x1n) / dfun41(x1n)
                print(f"Ответ: x{i} = {xn}")
            break

        elif task == 5:
            print("Работа 5 состоит из 2 заданий")
            print("Выберите задание, которое нужно решить:")
            print("1. Отделить корни уравнения аналитически и уточнить один из них методом итераций с точностью 0,001: log(x) + 2 = 0")
            print("2. Отделить корни уравнения аналитически и уточнить один из них методом итераций с точностью 0,001: (0.2 * x^2 - 0.4 * x + 1.4)^(1/3) = 0")
            chase = int(input("Задание: "))
    
            if chase == 1 or chase == 2:
                e = 0.001
                x0 = float(input("Введите начальное приближение: "))
                k = float(input("Введите значение k: "))  # Добавлен ввод значения k
                if chase == 1:
                    print("Уточняем корень методом итераций (x = log(x) + 2):")
                    result = method_iteracii(x0, e, phi51)
                    print("Ответ: x =", result)
                else:
                    print("Уточняем корень методом итераций (x = (0.2 * x^2 - 0.4 * x + 1.4)^(1/3)):")
                    result = method_iteracii(x0, e, phi52)
                    print("Ответ: x =", result)
            else:
                print("Такого задания в этой работе нет, попробуйте еще раз.")
                
        elif task == 6:
            print("Работа 6 состоит из 2 заданий")
            print("Выберите задание (1 или 2): ")
            chase = int(input())

            if chase == 1 or chase == 2:
                e = float(input("Введите точность: "))
                x0 = float(input("Введите начальное приближение для x: "))
                y0 = float(input("Введите начальное приближение для y: "))
                if chase == 1:
                    print("Уточняем корни методом итераций:")
                    x = x0
                    y = y0
                    while True:
                        x0 = x
                        y0 = y
                        x = 0.8 + math.sin(y0 + 1)
                        y = 1.3 - math.sin(x0 - 1)
                        print(f"x = {x}; y = {y}")
                        if abs(x - x0) <= e and abs(y - y0) <= e:
                            break
                    print("Достигнута заданная точность")
                    print(f"Ответ: x = {x}; y = {y}")
                elif chase == 2:
                    print("Уточняем корни методом Ньютона:")
                    x, y = method_newton(x0, y0, e)
                    print(f"Ответ: x = {x}; y = {y}")
            else:
                print("Такого задания в этой работе нет, попробуйте еще раз.")


if __name__ == "__main__":
    main()

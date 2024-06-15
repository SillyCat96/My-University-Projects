import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# Функция для получения пользовательских параметров
def get_user_parameters():
    max_time = float(input("Введите максимальное время (например, 5): "))
    time_step = float(input("Введите шаг времени (например, 0.01): "))
    L = float(input("Введите длину стержня (например, 1.0): "))
    alpha = float(input("Введите коэффициент теплопроводности (например, 0.001): "))
    func = input("Введите начальную функцию u(x, 0) (например, 'x * np.sin(5 * np.pi * x)'): ")
    return max_time, time_step, L, alpha, func

# Начальные параметры
default_max_time = 5.0
default_time_step = 0.01
default_L = 1.0
default_alpha = 0.001
default_func = 'x * np.sin(5 * np.pi * x)'

# Запрос выбора пользователя
choice = input("Выберите вариант (1 - запустить с изначальными параметрами, 2 - изменить параметры): ")

if choice == '2':
    max_time, time_step, L, alpha, func = get_user_parameters()
else:
    max_time = default_max_time
    time_step = default_time_step
    L = default_L
    alpha = default_alpha
    func = default_func

# Вычисляем dx с учетом условий стабильности
dx = np.sqrt(2 * alpha * time_step)
nx = int(L / dx) + 1  # Пересчитываем количество точек по x

# Обновляем dx после пересчета nx
dx = L / (nx - 1)

# Количество шагов по времени
nt = int(max_time / time_step) + 1

# Стабильность
gamma = alpha * time_step / dx**2
print(f"Проверка значения gamma = {gamma:.2f}")

# Начальные условия
x = np.linspace(0, L, nx)
u = eval(func)  # Используем eval для вычисления функции
u_new = np.zeros(nx)

# Для анимации
fig, ax = plt.subplots()
line, = ax.plot(x, u)
ax.set_xlim(0, L)
ax.set_ylim(-1, 1)
ax.set_xlabel('x')
ax.set_ylabel('Temperature')
ax.set_title('Решение уравнения теплопроводности')
ax.grid(True)

# Текст для отображения текущего времени
time_text = ax.text(0.85, 0.95, '', transform=ax.transAxes)

# Функция для обновления графика
def update(frame):
    global u, u_new
    t = frame * time_step
    if t > max_time:
        ani.event_source.stop()  # Остановка анимации при достижении максимального времени
        return line, time_text

    for i in range(1, nx-1):
        u_new[i] = u[i] + gamma * (u[i+1] - 2*u[i] + u[i-1])
    
    u_new[0] = 0  # Граничное условие u(0, t) = 0
    u_new[-1] = 0 # Граничное условие u(1, t) = 0
    u = u_new.copy()
    line.set_ydata(u)
    time_text.set_text(f't = {t:.2f}')
    return line, time_text

# Анимация
ani = FuncAnimation(fig, update, frames=nt, blit=True, interval=50, repeat=False)
plt.show()

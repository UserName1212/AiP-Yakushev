number = int(input("Введите номер школы: "))
print(f"Ученик учится в {number} школе")

name = input("Введите имя:  ")
year = int(input("Введите год поступления в школу: "))
print(f"{name} сейчас учитя в {2025 - year} классе")

money = int(input("Введите количество денег: "))
print(f"Вы можете купить {money // 12} конфет.\n Ваша сдача {money%12} рублей")

ch1 = int(input("Введите первое число: "))
ch2 = int(input("Введите второе число: "))
print(f"{ch1}*{ch2} = {ch1 *ch2}")
print(f"{ch1}+{ch2} = {ch1+ch2}")
print(f"{ch1}-{ch2} = {ch1-ch2}")
print(f"{ch1}/{ch2} = {ch1/ch2}")
print(f"{ch1}^{ch2} = {ch1**ch2}")

pas = 12345678
inpas = input("Введите пароль(12345678): ")
if (pas == inpas):
    print("Вход разрешен")
else:
    print("Вход запрещен")


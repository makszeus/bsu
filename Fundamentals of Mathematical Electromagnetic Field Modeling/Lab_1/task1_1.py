def is_leap_year(year_r):
    if (year_r % 4 == 0 and year_r % 100 != 0) or (year_r % 400 == 0):
        return True
    else:
        return False

year = int(input("Введите год: "))

if is_leap_year(year):
    print("Год является високосным.")
else:
    print("Год не является високосным.")

#include <iostream>
#include <limits>

using namespace std;

double get_double_value()
{
    double value;
    while (!(cin >> value))
    {
        cout << "Некорректное значение. Пожалуйста, введите число." << endl;
        cout << "Введите значение снова: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

int get_int_value()
{
    int value;
    while (!(cin >> value))
    {
        cout << "Некорректное значение." << endl;
        cout << "Значение должно быть целым числом." << endl;
        cout << "Введите значение снова:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int razmer;
    cout << "Введите размер массива:" << endl;
    razmer = get_int_value()-1 ;
    while (razmer <= 0) {
        cout << "Размер массива должен быть больше 0" << endl;
        razmer = get_int_value();
    }

    double grades[razmer];

    for (int i = 0; i < razmer; i++)
    {
        int choice;
        while (1)
        {
            cout << "Как вы хотите заполнить " << i + 1 << " элемент массива?" << endl
                 << "1) рандомным числом | 2) Ввести с клавиатуры" << endl;
            choice = get_int_value();
            switch (choice)
            {
                case 1:
                {
                    int min, max;
                    cout << "Введите минимальное значение рандомного числа:";
                    min = get_int_value();
                    cout << "Введите максимальное значение рандомного числа:";
                    max = get_int_value();

                    if (min > max) {
                        cout << "Ошибка: минимальное значение не может быть больше максимального." << endl;
                        continue;
                    }

                    grades[i] = min + rand() % (max - min + 1);
                    cout << "Ваше рандомное число: " << grades[i] << endl << endl;
                }
                break;
                case 2:
                    cout << "Введите " << i + 1 << " элемент массива:" << endl;
                    grades[i] = get_double_value();
                    break;
                default:
                    cout << "Такого выбора не было введите значение из предложенных" << endl;
                    break;
            }
            break;
        }
    }

    int last_zero_index = -1;

    for (int i = razmer; i >= 0; i--)
    {
        if (grades[i] == 0)
        {
            last_zero_index = i;
            break;
        }
    }

    double ans = 0;

    if (last_zero_index != -1 && last_zero_index < razmer - 1)
    {
        for (int i = last_zero_index + 1; i < razmer; i++)
        {
            ans += grades[i];
        }
    }

    cout << "\nВаш массив: ";
    for (int i = 0; i < razmer; i++) {
        cout << grades[i] << " ";
    }
    cout << endl;

    if (last_zero_index == -1) {
        cout << "В массиве не найдено элементов, равных нулю." << endl;
    }
    else if (last_zero_index == razmer - 1) {
        cout << "последний массива элемент равен нулю";
    }
    else {
        cout << "Сумма элементов массива, расположенных после последнего элемента, равного нулю = " << ans << endl;
    }

    return 0;
}
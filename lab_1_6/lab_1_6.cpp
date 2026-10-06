#include <iostream>
#include <Windows.h>
#include "Date.h"

using namespace std;

Date makeDate(int y, int m, int d)
{
    Date dt;
    if (!dt.Init(y, m, d))
    {
        cout << "Помилка ініціалізації! Встановлено дату за замовчуванням.\n";
    }
    return dt;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== 1. Демонстрація роботи з вкладеним класом Date::Triad ===\n";
    Date::Triad tr;
    tr.Init(5, 15, 25);
    cout << "Початкова трійка через Date::Triad: "; tr.Display();
    tr.IncrementAll();
    cout << "Після IncrementAll: "; tr.Display();

    cout << "\n=== 2. Демонстрація зовнішнього класу Date ===\n";
    Date d1 = makeDate(2024, 2, 28);
    cout << "Дата: "; d1.Display();
    d1.IncrementDay();
    cout << "Після IncrementDay() (високосний рік 2024): "; d1.Display();
    d1.IncrementDay();
    cout << "Після наступного IncrementDay(): "; d1.Display();

    cout << "\n=== 3. Додавання днів (AddDays) ===\n";
    d1.AddDays(40);
    cout << "Після AddDays(40): "; d1.Display();

    cout << "\n=== 4. Демонстрація динамічної пам'яті (-> та масив) ===\n";
    Date* ptrDate = new Date();
    ptrDate->Init(2023, 12, 31);
    cout << "Дата через вказівник: "; ptrDate->Display();
    ptrDate->IncrementDay();
    cout << "Після переходу на новий рік: "; ptrDate->Display();
    delete ptrDate;

    int n = 2;
    Date* arr = new Date[n];
    arr[0].Init(2025, 5, 1);
    arr[1].Init(2025, 12, 31);
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = ";
        arr[i].Display();
    }
    delete[] arr;

    return 0;
}
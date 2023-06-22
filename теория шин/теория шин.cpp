#include <iostream>

using namespace std;

/*
\bref меню

Функция предназначена для выбора пункта меню

\param vvod - номер пункта

\return vvod - возвращаем номер пункта
*/

int menu() {
    int vvod;
    cout << "1. Задача" << endl;
    cout << "2. Информация по задаче" << endl;
    cout << "3. Выход" << endl;
    cout << "Введите номер пункта: ";
    cin >> vvod;
    return vvod;
}

/*
\bref Вычисление жизни шины

Функция предназначена для вычисления жизни шины

\param shina - кол-во шин, iznos - износ шины, km - расстояние, week - неделя

\retirn result_live_shina - вернули результат формулы (жизнь шин)
*/

int calculation_live_shinas(int shina, double iznos, int km, int week)
{
    if (km >= 2000)
    {
        week = floor(km / 2000); //округление в менюшую сторону 
    }
    else
    {
        week = 1;
    }

    cout << "Состав будет ехать " << week << " недель" << endl;
    cout << '\n';

    if (week <= 3)
    {
        iznos = 1;
    }
    else if (week >= 4 && week <= 10) {
        iznos = 0.95;
    }
    else if (week >= 11 && week <= 13) {
        iznos = 0.60;
    }
    else if (week == 14) {
        iznos = 0.30;
    }
    else if (week >= 15) {
        iznos = 0;
    }
    else
        cout << "ERROR..." << endl;

    int check = 0, ostatok = 0;

    cout << "Укажите неделю обследования шины: ";
    cin >> check;

    ostatok = 15 - check;

    cout << "Недель до полного износа: " << ostatok << '\n';
    cout << '\n';

    double usl_ver_1 = (check + ostatok), usl_ver_2 = ostatok;

    if (usl_ver_1 < 0) {
        cout << "Числа введены неверно" << endl;
        return 1;
    }
    else if (usl_ver_1 >= 0 && usl_ver_1 <= 3) {
        usl_ver_1 = 1;
    }
    else if (usl_ver_1 >= 4 && usl_ver_1 <= 6) {
        usl_ver_1 = 0.95;
    }
    else if (usl_ver_1 >= 7 && usl_ver_1 <= 9) {
        usl_ver_1 = 0.85;
    }
    else if (usl_ver_1 >= 10 && usl_ver_1 <= 12) {
        usl_ver_1 = 0.60;
    }
    else if (usl_ver_1 >= 13 && usl_ver_1 <= 15) {
        usl_ver_1 = 0.30;
    }
    else if (usl_ver_1 >= 16) {
        usl_ver_1 = 0;
    }


    if (usl_ver_2 < 0) {
        cout << "Числа введены неверно" << endl;
        return 1;
    }
    else if (usl_ver_2 >= 0 && usl_ver_2 <= 3) {
        usl_ver_2 = 1;
    }
    else if (usl_ver_2 >= 4 && usl_ver_2 <= 6) {
        usl_ver_2 = 0.95;
    }
    else if (usl_ver_2 >= 7 && usl_ver_2 <= 9) {
        usl_ver_2 = 0.85;
    }
    else if (usl_ver_2 >= 10 && usl_ver_2 <= 12) {
        usl_ver_2 = 0.60;
    }
    else if (usl_ver_2 >= 13 && usl_ver_2 <= 15) {
        usl_ver_2 = 0.30;
    }
    else if (usl_ver_2 >= 16) {
        usl_ver_2 = 0;
    }

    double result_usl_ver = 0, result_live_shina = 0;

    result_usl_ver = usl_ver_1 / usl_ver_2; //нахождение условной вероятности

    if (result_usl_ver <= 0) {
        cout << "Числа введены неверно" << endl;
        return 1;
    }



    result_live_shina = iznos * result_usl_ver;

    if (result_live_shina <= 0) {
        cout << "Время жизни шины меньше или равна 0" << endl;
    }


    cout << "Вероятность износа шины: " << result_live_shina << endl;

    cout << '\n';

    return result_live_shina;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int shina = 0; // расчёт кол-ва шин в зависимости от кол-ва машин
    double iznos = 0; // расчёт износа в зависимоти от времени
    int km = 0; // указать расстояние
    int week = 0; // расчёт времени в зависисимости от расстояния
    int kar = 0; // указать кол-во машин чтобы узкать кол-во шин
    while (true) {
        int vvod = menu();
        if (vvod == 1)
        {
            cout << '\n';
            cout << "Введите кол-во машин: ";
            cin >> kar;
            shina = kar * 10;
            cout << "Кол-во шин: " << shina << '\n';
            cout << "Введите расстояние: ";
            cin >> km;
            calculation_live_shinas(shina, iznos, km, week);
        }
        else if (vvod == 2)
        {
            cout << "Имеется 40 машин у которых по 10 шин" << endl;
            cout << "===================================================" << endl;
            cout << "Шина, изншенная на 20% - прошла 6000км" << endl;
            cout << "Шина, изншенная на 40% - прошла 12000км" << endl;
            cout << "Шина, изншенная на 60% - прошла 18000км" << endl;
            cout << "Шина, изншенная на 80% - прошла 24000км" << endl;
            cout << "Шина, изншенная на 100% - прошла 30000км" << endl;
            cout << "===================================================" << endl;
            cout << "На 100 шин, 5 выходят из строя после 6000 км" << endl;
            cout << "На 100 шин, 10 выходят из строя между 6000 и 12000 км" << endl;
            cout << "На 100 шин, 25 выходят из строя между 12000 и 18000 км" << endl;
            cout << "На 100 шин, 30 выходят из строя между 18000 и 24000 км" << endl;
            cout << "На 100 шин, 30 выходят из строя между 24000 и 30000 км" << endl;
            cout << "===================================================" << endl;
            cout << "Вероятность, что шина прослуит больше 4 недель - 0,95" << endl;
            cout << "Вероятность, что шина прослуит больше 10 недель - 0,60" << endl;
            cout << "Вероятность, что шина прослуит больше 14 недель - 0,30" << endl;
            cout << "Вероятность, что шина прослуит больше 15 недель - 0" << endl;
            cout << "===================================================" << endl;
            cout << "V(A) - новая шина в момент t = 0, прослужит до момента t = A" << endl;
            cout << "V(t + A) - вероятность что шина прослужит до момента t + A" << endl;
            cout << "Va(t) - условная вероятность в момент t = 0, со степенью износа V(a), может прослужить до момента t" << endl;
            cout << "Формула для расчета: V(t + A) = V(A)*Va(t)" << endl;
            cout << "===================================================" << endl;
            cout << "ДОБАВИТЬ АВТОТЕСТИРОВАНИЕ" << endl;
        }
        else if (vvod == 3)
        {
            return 0;
        }
        else
        {
            cout << '\n';
            cout << "Введен неверный номер пункта меню" << '\n';
            cout << '\n';
        }
    }
}

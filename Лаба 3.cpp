#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251 > nul");
    char name1[100];
    int size = 1000, n = 1;
    int j;  //Количество введённых экскурсий
    char** name = new char* [size];
    string* place = new string[size];
    double* cena = new double[size];

    for (int i = 0; i < size; ++i)
    {
        cout << "Введите название экскурсии " << i + 1 << ": ";
        char massive[100];
        cin.getline(massive, 100);
        name[i] = new char[strlen(massive) + 1];
        strcpy_s(name[i], strlen(massive) + 1, massive);

        if (strlen(massive) == 0)
        {
            break;
        }

        cout << "Введите название места " << i + 1 << ": ";
        cin >> place[i];
        cin.ignore();
        cout << "Введите цену " << i + 1 << ": ";
        cin >> cena[i];
        cin.ignore();
        j = i;
    }
    ofstream outFile("excursion.txt");
    ofstream out("output.txt");

    if (outFile.is_open())
    {
        for (int i = 0; i <= j; i++)
        {
            outFile << "Название экскурсии:" << ' ' << name[i] << ' ' << ',' << ' ' << "название места:" << ' ' << place[i] << ' ' << ',' << ' ' << "стоимость:" << ' ' << cena[i] << '.' << endl;
        }
    }
    else
    {
        cerr << "Не удалось открыть файл для записи.\n";
    }

    int vibor;
    do
    {
        system("cls");
        cout << "1. Добавить\n";
        cout << "2. Поиск по названию\n";
        cout << "3. Поиск по месту\n";
        cout << "4. нахождение экскурсий меньшей стоимости\n";
        cout << "5. нахождение экскурсий большей стоимости\n";
        cout << "6. Сортировка по возрастанию цены (выполняется автоматически)\n";
        cout << "7. Сортировка по уменьшению цены (выполняется автоматически)\n";
        cout << "0. Завершить программу\n";
        cout << "Введите ваш выбор: ";
        cin >> vibor;
        switch (vibor)
        {
        case 1:
        {
            j += 1;
            cout << "Введите название экскурсии " << j + 1 << ": ";
            cin >> name[j];
            cout << "Введите название места " << j + 1 << ": ";
            cin >> place[j];
            cin.ignore();
            cout << "Введите цену " << j + 1 << ": ";
            cin >> cena[j];
            cin.ignore();
            out << "Название экскурсии: " << name[j] << ", название места: " << place[j] << ", стоимость: " << cena[j] << endl;
            outFile << "Название экскурсии: " << name[j] << ", название места: " << place[j] << ", стоимость: " << cena[j] << endl;
            break;
        }
        case 2:
        {
            cout << "Введите название экскурсии, которую ищете: ";
            cin >> name1;
            int y = 0;
            for (int i = 0; i <= j; i++)
            {
                if (strcmp(name1, name[i]) == 0)
                {
                    out << "Название экскурсии: " << ' ' << name[i] << ' ' << ',' << ' ' << "название место:" << ' ' << place[i] << ' ' << ',' << ' ' << "стоимость:" << ' ' << cena[i] << '.';
                    y += 1;
                }
            }
            if (y == 0)
            {
                out << "таких нет\n";
            }
            break;
        }
        case 3:
        {



            string place1;
            cout << "Введите название места экскурсии, которую ищете: ";
            cin >> place1;
            int y = 0;
            for (int i = 0; i <= j; i++)
            {
                if (place1 == place[i])
                {
                    out << "Название экскурсии: " << name[i] << ", название места: " << place[i] << ", стоимость: " << cena[i] << endl;
                    y += 1;
                }
            }
            if (y == 0)
            {
                out << "таких нет\n" << endl;
            }
            break;
        }
        case 4:
        {

            double cena1;
            cout << "Введите стоимость меньше, которой ищете: ";
            cin >> cena1;
            cin.ignore();
            out << "Стоимость меньше: " << cena1 << endl;
            for (int i = 0; i <= j; i++)
            {
                if (cena1 >= cena[i])
                {
                    out << "Название экскурсии: " << name[i] << ", название места: " << place[i] << ", стоимость: " << cena[i] << endl;
                }
            }
            break;
        }
        case 5:
        {
            double cena2;
            cout << "Введите стоимость больше, которой ищете: ";
            cin >> cena2;
            cin.ignore();
            out << "Стоимость больше: " << cena2 << endl;
            for (int i = 0; i <= j; i++)
            {
                if (cena2 <= cena[i])
                {
                    out << "\nНазвание экскурсии: " << name[i] << ", название места: " << place[i] << ", стоимость: " << cena[i] << endl;
                }
            }
            break;
        }
        case 6:
        {
            for (int i = 0; i <= j - 1; ++i)
            {
                for (int l = 0; l <= j - i - 1; ++l)
                {
                    if (cena[l] >= cena[l + 1])
                    {
                        swap(name[l], name[l + 1]);
                        swap(place[l], place[l + 1]);
                        swap(cena[l], cena[l + 1]);
                    }
                }
            }
            out << "\nОтсортированный список экскурсий по возрастанию стоимости:\n" << endl;
            for (int i = 0; i <= j; ++i)
            {
                out << "Название экскурсии: " << name[i] << ", название места: " << place[i] << ", стоимость: " << cena[i] << endl;
            }
            break;
        }
        case 7:
        {
            for (int i = 0; i <= j - 1; ++i)
            {
                for (int l = 0; l <= j - i - 1; ++l)
                {
                    if (cena[l] <= cena[l + 1])
                    {
                        swap(name[l], name[l + 1]);
                        swap(place[l], place[l + 1]);
                        swap(cena[l], cena[l + 1]);
                    }
                }
            }
            out << "\nОтсортированный список экскурсий по убыванию стоимости:\n" << endl;
            for (int i = 0; i <= j; ++i)
            {
                out << "Название экскурсии: " << name[i] << ", название места: " << place[i] << ", стоимость: " << cena[i] << endl;
            }
            break;
        }
        case 0:
        {
            cout << "Программа завершена.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
        }
    }
    while (vibor != 0);
    outFile.close();
    out.close();
    return 0;
}
  
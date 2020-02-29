// Laba_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;




//Перевод 10-ный число в 2-ный код
void TenToTwo(int n, int *ds)
{
    int m;
    int i = 0;
    while (n > 0)
    {
        m = n % 2;
        ds[16 - i] = m;
        n = n / 2;
        i++;

    }

}

// Делаем инфверсию 2-ного кода
void obr(int *a)
{
    for (size_t i = 1; i < 17; i++)
    {
        if (a[i] == 0)
            a[i] = 1;
        else
            a[i] = 0;
    }

}
//Сложение 2-ных чисел в прямом коде
void pryamoy_kod(int a, int b)
{
    int a1[17] = {0};
    int b1[17] = {0};
    int a2[17] = { 0 };
    int b2[17] = { 0 };
    int c1[17] = { 0 };

    if (a < 0)
    {
        a1[0] = 1;
        a *= -1;
    }

    if (b < 0)
    {
        b1[0] = 1;
        b *= -1;
    }
    TenToTwo(a, a1);
    TenToTwo(b, b1);
    for (size_t i = 0; i < 17; i++)
    {
        a2[i] = a1[i];
        b2[i] = b1[i];
    }
    int pr = 0;
    int sum = 0;
    int k = 0;
    bool fl = a1[0] xor b1[0];
    if (fl) 
    {
        bool fk = false;
        if (a > b) 
        {
            c1[0] = a1[0];
            for (size_t i = 16; i >= 1; i--)
            {
                if (a1[i] < b1[i])
                {
                    a1[i - 1]--;
                    a1[i] += 2;
                    c1[i] = a1[i] - b1[i];
                }
                else 
                {
                    c1[i] = a1[i] - b1[i];
                }
               
            }
            cout << "A=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << a2[i] << " ";
            }
            cout << endl;
            cout << "B=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << b2[i] << " ";
            }
            cout << endl;
            cout << "C=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << c1[i] << " ";
            }
        }
        else
        {
            c1[0] = b1[0];
            for (size_t i = 16; i >= 1; i--)
            {
                if (b1[i] < a1[i])
                {
                    b1[i - 1]--;
                    b1[i] += 2;


                    c1[i] = b1[i] - a1[i];

                }
                else
                {
                    c1[i] = b1[i] - a1[i];
                }
            }

            cout << "B=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << b2[i] << " ";
            }
            cout << endl;
            cout << "A=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << a2[i] << " ";
            }
            cout << endl;
            cout << "C=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << c1[i] << " ";
            }
        }


    }
    else
    {
        c1[0] = a1[0];
        for (size_t i = 16; i >= 1; i--)
        {
            sum = a1[i] + b1[i] + pr;

            c1[i] = sum % 2;

            pr = sum / 2;
        }
        cout << "A=";
        for (size_t i = 0; i < 17; i++)
        {
            cout << a2[i] << " ";
        }
        cout << endl;
        cout << "B=";
        for (size_t i = 0; i < 17; i++)
        {
            cout << b2[i] << " ";
        }
        cout << endl;
        cout << "C=";
        for (size_t i = 0; i < 17; i++)
        {
            cout << c1[i] << " ";
        }
    }
}
//Сложение 2-ных чисел в прямом коде
void obr_kod(int a, int b)
{
    int a1[17] = { 0 };
    int b1[17] = { 0 };
    int a2[17] = { 0 };
    int b2[17] = { 0 };
    int c1[17] = { 0 };
    int d[17] = { 0 };
    int d1[17] = { 0 };
    d[16] = 1;
    int k, l = 0;
    k = a;
    l = b;

    if (a < 0)
    {
        a1[0] = 1;
        a *= -1;
    }

    if (b < 0)
    {
        b1[0] = 1;
        b *= -1;
    }
    TenToTwo(a, a1);
    TenToTwo(b, b1);
    for (size_t i = 0; i < 17; i++)
    {
        a2[i] = a1[i];
        b2[i] = b1[i];
    }

    if (a1[0] == 1)
    {
        obr(a1);
    }
    if (b1[0] ==1)
    {
        obr(b1);
    }

    int sum = 0;
    int pr = 0;


    if ((k > 0) && (l > 0)) 
    {
        c1[0] = a1[0];
        for (size_t i = 16; i >= 2; i--)
        {
            sum = a1[i] + b1[i] + pr;
            c1[i] = sum % 2;
            pr = sum / 2;
        }
        cout << "A=";
        for (size_t i = 0; i < 17; i++)
        {
            cout << a2[i] << " ";
        }
        cout << endl;
        cout << "B=";
        for (size_t i = 0; i < 17; i++)
        {
            cout << b2[i] << " ";
        }
        cout << endl;
        cout << "C=";
        for (size_t i = 0; i < 17; i++)
        {
            cout << c1[i] << " ";
        }
    }
    else
        if ((k > 0) && (l < 0)&&(k<abs(l)))
        {
            c1[0] = b2[0];
            for (size_t i = 16; i >= 1; i--)
            {
                sum = a1[i] + b1[i] + pr;

                c1[i] = sum % 2;

                pr = sum / 2;
            }
            cout << "A=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << a2[i] << " ";
            }
            cout << endl;
            cout << "B=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << b1[i] << " ";
            }
            cout << endl;
            cout << "C=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << c1[i] << " ";
            }
        }
        else if ((k > 0) && (l < 0) && (k > abs(l)))
        {
            c1[0] = b2[0];
            for (size_t i = 16; i >= 1; i--)
            {
                sum = a1[i] + b1[i] + pr;

                c1[i] = sum % 2;

                pr = sum / 2;
            }
            cout << "A=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << a2[i] << " ";
            }
            cout << endl;
            cout << "B=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << b1[i] << " ";
            }
            cout << endl;
            cout << "C=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << c1[i] << " ";
            }
            cout << endl;
            cout << endl;
            cout << endl;
            pr = 0;
            for (size_t i = 16; i >= 1; i--)
            {
                sum = c1[i] + d[i] + pr;

                d1[i] = sum % 2;

                pr = sum / 2;
            }            
            cout << "C=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << c1[i] << " ";
            }
            cout << endl;
            cout << "P=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << d[i] << " ";
            }
            cout << endl;
            cout << "O=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << d1[i] << " ";
            }

        }
        else {
            c1[0] = b2[0];
            for (size_t i = 16; i >= 1; i--)
            {
                sum = a1[i] + b1[i] + pr;

                c1[i] = sum % 2;

                pr = sum / 2;
            }
            cout << "A=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << a1[i] << " ";
            }
            cout << endl;
            cout << "B=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << b1[i] << " ";
            }
            cout << endl;
            cout << "C=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << c1[i] << " ";
            }
            cout << endl;
            cout << endl;
           
            pr = 0;
            d1[0] = 1;
            for (size_t i = 16; i >= 1; i--)
            {
                sum = c1[i] + d[i] + pr;

                d1[i] = sum % 2;

                pr = sum / 2;
            }
            cout << "C=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << c1[i] << " ";
            }
            cout << endl;
            cout << "P=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << d[i] << " ";
            }
            cout << endl;
            cout << "O=";
            for (size_t i = 0; i < 17; i++)
            {
                cout << d1[i] << " ";
            }


        }




  


}


//Сложение 2-ных чисел в дополнительном коде
void dop_kod(int a, int b)
{
    

}

int main()
{
    setlocale(LC_ALL, "Russian");
    int nm = 0;
    int a, b ;
    cout << "Введите первое число:";
    cin >> a;
    cout << "Введите второе число:";
    cin >> b;

    cout << "Номера операций" << endl;
    cout << "0 прямой код" << endl;
    cout << "1 обратный код" << endl;
    cout << "2 Дополнительный код" << endl;


    cout << "Введите цифру:";
    cin >> nm;
 

    


    switch (nm)
    {
        case 0: pryamoy_kod(a,b);
            break;
        case 1: obr_kod(a,b);
            break;
        case 2: dop_kod(a,b);
            break;
        default: cout << "Ошибка!!! Такое операцие не поддерживается!";
        break;
      
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

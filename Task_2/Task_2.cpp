#include <iostream>
#include <iomanip>

int prov()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;
        std::cout << "\nНеверный ввод, попробуйте еще раз: ";
    }
    return a;
}

void hat()
{
    printf("\x1b[1;32m");
    std::cout << "   Задание №2, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';
    printf("\x1b[0m");
    printf("\x1b[32m");
    std::cout << "   Суть задания: Инициализировать при объявлении статический двумерный массив\n"
                 "целых чисел размером MxN\n"
                 "и найти произведение элементов, расположенных в нечётных\n"
                 "(по номеру) столбцах матрицы.\n"
              << '\n';
    printf("\x1b[0m");
}

int main()
{
    hat();
    while (true)
    {
        int m, n;
        std::cout << "Введите количество строк массива(M): ";
        m = prov();
        m = abs(m);
        std::cout << '\n';
        std::cout << "Введите количество столбцов массива(N): ";
        n = prov();
        n = abs(n);
        std::cout << '\n';
        int array[m][n];
        std::cout << "Введите элементы двумерного массива (после каждого элемента нажимать enter): \n\n";
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                array[i][j] = prov ();
            }
        }
        long double proizv = 1;
        for (int i = 1; i < n; i += 2)
        {
            for (int k = 0; k < m; k++)
            {
                proizv *= array[k][i];
            }
        }
        std::cout << "\nИсходные данные: \n\n";
        printf("\x1b[1m");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << array[i][j] << " ";
            }
            std::cout << std::endl;
        }
        printf("\x1b[0m");
        std::cout << '\n';
        std::cout << "Произведение элементов, расположенных в нечётных (по номеру) столбцах: ";
        printf("\x1b[1m");
        std::cout << std::setprecision(50) << proizv;
        printf("\x1b[0m");
        std::cout << '\n';
        std::cout << '\n'
                  << "▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭" << '\n'
                  << std::endl;

        std::cout << "Введите, чтобы: \n"
                  << "Вновь выполнить задание: 1\n"
                  << "Выйти из программы: 2" << '\n'
                  << std::endl;

        while (true)
        {
            int a;

            a = prov();
            std::cout << '\n';

            if (a == 1)
            {
                std::cout << "▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭" << '\n'
                          << std::endl;
                break;
            }
            if (a == 2)
                exit(0);
            else
                std::cout << "Необходимо ввести число 1 или 2, другие числа или буквы не допускаются!: ";
        }
    }
    return 0;
}
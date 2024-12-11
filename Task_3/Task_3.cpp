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

int provl()
{
    double a;
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
    printf("\x1b[1;33m");
    std::cout << "   Задание №3, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';
    printf("\x1b[0m");
    printf("\x1b[33m");
    std::cout << "   Суть задания: Дана действительная квадратная матрица порядка N. Найти сумму и\n"
                 "произведение элементов, расположенных в заштрихованной части матрицы\n"
              << '\n';
    printf("\x1b[0m");
}

int main()
{
    hat();
    while (true)
    {
        int n;
        std::cout << "Введите порядок квадратной матрицы: ";
        n = prov();
        n = abs(n);
        int **numbers = new int *[n];
        for (int i = 0; i < n; i++)
        {
            numbers[i] = new int[n];
        }
        std::cout << "\nВведите элементы матрицы (после каждого элемента нажимать enter): \n\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                numbers[i][j] = provl();
            }
        }
        std::cout << "\nИсходные данные: \n\n";
        printf("\x1b[1m");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << numbers[i][j] << " ";
            }
            std::cout << std::endl;
        }
        printf("\x1b[0m");
        long double sum = 0;
        long double pro = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i > j && i < (n - 1) && j < (n - 3) || i < j && i < (n - 1) && j > (n - 3) && i != 0) && ((i + j) != (n - 1)))
                {
                    sum += numbers[i][j];
                    pro *= numbers[i][j];
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            delete[] numbers[i];
            numbers[i] = nullptr;
        }
        delete[] numbers;
        numbers = nullptr;
        std::cout << "\nСумма элементов: ";
        printf("\x1b[1m");
        std::cout << sum;
        printf("\x1b[0m");
        std::cout << '\n' << '\n';
        std::cout << "Произведение элементов: ";
        printf("\x1b[1m");
        std::cout << std::setprecision(50) << pro;
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
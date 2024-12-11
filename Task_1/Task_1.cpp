#include <iostream>

int prov()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;
        std::cout << "\nНеверный ввод, опробуйте еще раз: ";
    }
    return a;
}

void hat()
{
    printf("\x1b[1;31m");
    std::cout << "   Задание №1, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';
    printf("\x1b[0m");
    printf("\x1b[31m");
    std::cout << "   Суть задания: Ввести одномерный статический массив из k чисел\n"
                 "и удалить элементы, значение которых меньше среднего значения\n"
                 "всех элементов массива.\n"
              << '\n';
    printf("\x1b[0m");
}

int main()
{
    hat();
    while (true)
    {
        std::cout << "Введите k: ";
        int k;
        k = prov();
        k = abs(k);
        int array[k];
        std::cout << '\n';
        std::cout << "Введите элементы одномерного массива (после каждого элемента нажимать enter): " << '\n'
                  << std::endl;
        for (int i = 0; i < k; i++)
        {
            array[i] = prov();
        }
        std::cout << '\n';
        int a = 0;
        for (auto i : array)
        {
            a += i;
        }
        int srednyi = a / k;
        std::cout << "Полученный массив: " << '\n'
                  << std::endl;
        printf("\x1b[1m");
        for (auto i : array)
        {
            if (i >= srednyi)
                std::cout << i << " ";
        }
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
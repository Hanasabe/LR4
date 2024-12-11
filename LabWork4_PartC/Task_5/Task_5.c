#include <stdio.h>
#include <stdlib.h>

// Функция проверки ввода чисел
int prov() {
    int a;
    while (scanf("%d", &a) != 1) {
        printf("\nНельзя вводить буквы или некорректные числа, попробуйте еще раз: ");
        while (getchar() != '\n'); // Очистка ввода
    }
    return a;
}

// Вывод шапки
void hat() {
    printf("\033[1;35m"); // Цвет текста
    printf("   Задание №5, выполнила Щербицкая Ника, 453501\n");
    printf("   Суть задания: На вход подаётся поле для игры в сапёр размером n*m символов,\n");
    printf("   где '.' означает пустое место, а '*' - бомбу. Требуется дополнить это\n");
    printf("   поле числами, как в оригинальной игре.\n\n");
    printf("\033[0m"); // Сброс цвета
}

int main() {
    hat();
    while (1) {
        printf("Введите количество строк массива: ");
        int n = prov();
        printf("Введите количество столбцов массива: ");
        int m = prov();

        // Создание массива с рамкой
        char** array = (char**)malloc((n + 2) * sizeof(char*));
        for (int i = 0; i < n + 2; i++) {
            array[i] = (char*)malloc((m + 2) * sizeof(char));
            for (int j = 0; j < m + 2; j++) {
                array[i][j] = '.'; // Заполнение рамки
            }
        }

        printf("Введите элементы поля (* или .):\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                while (1) {
                    char elem;
                    scanf(" %c", &elem); // Пропуск пробелов
                    if (elem == '*' || elem == '.') {
                        array[i][j] = elem;
                        break;
                    } else {
                        printf("Введите * или .: ");
                    }
                }
            }
        }

        // Создание массива для чисел
        int** bomb = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            bomb[i] = (int*)malloc(m * sizeof(int));
            for (int j = 0; j < m; j++) {
                bomb[i][j] = 0; // Инициализация нулями
            }
        }

        // Подсчёт бомб
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (array[i][j] == '*') continue;
                if (array[i - 1][j] == '*') bomb[i - 1][j - 1]++;
                if (array[i - 1][j + 1] == '*') bomb[i - 1][j - 1]++;
                if (array[i][j + 1] == '*') bomb[i - 1][j - 1]++;
                if (array[i + 1][j + 1] == '*') bomb[i - 1][j - 1]++;
                if (array[i + 1][j] == '*') bomb[i - 1][j - 1]++;
                if (array[i + 1][j - 1] == '*') bomb[i - 1][j - 1]++;
                if (array[i][j - 1] == '*') bomb[i - 1][j - 1]++;
                if (array[i - 1][j - 1] == '*') bomb[i - 1][j - 1]++;
            }
        }

        // Вывод конечного поля
        printf("\nКонечное поле:\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (array[i][j] == '*') {
                    printf("* ");
                } else {
                    printf("%d ", bomb[i - 1][j - 1]);
                }
            }
            printf("\n");
        }

        // Очистка памяти
        for (int i = 0; i < n + 2; i++) {
            free(array[i]);
        }
        free(array);

        for (int i = 0; i < n; i++) {
            free(bomb[i]);
        }
        free(bomb);

        // Повтор программы или выход
        printf("\nВведите 1, чтобы выполнить задание заново, или 2, чтобы выйти: ");
        int choice = prov();
        if (choice == 2) break;
    }
    return 0;
}
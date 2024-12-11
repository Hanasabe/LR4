#include <stdio.h>
#include <stdlib.h>

int prov() {
    int a;
    while (scanf("%d", &a) != 1) {
        printf("\nНельзя вводить буквы или некорректные числа, попробуйте еще раз: ");
        while (getchar() != '\n'); // Очистка ввода
    }
    return a;
}

void hat() {
    printf("\x1b[1;34m");
    printf("   Задание №4, выполнила Щербицкая Ника, 453501\n");
    printf("\x1b[0m");
    printf("\x1b[34m");
    printf("   Суть задания: Дан трёхмерный динамический массив размером n^3 целых\n");
    printf("неотрицательных чисел. Необходимо определить диагональ с наибольшей\n");
    printf("суммой чисел.\n\n");
    printf("\x1b[0m");
}

int main() {
    hat();

    while (1) {
        printf("Введите размер массива: ");
        long long sum[4] = {0, 0, 0, 0};
        int n;
        n = prov();

        int ***massiv = (int***)malloc(n * sizeof(int**));
        for (int i = 0; i < n; i++) {
            massiv[i] = (int**)malloc(n * sizeof(int*));
            for (int j = 0; j < n; j++) {
                massiv[i][j] = (int*)malloc(n * sizeof(int));
            }
        }

        printf("\nВведите элементы массива (после каждого элемента нажимать enter): ");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    while (1) {
                        massiv[i][j][k] = prov();
                        if (massiv[i][j][k] < 0) {
                          printf("Массив должен состоять из целых неотрицательных чисел \n\n");
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            sum[0] += massiv[i][i][i];
            sum[1] += massiv[n - 1 - i][i][i];
            sum[2] += massiv[i][n - 1 - i][i];
            sum[3] += massiv[i][i][n - 1 - i];
        }

        int max = sum[0];
        for (int i = 1; i < 4; i++) {
            if (sum[i] > max) {
                max = sum[i];
            }
        }

        printf("\nМаксимальная сумма чисел на диагонали: %d\n", max);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                free(massiv[i][j]);
            }
            free(massiv[i]);
        }
        free(massiv);

        printf("\n▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭");

        printf("\n\nВведите, чтобы: \n");
        printf("Вновь выполнить задание: 1\n");
        printf("Выйти из программы: 2\n\n");

        while (1) {
            int a;
            a = prov();

            if (a == 1) {
                printf("▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭\n\n");
                break;
            } else if (a == 2) {
                exit(0);
            } else {
                printf("Необходимо ввести число 1 или 2, другие числа или буквы не допускаются!: ");
            }
        }
    }

    return 0;
}
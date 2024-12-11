#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Функция проверки корректности ввода
int prov() {
    int a;
    while (scanf("%d", &a) != 1) {
        printf("\nНеверный ввод, попробуйте еще раз: ");
        while (getchar() != '\n'); // Очистка буфера ввода
    }
    return a;
}


void hat() {
    printf("\033[1;36m"); 
    printf("   Задание №6, выполнила Щербицкая Ника, 453501\n");
    printf("\033[0m"); 
    printf("\033[36m");
    printf("   Суть задания: Построить магический квадрат. Порядок квадрата задаётся\n");
    printf("пользователем. Максимальный размер магического квадрата не превышает 2^32 - 1\n\n");
    printf("\033[0m");
}

int main() {
    hat();
    while (1) {
        printf("Введите порядок магического квадрата: ");
        int n = abs(prov());

        int** square = (int**)malloc(n * sizeof(int*));
        for (int i = 0; i < n; i++) {
            square[i] = (int*)malloc(n * sizeof(int));
        }


        if (n == 2) {
            printf("\nМагического квадрата 2 * 2 не существует\n");
        } else if (n % 2 != 0) {
            // Нечётный порядок
            int k = n / 2;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    square[i][j] = 0;

            square[0][k] = 1;
            int p_previous = 0, q_previous = k;
            for (int num = 2; num <= n * n; num++) {
                int p = (p_previous == 0) ? (n - 1) : (p_previous - 1);
                int q = (q_previous == n - 1) ? 0 : (q_previous + 1);

                if (square[p][q] != 0) {
                    p = (p_previous == n - 1) ? 0 : (p_previous + 1);
                    q = q_previous;
                }

                square[p][q] = num;
                p_previous = p;
                q_previous = q;
            }
        } 
          else if (n % 4 == 0)
        {
            {
                // кратно 4
                int num = 1, num_2 = n * n;
                while (num <= n * n)
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if ((i < n / 4 && j < n / 4) || (j >= n - n / 4 && i < n / 4) || (i >= n - n / 4 && j < n / 4) || (i >= n - n / 4 && j >= n - n / 4) || (i >= n / 4 && i < n - n / 4 && j >= n / 4 && j < n - n / 4))
                            {
                                square[i][j] = num_2;
                                num_2--;
                                num++;
                            }
                            else
                            {
                                square[i][j] = num;
                                num++;
                                num_2--;
                            }
                        }
                    }
                }
            }
        } else {
            // Составление для четного порядка, не кратного 4
              // кратно 2
            // часть А

            square[0][n / 4] = 1;
            int p_previous_a = 0, q_previous_a = n / 4;
            int p_a = 0, q_a = 0;
            for (int num = 2; num <= n * n / 4; num++)
            {
                p_a = p_previous_a;
                q_a = q_previous_a;
                if (p_a == 0)
                    p_a = n / 2 - 1;
                if (q_a == n / 2 - 1)
                    q_a = 0;
                if (p_a == p_previous_a)
                    p_a--;
                if (q_a == q_previous_a)
                    q_a++;
                if (square[p_a][q_a] != 0)
                {
                    if (p_previous_a == n / 2 - 1)
                        p_previous_a = 0;
                    else
                    {
                        p_previous_a++;
                    }
                    square[p_previous_a][q_previous_a] = num;
                }
                else
                {
                    square[p_a][q_a] = num;
                    p_previous_a = p_a;
                    q_previous_a = q_a;
                }
            }

            // часть Б
            square[n / 2][n / 4 + n / 2] = 1 + n * n / 4;
            int p_previous_b = n / 2, q_previous_b = n / 4 + n / 2;
            int p_b = 0, q_b = 0;
            for (int num = 2 + n * n / 4; num <= (n * n / 4) * 2; num++)
            {
                p_b = p_previous_b;
                q_b = q_previous_b;
                if (p_b == n / 2)
                    p_b = n - 1;
                if (q_b == n - 1)
                    q_b = n / 2;
                if (p_b == p_previous_b)
                    p_b--;
                if (q_b == q_previous_b)
                    q_b++;
                if (square[p_b][q_b] != 0)
                {
                    if (p_previous_b == n - 1)
                        p_previous_b = n / 2;
                    else
                    {
                        p_previous_b++;
                    }
                    square[p_previous_b][q_previous_b] = num;
                }
                else
                {
                    square[p_b][q_b] = num;
                    p_previous_b = p_b;
                    q_previous_b = q_b;
                }
            }

            // часть С
            square[0][n / 4 + n / 2] = 1 + (n * n / 4) * 2;
            int p_previous_c = 0, q_previous_c = n / 4 + n / 2;
            int p_c = 0, q_c = 0;
            for (int num = 2 + 2 * n * n / 4; num <= (n * n / 4) * 3; num++)
            {
                p_c = p_previous_c;
                q_c = q_previous_c;
                if (p_c == 0)
                    p_c = n / 2 - 1;
                if (q_c == n - 1)
                    q_c = n / 2;
                if (p_c == p_previous_c)
                    p_c--;
                if (q_c == q_previous_c)
                    q_c++;
                if (square[p_c][q_c] != 0)
                {
                    if (p_previous_c == n / 2 - 1)
                        p_previous_c = 0;
                    else
                    {
                        p_previous_c++;
                    }
                    square[p_previous_c][q_previous_c] = num;
                }
                else
                {
                    square[p_c][q_c] = num;
                    p_previous_c = p_c;
                    q_previous_c = q_c;
                }
            }

            // часть Д
            square[n / 2][n / 4] = 1 + (n * n / 4) * 3;
            int p_previous_d = n / 2, q_previous_d = n / 4;
            int p_d = 0, q_d = 0;
            for (int num = 2 + 3 * n * n / 4; num <= (n * n / 4) * 4; num++)
            {
                p_d = p_previous_d;
                q_d = q_previous_d;
                if (p_d == n / 2)
                    p_d = n - 1;
                if (q_d == n / 2 - 1)
                    q_d = 0;
                if (p_d == p_previous_d)
                    p_d--;
                if (q_d == q_previous_d)
                    q_d++;
                if (square[p_d][q_d] != 0)
                {
                    if (p_previous_d == n - 1)
                        p_previous_d = n / 2;
                    else
                    {
                        p_previous_d++;
                    }
                    square[p_previous_d][q_previous_d] = num;
                }
                else
                {
                    square[p_d][q_d] = num;
                    p_previous_d = p_d;
                    q_previous_d = q_d;
                }
            }

            // меняем штуки с выступом
            unsigned long long changer;
            for (unsigned long long i = 0; i < n / 2; ++i)
            {
                for (unsigned long long j = 0; j < (n / 2) / 2; ++j)
                {
                    if (i != (n / 2) / 2)
                    {
                        changer = square[i][j];
                        square[i][j] = square[i + n / 2][j];
                        square[i + n / 2][j] = changer;
                    }
                    else
                    {
                        changer = square[i][j + 1];
                        square[i][j + 1] = square[i + n / 2][j + 1];
                        square[i + n / 2][j + 1] = changer;
                    }
                }
            } // поменяла местами штуки с выступом
            for (unsigned long long i = 0; i < n / 2; ++i)
            {
                for (unsigned long long j = n - (n / 2) / 2 + 1; j < n; ++j)
                {
                    changer = square[i][j];
                    square[i][j] = square[i + n / 2][j];
                    square[i + n / 2][j] = changer;
                }
            }
        }

        if (n != 2) {
            printf("\nМагический квадрат: \n\n\033[1m");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%4d ", square[i][j]);
                }
                printf("\n");
            }
            printf("\033[0m");
        }

        // Освобождение памяти
        for (int i = 0; i < n; i++) {
            free(square[i]);
        }
        free(square);

        printf("\n▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭\n\n");
        printf("Введите, чтобы: \n");
        printf("1 - Вновь выполнить задание\n");
        printf("2 - Выйти из программы\n");

        int a;
        while (1) {
            a = prov();
            if (a == 1 || a == 2) break;
            printf("Необходимо ввести число 1 или 2, другие значения недопустимы!: ");
        }
        if (a == 2) break;
    }

    return 0;
}
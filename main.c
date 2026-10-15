#include <stdio.h>
#include <math.h>

int main() {
    int N = 60;
    double X[60];
    double Q[60];
    double LCL = 31.00;

    for (int i = 0; i < N; i++) {
        X[i] = 10.0 + (double)i * (90.0 / 59.0);
    }
    X[0] = 56.60;

    for (int i = 0; i < N; i++) {
        if (X[i] < 35.0) {
            Q[i] = 4.0 * log(X[i] - 35.0 + 2.0) + 15.0;
        } else if (X[i] >= 35.0 && X[i] <= 65.0) {
            Q[i] = pow(X[i] - 50.0, 2.0) / 8.0 + 45.0;
        } else {
            Q[i] = 2.0 * (X[i] - 65.0) + 60.0;
        }

        printf("X = %.2f, Q = %.2f", X[i], Q[i]);
        if (X[i] < 35.0 || X[i] > 65.0) {
            printf(" [отклонение технологического процесса]");
        } else {
            printf(" [штатный режим]");
        }
        if (Q[i] < LCL) {
            printf(" [Сигнал тревоги: Q < LCL]");
        }
        printf("\n");
    }

    double sum1 = 0;
    double sum2 = 0;

    for (int i = 20; i <= 25; i++) {
        sum1 += Q[i];
    }
    double mean1 = sum1 / 6.0;

    for (int i = 26; i <= 30; i++) {
        sum2 += Q[i];
    }
    double mean2 = sum2 / 5.0;

    double diff = mean1 - mean2;

    printf("\nСтатистический анализ для Q[21..31]:\n");
    printf("Среднее значение первой половины: %.2f\n", mean1);
    printf("Среднее значение второй половины: %.2f\n", mean2);
    printf("Разность: %.2f\n", diff);

    return 0;
}
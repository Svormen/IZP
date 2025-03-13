/*
 * Slavomir Svorada
 * xsvora02
 * 28.11.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define I_0 1 * pow(10, -12)
#define U_T 0.0258563
#define M_E 2.71828182845904523536
#define ERROR -1

double absolute_value(double x);
double diode(double u0, double r, double eps);

int main(int argc, char *argv[])
{
    char *check1 = NULL;
    char *check2 = NULL;
    char *check3 = NULL;

    if (argc != 4)  // Not allowed number of arguments
    {
        fprintf(stderr, "error: invalid arguments\n");
        return ERROR;
    }

    double U0 = strtod(argv[1], &check1);
    double R = strtod(argv[2], &check2);
    double EPS = strtod(argv[3], &check3);
    double Up = diode(U0, R, EPS);
    double Ip = I_0 * (pow(M_E, Up / U_T) - 1);

    if ((U0 < 0) || (R <= 0) || (EPS < 0))  // Values can not be less than '0'
    {
        fprintf(stderr, "error: invalid arguments\n");
        return ERROR;
    }

    if (argc == 4)  // Use just 4 arguments
    {
        if ((check1[0] == '\0') && (check2[0] == '\0') && (check3[0] == '\0'))  // Control if it's empty string
        {
            diode(U0, R, EPS);
            printf("Up=%g V\n", Up);
            printf("Ip=%g A\n", Ip);
        } else
            fprintf(stderr, "error: invalid arguments\n");
    }
    return 0;
}

double absolute_value(double x)
{
    return x > 0 ? x : -x;
}

double diode(double u0, double r, double eps)
{
    double min, max;
    min = 0;
    max = u0;

    double middle = (min + max) / 2;    // Find the middle between 2 numbers

    while (absolute_value(max - min) > eps)
    {
        double first = I_0 * (pow(M_E, middle / U_T) - 1) - ((u0 - middle) / r);
        if ((I_0 * (pow(M_E, middle / U_T) - 1) - ((u0 - middle) / r) > 0))
            max = middle;
        else
            min = middle;
        if (absolute_value(max - min) > eps)
        {
            middle = (min + max) / 2;
        }
        double second = I_0 * (pow(M_E, middle / U_T) - 1) - ((u0 - middle) / r);

        if (first == second)
            break;
    }

    return middle;
}
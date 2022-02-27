#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 80
#define R 5

struct circle {
  float x, y, r;
} c;

double chisla(char *str, int *i);  //функция проверки числа

int main() {
  int i;
  char m1[N] = "circle";
  char m3[N];

  FILE *file;
  file = fopen("figures.txt", "r");

  // Проверка открытия файла
  printf("Открытие файла:");
  if (file == NULL)
    printf("ошибка\n");
  else
    printf("выполнено\n");

  while (fgets(m3, N, file) != NULL) {
    if (strncmp(m1, m3, R) == 0) {
      i = 7;
      c.x = chisla(m3, &i);
      c.y = chisla(m3, &i);
      c.r = chisla(m3, &i);
      printf("Circle: (%0.0f %0.0f) R = %0.2f\n", c.x, c.y, c.r);
    } else {
      printf("Error\n");
    }
  }
}

// FUNCTION

double chisla(char *str, int *i)  //функция проверки числа
{
  double result = 0;
  double div = 10;
  int sign = 1;

  while (result == 0) {
    if (str[*i] == '-')  //проверка на отрицательное число
    {
      sign = -1;
      ++*i;
    }

    while (str[*i] >= '0' && str[*i] <= '9') {
      result = result * 10.0 + (str[*i] - '0');

      ++*i;
    }

    if (str[*i] == '.')  //проверка на десятичную дробь
    {
      ++*i;

      while (str[*i] >= '0' && str[*i] <= '9') {
        result = result + (str[*i] - '0') / div;
        div *= 10;

        ++*i;
      }
    }
    ++*i;
  }

  return sign * result;
}
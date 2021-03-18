# Отчет по лабораторной работе 1


## Задача 5

### Краткая формулировка задачи

С клавиатуры вводятся два целых положительных числа: *num* (numerator),
*denom* (denominator). Требуется вывести два числа: *quo* (quotient), *rest* - 
частное и остаток при делении *num* на *denom*.

### Функциональные тесты
##### Входные данные

- int num
- int denom

##### Выходные данные

- int quo (частное)
- int num (остаток rest)

###### Positive tests

- 01 - обычные данные
    - покрытие gcov - 87.5%
- 02 - два одинаковых числа
  - покрытие gcov - 87.5%
- 03 - деление без остатка
  - покрытие gcov - 87.5%

###### Negative tests

- 01 - введена буква
  - покрытие gcov - 93.75%
- 02 - первое число отрицательное
  - покрытие gcov - 100%
- 03 - второе число 0
  - покрытие gcov - 100%

После выполнения тестов файл main.c.gcov имеет вид:

        -:    0:Source:main.c
        -:    0:Graph:main.gcno
        -:    0:Data:main.gcda
        -:    0:Runs:6
        -:    0:Programs:1
        -:    1://
        -:    2://  main.c
        -:    3://  lab01task0501
        -:    4://
        -:    5://  Created by Yaroslav Bairamgalin on 27.02.2021.
        -:    6://
        -:    7:
        -:    8:#include <stdio.h>
        -:    9:
        -:   10:#define OK 0
        -:   11:#define INCORRECT_TYPE 10
        -:   12:#define INCORRECT_VALUE 5
        -:   13:
        -:   14:#define EXPECTED_ARGS 2
        -:   15:
        -:   16:
        -:   17:// function puts in quo and num the whole part and the rest of
        -:   18:// division of num by denom
        3:   19:void integer_division(int *quo, int *num, int denom)
        -:   20:{
        -:   21:    // num finally equals rest
       10:   22:    while (*num >= denom)
        -:   23:    {
        7:   24:        (*quo)++;
        7:   25:        *num -= denom;
        -:   26:    }
        3:   27:}
        -:   28:
        6:   29:int main(void)
        -:   30:{
        -:   31:    int num, denom;
        6:   32:    int corr_input = scanf("%d%d", &num, &denom);
        6:   33:    if (corr_input != EXPECTED_ARGS)
        1:   34:        return INCORRECT_TYPE;
        -:   35:
        5:   36:    if (num <= 0 || denom <= 0)
        2:   37:        return INCORRECT_VALUE;
        -:   38:    
        3:   39:    int quo = 0;
        3:   40:    integer_division(&quo, &num, denom);
        -:   41:
        3:   42:    printf("%d %d", quo, num);
        -:   43:    
        3:   44:    return OK;
        6:   45:}

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

## Задача 6
### Краткая формулировка задачи
Вводятся координаты треугольника *x<sub>a</sub>, y<sub>a</sub>*,
*x<sub>b</sub>, y<sub>b</sub>*, *x<sub>c</sub>, y<sub>c</sub>* на плоскости.
Требуется вычислить площадь такого треугольника.
### Функциональные тесты
##### Входные данные

- float x_a
- float y_a
- float x_b
- float y_b
- float x_c
- float y_c

##### Выходные данные

- float square

###### Positive tests

- 01 - обычные данные, определитель положительный, все числа положительные
  - покрытие gcov - 84.62%
- 02 - обычные данные, определитель отрицательный, одна из точек в 3 четверти
  - покрытие gcov - 84.62%
- 03 - вещественные числа, а не целые
  - покрытие gcov - 84.62%

###### Negative tests

- 01 - введена буква
  - покрытие gcov - 92.31%
- 02 - последней введена буква
  - покрытие gcov - 92.31%
- 03 - вырожденный случай (точки на одной линии)
  - покрытие gcov - 100%
- 04 - две точки совпадают
  - покрытие gcov - 100%
- 05 - три точки совпадают
  - покрытие gcov - 100%

После выполнения тестов файл main.c.gcov имеет вид:

        -:    0:Source:main.c
        -:    0:Graph:main.gcno
        -:    0:Data:main.gcda
        -:    0:Runs:8
        -:    0:Programs:1
        -:    1://
        -:    2://  main.c
        -:    3://  lab01task05
        -:    4://
        -:    5://  Created by Yaroslav Bairamgalin on 27.02.2021.
        -:    6://
        -:    7:
        -:    8:#include <stdio.h>
        -:    9:#include <math.h>
        -:   10:
        -:   11:#define OK 0
        -:   12:#define INCORRECT_INPUT 10
        -:   13:#define IN_THE_SAME_LINE 11
        -:   14:
        -:   15:#define EXPECTED_ARGS 6
        -:   16:
        -:   17:#define EPS 1e-10
        -:   18:
        -:   19:
        -:   20:// function receives elements of 2x2 matrix and returns its determinant
        6:   21:float det_2x2(float m11, float m12, float m21, float m22)
        -:   22:{
        6:   23:    return m11 * m22 - m21 * m12;
        -:   24:}
        -:   25:
        8:   26:int main(void)
        -:   27:{
        -:   28:    float x_a, y_a, x_b, y_b, x_c, y_c;
        -:   29:    float det, square;
        -:   30:    
        8:   31:    int corr_input = scanf("%f%f%f%f%f%f", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
        8:   32:    if (corr_input != EXPECTED_ARGS)
        2:   33:        return INCORRECT_INPUT;
        -:   34:    
        -:   35:    // solve for signed square using det formula
        6:   36:    det = det_2x2(x_a - x_c, y_a - y_c, x_b - x_c, y_b - y_c);
        6:   37:    square = fabsf(det / 2);
        -:   38:    
        -:   39:    // check if the points are in the same line
        6:   40:    if (square < EPS)
        3:   41:        return IN_THE_SAME_LINE;
        -:   42:    
        3:   43:    printf("%f", square);
        3:   44:    return OK;
        8:   45:}


Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

## Задача 1
### Краткая формулировка задачи
Найти и исправить ошибки в программе.
```C
include studio.h
main{}
(
int s;
s: = 56;
print (Year has s weeks)
)
```

### Установка ПО

Для выполнения лабораторной работы было установлено все необходимое программное обеспечение.
Трудностей при установке не возникло.

### Сборка

```bash
gcc -std=c99 -Wall -Werror main.c -o main.exe
```

### Ошибки

1.  
    ```bash
    main.c:1:1: error: unknown type name 'include'
    1 | include studio.h
    ```
    - Причина: отсутствует символ '#' перед ключевым словом include
    - Решение: добавить #
2.
     ```bash
    main.c:1:10: error: #include expects "FILENAME" or <FILENAME>
    1 | #include studio.h
     ```
    - Причина: неверный синтаксис подключения заголовочного файла
    - Решение: добвить <>
3. 
    ```bash
   main.c:1:10: fatal error: studio.h: No such file or directory
   1 | #include <studio.h>
    ```
    - Причина: ошибка в имени заголовочного файла
    - Решение: изменить на stdio.h
4. 
    ```bash
   main.c:3:5: error: expected '=', ',', ';', 'asm' or '__attribute__' before '{' token
   3 | main{}
    ```
    - Причина: компилятор не смог распознать функцию
    - Решение: добавить перед именем функции тип возвращаемого ей значения, а также скобки для аргументов
5. 
    ```bash
   main.c:5:1: error: expected identifier or '(' before 'int'
   5 | int s;
    ```
    - Причина: отсутствует тело функции `main`
    - Решение: добавить скобки `{...}`
6. 
    ```bash
   main.c:5:8: error: expected expression before '=' token
   5 |     s: = 56;
    ```
    - Причина: неправильное присваивание
    - Решение: исправить присваивание на `s = 56;`
7. 
    ```bash
   main.c:6:5: error: implicit declaration of function 'print'; did you mean 'printf'? [-Werror=implicit-function-declaration]
   6 |     print (Year has s weeks)
    ```
    - Причина: ошибка в имени функции
    - Решение: заменить на `printf()`
8. 
    ```bash
   main.c:6:12: error: 'Year' undeclared (first use in this function)
   6 |     printf(Year has s weeks)
    ```
    - Причина: неправильный вывод строки
    - Решение: добавить двойные кавычки
9. 
    ```bash
   main.c:6:31: error: expected ';' before '}' token
   6 |     printf("Year has s weeks")
    ```
    - Причина: отсутствует точка с запятой
    - Решение: добавить точку с запятой
10. 123
    ```bash
    main.c:4:9: error: variable 's' set but not used [-Werror=unused-but-set-variable]
    4 |     int s;
    ```
    - Причина: не используется переменная
    - Решение: добавить переменную в вывод

### Итоговый код
```C
#include <stdio.h>

int main(void) {
    int s;
    s = 56;
    printf("Year has %d weeks", s);
}
```

### QT Creator

Выполнение задачи 1 помогло мне научиться создавать проект, настраивать сборку, анализировать сообщения
об ошибках компиляции, использовать отладчик в IDE QT Creator.

## Задача 5

### Краткая формулировка задачи

С клавиатуры вводятся два целых положительных числа: *num* (numerator),
*denom* (denominator). Требуется вывести два числа: *quo* (quotient), *rest* -
частное и остаток при делении *num* на *denom*.

### Сборка

```bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -O0 -fprofile-arcs -ftest-coverage main.c -o main.exe
```

### Код программы
```C
//
//  main.c
//  lab01task0501
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 10
#define INCORRECT_VALUE 5

#define EXPECTED_ARGS 2


// function puts in quo and num the whole part and the rest of
// division of num by denom
void integer_division(int *quo, int *num, const int denom)
{
    // num finally equals rest
    while (*num >= denom)
    {
        (*quo)++;
        *num -= denom;
    }
}

int main(void)
{
    int num, denom;
    int corr_input = scanf("%d%d", &num, &denom);

    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (num <= 0 || denom <= 0)
        return INCORRECT_VALUE;
    
    int quo = 0;
    integer_division(&quo, &num, denom);

    printf("%d %d", quo, num);
    
    return OK;
}

```

### Тестирование

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:87.50% of 16
main.c:creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:87.50% of 16
main.c:creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:93.75% of 16
main.c:creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:100.00% of 16
main.c:creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:100.00% of 16
main.c:creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:
```C
        -:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:5
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
2:   19:void integer_division(int *quo, int *num, const int denom)
-:   20:{
-:   21:    // num finally equals rest
6:   22:    while (*num >= denom)
-:   23:    {
4:   24:        (*quo)++;
4:   25:        *num -= denom;
-:   26:    }
2:   27:}
-:   28:
5:   29:int main(void)
-:   30:{
-:   31:    int num, denom;
5:   32:    int corr_input = scanf("%d%d", &num, &denom);
-:   33:
5:   34:    if (corr_input != EXPECTED_ARGS)
1:   35:        return INCORRECT_TYPE;
-:   36:
4:   37:    if (num <= 0 || denom <= 0)
2:   38:        return INCORRECT_VALUE;
-:   39:
2:   40:    int quo = 0;
2:   41:    integer_division(&quo, &num, denom);
-:   42:
2:   43:    printf("%d %d", quo, num);
-:   44:
2:   45:    return OK;
5:   46:}
```
Производилось 3 позитивных и 3 негативных функциональный теста, расположенных
в папке `func_tests`. Покрытие `gcov` - 100%.

## Задача 6
### Краткая формулировка задачи
Вводятся координаты вершин *x<sub>a</sub>, y<sub>a</sub>*,
*x<sub>b</sub>, y<sub>b</sub>*, *x<sub>c</sub>, y<sub>c</sub>* на плоскости.
Требуется вычислить площадь такого треугольника.

### Сборка

```bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -O0 -fprofile-arcs -ftest-coverage main.c -o main.exe
```

### Код программы

```C
//
//  main.c
//  lab01task05
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>
#include <math.h>

#define OK 0
#define INCORRECT_INPUT 10
#define IN_THE_SAME_LINE 11

#define EXPECTED_ARGS 6

#define EPS 1e-10


// function receives elements of 2x2 matrix and returns its determinant
float det_2x2(const float m11, const float m12, const float m21, const float m22)
{
    return m11 * m22 - m21 * m12;
}

int main(void)
{
    float x_a, y_a;
    float x_b, y_b;
    float x_c, y_c;

    float det, square;
    
    int corr_input = scanf("%f%f%f%f%f%f", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);

    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_INPUT;
    
    // solve for signed square using det formula
    det = det_2x2(x_a - x_c, y_a - y_c, x_b - x_c, y_b - y_c);
    square = fabsf(det / 2);
    
    // check if the points are in the same line
    if (square < EPS)
        return IN_THE_SAME_LINE;
    
    printf("%f", square);
    return OK;
}

```

### Тестирование

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:84.62% of 13
main.c:creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:84.62% of 13
main.c:creating 'main.c.gcov'

Positive test 3
File 'main.c'
Lines executed:84.62% of 13
main.c:creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:92.31% of 13
main.c:creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:92.31% of 13
main.c:creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:100.00% of 13
main.c:creating 'main.c.gcov'

Negative test 4
File 'main.c'
Lines executed:100.00% of 13
main.c:creating 'main.c.gcov'

Negative test 5
File 'main.c'
Lines executed:100.00% of 13
main.c:creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:
```C
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
6:   21:float det_2x2(const float m11, const float m12, const float m21, const float m22)
-:   22:{
6:   23:    return m11 * m22 - m21 * m12;
-:   24:}
-:   25:
8:   26:int main(void)
-:   27:{
-:   28:    float x_a, y_a;
-:   29:    float x_b, y_b;
-:   30:    float x_c, y_c;
-:   31:
-:   32:    float det, square;
-:   33:
8:   34:    int corr_input = scanf("%f%f%f%f%f%f", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);
-:   35:
8:   36:    if (corr_input != EXPECTED_ARGS)
2:   37:        return INCORRECT_INPUT;
-:   38:
-:   39:    // solve for signed square using det formula
6:   40:    det = det_2x2(x_a - x_c, y_a - y_c, x_b - x_c, y_b - y_c);
6:   41:    square = fabsf(det / 2);
-:   42:
-:   43:    // check if the points are in the same line
6:   44:    if (square < EPS)
3:   45:        return IN_THE_SAME_LINE;
-:   46:
3:   47:    printf("%f", square);
3:   48:    return OK;
8:   49:}

```
Производилось 3 позитивных и 5 негативных функциональный теста, расположенных
в папке `func_tests`. Покрытие `gcov` - 100%.

## Задача 7
### Краткая формулировка задачи

С клавиатуры вводятся x, eps (0 < eps <= 1). Необходимо вычислить с точночтью eps
приближенное значение s(x), точное значение f(x), абсолютную и относительную погрешности.
f(x) = sin(x)
s(x) - ряд Тейлора для синуса

### Сборка

```bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -O0 -fprofile-arcs -ftest-coverage main.c -o main.exe
```

### Код программы

```C
//
//  main.c
//  lab01task07
//
//  Created by Yaroslav Bairamgalin on 27.02.2021.
//

#include <stdio.h>
#include <math.h>

#define OK 0
#define INCORRECT_TYPE 10
#define EPS_IS_TOO_LOW 9
#define INCORRECT_VALUE 5
#define DIVISION_BY_ZERO 3

#define EXPECTED_ARGS 2

#define EPS 1e-10
#define MAX_CYCLES 1000

// function receives two parameters: double expected -
// the precise value, double measured - measured or
// approximated value
// function returns abs error of the given data
double abs_error(double const expected, double const measured)
{
    return fabs(expected - measured);
}

int main(void)
{
    double x;
    double eps;
    int corr_input = scanf("%lf%lf", &x, &eps);

    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    // due to the task
    if (eps <= 0 || eps > 1)
        return INCORRECT_VALUE;
    
    double precise_value = sin(x);
    double approx_value = x;
    double current = approx_value;
    int count = 1; // for managing the power of x
    
    while (fabs(precise_value - approx_value) > eps && count <= MAX_CYCLES)
    {
        current *= - (x * x) / ((count + 1) * (count + 2));
        approx_value += current;
        count += 2;
    }

    if (count >= MAX_CYCLES)
        return EPS_IS_TOO_LOW;
    
    // errors
    double absolute_error = abs_error(precise_value, approx_value);

    if (fabs(precise_value) < EPS)
        return DIVISION_BY_ZERO;

    double relative_error = absolute_error / precise_value;

    printf("%lf %lf %lf %lf", approx_value, precise_value, absolute_error, relative_error);

    return OK;
}

```

### Тестирование

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:84.00% of 25
main.c:creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:84.00% of 25
main.c:creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:88.00% of 25
main.c:creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:92.00% of 25
main.c:creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:92.00% of 25
main.c:creating 'main.c.gcov'

Negative test 4
File 'main.c'
Lines executed:96.00% of 25
main.c:creating 'main.c.gcov'

Negative test 5
File 'main.c'
Lines executed:100.00% of 25
main.c:creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:

```C
        -:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:7
-:    0:Programs:1
-:    1://
-:    2://  main.c
-:    3://  lab01task07
-:    4://
-:    5://  Created by Yaroslav Bairamgalin on 27.02.2021.
-:    6://
-:    7:
-:    8:#include <stdio.h>
-:    9:#include <math.h>
-:   10:
-:   11:#define OK 0
-:   12:#define INCORRECT_TYPE 10
-:   13:#define EPS_IS_TOO_LOW 9
-:   14:#define INCORRECT_VALUE 5
-:   15:#define DIVISION_BY_ZERO 3
-:   16:
-:   17:#define EXPECTED_ARGS 2
-:   18:
-:   19:#define EPS 1e-10
-:   20:#define MAX_CYCLES 1000
-:   21:
-:   22:// function receives two parameters: double expected -
-:   23:// the precise value, double measured - measured or
-:   24:// approximated value
-:   25:// function returns abs error of the given data
3:   26:double abs_error(double const expected, double const measured)
-:   27:{
3:   28:    return fabs(expected - measured);
-:   29:}
-:   30:
7:   31:int main(void)
-:   32:{
-:   33:    double x;
-:   34:    double eps;
7:   35:    int corr_input = scanf("%lf%lf", &x, &eps);
-:   36:
7:   37:    if (corr_input != EXPECTED_ARGS)
1:   38:        return INCORRECT_TYPE;
-:   39:
-:   40:    // due to the task
6:   41:    if (eps <= 0 || eps > 1)
2:   42:        return INCORRECT_VALUE;
-:   43:
4:   44:    double precise_value = sin(x);
4:   45:    double approx_value = x;
4:   46:    double current = approx_value;
4:   47:    int count = 1; // for managing the power of x
-:   48:
507:   49:    while (fabs(precise_value - approx_value) > eps && count <= MAX_CYCLES)
-:   50:    {
503:   51:        current *= - (x * x) / ((count + 1) * (count + 2));
503:   52:        approx_value += current;
503:   53:        count += 2;
-:   54:    }
-:   55:
4:   56:    if (count >= MAX_CYCLES)
1:   57:        return EPS_IS_TOO_LOW;
-:   58:
-:   59:    // errors
3:   60:    double absolute_error = abs_error(precise_value, approx_value);
-:   61:
3:   62:    if (fabs(precise_value) < EPS)
1:   63:        return DIVISION_BY_ZERO;
-:   64:
2:   65:    double relative_error = absolute_error / precise_value;
-:   66:
2:   67:    printf("%lf %lf %lf %lf", approx_value, precise_value, absolute_error, relative_error);
-:   68:
2:   69:    return OK;
7:   70:}

```

Производилось 2 позитивных и 5 негативных функциональный теста, расположенных
в папке `func_tests`. Покрытие `gcov` - 100%.

## Задача 8
### Краткая формулировка задачи
Вводятся значения 4 байт в десятичной системе счисления. Необходимо выполнить упаковку
введенный байт в целое беззнаковое число. Сначала вывести результат упаковки в двоичной
системе счисления, затем вывести результат распаковки (по 1 байту) в десятичной системе
счисления.

### Сборка

```bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -O0 -fprofile-arcs -ftest-coverage main.c -o main.exe
```

### Код программы
```C
//  Created by Yaroslav Bairamgalin on 02.03.2021.
//

#include <stdio.h>

#define OK 0
#define INCORRECT_TYPE 10
#define INCORRECT_VALUE 5

#define EXPECTED_ARGS 4

#define MAX_BYTE_VALUE 255
#define BYTE_DIGITS 8
#define INT_DIGITS 32

// function receives 4 bytes and returns 4 bytes packed into a single var
// all vars type is unsigned long int
unsigned long int pack(const unsigned long int byte_1, const unsigned long int byte_2, const unsigned long int byte_3, const unsigned long int byte_4)
{
    return byte_1 | byte_2 | byte_3 | byte_4;
}


int main(void)
{
    unsigned long int byte_a, byte_b, byte_c, byte_d;
    unsigned long int corr_input = scanf("%lu%lu%lu%lu", &byte_a, &byte_b, &byte_c, &byte_d);

    if (corr_input != EXPECTED_ARGS)
    {
        printf("Error: input error");
        return INCORRECT_TYPE;
    }

    if (byte_a > MAX_BYTE_VALUE || byte_b > MAX_BYTE_VALUE || byte_c > MAX_BYTE_VALUE || byte_d > MAX_BYTE_VALUE)
    {
        printf("Error: input error");
        return INCORRECT_VALUE;
    }

    unsigned long int byte_a_left_24 = byte_a << BYTE_DIGITS * 3;
    unsigned long int byte_b_left_16 = byte_b << BYTE_DIGITS * 2;
    unsigned long int byte_c_left_8 = byte_c << BYTE_DIGITS;
    
    unsigned long int packed = pack(byte_a_left_24, byte_b_left_16, byte_c_left_8, byte_d);
    
    printf("Result: ");

    for (int i = INT_DIGITS - 1; i >= 0; i--)
        printf("%lu", (packed >> i) % 2);
    
    printf(" ");
    
    for (int i = EXPECTED_ARGS - 1; i >= 0; i--)
        printf("%lu ", (packed >> (i * BYTE_DIGITS)) % (MAX_BYTE_VALUE + 1));
    
    return OK;
}

```


### Тестирование

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:81.82% of 22
main.c:creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:81.82% of 22
main.c:creating 'main.c.gcov'

Positive test 3
File 'main.c'
Lines executed:81.82% of 22
main.c:creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:90.91% of 22
main.c:creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:100.00% of 22
main.c:creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:
```C
        -:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:5
-:    0:Programs:1
-:    1://  Created by Yaroslav Bairamgalin on 02.03.2021.
-:    2://
-:    3:
-:    4:#include <stdio.h>
-:    5:
-:    6:#define OK 0
-:    7:#define INCORRECT_TYPE 10
-:    8:#define INCORRECT_VALUE 5
-:    9:
-:   10:#define EXPECTED_ARGS 4
-:   11:
-:   12:#define MAX_BYTE_VALUE 255
-:   13:#define BYTE_DIGITS 8
-:   14:#define INT_DIGITS 32
-:   15:
-:   16:// function receives 4 bytes and returns 4 bytes packed into a single var
-:   17:// all vars type is unsigned long int
3:   18:unsigned long int pack(const unsigned long int byte_1, const unsigned long int byte_2, const unsigned long int byte_3, const unsigned long int byte_4)
-:   19:{
3:   20:    return byte_1 | byte_2 | byte_3 | byte_4;
-:   21:}
-:   22:
-:   23:
5:   24:int main(void)
-:   25:{
-:   26:    unsigned long int byte_a, byte_b, byte_c, byte_d;
5:   27:    unsigned long int corr_input = scanf("%lu%lu%lu%lu", &byte_a, &byte_b, &byte_c, &byte_d);
-:   28:
5:   29:    if (corr_input != EXPECTED_ARGS)
-:   30:    {
1:   31:        printf("Error: input error");
1:   32:        return INCORRECT_TYPE;
-:   33:    }
-:   34:
4:   35:    if (byte_a > MAX_BYTE_VALUE || byte_b > MAX_BYTE_VALUE || byte_c > MAX_BYTE_VALUE || byte_d > MAX_BYTE_VALUE)
-:   36:    {
1:   37:        printf("Error: input error");
1:   38:        return INCORRECT_VALUE;
-:   39:    }
-:   40:
3:   41:    unsigned long int byte_a_left_24 = byte_a << BYTE_DIGITS * 3;
3:   42:    unsigned long int byte_b_left_16 = byte_b << BYTE_DIGITS * 2;
3:   43:    unsigned long int byte_c_left_8 = byte_c << BYTE_DIGITS;
-:   44:
3:   45:    unsigned long int packed = pack(byte_a_left_24, byte_b_left_16, byte_c_left_8, byte_d);
-:   46:
3:   47:    printf("Result: ");
-:   48:
99:   49:    for (int i = INT_DIGITS - 1; i >= 0; i--)
96:   50:        printf("%lu", (packed >> i) % 2);
-:   51:
3:   52:    printf(" ");
-:   53:
15:   54:    for (int i = EXPECTED_ARGS - 1; i >= 0; i--)
12:   55:        printf("%lu ", (packed >> (i * BYTE_DIGITS)) % (MAX_BYTE_VALUE + 1));
-:   56:
3:   57:    return OK;
5:   58:}
```

Производилось 2 позитивных и 5 негативных функциональный теста, расположенных
в папке `func_tests`. Покрытие `gcov` - 100%.

## Задача 9
### Краткая формулировка задачи
Принять на ввод элементы последовательности *x* по концевому признаку (до первого
отрицательного элемента). Вычислить и вывести на экран значение *g(x)*.  
g(x) = sin(sqrt(x<sub>1</sub>) + sqrt(x<sub>2</sub> / 2) + ... + sqrt(x<sub>n</sub> / n))

### Сборка

```bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -O0 -fprofile-arcs -ftest-coverage main.c -o main.exe
```

### Код программы

```C
//  Created by Yaroslav Bairamgalin on 28.02.2021.
//

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define OK 0
#define INCORRECT_TYPE 10
#define INCORRECT_VALUE 5

#define EXPECTED_ARGS 1

// function receives sum and returns sin value of this sum
double g_term(double const x, int const count)
{
    return sqrt(x / count);
}

int main(void)
{
    double element;

    int corr_input = scanf("%lf", &element);

    if (corr_input != EXPECTED_ARGS)
        return INCORRECT_TYPE;

    if (element < 0)
        return INCORRECT_VALUE;

    double sum = sqrt(element);
    
    // set count = 2 as the first element has already been given
    int count = 2;
    
    // until appears negative element
    while (true)
    {
        int corr_input = scanf("%lf", &element);

        if (corr_input != 1)
            return INCORRECT_TYPE;

        if (element >= 0)
            sum += g_term(element, count);
        else
            break;
        count++;
    }

    double result = sin(sum);
    printf("%lf", result);

    return OK;
}



```

### Тестирование

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:86.36% of 22
main.c:creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:86.36% of 22
main.c:creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:90.91% of 22
main.c:creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:95.45% of 22
main.c:creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:100.00% of 22
main.c:creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:

```C
        -:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:5
-:    0:Programs:1
-:    1://  Created by Yaroslav Bairamgalin on 28.02.2021.
-:    2://
-:    3:
-:    4:#include <stdio.h>
-:    5:#include <math.h>
-:    6:#include <stdbool.h>
-:    7:
-:    8:#define OK 0
-:    9:#define INCORRECT_TYPE 10
-:   10:#define INCORRECT_VALUE 5
-:   11:
-:   12:#define EXPECTED_ARGS 1
-:   13:
-:   14:// function receives sum and returns sin value of this sum
10:   15:double g_term(double const x, int const count)
-:   16:{
10:   17:    return sqrt(x / count);
-:   18:}
-:   19:
5:   20:int main(void)
-:   21:{
-:   22:    double element;
-:   23:
5:   24:    int corr_input = scanf("%lf", &element);
-:   25:
5:   26:    if (corr_input != EXPECTED_ARGS)
1:   27:        return INCORRECT_TYPE;
-:   28:
4:   29:    if (element < 0)
1:   30:        return INCORRECT_VALUE;
-:   31:
3:   32:    double sum = sqrt(element);
-:   33:
-:   34:    // set count = 2 as the first element has already been given
3:   35:    int count = 2;
-:   36:
-:   37:    // until appears negative element
13:   38:    while (true)
-:   39:    {
13:   40:        int corr_input = scanf("%lf", &element);
-:   41:
13:   42:        if (corr_input != 1)
1:   43:            return INCORRECT_TYPE;
-:   44:
12:   45:        if (element >= 0)
10:   46:            sum += g_term(element, count);
-:   47:        else
2:   48:            break;
10:   49:        count++;
-:   50:    }
-:   51:
2:   52:    double result = sin(sum);
2:   53:    printf("%lf", result);
-:   54:
2:   55:    return OK;
5:   56:}
-:   57:
-:   58:
```

Производилось 2 позитивных и 5 негативных функциональный теста, расположенных
в папке `func_tests`. Покрытие `gcov` - 100%.
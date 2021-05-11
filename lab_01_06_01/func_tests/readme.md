## Задача 6

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

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

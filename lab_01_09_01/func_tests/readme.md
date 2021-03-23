## Задача 9

### Функциональные тесты
##### Входные данные

- double element (переменная в которую происходит ввод каждого элемента)

##### Выходные данные

- double result

###### Positive tests

- 01 - обычные данные
    - покрытие gcov - 86.36%
- 02 - обычные данные (все элементы нули)
    - покрытие gcov - 86.36%

###### Negative tests

- 01 - первой введена буква
    - покрытие gcov - 90.91%
- 02 - первый элемент меньше нуля
    - покрытие gcov - 95.45%
- 03 - введена буква после ввода нескольких элементов
    - покрытие gcov - 100%

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
       10:   15:double g_term(double x, int count)
        -:   16:{
       10:   17:    return sqrt(x / count);
        -:   18:}
        -:   19:
        5:   20:int main(void)
        -:   21:{
        -:   22:    double element;
        -:   23:
        5:   24:    int corr_input = scanf("%lf", &element);
        5:   25:    if (corr_input != EXPECTED_ARGS)
        1:   26:        return INCORRECT_TYPE;
        4:   27:    if (element < 0)
        1:   28:        return INCORRECT_VALUE;
        -:   29:
        3:   30:    double sum = sqrt(element);
        -:   31:    
        -:   32:    // set count = 2 as the first element has already been given
        3:   33:    int count = 2;
        -:   34:    
        -:   35:    // until appears negative element
       13:   36:    while (true)
        -:   37:    {
       13:   38:        int corr_input = scanf("%lf", &element);
       13:   39:        if (corr_input != 1)
        1:   40:            return INCORRECT_TYPE;
        -:   41:
       12:   42:        if (element >= 0)
       10:   43:            sum += g_term(element, count);
        -:   44:        else
        2:   45:            break;
       10:   46:        count++;
        -:   47:    }
        -:   48:
        2:   49:    double result = sin(sum);
        2:   50:    printf("%lf", result);
        -:   51:
        2:   52:    return OK;
        5:   53:}
        -:   54:
        -:   55:
```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

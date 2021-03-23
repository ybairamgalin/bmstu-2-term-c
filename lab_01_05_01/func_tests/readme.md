## Задача 5
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

```C
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
```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

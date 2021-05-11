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

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

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

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

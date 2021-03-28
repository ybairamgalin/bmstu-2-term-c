## Задача 1
### Функциональные тесты
##### Входные данные

1. int number_of_elements
2. int arr

##### Выходные данные

1. int product

###### Positive tests

1. Обычные данные
2. Обычные данные (1 элемент)
3. Обычные данные (10 элементов)

###### Negative tests

1. Вместо количества элементов введена буква
2. Количество элементов отрицательное
3. Вместо одного из элементов введена буква
4. В массиве отсутствуют нечентные элементы

#### gcov
##### Вывод после каждого теста

```bash
File 'main.c'
Lines executed:78.57% of 28
Creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:78.57% of 28
Creating 'main.c.gcov'

Positive test 3
File 'main.c'
Lines executed:78.57% of 28
Creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:82.14% of 28
Creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:92.86% of 28
Creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:96.43% of 28
Creating 'main.c.gcov'

Negative test 4
File 'main.c'
Lines executed:100.00% of 28
Creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:

```C
        -:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:7
-:    1:#include <stdio.h>
-:    2:
-:    3:#define OK 0
-:    4:#define INCORRECT_TYPE 2
-:    5:#define INCORRECT_VALUE 3
-:    6:#define NO_ODD_ELEMENTS_IN_ARRAY 4
-:    7:
-:    8:#define ARRAY_SIZE 10
-:    9:#define YES 1
-:   10:#define NO 0
-:   11:
-:   12:
5:   13:int input(int *array, int num_of_elem)
-:   14:{
5:   15:    int input_is_correct = YES;
-:   16:
32:   17:    for (int i = 0; i < num_of_elem; i++)
-:   18:    {
28:   19:        int read_elements = scanf("%d", array + i);
-:   20:
28:   21:        if (read_elements != 1)
-:   22:        {
1:   23:            input_is_correct = NO;
1:   24:            break;
-:   25:        }
-:   26:    }
-:   27:
5:   28:    return input_is_correct;
-:   29:}
-:   30:
-:   31:// function finds the product of all negative elements and them in into *product
-:   32:// if no such elements exist returns 0
-:   33:// else returns 1
4:   34:int solve(int *array, int arr_lng, int *product)
-:   35:{
4:   36:    int contains_odd = NO;
-:   37:
28:   38:    for (int i = 0; i < arr_lng; i++)
-:   39:    {
-:   40:        // != to avoid problems with negative elements
24:   41:        if (*(array + i) % 2 != 0)
-:   42:        {
11:   43:            *product *= *(array + i);
11:   44:            contains_odd = YES;
-:   45:        }
-:   46:    }
4:   47:    return contains_odd;
-:   48:}
-:   49:
7:   50:int main(void)
-:   51:{
-:   52:    int number_of_elements;
7:   53:    int corr_input = scanf("%d", &number_of_elements);
-:   54:
7:   55:    if (corr_input != 1)
1:   56:        return INCORRECT_TYPE;
-:   57:
6:   58:    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
1:   59:        return INCORRECT_VALUE;
-:   60:
-:   61:    int arr[ARRAY_SIZE];
-:   62:
5:   63:    if (input(arr, number_of_elements) == NO)
1:   64:        return INCORRECT_TYPE;
-:   65:
-:   66:    // prod - final product
4:   67:    int product = 1;
-:   68:
4:   69:    if (solve(arr, number_of_elements, &product) == 0)
1:   70:        return NO_ODD_ELEMENTS_IN_ARRAY;
-:   71:
3:   72:    printf("%d", product);
-:   73:
3:   74:    return OK;
-:   75:}

```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

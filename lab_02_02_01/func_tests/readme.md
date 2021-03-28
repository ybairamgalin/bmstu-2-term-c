## Задача 2
### Функциональные тесты
##### Входные данные

1. int number_of_elements
2. int arr

##### Выходные данные

1. int arr

###### Positive tests

1. Обычные данные
2. Обычные данные (1 элемент)
3. Обычные данные (10 элементов)

###### Negative tests

1. Вместо количества элементов введена буква
2. Количество элементов отрицательное
3. Вместо одного из элементов введена буква

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:82.86% of 35
Creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:82.86% of 35
Creating 'main.c.gcov'

Positive test 3
File 'main.c'
Lines executed:82.86% of 35
Creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:85.71% of 35
Creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:88.57% of 35
Creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:97.14% of 35
Creating 'main.c.gcov'

Negative test 4
File 'main.c'
Lines executed:100.00% of 35
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
-:    2:#include <stdlib.h>
-:    3:#include <math.h>
-:    4:
-:    5:#define OK 0
-:    6:#define INCORRECT_TYPE 2
-:    7:#define INCORRECT_VALUE 3
-:    8:#define NO_PRIME_ELEMENTS_IN_ARRAY 4
-:    9:
-:   10:#define ARRAY_SIZE 10
-:   11:#define YES 1
-:   12:#define NO 0
-:   13:
-:   14:
-:   15:// function receives pointer to an array and number of elements in this array
-:   16:// function returns 1, if input is correct
-:   17:// 0, if input in not correct
5:   18:int input(int *array, const int num_of_elem)
-:   19:{
5:   20:    int input_is_correct = YES;
-:   21:
32:   22:    for (int i = 0; i < num_of_elem; i++)
-:   23:    {
28:   24:        int read_elements = scanf("%d", array + i);
-:   25:
28:   26:        if (read_elements != 1)
-:   27:        {
1:   28:            input_is_correct = NO;
1:   29:            break;
-:   30:        }
-:   31:    }
5:   32:    return input_is_correct;
-:   33:}
-:   34:
-:   35:// function receives int x and returns 1 if:
-:   36:// 1. x <= 1, 2. x is prime;
-:   37:// otherwise function returns 0
24:   38:int is_prime(const int x)
-:   39:{
24:   40:    int x_is_prime = YES;
-:   41:
-:   42:    // if the condition is completed for cycle won't be executed
24:   43:    if (x <= 1)
2:   44:        x_is_prime = NO;
-:   45:
29:   46:    for (int i = 2; i <= (int)sqrt(x); i++)
-:   47:    {
18:   48:        if (x % i == 0)
-:   49:        {
13:   50:            x_is_prime = NO;
13:   51:            break;
-:   52:        }
-:   53:    }
24:   54:    return x_is_prime;
-:   55:}
-:   56:
-:   57:
7:   58:int main(void)
-:   59:{
-:   60:    int number_of_elements;
7:   61:    int corr_input = scanf("%d", &number_of_elements);
-:   62:
7:   63:    if (corr_input != 1 )
1:   64:        return INCORRECT_TYPE;
-:   65:
6:   66:    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
1:   67:        return INCORRECT_VALUE;
-:   68:
-:   69:    int arr[ARRAY_SIZE];
-:   70:
5:   71:    if (input(arr, number_of_elements) == NO)
1:   72:        return INCORRECT_TYPE;
-:   73:
-:   74:    int result_array[ARRAY_SIZE];
4:   75:    int count_new_array = 0;
-:   76:
28:   77:    for (int i = 0; i < number_of_elements; i++)
-:   78:    {
24:   79:        if (is_prime(arr[i]) == YES)
-:   80:        {
9:   81:            result_array[count_new_array] = arr[i];
9:   82:            count_new_array++;
-:   83:        }
-:   84:    }
-:   85:
-:   86:    // due to the task if no elements are found, return error
4:   87:    if (count_new_array == 0)
1:   88:        return NO_PRIME_ELEMENTS_IN_ARRAY;
-:   89:
12:   90:    for (int i = 0; i < count_new_array; i++)
9:   91:        printf("%d ", result_array[i]);
-:   92:
3:   93:    return OK;
-:   94:}

```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

## Задача 3
### Функциональные тесты
##### Входные данные

1. int number_of_elements
2. int arr

##### Выходные данные

1. int result_array

###### Positive tests

1. Обычные данные
2. Обычные данные (1 элемент)
3. Обычные данные (10 элементов)
4. Нет элементов кратных трем

###### Negative tests

1. Вместо количества элементов введена буква
2. Количество элементов отрицательное
3. Вместо одного из элементов введена буква

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:70.73% of 41
Creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:70.73% of 41
Creating 'main.c.gcov'

Positive test 3
File 'main.c'
Lines executed:87.80% of 41
Creating 'main.c.gcov'

Positive test 4
File 'main.c'
Lines executed:87.80% of 41
Creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:90.24% of 41
Creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:92.68% of 41
Creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:100.00% of 41
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
-:    6:
-:    7:#define ARRAY_SIZE 21
-:    8:#define BORDER_VALUE -1000000
-:    9:#define YES 1
-:   10:#define NO 0
-:   11:
-:   12:// function receives pointer to an array and number of elements in this array
-:   13:// function returns 1, if input is correct
-:   14:// 0, if input in not correct
5:   15:int input(int *array, const int num_of_elem)
-:   16:{
5:   17:    int input_is_correct = YES;
-:   18:
24:   19:    for (int i = 0; i < num_of_elem; i++)
-:   20:    {
20:   21:        int read_elements = scanf("%d", array + i);
-:   22:
20:   23:        if (read_elements != 1)
-:   24:        {
1:   25:            input_is_correct = NO;
1:   26:            break;
-:   27:        }
-:   28:    }
-:   29:
5:   30:    return input_is_correct;
-:   31:}
-:   32:
-:   33:
-:   34:// the functions returns fib_i,, where i is the number of times, the function was previously called
5:   35:int get_next_fibonacci()
-:   36:{
-:   37:    static int fib_first = 0;
-:   38:    static int fib_second = 1;
-:   39:    static int count = 0;
-:   40:
5:   41:    if (count == 0)
-:   42:    {
3:   43:        count++;
3:   44:        return fib_first;
-:   45:    }
-:   46:
2:   47:    if (count == 1)
-:   48:    {
1:   49:        count++;
1:   50:        return fib_second;
-:   51:    }
-:   52:
1:   53:    int result = fib_first + fib_second;
1:   54:    fib_first = fib_second;
1:   55:    fib_second = result;
-:   56:
1:   57:    return result;
-:   58:}
-:   59:
7:   60:int main()
-:   61:{
-:   62:    int number_of_elements;
7:   63:    int corr_input = scanf("%d", &number_of_elements);
-:   64:
7:   65:    if (corr_input != 1)
1:   66:        return INCORRECT_TYPE;
-:   67:
6:   68:    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
1:   69:        return INCORRECT_VALUE;
-:   70:
-:   71:    int arr[ARRAY_SIZE];
-:   72:
110:   73:    for (int i = 0; i < ARRAY_SIZE; i++)
105:   74:        arr[i] = BORDER_VALUE;
-:   75:
5:   76:    if (input(arr, number_of_elements) == NO)
1:   77:        return INCORRECT_TYPE;
-:   78:
4:   79:    int count = 0;
-:   80:
23:   81:    while (arr[count] != BORDER_VALUE)
-:   82:    {
19:   83:        if (arr[count] % 3 == 0)
-:   84:        {
-:   85:            // move all the following elements 1 forward
81:   86:            for (int i = ARRAY_SIZE - 1; i > count + 1; i--)
76:   87:                arr[i] = arr[i - 1];
-:   88:
5:   89:            arr[count + 1] = get_next_fibonacci();
5:   90:            number_of_elements++;
5:   91:            count += 2;
-:   92:        }
-:   93:        else
14:   94:            count++;
-:   95:    }
-:   96:
28:   97:    for (int i = 0; i < number_of_elements; i++)
24:   98:        printf("%d ", arr[i]);
-:   99:
4:  100:    return OK;
-:  101:}

```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

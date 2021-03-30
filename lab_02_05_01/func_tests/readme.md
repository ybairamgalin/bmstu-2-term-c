## Задача 5
### Функциональные тесты
##### Входные данные

1. int number_of_elements
2. input_array

##### Выходные данные

1. int sum

###### Positive tests

1. Обычные данные
2. Обычные данные (2 элемента)
3. Обычные данные (10 элементов)

###### Negative tests

1. Вместо количества элементов введена буква
2. Количество элементов отрицательное
3. Вместо одного из элементов массива введена буква
4. Нет положительных элементов
5. Нет отрицательных элементов

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:84.62% of 39
Creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:84.62% of 39
Creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:87.18% of 39
Creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:89.74% of 39
Creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:97.44% of 39
Creating 'main.c.gcov'

Negative test 4
File 'main.c'
Lines executed:100.00% of 39
Creating 'main.c.gcov'

Negative test 5
File 'main.c'
Lines executed:100.00% of 39
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
-:    7:#define VALUE_CANNOT_BE_DEFINED 20
-:    8:
-:    9:#define YES 1
-:   10:#define NO 0
-:   11:
-:   12:#define ARRAY_SIZE 10
-:   13:
-:   14:
-:   15:// function receives pointer to an array and number of elements in this array
-:   16:// function returns 1, if input is correct
-:   17:// 0, if input in not correct
5:   18:int input(int *first, int *last)
-:   19:{
5:   20:    long num_of_elem = last - first;
5:   21:    int input_is_correct = YES;
-:   22:
22:   23:    for (int i = 0; i < num_of_elem; i++)
-:   24:    {
18:   25:        int read_elements = scanf("%d", first + i);
-:   26:
18:   27:        if (read_elements != 1)
-:   28:        {
1:   29:            input_is_correct = NO;
1:   30:            break;
-:   31:        }
-:   32:    }
-:   33:
5:   34:    return input_is_correct;
-:   35:}
-:   36:
-:   37:// function receives pointer to the first and last+1 element of an array and one more pointer to an array
-:   38:// it is expected that in b_array exist elements to (a_last - a_first)
-:   39:// function returns sum of product of respective elements of 2 given arrays
2:   40:int find_expected_sum(int *a_first, int *a_last, int *b_first)
-:   41:{
2:   42:    long size = a_last - a_first;
2:   43:    int sum = 0;
-:   44:
5:   45:    for (int i = 0; i < size; i++)
3:   46:        sum += *(a_first + i) * *(b_first + i);
-:   47:
2:   48:    return sum;
-:   49:}
-:   50:
-:   51:
7:   52:int main(void)
-:   53:{
-:   54:    int number_of_elements;
7:   55:    int corr_input = scanf("%d", &number_of_elements);
-:   56:
7:   57:    if (corr_input != 1)
1:   58:        return INCORRECT_TYPE;
-:   59:
6:   60:    if (number_of_elements <= 0 || number_of_elements > ARRAY_SIZE)
1:   61:        return INCORRECT_VALUE;
-:   62:
-:   63:    int input_array[ARRAY_SIZE];
-:   64:
5:   65:    if (input(input_array, input_array + number_of_elements) == NO)
1:   66:        return INCORRECT_TYPE;
-:   67:
-:   68:    int neg_array[ARRAY_SIZE];
4:   69:    int count_neg_elements = 0;
-:   70:
20:   71:    for (int i = 0; i < number_of_elements; i++)
-:   72:    {
16:   73:        if (*(input_array + i) < 0)
-:   74:        {
8:   75:            *(neg_array + count_neg_elements) = *(input_array + i);
8:   76:            count_neg_elements++;
-:   77:        }
-:   78:    }
-:   79:
-:   80:    int pos_array[ARRAY_SIZE];
4:   81:    int count_pos_elements = 0;
-:   82:
20:   83:    for (int i = number_of_elements - 1; i >= 0; i--)
-:   84:    {
16:   85:        if (*(input_array + i) > 0)
-:   86:        {
8:   87:            *(pos_array + count_pos_elements) = *(input_array + i);
8:   88:            count_pos_elements++;
-:   89:        }
-:   90:    }
-:   91:
4:   92:    int iterate_to = (count_neg_elements > count_pos_elements) ? count_pos_elements : count_neg_elements;
-:   93:
4:   94:    if (iterate_to == 0)
2:   95:        return VALUE_CANNOT_BE_DEFINED;
-:   96:
2:   97:    int sum = find_expected_sum(neg_array, neg_array + iterate_to, pos_array);
-:   98:
2:   99:    printf("%d", sum);
-:  100:
2:  101:    return OK;
-:  102:}
```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

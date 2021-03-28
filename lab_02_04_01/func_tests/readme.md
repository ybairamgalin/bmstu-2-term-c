## Задача 2
### Функциональные тесты
##### Входные данные

1. int arr (по концевому признаку)

##### Выходные данные

1. int arr

###### Positive tests

1. Обычные данные
2. Обычные данные (1 элемент)
3. Обычные данные (10 элементов)

###### Negative tests

1. Вместо первого элемента введена буква
2. После введения 10 элементов ввод продолжается

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:92.31% of 26
Creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:92.31% of 26
Creating 'main.c.gcov'

Positive test 3
File 'main.c'
Lines executed:92.31% of 26
Creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:96.15% of 26
Creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:100.00% of 26
Creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:

```C
        -:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:5
-:    1:#include <stdio.h>
-:    2:
-:    3:#define OK 0
-:    4:#define INCORRECT_INPUT 10
-:    5:#define REACHED_MAX_ARRAY_SIZE 100
-:    6:
-:    7:#define READ_CORRECTLY 1
-:    8:
-:    9:#define ARRAY_SIZE 10
-:   10:
-:   11:// function receives pointer to an array and scans the user input
-:   12:// returns number of elements that were scanned
5:   13:int input(int *array)
-:   14:{
5:   15:    int number_of_elements = 0;
-:   16:
29:   17:    while (number_of_elements != ARRAY_SIZE && scanf("%d", array + number_of_elements) == READ_CORRECTLY)
24:   18:        number_of_elements++;
-:   19:
-:   20:    int check_element;
5:   21:    int added_new = scanf("%d", &check_element);
5:   22:    number_of_elements = number_of_elements + added_new;
-:   23:
5:   24:    return number_of_elements;
-:   25:}
-:   26:
-:   27:// function receives pointer to an array and sorts it
-:   28:// sort method - bubble sort
4:   29:void sort(int *array, const int number_of_elements)
-:   30:{
28:   31:    for (int i = 0; i < number_of_elements; i++)
-:   32:    {
117:   33:        for (int j = 1; j < number_of_elements - i; j++)
-:   34:        {
93:   35:            if (*(array + j - 1) > *(array + j))
-:   36:            {
42:   37:                int buf = *(array + j - 1);
42:   38:                *(array + j - 1) = *(array + j);
42:   39:                *(array + j) = buf;
-:   40:            }
-:   41:        }
-:   42:    }
4:   43:}
-:   44:
5:   45:int main(void)
-:   46:{
-:   47:    int arr[ARRAY_SIZE];
5:   48:    int number_of_input_elements = input(arr);
5:   49:    int number_of_elements = (number_of_input_elements <= ARRAY_SIZE) ? number_of_input_elements : number_of_input_elements - 1;
-:   50:
5:   51:    if (number_of_elements == 0)
1:   52:        return INCORRECT_INPUT;
-:   53:
4:   54:    sort(arr, number_of_elements);
-:   55:
28:   56:    for (int i = 0; i < number_of_elements; i++)
24:   57:        printf("%d ", arr[i]);
-:   58:
4:   59:    if (number_of_input_elements > ARRAY_SIZE)
1:   60:        return REACHED_MAX_ARRAY_SIZE;
-:   61:
3:   62:    return OK;
-:   63:}

```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

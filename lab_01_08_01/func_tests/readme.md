## Задача 8

### Функциональные тесты

##### Входные данные

- unsigned long int byte_a
- unsigned long int byte_b
- unsigned long int byte_c
- unsigned long int byte_d

##### Выходные данные

- unsigned long int packed (в двоичной СС)
- unsigned long int packed (побайтово в 10-ой СС)

###### Positive tests

- 01 - обычные данные
    - покрытие gcov - 81.82%
- 02 - все байты равны 255 (крайнее значение)
    - покрытие gcov - 81.82%
- 03 - все байты равны 0 (крайнее значение)
    - покрытие gcov - 81.82%

###### Negative tests

- 01 - введена буква
    - покрытие gcov - 90.91%
- 02 - один из байтов больше 255
    - покрытие gcov - 100%

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:81.82% of 22
main.c:creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:81.82% of 22
main.c:creating 'main.c.gcov'

Positive test 3
File 'main.c'
Lines executed:81.82% of 22
main.c:creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:90.91% of 22
main.c:creating 'main.c.gcov'

Negative test 2
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
-:    1://  Created by Yaroslav Bairamgalin on 02.03.2021.
-:    2://
-:    3:
-:    4:#include <stdio.h>
-:    5:
-:    6:#define OK 0
-:    7:#define INCORRECT_TYPE 10
-:    8:#define INCORRECT_VALUE 5
-:    9:
-:   10:#define EXPECTED_ARGS 4
-:   11:
-:   12:#define MAX_BYTE_VALUE 255
-:   13:#define BYTE_DIGITS 8
-:   14:#define INT_DIGITS 32
-:   15:
-:   16:// function receives 4 bytes and returns 4 bytes packed into a single var
-:   17:// all vars type is unsigned long int
3:   18:unsigned long int pack(const unsigned long int byte_1, const unsigned long int byte_2, const unsigned long int byte_3, const unsigned long int byte_4)
-:   19:{
3:   20:    return byte_1 | byte_2 | byte_3 | byte_4;
-:   21:}
-:   22:
-:   23:
5:   24:int main(void)
-:   25:{
-:   26:    unsigned long int byte_a, byte_b, byte_c, byte_d;
5:   27:    unsigned long int corr_input = scanf("%lu%lu%lu%lu", &byte_a, &byte_b, &byte_c, &byte_d);
-:   28:
5:   29:    if (corr_input != EXPECTED_ARGS)
-:   30:    {
1:   31:        printf("Error: input error");
1:   32:        return INCORRECT_TYPE;
-:   33:    }
-:   34:
4:   35:    if (byte_a > MAX_BYTE_VALUE || byte_b > MAX_BYTE_VALUE || byte_c > MAX_BYTE_VALUE || byte_d > MAX_BYTE_VALUE)
-:   36:    {
1:   37:        printf("Error: input error");
1:   38:        return INCORRECT_VALUE;
-:   39:    }
-:   40:
3:   41:    unsigned long int byte_a_left_24 = byte_a << BYTE_DIGITS * 3;
3:   42:    unsigned long int byte_b_left_16 = byte_b << BYTE_DIGITS * 2;
3:   43:    unsigned long int byte_c_left_8 = byte_c << BYTE_DIGITS;
-:   44:
3:   45:    unsigned long int packed = pack(byte_a_left_24, byte_b_left_16, byte_c_left_8, byte_d);
-:   46:
3:   47:    printf("Result: ");
-:   48:
99:   49:    for (int i = INT_DIGITS - 1; i >= 0; i--)
96:   50:        printf("%lu", (packed >> i) % 2);
-:   51:
3:   52:    printf(" ");
-:   53:
15:   54:    for (int i = EXPECTED_ARGS - 1; i >= 0; i--)
12:   55:        printf("%lu ", (packed >> (i * BYTE_DIGITS)) % (MAX_BYTE_VALUE + 1));
-:   56:
3:   57:    return OK;
5:   58:}

```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

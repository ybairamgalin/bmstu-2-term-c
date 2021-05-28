## Задача 7

### Функциональные тесты

##### Входные данные

- double x
- double eps

##### Выходные данные

- double approx_value (точное значение)
- double precise_value (приближенное значение)
- double absolute_error (абсолютная погрешность)
- double relative_error (относительная погрешность)

###### Positive tests

- 01 - обычные данные, x > 0
    - покрытие gcov - 84%
- 02 - обычные данные, x < 0
    - покрытие gcov - 84%

###### Negative tests

- 01 - введена буква
    - покрытие gcov - 88%
- 02 - eps = 0
    - покрытие gcov - 92%
- 03 - eps > 1
    - покрытие gcov - 92%
- 04 - eps слишком маленький
    - покрытие gcov - 96%
- 05 - деление на ноль при вычислении относительной погрешности
    - покрытие gcov - 100%

#### gcov
##### Вывод после каждого теста

```bash
Positive test 1
File 'main.c'
Lines executed:84.00% of 25
main.c:creating 'main.c.gcov'

Positive test 2
File 'main.c'
Lines executed:84.00% of 25
main.c:creating 'main.c.gcov'

Negative test 1
File 'main.c'
Lines executed:88.00% of 25
main.c:creating 'main.c.gcov'

Negative test 2
File 'main.c'
Lines executed:92.00% of 25
main.c:creating 'main.c.gcov'

Negative test 3
File 'main.c'
Lines executed:92.00% of 25
main.c:creating 'main.c.gcov'

Negative test 4
File 'main.c'
Lines executed:96.00% of 25
main.c:creating 'main.c.gcov'

Negative test 5
File 'main.c'
Lines executed:100.00% of 25
main.c:creating 'main.c.gcov'
```

##### Литстинг
После выполнения тестов файл main.c.gcov имеет вид:
```C
-:    0:Source:main.c
-:    0:Graph:main.gcno
-:    0:Data:main.gcda
-:    0:Runs:7
-:    0:Programs:1
-:    1://
-:    2://  main.c
-:    3://  lab01task07
-:    4://
-:    5://  Created by Yaroslav Bairamgalin on 27.02.2021.
-:    6://
-:    7:
-:    8:#include <stdio.h>
-:    9:#include <math.h>
-:   10:
-:   11:#define OK 0
-:   12:#define INCORRECT_TYPE 10
-:   13:#define EPS_IS_TOO_LOW 9
-:   14:#define INCORRECT_VALUE 5
-:   15:#define DIVISION_BY_ZERO 3
-:   16:
-:   17:#define EXPECTED_ARGS 2
-:   18:
-:   19:#define EPS 1e-10
-:   20:#define MAX_CYCLES 1000
-:   21:
-:   22:// function receives two parameters: double expected -
-:   23:// the precise value, double measured - measured or
-:   24:// approximated value
-:   25:// function returns abs error of the given data
3:   26:double abs_error(double const expected, double const measured)
-:   27:{
3:   28:    return fabs(expected - measured);
-:   29:}
-:   30:
7:   31:int main(void)
-:   32:{
-:   33:    double x;
-:   34:    double eps;
7:   35:    int corr_input = scanf("%lf%lf", &x, &eps);
-:   36:
7:   37:    if (corr_input != EXPECTED_ARGS)
1:   38:        return INCORRECT_TYPE;
-:   39:
-:   40:    // due to the task
6:   41:    if (eps <= 0 || eps > 1)
2:   42:        return INCORRECT_VALUE;
-:   43:
4:   44:    double precise_value = sin(x);
4:   45:    double approx_value = x;
4:   46:    double current = approx_value;
4:   47:    int count = 1; // for managing the power of x
-:   48:
507:   49:    while (fabs(precise_value - approx_value) > eps && count <= MAX_CYCLES)
-:   50:    {
503:   51:        current *= - (x * x) / ((count + 1) * (count + 2));
503:   52:        approx_value += current;
503:   53:        count += 2;
-:   54:    }
-:   55:
4:   56:    if (count >= MAX_CYCLES)
1:   57:        return EPS_IS_TOO_LOW;
-:   58:
-:   59:    // errors
3:   60:    double absolute_error = abs_error(precise_value, approx_value);
-:   61:
3:   62:    if (fabs(precise_value) < EPS)
1:   63:        return DIVISION_BY_ZERO;
-:   64:
2:   65:    double relative_error = absolute_error / precise_value;
-:   66:
2:   67:    printf("%lf %lf %lf %lf", approx_value, precise_value, absolute_error, relative_error);
-:   68:
2:   69:    return OK;
7:   70:}

```

Каждая строка была выполнена хотя бы 1 раз, поэтому тесты описанные выше
полностью покрывают код, приведенный для решения задачи.

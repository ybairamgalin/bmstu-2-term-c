#include "my_regex.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void move_str_left(char *str)
{
    for (int i = 0; str[i] != CHAR_END_OF_STR; i++)
        str[i] = str[i + 1];
}

// deletes unnecessary spaces
void trim(char *str)
{
    while (str[0] == CHAR_SPACE || str[0] == CHAR_TAB)
        move_str_left(str);

    for (int i = strlen(str) - 1;
            str[i] == CHAR_SPACE || str[i] == CHAR_TAB; i--)
        str[i] = CHAR_END_OF_STR;
}

void del_sign(char *str)
{
    if (str[0] == CHAR_PLUS || str[0] == CHAR_MINUS)
        move_str_left(str);
}

int del_decimal(char *str)
{
    int deleted = 0;

    while (isdigit(str[0]))
    {
        move_str_left(str);
        deleted++;
    }

    return deleted;
}

void del_point(char *str)
{
    if (str[0] == CHAR_POINT)
        move_str_left(str);
}

int del_exp(char *str)
{
    int deleted = 0;

    if (str[0] == CHAR_LOWER_E || str[0] == CHAR_UPPER_E)
    {
        deleted = 1;
        move_str_left(str);
    }

    return deleted;
}

int is_exp_num(const char *str)
{
    int result = IS_NUM;
    char new_str[MAX_STR_SIZE];

    strncpy(new_str, str, MAX_STR_SIZE);
    new_str[strlen(new_str) - 1] = CHAR_END_OF_STR;
    trim(new_str);
    del_sign(new_str);
    int deleted = del_decimal(new_str);

    if (deleted == 0)
        result = IS_NOT_NUM;

    del_point(new_str);
    del_decimal(new_str);
    deleted = del_exp(new_str);

    if (deleted)
    {
        del_sign(new_str);
        deleted = del_decimal(new_str);

        if (deleted == 0)
            result = IS_NOT_NUM;
    }

    if (strlen(new_str) != 0)
        result = IS_NOT_NUM;

    return result;
}

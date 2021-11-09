#include <stdlib.h>
#include <check.h>
#include "check_movie.h"
#include <movies.h>
#include "movie.h"

START_TEST(test_str_to_field_title)
{
    char *str = "title";

    field_t field;
    int rc = str_to_field(&field, str);

    ck_assert_msg(field == title, "field should be 'title'");
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_str_to_field_name)
{
    char *str = "name";

    field_t field;
    int rc = str_to_field(&field, str);

    ck_assert_msg(field == name, "field should be 'name'");
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_str_to_field_year)
{
    char *str = "year";

    field_t field;
    int rc = str_to_field(&field, str);

    ck_assert_msg(field == year, "field should be 'year'");
    ck_assert_int_eq(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_str_to_field_wrong_field)
{
    char *str = "random_str";

    field_t field;
    int rc = str_to_field(&field, str);

    ck_assert_int_ne(rc, EXIT_SUCCESS);
}
END_TEST

START_TEST(test_movies_read_normal)
{
    movies_t *movies = movies_create();

    int rc = movies_read("func_tests/in_files/normal_data.txt", movies, title);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(movies->cur_busy, 5);

    ck_assert_str_eq(movies->movies[0]->title, "Catch me if you can");
    ck_assert_str_eq(movies->movies[1]->title, "Men in black");
    ck_assert_str_eq(movies->movies[2]->title, "Suicide squad");
    ck_assert_str_eq(movies->movies[3]->title, "The wolf of wall street");
    ck_assert_str_eq(movies->movies[4]->title, "Winx club");

    movies_free(movies);
}
END_TEST

START_TEST(test_movies_read_one_movie)
{
    movies_t *movies = movies_create();

    int rc = movies_read("func_tests/in_files/one_movie.txt", movies, title);

    ck_assert_int_eq(rc, EXIT_SUCCESS);
    ck_assert_int_eq(movies->cur_busy, 1);

    ck_assert_str_eq(movies->movies[0]->title, "Catch me if you can");
    ck_assert_str_eq(movies->movies[0]->name, "Steven Spielberg");
    ck_assert_int_eq(movies->movies[0]->year, 2002);

    movies_free(movies);
}
END_TEST

START_TEST(test_movies_read_no_file)
{
    movies_t *movies = movies_create();

    int rc = movies_read("func_tests/in_files/no_file.txt", movies, title);

    ck_assert_int_ne(rc, EXIT_SUCCESS);

    movies_free(movies);
}
END_TEST

START_TEST(test_movies_read_empty)
{
    movies_t *movies = movies_create();

    int rc = movies_read("func_tests/in_files/empty.txt", movies, title);

    ck_assert_int_ne(rc, EXIT_SUCCESS);

    movies_free(movies);
}
END_TEST

Suite *test_str_to_field_suite(void)
{
    Suite *suite;
    suite = suite_create("str_to_field");

    TCase *pos;
    pos = tcase_create("positive");
    tcase_add_test(pos, test_str_to_field_title);
    tcase_add_test(pos, test_str_to_field_name);
    tcase_add_test(pos, test_str_to_field_year);
    suite_add_tcase(suite, pos);

    TCase *neg;
    neg = tcase_create("negative");
    tcase_add_test(neg, test_str_to_field_wrong_field);
    suite_add_tcase(suite, neg);

    return suite;
}

Suite *test_movies_read_suite(void)
{
    Suite *suite;
    suite = suite_create("str_to_field");

    TCase *pos;
    pos = tcase_create("positive");
    tcase_add_test(pos, test_movies_read_normal);
    tcase_add_test(pos, test_movies_read_one_movie);

    suite_add_tcase(suite, pos);

    TCase *neg;
    neg = tcase_create("negative");
    tcase_add_test(neg, test_movies_read_no_file);
    tcase_add_test(neg, test_movies_read_empty);

    suite_add_tcase(suite, neg);

    return suite;
}

int run_check_movie()
{
    int failed = 0;
    Suite *s;
    SRunner *runner;

    s = test_str_to_field_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);

    s = test_movies_read_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);


    return EXIT_SUCCESS;
}

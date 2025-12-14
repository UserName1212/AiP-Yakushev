#include "test.h"
#include "functions.h"

MU_TEST(test_1) 
{
    int a = 1, b = 2;
    swap(&a, &b);
    mu_assert_int_eq(2, a);
    mu_assert_int_eq(1, b);
}

MU_TEST(test_2) 
{
    int a = 0, b = 0;
    swap(&a, &b);
    mu_assert_int_eq(0, a);
    mu_assert_int_eq(0, b);
}

MU_TEST(test_3)
{
    int a = -5, b = 5;
    swap(&a, &b);
    mu_assert_int_eq(5, a);
    mu_assert_int_eq(-5, b);
}

MU_TEST(test_4) 
{
    int a = -10, b = -5;
    swap(&a, &b);
    mu_assert_int_eq(-5, a);
    mu_assert_int_eq(-10, b);
}

MU_TEST(test_5) 
{
    int a = INT_MAX, b = 0;
    swap(&a, &b);
    mu_assert_int_eq(INT_MAX, b);
    mu_assert_int_eq(0, a);
}

MU_TEST(test_6) 
{
    int a = INT_MIN, b = INT_MAX;
    swap(&a, &b);
    mu_assert_int_eq(INT_MAX, a);
    mu_assert_int_eq(INT_MIN, b);
}

MU_TEST(test_7) 
{
    int a = 123, b = 0;
    swap(&a, &b);
    mu_assert_int_eq(0, a);
    mu_assert_int_eq(123, b);
}

MU_TEST(test_8) 
{
    int a = -110, b = 210;
    swap(&a, &b);
    mu_assert_int_eq(210, a);
    mu_assert_int_eq(-110, b);
}

MU_TEST(test_9) 
{
    int a = INT_MAX - 1, b = INT_MIN + 2;
    swap(&a, &b);
    mu_assert_int_eq(INT_MIN + 2, a);
    mu_assert_int_eq(INT_MAX - 1, b);
}

MU_TEST(test_10) 
{
    int a = 1.6, b = 5;
    swap(&a, &b);
    mu_assert_int_eq(5, a);
    mu_assert_int_eq(1, b);
}

MU_TEST(test_start_year) 
{
    unsigned week;
    enum DayType day;

    int res = transfrom(2024, 1, 1, &week, &day);

    mu_assert_int_eq(0, res);
    mu_assert_int_eq(1, week);
    mu_assert_int_eq(MON, day);
}

MU_TEST(test_leap_day) 
{
    unsigned week;
    enum DayType day;

    int res = transfrom(2024, 2, 29, &week, &day);

    mu_assert_int_eq(0, res);
}

MU_TEST(test_end_of_year)
{
    unsigned week;
    enum DayType day;

    int res = transfrom(2023, 12, 31, &week, &day);

    mu_assert_int_eq(0, res);
    mu_assert(week >= 1 && week <= 53, "");
}

MU_TEST(test_invalid_month)
{
    unsigned week;
    enum DayType day;

    int res = transfrom(2023, 13, 1, &week, &day);

    mu_assert_int_eq(-1, res);
}

MU_TEST(test_invalid_day)
{
    unsigned week;
    enum DayType day;

    int res = transfrom(2023, 2, 30, &week, &day);

    mu_assert_int_eq(-1, res);
}



void run_tests(void) {
    MU_RUN_TEST(test_1);
    MU_RUN_TEST(test_2);
    MU_RUN_TEST(test_3);
    MU_RUN_TEST(test_4);
    MU_RUN_TEST(test_5);
    MU_RUN_TEST(test_6);
    MU_RUN_TEST(test_7);
    MU_RUN_TEST(test_8);
    MU_RUN_TEST(test_9);
    MU_RUN_TEST(test_10);
    //tasks 8
    MU_RUN_TEST(test_start_year);
    MU_RUN_TEST(test_leap_day);
    MU_RUN_TEST(test_end_of_year);
    MU_RUN_TEST(test_invalid_month);
    MU_RUN_TEST(test_invalid_day);
    MU_REPORT();
}

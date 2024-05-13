/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for string put format function
*/

#include <stdio.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "pf.h"
#include "str.h"

Test(fpf_tests, fpf_complex_tests, .init = cr_redirect_stdout)
{
    char *format = "My name is %s, I'm %i years old and I'm %f meters tall\n";
    char *expected = "My name is John, I'm 42 years old and I'm 1.7500 meters tall\n";
    
    fpf(1, format, "John", 42, 1.75);
    cr_assert_stdout_eq_str(expected, "fpf(1, format, \"John\", 42, 1.75) != expected");
}

Test(fpf_tests, fpf_simple_tests, .init = cr_redirect_stdout)
{
    char *format = "[%i; %i] is %s. %s have %d %s. ID = %c\n";
    char *expected = "[123; 456] is Hello. World have 1.2300 seconds. ID = X\n";
    
    fpf(1, format, 123, 456, "Hello", "World", 1.23, "seconds", 'X');
    cr_assert_stdout_eq_str(expected, "fpf(1, format, 123, 456, \"Hello\", \"World\", 1.23, \"seconds\", 'X') != expected");
}

Test(fpf_tests, fpf_empty_tests, .init = cr_redirect_stdout)
{
    char *format = "[%i; %i] is %s. %s have %d %s. ID = %c\n";
    char *expected = "[0; 0] is .  have 0.0000 . ID =  \n";
    
    fpf(1, format, 0, 0, "", "", 0.0, "", ' ');
    cr_assert_stdout_eq_str(expected, "fpf(1, format, \"\", \"\", \"\", \"\", \"\", \"\", \"\") != expected");
}

Test(fpf_tests, opf_tests, .init = cr_redirect_stdout)
{
    char *format = "[%i; %i] is %s. %s have %d %s. ID = %c\n";
    char *expected = "[123; 456] is Hello. World have 1.2300 seconds. ID = X\n";
    
    opf(format, 123, 456, "Hello", "World", 1.23, "seconds", 'X');
    cr_assert_stdout_eq_str(expected, "opf(format, 123, 456, \"Hello\", \"World\", 1.23, \"seconds\", 'X') != expected");
}

Test(fpf_tests, epf_tests, .init = cr_redirect_stderr)
{
    char *format = "[%i; %i] is %s. %s have %d %s. ID = %c\n";
    char *expected = "[123; 456] is Hello. World have 1.2300 seconds. ID = X\n";
    
    epf(format, 123, 456, "Hello", "World", 1.23, "seconds", 'X');
    cr_assert_stderr_eq_str(expected, "epf(format, 123, 456, \"Hello\", \"World\", 1.23, \"seconds\", 'X') != expected");
}
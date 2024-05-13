/*
** EPITECH PROJECT, 2023
** Public_Library
** File description:
** Base tests for type length
*/

#include <criterion/criterion.h>
#include "str.h"

Test(schange_tests, sswapc_tests)
{
    char str[60] = "Hello World!";
    char *str2 = "Hella Warld!";
    char *str3 = "Heaaa Warad!";
    char *str4 = "Heaaa";

    sswapc(str, 'o', 'a');
    cr_assert_str_eq(str, str2, "sswapc(\"Hello World!\", 'o', 'a') != \"Hella Warld!\", str = %s", str);
    sswapc(str, 'l', 'a');
    cr_assert_str_eq(str, str3, "sswapc(\"Hella Warld!\", 'l', 'a') != \"Heaaa Warad!\", str = %s", str);
    sswapc(str, ' ', '\0');
    cr_assert_str_eq(str, str4, "sswapc(\"Heaaa Warad!\", ' ', '\\0') != \"Heaaa\", str = %s", str);
}

Test(schange_tests, sswaps_tests1)
{
    char str[60] = "Hello World!";
    char *str2 = "Hello Hello!";

    sswaps(str, "World", "Hello");
    cr_assert_str_eq(str, str2, "sswaps(\"Hello World!\", \"World\", \"Hello\") != \"Hello Hello!\", str = %s", str);
}

Test(schange_tests, sswaps_tests2)
{
    char str[60] = "Hello World!";
    char *str2 = "Hello Wollo!";

    sswaps(str, "rld", "llo");
    cr_assert_str_eq(str, str2, "sswaps(\"Hello World!\", \"rld\", \"llo\") != \"Hello Wollo!\", str = %s", str);
}

Test(schange_tests, sswaps_tests3)
{
    char str[60] = "!mic,?.mac_56";
    char *str2 = "5656";

    sswaps(str, "!mic,?.mac_", "56");
    cr_assert_str_eq(str, str2, "sswaps(\"!mic,?.mac_56\", \"!mic,?.mac_\", \"56\") != \"5655\", str = %s", str);
}

Test(schange_tests, sslice_tests1)
{
    char str[60] = "Hello World!";
    char **tab = sslice(str, " ");

    cr_assert_str_eq(tab[0], "Hello", "sslice(\"Hello World!\", \" \")[0] != \"Hello\", tab[0] = %s", tab[0]);
    cr_assert_str_eq(tab[1], "World!", "sslice(\"Hello World!\", \" \")[1] != \"World!\", tab[1] = %s", tab[1]);
}

Test(schange_tests, sslice_tests2)
{
    char lstr[60] = "Hello\nWorld\nYes\nNo\n.\0";
    char **tab = sslice(lstr, "\n");

    cr_assert_str_eq(tab[0], "Hello", "sslice(\"Hello\\nWorld\\nYes\\nNo\\n.\", \"\\n\")[0] != \"Hello\", tab[0] = %s", tab[0]);
    cr_assert_str_eq(tab[1], "World", "sslice(\"Hello\\nWorld\\nYes\\nNo\\n.\", \"\\n\")[1] != \"World\", tab[1] = %s", tab[1]);
    cr_assert_str_eq(tab[2], "Yes", "sslice(\"Hello\\nWorld\\nYes\\nNo\\n.\", \"\\n\")[2] != \"Yes\", tab[2] = %s", tab[2]);
    cr_assert_str_eq(tab[3], "No", "sslice(\"Hello\\nWorld\\nYes\\nNo\\n.\", \"\\n\")[3] != \"No\", tab[3] = %s", tab[3]);
    cr_assert_str_eq(tab[4], ".", "sslice(\"Hello\\nWorld\\nYes\\nNo\\n.\", \"\\n\")[4] != \".\", tab[4] = %s", tab[4]);
}

Test(schange_tests, sslice_tests3)
{
    char str[60] = "Hello World!";
    char **tab = sslice(str, "World");

    cr_assert_str_eq(tab[0], "Hello ", "sslice(\"Hello World!\", \"World\")[0] != \"Hello \", tab[0] = %s", tab[0]);
    cr_assert_str_eq(tab[1], "!", "sslice(\"Hello World!\", \"World\")[1] != \"!\", tab[1] = %s", tab[1]);
}
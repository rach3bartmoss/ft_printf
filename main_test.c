/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:35:40 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/14 00:19:48 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main()
{
    // Basic tests
    printf("printf:    %%d: ");
    printf("%d\n", 42);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", 42);

    printf("printf:    %%i: ");
    printf("%i\n", INT_MIN);
    ft_printf("ft_printf: %%i: ");
    ft_printf("%i\n\n", INT_MIN);

    printf("printf:    %%d: ");
    printf("%d\n", INT_MIN);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", INT_MIN);

    printf("printf:    %%u: 'uint_max'");
    printf("%u\n", UINT_MAX);
    ft_printf("ft_printf: %%u: 'uint_max'");
    ft_printf("%u\n\n", UINT_MAX);

    char *a = NULL;
    printf("printf:    %%s: ");
    printf("%s\n", "42");
    ft_printf("ft_printf: %%s: ");
    ft_printf("%s\n\n", a);

    printf("printf:    %%x: ");
    printf("%x\n", 255);
    ft_printf("ft_printf: %%x: ");
    ft_printf("%x\n\n", 255);

    printf("printf:    %%X: ");
    printf("%X\n", 255);
    ft_printf("ft_printf: %%X: ");
    ft_printf("%X\n\n", 255);

    printf("printf:    %%c: ");
    printf("%c\n", 'A');
    ft_printf("ft_printf: %%c: ");
    ft_printf("%c\n\n", 'A');


    printf("printf:    %%5c: ");
    printf("%5c\n", 'A');
    ft_printf("ft_printf: %%5c: ");
    ft_printf("%5c\n\n", 'A');

    printf("printf:    %%s: ");
    printf("%s\n", "Hello");
    ft_printf("ft_printf: %%s: ");
    ft_printf("%s\n\n", "Hello");

    int n = 42;
    printf("printf:    %%p: ");
    printf("%p\n", (void*)&n);
    ft_printf("ft_printf: %%p: ");
    ft_printf("%p\n\n", (void*)&n);
    printf("printf null pointer:   %%p: ");
    printf("%p\n", NULL);
    ft_printf("ft_printf null pointer:%%p: ");
    ft_printf("%p\n\n", NULL);


    // Width tests
    printf("printf:    %%5d: ");
    printf("%5d\n", 42);
    ft_printf("ft_printf: %%5d: ");
    ft_printf("%5d\n\n", 42);

    printf("printf:    %%-5d: ");
    printf("%-5d\n", 42);
    ft_printf("ft_printf: %%-5d: ");
    ft_printf("%-5d\n\n", 42);

    // Precision tests
    printf("printf:    %%.5s: ");
    printf("%.5s\n", "Hello, world!");
    ft_printf("ft_printf: %%.5s: ");
    ft_printf("%.5s\n\n", "Hello, world!");

    // Flag tests
    printf("printf:    %%+d: ");
    printf("%+d\n", 42);
    ft_printf("ft_printf: %%+d: ");
    ft_printf("%+d\n\n", 42);

    printf("printf:    %% d: ");
    printf("% d\n", 42);
    ft_printf("ft_printf: %% d: ");
    ft_printf("% d\n\n", 42);

    printf("printf:    %%#x: ");
    printf("%#x\n", 255);
    ft_printf("ft_printf: %%#x: ");
    ft_printf("%#x\n\n", 255);

    // Zero-padding
    printf("printf:    %%05d: ");
    printf("%05d\n", 42);
    ft_printf("ft_printf: %%05d: ");
    ft_printf("%05d\n\n", 42);

    // Negative numbers
    printf("printf:    %%d: ");
    printf("%d\n", -42);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", -42);

    // Combination of flags and width
    printf("printf:    %%+10d: ");
    printf("%+10d\n", 42);
    ft_printf("ft_printf: %%+10d: ");
    ft_printf("%+10d\n\n", 42);

    // Escape character
    printf("printf:    %%%%: ");
    printf("%%\n");
    ft_printf("ft_printf: %%%%: ");
    ft_printf("%%\n\n");

    printf("(printf)Further tests below:\n\n");
    ft_printf("(ft_printf)Further tests below: \n\n");

    //Combining width, precision and flags
    printf("printf:    %%10.5d: ");
    printf("%10.5d\n", 123);
    ft_printf("ft_printf: %%10.5d: ");
    ft_printf("%10.5d\n\n", 123);

    //Testing with different lenght modifiers
    /*printf("printf:    %%ld: ");
    printf("%ld\n", 1234567890L);
    ft_printf("ft_printf: %%ld: ");
    ft_printf("%ld\n\n", 1234567890L);

    printf("printf:    %%hd: ");
    printf("%hd\n", (short)32767);
    ft_printf("ft_printf: %%hd: ");
    ft_printf("%hd\n\n", (short)32767);
*/
    //Testing with zero padding and left-align
    printf("printf:    %%0+10d: ");
    printf("%0+10d\n", 42);
    ft_printf("ft_printf: %%0+10d: ");
    ft_printf("%0+10d\n\n", 42);

    printf("printf:    %%-10.5s: ");
    printf("%-10.5s\n", "Hello, world!");
    ft_printf("ft_printf: %%-10.5s: ");
    ft_printf("%-10.5s\n\n", "Hello, world!");

    //Testing with space flag and precision:
    printf("printf:    %% .5d: ");
    printf("% .5d\n", 2077);
    ft_printf("ft_printf: %% .5d: ");
    ft_printf("% .5d\n\n", 2077);

    //Testing with hash flags for different bases
  /*  printf("printf:    %%#o: ");
    printf("%#o\n", 42);
    ft_printf("ft_printf: %%#o: ");
    ft_printf("%#o\n\n", 42);
*/
    printf("printf: %%#X: ");
    printf("%#X\n", 2077);
    ft_printf("ft_printf: %%#X: ");
    ft_printf("%#X\n\n", 2077);

    printf("EVEN FURTHER TESTS:\n\n");
     
	    //testing with multiples format specifiers in one call:
     printf("printf:    Multiple: ");
     printf("%d %s %c %f\n", 42, "test", 'X', 3.14159);
     ft_printf("ft_printf: Multiple: ");
     ft_printf("%d %s %c\n\n", 42, "test", 'X');

     printf("printf:    Multiple specifiers: %d %s %c %x\n", 42, "test", 'A', 255);
     ft_printf("ft_printf: Multiple specifiers: %d %s %c %x\n\n", 42, "test", 'A', 255);

     printf("printf:    Mixed flags: %+d % d %05d %#x\n", 42, -42, 123, 255);
     ft_printf("ft_printf: Mixed flags: %+d % d %05d %#x\n\n", 42, -42, 123, 255);

     printf("printf:    Width and precision: %10.5d %8.3s\n", 123, "hello");
     ft_printf("ft_printf: Width and precision: %10.5d %8.3s\n\n", 123, "hello");

     printf("printf:    Left-aligned: %-10d %-10s\n", 42, "left");
     ft_printf("ft_printf: Left-aligned: %-10d %-10s\n\n", 42, "left");

     //some paco bonus tests
     printf("SOME PACO BONUS TESTS:\n\n");

    printf("printf:    %%.p: ");
    printf("%p\n", NULL);
    ft_printf("ft_printf: %%.p: ");
    ft_printf("%.p\n\n", NULL);

    printf("printf:    %%.s: ");
    printf("%.s\n", "hello");
    ft_printf("ft_printf: %%.s: ");
    ft_printf("%.s\n\n", "hello");

    printf("printf:    %%.3s: ");
    printf("%.3s\n", "hello");
    ft_printf("ft_printf: %%.3s: ");
    ft_printf("%.3s\n\n", "hello");

    printf("printf:    %%.10s: ");
    printf("%.10s\n", "hello");
    ft_printf("ft_printf: %%.10s: ");
    ft_printf("%.10s\n\n", "hello");

    printf("printf:    %%10.s: ");
    printf("%10.s\n", "hello");
    ft_printf("ft_printf: %%10.s: ");
    ft_printf("%10.s\n\n", "hello");

    printf("printf:    %%-10.s: ");
    printf("%-10.s\n", "hello");
    ft_printf("ft_printf: %%-10.s: ");
    ft_printf("%-10.s\n\n", "hello");

    printf("printf:    %%.03s: ");
    printf("%.03s\n", "hello");
    ft_printf("ft_printf: %%.03s: ");
    ft_printf("%.03s\n\n", "hello");

    printf("printf:    %%6.3s: ");
    printf("%6.3s\n", "hello");
    ft_printf("ft_printf: %%6.3s: ");
    ft_printf("%6.3s\n\n", "hello");

    printf("printf:    %%-6.3s: ");
    printf("%-6.3s\n", "hello");
    ft_printf("ft_printf: %%-6.3s: ");
    ft_printf("%-6.3s\n\n", "hello");

    ft_printf("****TEST SOME MIXED FLAGS VARIATIONS****\n\n\n");

    // Testing precision with different types
    printf("printf:    %%5.2d: ");
    printf("%5.2d\n", 123);
    ft_printf("ft_printf: %%5.2d: ");
    ft_printf("%5.2d\n\n", 123);

    printf("printf:    %%5.2u: ");
    printf("%5.2u\n", 123);
    ft_printf("ft_printf: %%5.2u: ");
    ft_printf("%5.2u\n\n", 123);

    // Testing zero-padding with precision
    printf("printf:    %%2d: ");
    printf("%10d\n", 123);
    ft_printf("ft_printf: %%2d: ");
    ft_printf("%10d\n\n", 123);

    int num = 42;
    
    // Printing with different precisions
    printf("***printf below***:\n");
    printf("Default: %d\n", num);
    printf("Precision 5: %-10.5d\n", num);
    printf("Precision 3: %+5.3d\n", num);
    printf("Precision 1: %.1d\n\n", num);
    ft_printf("***ft_printf below***\n");
    ft_printf("Default: %d\n", num);
    ft_printf("Precision 5: %-10.5d\n", num);
    ft_printf("Precision 3: %+5.3d\n", num);
    ft_printf("Precision 1: %.1d\n\n", num);

    // Testing with very large width and small precision
    printf("printf:    %%20.2s: ");
    printf("%20.2s\n", "Hello");
    ft_printf("ft_printf: %%20.2s: ");
    ft_printf("%20.2s\n\n", "Hello");

    // Testing with zero precision
    printf("printf:    %%.0d: ");
    printf("%.0d\n", 0);
    ft_printf("ft_printf: %%.0d: ");
    ft_printf("%.0d\n\n", 0);

    // Testing with zero precision and non-zero value
    printf("printf:    %%.0d: ");
    printf("%.0d\n", 1);
    ft_printf("ft_printf: %%.0d: ");
    ft_printf("%.0d\n\n", 1);

    // Testing with precision for pointer
    printf("printf:    %%15p: ");
    printf("%15p\n", NULL);
    ft_printf("ft_printf: %%15p: ");
    ft_printf("%15p\n\n", NULL);

    // Testing with negative numbers and different flags
    printf("printf:    %% d: ");
    printf("% d\n", -42);
    ft_printf("ft_printf: %% d: ");
    ft_printf("% d\n\n", -42);

    printf("printf:    %%+d: ");
    printf("%+d\n", -42);
    ft_printf("ft_printf: %%+d: ");
    ft_printf("%+d\n\n", -42);

    printf("*****PRINT_INT MAX/MIN TESTING*****\n\n");
    // Testing with very large numbers
    printf("printf:    %%d: ");
    printf("%d\n", INT_MAX);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", INT_MAX);

    printf("printf:    %%d: ");
    printf("%d\n", -2147483647);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", -2147483647);

    printf("*****HEXA-D WITH UNUSUAL FLAGS******\n\n");
    // Testing with unusual flag combinations
    printf("printf:    %%#08x: ");
    printf("%#08x\n", 42);
    ft_printf("ft_printf: %%#08x: ");
    ft_printf("%#08x\n\n", 42);

    printf("printf:    %%-#8x: ");
    printf("%-#8x\n", 42);
    ft_printf("ft_printf: %%-#8x: ");
    ft_printf("%-#8x\n\n", 42);

    printf("******STRING EDGE CASES TESTING******\n\n");
    // Testing with strings containing % character
    printf("printf:    %%s: ");
    printf("%s\n", "50% off!");
    ft_printf("ft_printf: %%s: ");
    ft_printf("%s\n\n", "50% off!");

    // Testing with empty string
    printf("printf:    %%s: ");
    printf("%s\n", "");
    ft_printf("ft_printf: %%s: ");
    ft_printf("%s\n\n", "");

    printf("printf:    %%.20s: ");
    printf("%.20s\n", "Hello");
    ft_printf("ft_printf: %%.20s: ");
    ft_printf("%.20s\n\n", "Hello");

    char    *d = NULL;
    printf("printf:    %%.6s: ");
    printf("%.6s\n", d);
    ft_printf("ft_printf: %%.6s: ");
    ft_printf("%.6s\n\n", d);

    printf("printf:    %%.s: ");
    printf("%.s\n", d);
    ft_printf("ft_printf: %%.s: ");
    ft_printf("%.s\n\n", d);

    printf("printf:    %%.15s: ");
    printf("%.15s\n", d);
    ft_printf("ft_printf: %%.15s: ");
    ft_printf("%.15s\n\n", d);

    printf("printf:    %%s: ");
    printf("%s\n", "(null)");
    ft_printf("ft_printf: %%s: ");
    ft_printf("%s\n\n", d);

    /*printf("********PRINT_INT TESTING***********\n\n");
    printf("printf:    %%d: ");
    printf("%d\n", INT_MIN);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", INT_MIN);

    printf("printf:    %%-d: ");
    printf("%-d\n", INT_MIN);
    ft_printf("ft_printf: %%-d: ");
    ft_printf("%-d\n\n", INT_MIN);

    printf("printf:    %%04d: ");
    printf("%04d\n", INT_MIN);
    ft_printf("ft_printf: %%04d: ");
    ft_printf("%04d\n\n", INT_MIN);

    printf("printf:    %%04d: ");
    printf("%04d\n", 42);
    ft_printf("ft_printf: %%04d: ");
    ft_printf("%04d\n\n", 42);

    printf("printf:    %%04d: ");
    printf("%04d\n", 20777);
    ft_printf("ft_printf: %%04d: ");
    ft_printf("%04d\n\n", 20777);

    printf("printf:    %%.10d: ");
    printf("[%.10d]\n", INT_MIN);
    ft_printf("ft_printf: %%.10d: ");
    ft_printf("[%.10d]\n\n", INT_MIN);

    printf("printf:    %%.5d: ");
    printf("[%.5d]\n", INT_MIN);
    ft_printf("ft_printf: %%.5d: ");
    ft_printf("[%.5d]\n\n", INT_MIN);

    printf("printf:    %%20.5d: ");
    printf("[%20.5d]\n", INT_MIN);
    ft_printf("ft_printf: %%20.5d: ");
    ft_printf("[%20.5d]\n\n", INT_MIN);

    printf("printf:    %%15d: ");
    printf("[%15d]\n", INT_MIN);
    ft_printf("ft_printf: %%15d: ");
    ft_printf("[%15d]\n\n", INT_MIN);

    printf("printf:    %%20d: ");
    printf("[%20d]\n", -2147483000);
    ft_printf("ft_printf: %%20d: ");
    ft_printf("[%20d]\n\n", -2147483000);

    printf("printf:    %%12d: ");
    printf("[%12d]\n", (int)-2147483648);
    ft_printf("ft_printf: %%12d: ");
    ft_printf("[%12d]\n\n", (int)-2147483648);

    printf("printf:    %%.0d: ");
    printf("[%.0d]\n", 42000);
    ft_printf("ft_printf: %%.0d: ");
    ft_printf("[%.0d]\n\n", 42000);

    printf("printf:    %%-10.5d: ");
    printf("[%-10.5d]\n", INT_MIN);
    ft_printf("ft_printf: %%-10.5d: ");
    ft_printf("[%-10.5d]\n\n", INT_MIN);

    printf("printf:    %%030d: ");
    printf("[%030d]\n", INT_MIN);
    ft_printf("ft_printf: %%030d: ");
    ft_printf("[%030d]\n\n", INT_MIN);

    printf("printf:    %%012d: ");
    printf("[%012d]\n", INT_MIN);
    ft_printf("ft_printf: %%012d: ");
    ft_printf("[%012d]\n\n", INT_MIN);*/

printf("\n*****************************************\n");
/*
    printf("********STRINGS TESTING***********\n\n");
    printf("printf:    %%-25s: hello");
    printf("%-25s\n", "hello");
    ft_printf("ft_printf: %%-25s: hello");
    ft_printf("%-25s\n\n", "hello");

    printf("printf:    %%1s: hello");
    printf("%1s\n", "hello");
    ft_printf("ft_printf: %%1s: hello");
    ft_printf("%1s\n\n", "hello");

    printf("********POINTERS TESTING***********\n\n");
    int m = 3000;
    printf("printf:    %%3p: ");
    printf("%3p\n", (void*)&m);
    ft_printf("ft_printf: %%3p: ");
    ft_printf("%3p\n\n", (void*)&m);

    int o = 3000;
    printf("printf:    %%-3p: ");
    printf("%-p\n", (void*)&o);
    ft_printf("ft_printf: %%-3p: ");
    ft_printf("%-3p\n\n", (void*)&o);

    printf("printf null pointer:   %%p: ");
    printf("%p\n", NULL);
    ft_printf("ft_printf null pointer:%%p: ");
    ft_printf("%p\n\n", NULL);

    printf("printf null pointer:   %%8p: ");
    printf("[the address is %8p]\n", (void *)0);
    ft_printf("ft_printf null pointer:%%8p: ");
    ft_printf("[the address is %8p]\n\n", (void *)0);

    printf("printf null pointer:   %%-8p: ");
    printf("[the address is %-8p]\n", (void *)0);
    ft_printf("ft_printf null pointer:%%-8p: ");
    ft_printf("[the address is %-8p]\n\n", (void *)0);

    printf("printf null pointer:   %%-25p: ");
    printf("[the address is %25p]\n", &o);
    ft_printf("ft_printf null pointer:%%-25p: ");
    ft_printf("[the address is %25p]\n\n", &o);
*/
    return 0;
}

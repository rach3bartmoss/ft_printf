/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 01:35:40 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/01 23:32:10 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Basic tests
    printf("printf:    %%d: ");
    printf("%d\n", 42);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", 42);

    printf("printf:    %%i: ");
    printf("%i\n", -2147483647);
    ft_printf("ft_printf: %%i: ");
    ft_printf("%i\n\n", -2147483647);

    printf("printf:    %%u: ");
    printf("%u\n", 42U);
    ft_printf("ft_printf: %%u: ");
    ft_printf("%u\n\n", 42U);

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

    ft_printf("ADD TESTS FOR MORE MIXED FLAGS VARIATIONS\n\n\n");

    printf("\nADDITIONAL TESTS:\n\n");

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
    printf("printf:    %%5.2d: ");
    printf("%5.2d\n", 123);
    ft_printf("ft_printf: %%5.2d: ");
    ft_printf("%5.2d\n\n", 123);

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

    // Testing with very large numbers
    printf("printf:    %%d: ");
    printf("%d\n", 2147483647);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", 2147483647);

    printf("printf:    %%d: ");
    printf("%d\n", -2147483647);
    ft_printf("ft_printf: %%d: ");
    ft_printf("%d\n\n", -2147483647);

    // Testing with unusual flag combinations
    printf("printf:    %%#08x: ");
    printf("%#08x\n", 42);
    ft_printf("ft_printf: %%#08x: ");
    ft_printf("%#08x\n\n", 42);

    printf("printf:    %%-#8x: ");
    printf("%-#8x\n", 42);
    ft_printf("ft_printf: %%-#8x: ");
    ft_printf("%-#8x\n\n", 42);

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

    // Testing with precision larger than string length
    printf("printf:    %%.20s: ");
    printf("%.20s\n", "Hello");
    ft_printf("ft_printf: %%.20s: ");
    ft_printf("%.20s\n\n", "Hello");
    return 0;
}

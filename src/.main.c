/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .main.c                                                    _             */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 15:10:52 by jodos-sa          #+#    #+#             */
/*   Updated: 2026/01/03 14:01:57 by jodos-sa                                 */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <inttypes.h>
#include <stddef.h>

#define TEST(name, format, ...) do { \
	printf("Test: %s\n", name); \
	int og = printf("OG: " format, ##__VA_ARGS__); \
	int ft = ft_printf("FT: " format, ##__VA_ARGS__); \
	if (og == ft) printf("✅ OK\n\n"); \
	else printf("❌ KO | OG: %d, FT: %d\n\n", og, ft); \
} while(0)

/* ========== BASIC CONVERSIONS ========== */

void test_char(void)
{
	printf("--- Testing %%c (char) ---\n");
	TEST("Basic 'A'", "%c\n", 'A');
	TEST("Digit '0'", "%c\n", '0');
	TEST("Null char", "%c\n", '\0');
	TEST("Newline", "%c\n", '\n');
	TEST("With width %5c", "|%5c|\n", 'X');
	TEST("Left align %-5c", "|%-5c|\n", 'X');
	TEST("Multiple %c%c%c", "%c%c%c\n", 'a', 'b', 'c');
}

void test_string(void)
{
	printf("--- Testing %%s (string) ---\n");
	TEST("Basic string", "%s\n", "Hello, world!");
	TEST("Empty string", "%s\n", "");
	TEST("NULL string", "%s\n", (char *)NULL);
	TEST("With width %20s", "|%20s|\n", "test");
	TEST("Left align %-20s", "|%-20s|\n", "test");
	TEST("Precision %.5s", "|%.5s|\n", "Hello World");
	TEST("Width+Precision %15.5s", "|%15.5s|\n", "Hello World");
	TEST("Precision .0s", "|%.0s|\n", "Hidden");
	TEST("NULL with precision %.5s", "|%.5s|\n", (char *)NULL);
	TEST("Long string %50s", "|%50s|\n", "This is a longer test string");
}

void test_pointer(void)
{
	printf("--- Testing %%p (pointer) ---\n");
	int a = 42;
	TEST("Valid pointer", "%p\n", &a);
	TEST("NULL pointer", "%p\n", NULL);
	TEST("With width %20p", "|%20p|\n", &a);
	TEST("Left align %-20p", "|%-20p|\n", &a);
	TEST("Max address", "%p\n", (void *)0x7fffffffffffffff);
	TEST("Low address", "%p\n", (void *)0x1);
}

void test_decimal(void)
{
	printf("--- Testing %%d and %%i (decimal) ---\n");
	TEST("Positive 42", "%d %i\n", 42, 42);
	TEST("Negative -42", "%d %i\n", -42, -42);
	TEST("Zero", "%d %i\n", 0, 0);
	TEST("INT_MAX", "%d %i\n", INT_MAX, INT_MAX);
	TEST("INT_MIN", "%d %i\n", INT_MIN, INT_MIN);
	TEST("Multiple", "%d %d %d\n", 1, 2, 3);
}

void test_unsigned(void)
{
	printf("--- Testing %%u (unsigned) ---\n");
	TEST("Zero", "%u\n", 0);
	TEST("Positive 42", "%u\n", 42);
	TEST("UINT_MAX", "%u\n", UINT_MAX);
	TEST("Cast negative", "%u\n", -1);
	TEST("With width %10u", "|%10u|\n", 42);
	TEST("With precision %.5u", "|%.5u|\n", 42);
}

void test_hex(void)
{
	printf("--- Testing %%x and %%X (hexadecimal) ---\n");
	TEST("Zero", "%x %X\n", 0, 0);
	TEST("Lowercase 42", "%x\n", 42);
	TEST("Uppercase 42", "%X\n", 42);
	TEST("255", "%x %X\n", 255, 255);
	TEST("UINT_MAX", "%x %X\n", UINT_MAX, UINT_MAX);
	TEST("Negative cast", "%x\n", -1);
}

void test_percent(void)
{
	printf("--- Testing %%%% (percent) ---\n");
	TEST("Single %%", "%%\n");
	TEST("Multiple %%%%%%", "%%%%%%\n");
	TEST("With text", "50%% complete\n");
	TEST("Multiple in string", "%%d %%s %%x\n");
}

void test_octal(void)
{
	printf("--- Testing %%o (octal) ---\n");
	TEST("Zero", "%o\n", 0);
	TEST("Positive 42", "%o\n", 42);
	TEST("Octal 8", "%o\n", 8);
	TEST("Octal 64", "%o\n", 64);
	TEST("UINT_MAX", "%o\n", UINT_MAX);
	TEST("Cast negative", "%o\n", -1);
	TEST("With width %10o", "|%10o|\n", 42);
	TEST("With precision %.5o", "|%.5o|\n", 42);
	TEST("Hash with octal %#o", "%#o\n", 42);
	TEST("Hash with zero %#o", "%#o\n", 0);
	TEST("Hash+width %#10o", "|%#10o|\n", 42);
	TEST("Hash+zero %#010o", "|%#010o|\n", 42);
	TEST("Hash+precision %#.10o", "|%#.10o|\n", 42);
}

void test_ll_modifier(void)
{
	printf("--- Testing 'll' Length Modifier (long long) ---\n");
	long long ll_max = 9223372036854775807LL;
	long long ll_min = -9223372036854775807LL - 1;
	unsigned long long ull_max = 18446744073709551615ULL;
	long long zero = 0LL;
	long long pos = 1234567890123LL;
	long long neg = -9876543210987LL;
	
	TEST("Basic %%lld positive", "|%lld|\n", pos);
	TEST("Basic %%lld negative", "|%lld|\n", neg);
	TEST("Basic %%lld zero", "|%lld|\n", zero);
	TEST("LLONG_MAX %%lld", "|%lld|\n", ll_max);
	TEST("LLONG_MIN %%lld", "|%lld|\n", ll_min);
	
	TEST("Basic %%lli positive", "|%lli|\n", pos);
	TEST("Basic %%lli negative", "|%lli|\n", neg);
	TEST("Basic %%lli zero", "|%lli|\n", zero);
	TEST("LLONG_MAX %%lli", "|%lli|\n", ll_max);
	TEST("LLONG_MIN %%lli", "|%lli|\n", ll_min);
	
	TEST("Basic %%llu", "|%llu|\n", (unsigned long long)pos);
	TEST("ULLONG_MAX %%llu", "|%llu|\n", ull_max);
	TEST("Cast negative %%llu", "|%llu|\n", (unsigned long long)neg);
	TEST("Zero %%llu", "|%llu|\n", (unsigned long long)zero);
	
	TEST("Hex %%llx lowercase", "|%llx|\n", (unsigned long long)pos);
	TEST("Hex %%llX uppercase", "|%llX|\n", (unsigned long long)pos);
	TEST("Hex ULLONG_MAX %%llx", "|%llx|\n", ull_max);
	TEST("Hex zero %%llx", "|%llx|\n", (unsigned long long)zero);
	TEST("Hex negative cast %%llx", "|%llx|\n", (unsigned long long)neg);
	
	TEST("Octal %%llo", "|%llo|\n", (unsigned long long)pos);
	TEST("Octal ULLONG_MAX", "|%llo|\n", ull_max);
	TEST("Octal zero", "|%llo|\n", (unsigned long long)zero);
	
	TEST("Width %%20lld", "|%20lld|\n", pos);
	TEST("Width %%25lld LLONG_MAX", "|%25lld|\n", ll_max);
	TEST("Width %%25lld LLONG_MIN", "|%25lld|\n", ll_min);
	TEST("Left align %%-20lld", "|%-20lld|\n", pos);
	TEST("Left align %%-25lld MIN", "|%-25lld|\n", ll_min);
	
	TEST("Precision %%.15lld", "|%.15lld|\n", pos);
	TEST("Precision %%.25lld MAX", "|%.25lld|\n", ll_max);
	TEST("Precision %%.25lld MIN", "|%.25lld|\n", ll_min);
	TEST("Precision %%.0lld zero", "|%.0lld|\n", zero);
	TEST("Precision %%.15llu", "|%.15llu|\n", (unsigned long long)pos);
	
	TEST("Plus %%+lld positive", "|%+lld|\n", pos);
	TEST("Plus %%+lld negative", "|%+lld|\n", neg);
	TEST("Plus %%+lld zero", "|%+lld|\n", zero);
	TEST("Plus %%+lld LLONG_MAX", "|%+lld|\n", ll_max);
	TEST("Plus %%+lld LLONG_MIN", "|%+lld|\n", ll_min);
	
	TEST("Space %% lld positive", "|% lld|\n", pos);
	TEST("Space %% lld negative", "|% lld|\n", neg);
	TEST("Space %% lld zero", "|% lld|\n", zero);
	TEST("Space %% lld LLONG_MAX", "|% lld|\n", ll_max);
	
	TEST("Hash %%#llx", "|%#llx|\n", (unsigned long long)pos);
	TEST("Hash %%#llX", "|%#llX|\n", (unsigned long long)pos);
	TEST("Hash %%#llo", "|%#llo|\n", (unsigned long long)pos);
	TEST("Hash %%#llx zero", "|%#llx|\n", (unsigned long long)zero);
	TEST("Hash %%#llo zero", "|%#llo|\n", (unsigned long long)zero);
	
	TEST("Zero pad %%020lld", "|%020lld|\n", pos);
	TEST("Zero pad %%025lld MAX", "|%025lld|\n", ll_max);
	TEST("Zero pad %%025lld MIN", "|%025lld|\n", ll_min);
	TEST("Zero pad %%020llu", "|%020llu|\n", (unsigned long long)pos);
	TEST("Zero pad %%020llx", "|%020llx|\n", (unsigned long long)pos);
	
	TEST("Width+Precision %%25.15lld", "|%25.15lld|\n", pos);
	TEST("Width+Precision %%30.25lld MAX", "|%30.25lld|\n", ll_max);
	TEST("Width+Precision %%30.25lld MIN", "|%30.25lld|\n", ll_min);
	TEST("Width+Prec+Plus %%+25.15lld", "|%+25.15lld|\n", pos);
	TEST("Width+Prec+Space %% 25.15lld", "|% 25.15lld|\n", pos);
	
	TEST("Left+Plus %%-+20lld", "|%-+20lld|\n", pos);
	TEST("Left+Space %%- 20lld", "|%- 20lld|\n", pos);
	TEST("Left+Prec %%-20.10lld", "|%-20.10lld|\n", pos);
	
	TEST("Hash+Zero %%#020llx", "|%#020llx|\n", (unsigned long long)pos);
	TEST("Hash+Width %%#25llx", "|%#25llx|\n", (unsigned long long)pos);
	TEST("Hash+Prec %%#.15llx", "|%#.15llx|\n", (unsigned long long)pos);
	TEST("Hash+Width+Prec %%#25.15llx", "|%#25.15llx|\n", (unsigned long long)pos);
	
	TEST("Complex %%+#025.15llx", "|%+#025.15llx|\n", (unsigned long long)pos);
	TEST("Complex %%-+25.15lld", "|%-+25.15lld|\n", pos);
	TEST("Complex %%- 25.15lld", "|%- 25.15lld|\n", pos);
	
	TEST("Multiple %%lld values", "%lld %lld %lld\n", pos, neg, zero);
	TEST("Multiple types", "%lld %llu %llx %llo\n", 
		pos, (unsigned long long)pos, (unsigned long long)pos, (unsigned long long)pos);
	TEST("Mixed with regular", "%d %lld %u %llu\n", 42, pos, 100, (unsigned long long)neg);
	
	TEST("Very large positive", "|%lld|\n", 9000000000000000000LL);
	TEST("Very large negative", "|%lld|\n", -9000000000000000000LL);
	TEST("Edge near max", "|%lld|\n", ll_max - 1);
	TEST("Edge near min", "|%lld|\n", ll_min + 1);
	
	TEST("All flags %%+#0- 30.20lld", "|%+#0- 30.20lld|\n", pos);
	TEST("Extreme width %%100lld", "|%100lld|\n", pos);
	TEST("Extreme prec %%.50lld", "|%.50lld|\n", pos);
	TEST("Both extreme %%100.50lld", "|%100.50lld|\n", ll_max);
}

void test_l_modifier(void)
{
	printf("--- Testing 'l' Length Modifier (long) ---\n");
	long l_max = 2147483647L;
	long l_min = -2147483648L;
	unsigned long ul_max = 4294967295UL;
	long zero = 0L;
	long pos = 123456789L;
	long neg = -987654321L;
	
	TEST("Basic %%ld positive", "|%ld|\n", pos);
	TEST("Basic %%ld negative", "|%ld|\n", neg);
	TEST("Basic %%ld zero", "|%ld|\n", zero);
	TEST("LONG_MAX %%ld", "|%ld|\n", l_max);
	TEST("LONG_MIN %%ld", "|%ld|\n", l_min);
	
	TEST("Basic %%li positive", "|%li|\n", pos);
	TEST("Basic %%li negative", "|%li|\n", neg);
	TEST("Basic %%li zero", "|%li|\n", zero);
	TEST("LONG_MAX %%li", "|%li|\n", l_max);
	TEST("LONG_MIN %%li", "|%li|\n", l_min);
	
	TEST("Basic %%lu", "|%lu|\n", (unsigned long)pos);
	TEST("ULONG_MAX %%lu", "|%lu|\n", ul_max);
	TEST("Cast negative %%lu", "|%lu|\n", (unsigned long)neg);
	TEST("Zero %%lu", "|%lu|\n", (unsigned long)zero);
	TEST("Large %%lu", "|%lu|\n", 4000000000UL);
	
	TEST("Hex %%lx lowercase", "|%lx|\n", (unsigned long)pos);
	TEST("Hex %%lX uppercase", "|%lX|\n", (unsigned long)pos);
	TEST("Hex ULONG_MAX %%lx", "|%lx|\n", ul_max);
	TEST("Hex zero %%lx", "|%lx|\n", (unsigned long)zero);
	TEST("Hex negative cast %%lx", "|%lx|\n", (unsigned long)neg);
	TEST("Hex large %%lx", "|%lx|\n", 4000000000UL);
	
	TEST("Octal %%lo", "|%lo|\n", (unsigned long)pos);
	TEST("Octal ULONG_MAX", "|%lo|\n", ul_max);
	TEST("Octal zero", "|%lo|\n", (unsigned long)zero);
	TEST("Octal large", "|%lo|\n", 4000000000UL);
	
	TEST("Width %%20ld", "|%20ld|\n", pos);
	TEST("Width %%15ld LONG_MAX", "|%15ld|\n", l_max);
	TEST("Width %%15ld LONG_MIN", "|%15ld|\n", l_min);
	TEST("Left align %%-20ld", "|%-20ld|\n", pos);
	TEST("Left align %%-15ld MIN", "|%-15ld|\n", l_min);
	
	TEST("Precision %%.10ld", "|%.10ld|\n", pos);
	TEST("Precision %%.15ld MAX", "|%.15ld|\n", l_max);
	TEST("Precision %%.15ld MIN", "|%.15ld|\n", l_min);
	TEST("Precision %%.0ld zero", "|%.0ld|\n", zero);
	TEST("Precision %%.12lu", "|%.12lu|\n", (unsigned long)pos);
	
	TEST("Plus %%+ld positive", "|%+ld|\n", pos);
	TEST("Plus %%+ld negative", "|%+ld|\n", neg);
	TEST("Plus %%+ld zero", "|%+ld|\n", zero);
	TEST("Plus %%+ld LONG_MAX", "|%+ld|\n", l_max);
	TEST("Plus %%+ld LONG_MIN", "|%+ld|\n", l_min);
	
	TEST("Space %% ld positive", "|% ld|\n", pos);
	TEST("Space %% ld negative", "|% ld|\n", neg);
	TEST("Space %% ld zero", "|% ld|\n", zero);
	TEST("Space %% ld LONG_MAX", "|% ld|\n", l_max);
	
	TEST("Hash %%#lx", "|%#lx|\n", (unsigned long)pos);
	TEST("Hash %%#lX", "|%#lX|\n", (unsigned long)pos);
	TEST("Hash %%#lo", "|%#lo|\n", (unsigned long)pos);
	TEST("Hash %%#lx zero", "|%#lx|\n", (unsigned long)zero);
	TEST("Hash %%#lo zero", "|%#lo|\n", (unsigned long)zero);
	
	TEST("Zero pad %%015ld", "|%015ld|\n", pos);
	TEST("Zero pad %%015ld MAX", "|%015ld|\n", l_max);
	TEST("Zero pad %%015ld MIN", "|%015ld|\n", l_min);
	TEST("Zero pad %%015lu", "|%015lu|\n", (unsigned long)pos);
	TEST("Zero pad %%015lx", "|%015lx|\n", (unsigned long)pos);
	
	TEST("Width+Precision %%20.10ld", "|%20.10ld|\n", pos);
	TEST("Width+Precision %%20.15ld MAX", "|%20.15ld|\n", l_max);
	TEST("Width+Precision %%20.15ld MIN", "|%20.15ld|\n", l_min);
	TEST("Width+Prec+Plus %%+20.10ld", "|%+20.10ld|\n", pos);
	TEST("Width+Prec+Space %% 20.10ld", "|% 20.10ld|\n", pos);
	
	TEST("Left+Plus %%-+15ld", "|%-+15ld|\n", pos);
	TEST("Left+Space %%- 15ld", "|%- 15ld|\n", pos);
	TEST("Left+Prec %%-15.8ld", "|%-15.8ld|\n", pos);
	
	TEST("Hash+Zero %%#015lx", "|%#015lx|\n", (unsigned long)pos);
	TEST("Hash+Width %%#20lx", "|%#20lx|\n", (unsigned long)pos);
	TEST("Hash+Prec %%#.10lx", "|%#.10lx|\n", (unsigned long)pos);
	TEST("Hash+Width+Prec %%#20.10lx", "|%#20.10lx|\n", (unsigned long)pos);
	
	TEST("Complex %%+#015.10lx", "|%+#015.10lx|\n", (unsigned long)pos);
	TEST("Complex %%-+20.10ld", "|%-+20.10ld|\n", pos);
	TEST("Complex %%- 20.10ld", "|%- 20.10ld|\n", pos);
	
	TEST("Multiple %%ld values", "%ld %ld %ld\n", pos, neg, zero);
	TEST("Multiple types", "%ld %lu %lx %lo\n", 
		pos, (unsigned long)pos, (unsigned long)pos, (unsigned long)pos);
	TEST("Mixed with regular", "%d %ld %u %lu\n", 42, pos, 100, (unsigned long)neg);
	
	TEST("Edge near max", "|%ld|\n", l_max - 1);
	TEST("Edge near min", "|%ld|\n", l_min + 1);
	TEST("Mid positive", "|%ld|\n", 1000000000L);
	TEST("Mid negative", "|%ld|\n", -1000000000L);
	
	TEST("All flags %%+#0- 25.15ld", "|%+#0- 25.15ld|\n", pos);
	TEST("Extreme width %%80ld", "|%80ld|\n", pos);
	TEST("Extreme prec %%.40ld", "|%.40ld|\n", pos);
	TEST("Both extreme %%80.40ld", "|%80.40ld|\n", l_max);
}

void test_h_modifier(void)
{
	printf("--- Testing 'h' Length Modifier (short) ---\n");
	short s_max = 32767;
	short s_min = -32768;
	unsigned short us_max = 65535;
	short zero = 0;
	short pos = 12345;
	short neg = -9876;
	int val = 70000;
	
	TEST("Basic %%hd positive", "|%hd|\n", pos);
	TEST("Basic %%hd negative", "|%hd|\n", neg);
	TEST("Basic %%hd zero", "|%hd|\n", zero);
	TEST("SHRT_MAX %%hd", "|%hd|\n", s_max);
	TEST("SHRT_MIN %%hd", "|%hd|\n", s_min);
	TEST("Truncate int %%hd", "|%hd|\n", val);
	
	TEST("Basic %%hi positive", "|%hi|\n", pos);
	TEST("Basic %%hi negative", "|%hi|\n", neg);
	TEST("Basic %%hi zero", "|%hi|\n", zero);
	TEST("SHRT_MAX %%hi", "|%hi|\n", s_max);
	TEST("SHRT_MIN %%hi", "|%hi|\n", s_min);
	TEST("Truncate int %%hi", "|%hi|\n", val);
	
	TEST("Basic %%hu", "|%hu|\n", (unsigned short)pos);
	TEST("USHRT_MAX %%hu", "|%hu|\n", us_max);
	TEST("Cast negative %%hu", "|%hu|\n", (unsigned short)neg);
	TEST("Zero %%hu", "|%hu|\n", (unsigned short)zero);
	TEST("Truncate int %%hu", "|%hu|\n", val);
	
	TEST("Hex %%hx lowercase", "|%hx|\n", (unsigned short)pos);
	TEST("Hex %%hX uppercase", "|%hX|\n", (unsigned short)pos);
	TEST("Hex USHRT_MAX %%hx", "|%hx|\n", us_max);
	TEST("Hex zero %%hx", "|%hx|\n", (unsigned short)zero);
	TEST("Hex negative cast %%hx", "|%hx|\n", (unsigned short)neg);
	TEST("Hex truncate %%hx", "|%hx|\n", val);
	
	TEST("Octal %%ho", "|%ho|\n", (unsigned short)pos);
	TEST("Octal USHRT_MAX", "|%ho|\n", us_max);
	TEST("Octal zero", "|%ho|\n", (unsigned short)zero);
	TEST("Octal truncate", "|%ho|\n", val);
	
	TEST("Width %%10hd", "|%10hd|\n", pos);
	TEST("Width %%10hd SHRT_MAX", "|%10hd|\n", s_max);
	TEST("Width %%10hd SHRT_MIN", "|%10hd|\n", s_min);
	TEST("Left align %%-10hd", "|%-10hd|\n", pos);
	TEST("Left align %%-10hd MIN", "|%-10hd|\n", s_min);
	
	TEST("Precision %%.8hd", "|%.8hd|\n", pos);
	TEST("Precision %%.8hd MAX", "|%.8hd|\n", s_max);
	TEST("Precision %%.8hd MIN", "|%.8hd|\n", s_min);
	TEST("Precision %%.0hd zero", "|%.0hd|\n", zero);
	TEST("Precision %%.8hu", "|%.8hu|\n", (unsigned short)pos);
	
	TEST("Plus %%+hd positive", "|%+hd|\n", pos);
	TEST("Plus %%+hd negative", "|%+hd|\n", neg);
	TEST("Plus %%+hd zero", "|%+hd|\n", zero);
	TEST("Plus %%+hd SHRT_MAX", "|%+hd|\n", s_max);
	TEST("Plus %%+hd SHRT_MIN", "|%+hd|\n", s_min);
	
	TEST("Space %% hd positive", "|% hd|\n", pos);
	TEST("Space %% hd negative", "|% hd|\n", neg);
	TEST("Space %% hd zero", "|% hd|\n", zero);
	TEST("Space %% hd SHRT_MAX", "|% hd|\n", s_max);
	
	TEST("Hash %%#hx", "|%#hx|\n", (unsigned short)pos);
	TEST("Hash %%#hX", "|%#hX|\n", (unsigned short)pos);
	TEST("Hash %%#ho", "|%#ho|\n", (unsigned short)pos);
	TEST("Hash %%#hx zero", "|%#hx|\n", (unsigned short)zero);
	TEST("Hash %%#ho zero", "|%#ho|\n", (unsigned short)zero);
	
	TEST("Zero pad %%08hd", "|%08hd|\n", pos);
	TEST("Zero pad %%08hd MAX", "|%08hd|\n", s_max);
	TEST("Zero pad %%08hd MIN", "|%08hd|\n", s_min);
	TEST("Zero pad %%08hu", "|%08hu|\n", (unsigned short)pos);
	TEST("Zero pad %%08hx", "|%08hx|\n", (unsigned short)pos);
	
	TEST("Width+Precision %%12.8hd", "|%12.8hd|\n", pos);
	TEST("Width+Precision %%12.8hd MAX", "|%12.8hd|\n", s_max);
	TEST("Width+Precision %%12.8hd MIN", "|%12.8hd|\n", s_min);
	TEST("Width+Prec+Plus %%+12.8hd", "|%+12.8hd|\n", pos);
	TEST("Width+Prec+Space %% 12.8hd", "|% 12.8hd|\n", pos);
	
	TEST("Left+Plus %%-+10hd", "|%-+10hd|\n", pos);
	TEST("Left+Space %%- 10hd", "|%- 10hd|\n", pos);
	TEST("Left+Prec %%-10.6hd", "|%-10.6hd|\n", pos);
	
	TEST("Hash+Zero %%#010hx", "|%#010hx|\n", (unsigned short)pos);
	TEST("Hash+Width %%#15hx", "|%#15hx|\n", (unsigned short)pos);
	TEST("Hash+Prec %%#.8hx", "|%#.8hx|\n", (unsigned short)pos);
	TEST("Hash+Width+Prec %%#15.8hx", "|%#15.8hx|\n", (unsigned short)pos);
	
	TEST("Complex %%+#010.8hx", "|%+#010.8hx|\n", (unsigned short)pos);
	TEST("Complex %%-+12.8hd", "|%-+12.8hd|\n", pos);
	TEST("Complex %%- 12.8hd", "|%- 12.8hd|\n", pos);
	
	TEST("Multiple %%hd values", "%hd %hd %hd\n", pos, neg, zero);
	TEST("Multiple types", "%hd %hu %hx %ho\n", 
		pos, (unsigned short)pos, (unsigned short)pos, (unsigned short)pos);
	TEST("Mixed with regular", "%d %hd %u %hu\n", 42, pos, 100, (unsigned short)neg);
	
	TEST("Edge near max", "|%hd|\n", (short)(s_max - 1));
	TEST("Edge near min", "|%hd|\n", (short)(s_min + 1));
	TEST("Boundary 255", "|%hd|\n", (short)255);
	TEST("Boundary 256", "|%hd|\n", (short)256);
	
	TEST("Overflow positive %%hd", "|%hd|\n", 100000);
	TEST("Overflow negative %%hd", "|%hd|\n", -100000);
	TEST("Overflow unsigned %%hu", "|%hu|\n", 100000);
	
	TEST("All flags %%+#0- 15.10hd", "|%+#0- 15.10hd|\n", pos);
	TEST("Extreme width %%50hd", "|%50hd|\n", pos);
	TEST("Extreme prec %%.30hd", "|%.30hd|\n", pos);
	TEST("Both extreme %%50.30hd", "|%50.30hd|\n", s_max);
}

void test_hh_modifier(void)
{
	printf("--- Testing 'hh' Length Modifier ---\n");
	char c = -1;
	signed char sc = -128;
	unsigned char uc = 255;
	int val = 1234567;
	
	TEST("Basic %%hhd with -1", "|%hhd|\n", c);
	TEST("Basic %%hhd with -128", "|%hhd|\n", sc);
	TEST("Basic %%hhd with 1234567", "|%hhd|\n", val);
	TEST("Basic %%hhu with -1", "|%hhu|\n", c);
	TEST("Basic %%hhu with 255", "|%hhu|\n", uc);
	TEST("Basic %%hhu with 1234567", "|%hhu|\n", val);
	TEST("Basic %%hhi with -1", "|%hhi|\n", c);
	TEST("Basic %%hhi with -128", "|%hhi|\n", sc);
	TEST("Width %%5hhd with -1", "|%5hhd|\n", c);
	TEST("Width %%5hhu with 255", "|%5hhu|\n", uc);
	TEST("Zero flag %%05hhd with -1", "|%05hhd|\n", c);
	TEST("Zero flag %%05hhd with -128", "|%05hhd|\n", sc);
	TEST("Zero flag %%05hhu with 255", "|%05hhu|\n", uc);
	TEST("Minus flag %%-5hhd with -1", "|%-5hhd|\n", c);
	TEST("Minus flag %%-5hhu with 255", "|%-5hhu|\n", uc);
	TEST("Plus flag %%+hhd with -1", "|%+hhd|\n", c);
	TEST("Plus flag %%+5hhd with -128", "|%+5hhd|\n", sc);
	TEST("Plus flag %%+hhd with 127", "|%+hhd|\n", (signed char)127);
	TEST("Space flag %% hhd with -1", "| %hhd|\n", c);
	TEST("Space flag %% hhd with 127", "| %hhd|\n", (signed char)127);
	TEST("Precision %%.5hhd with -1", "|%.5hhd|\n", c);
	TEST("Precision %%.5hhu with 255", "|%.5hhu|\n", uc);
	TEST("Precision %%8.5hhd with -1", "|%8.5hhd|\n", c);
	TEST("Combined %%+05hhd with -1", "|%+05hhd|\n", c);
	TEST("Combined %%+-5hhd with -1", "|%+-5hhd|\n", c);
	TEST("Combined %% 05hhd with 127", "| %05hhd|\n", (signed char)127);
	TEST("Edge %%hhd with 0", "|%hhd|\n", 0);
	TEST("Edge %%.0hhd with 0", "|%.0hhd|\n", 0);
	TEST("Edge %%5.0hhd with 0", "|%5.0hhd|\n", 0);
	TEST("Hex %%hhx with -1", "|%hhx|\n", c);
	TEST("Hex %%hhX with -1", "|%hhX|\n", c);
	TEST("Hex %%#hhx with 255", "|%#hhx|\n", uc);
	TEST("Octal %%hho with -1", "|%hho|\n", c);
	TEST("Octal %%#hho with 255", "|%#hho|\n", uc);
}

/* ========== FLAGS TESTS ========== */

void test_flag_hash(void)
{
	printf("--- Testing # flag ---\n");
	TEST("Hash with hex %#x", "%#x\n", 42);
	TEST("Hash with HEX %#X", "%#X\n", 255);
	TEST("Hash with zero %#x", "%#x\n", 0);
	TEST("Hash+width %#10x", "|%#10x|\n", 42);
	TEST("Hash+zero %#010x", "|%#010x|\n", 42);
	TEST("Hash+precision %#.10x", "|%#.10x|\n", 42);
	TEST("Hash with minus %-#10x", "|%-#10x|\n", 42);
}

void test_flag_plus(void)
{
	printf("--- Testing + flag ---\n");
	TEST("Plus with positive %+d", "%+d\n", 42);
	TEST("Plus with negative %+d", "%+d\n", -42);
	TEST("Plus with zero %+d", "%+d\n", 0);
	TEST("Plus+width %+10d", "|%+10d|\n", 42);
	TEST("Plus+zero %+010d", "|%+010d|\n", 42);
	TEST("Plus+precision %+.5d", "|%+.5d|\n", 42);
	TEST("Plus+minus %-+10d", "|%-+10d|\n", 42);
	TEST("Plus with INT_MAX %+d", "%+d\n", INT_MAX);
	TEST("Plus with INT_MIN %+d", "%+d\n", INT_MIN);
}

void test_flag_space(void)
{
	printf("--- Testing space flag ---\n");
	TEST("Space with positive % d", "% d\n", 42);
	TEST("Space with negative % d", "% d\n", -42);
	TEST("Space with zero % d", "% d\n", 0);
	TEST("Space+width % 10d", "|% 10d|\n", 42);
	TEST("Space+zero % 010d", "|% 010d|\n", 42);
	TEST("Space+precision % .5d", "|% .5d|\n", 42);
}

void test_flag_minus(void)
{
	printf("--- Testing - flag (left align) ---\n");
	TEST("Minus int %-10d", "|%-10d|\n", 42);
	TEST("Minus string %-20s", "|%-20s|\n", "test");
	TEST("Minus char %-5c", "|%-5c|\n", 'X');
	TEST("Minus hex %-10x", "|%-10x|\n", 255);
	TEST("Minus+zero %-010d", "|%-010d|\n", 42);
	TEST("Minus+precision %-10.5d", "|%-10.5d|\n", 42);
}

void test_flag_zero(void)
{
	printf("--- Testing 0 flag (zero padding) ---\n");
	TEST("Zero int %010d", "|%010d|\n", 42);
	TEST("Zero negative %010d", "|%010d|\n", -42);
	TEST("Zero hex %010x", "|%010x|\n", 42);
	TEST("Zero unsigned %010u", "|%010u|\n", 42);
	TEST("Zero+hash %#010x", "|%#010x|\n", 42);
	TEST("Zero+plus %+010d", "|%+010d|\n", 42);
	TEST("Zero+space % 010d", "|% 010d|\n", 42);
}

void test_width(void)
{
	printf("--- Testing width ---\n");
	TEST("Width 10 int %10d", "|%10d|\n", 42);
	TEST("Width 20 string %20s", "|%20s|\n", "test");
	TEST("Width 5 char %5c", "|%5c|\n", 'X');
	TEST("Width 15 hex %15x", "|%15x|\n", 255);
	TEST("Width smaller %2d", "|%2d|\n", 12345);
	TEST("Width 0 %0d", "|%0d|\n", 42);
	TEST("Width 100 %100d", "|%100d|\n", 42);
}

void test_precision(void)
{
	printf("--- Testing precision ---\n");
	TEST("Precision int %.5d", "|%.5d|\n", 42);
	TEST("Precision string %.5s", "|%.5s|\n", "Hello World");
	TEST("Precision hex %.10x", "|%.10x|\n", 42);
	TEST("Precision unsigned %.5u", "|%.5u|\n", 42);
	TEST("Precision 0 int %.0d", "|%.0d|\n", 42);
	TEST("Precision 0 zero %.0d", "|%.0d|\n", 0);
	TEST("Precision 50 %.50d", "|%.50d|\n", 42);
	TEST("Precision negative %.5d", "|%.5d|\n", -42);
	TEST("Precision+width %10.5d", "|%10.5d|\n", 42);
}

void test_wildcard(void)
{
	printf("--- Testing * (wildcard) ---\n");
	TEST("Width wildcard %*d", "|%*d|\n", 10, 42);
	TEST("Precision wildcard %.*d", "|%.*d|\n", 5, 42);
	TEST("Both wildcards %*.*d", "|%*.*d|\n", 10, 5, 42);
	TEST("Negative width %*d", "|%*d|\n", -10, 42);
	TEST("Negative precision %.*d", "|%.*d|\n", -5, 42);
	TEST("Zero width %*d", "|%*d|\n", 0, 42);
	TEST("String width %*s", "|%*s|\n", 20, "test");
	TEST("String precision %.*s", "|%.*s|\n", 5, "Hello World");
	TEST("String both %*.*s", "|%*.*s|\n", 15, 5, "Hello World");
}

/* ========== COMBINATIONS ========== */

void test_flag_precedence(void)
{
	printf("--- Testing flag precedence ---\n");
	TEST("Plus over space %+ d", "|%+ d|\n", 42);
	TEST("Minus over zero %-010d", "|%-010d|\n", 42);
	TEST("Precision over zero %08.5d", "|%08.5d|\n", 42);
	TEST("All flags %+#0- 20.10d", "|%+#0- 20.10d|\n", 42);
}

void test_complex_combinations(void)
{
	printf("--- Testing complex combinations ---\n");
	TEST("Width+prec+plus %+20.15d", "|%+20.15d|\n", -42);
	TEST("Width+prec+space % 20.15d", "|% 20.15d|\n", -42);
	TEST("Hash+zero+width %#020x", "|%#020x|\n", 255);
	TEST("Hash+minus+width %-#20x", "|%-#20x|\n", 255);
	TEST("All for hex %+#0- 20.15x", "|%+#0- 20.15x|\n", 255);
	TEST("String complex %-20.10s", "|%-20.10s|\n", "Long String Test");
}

void test_j_modifier(void)
{
	printf("--- Testing 'j' Length Modifier (intmax_t) ---\n");
	intmax_t jm_max = INTMAX_MAX;
	intmax_t jm_min = INTMAX_MIN;
	uintmax_t ujm_max = UINTMAX_MAX;
	intmax_t zero = 0;
	intmax_t pos = 1234567890123456LL;
	intmax_t neg = -9876543210987654LL;
	
	TEST("Basic %%jd positive", "|%jd|\n", pos);
	TEST("Basic %%jd negative", "|%jd|\n", neg);
	TEST("Basic %%jd zero", "|%jd|\n", zero);
	TEST("INTMAX_MAX %%jd", "|%jd|\n", jm_max);
	TEST("INTMAX_MIN %%jd", "|%jd|\n", jm_min);
	
	TEST("Basic %%ji positive", "|%ji|\n", pos);
	TEST("Basic %%ji negative", "|%ji|\n", neg);
	TEST("Basic %%ji zero", "|%ji|\n", zero);
	TEST("INTMAX_MAX %%ji", "|%ji|\n", jm_max);
	TEST("INTMAX_MIN %%ji", "|%ji|\n", jm_min);
	
	TEST("Basic %%ju", "|%ju|\n", (uintmax_t)pos);
	TEST("UINTMAX_MAX %%ju", "|%ju|\n", ujm_max);
	TEST("Cast negative %%ju", "|%ju|\n", (uintmax_t)neg);
	TEST("Zero %%ju", "|%ju|\n", (uintmax_t)zero);
	TEST("Large %%ju", "|%ju|\n", (uintmax_t)9000000000000000000LL);
	
	TEST("Hex %%jx lowercase", "|%jx|\n", (uintmax_t)pos);
	TEST("Hex %%jX uppercase", "|%jX|\n", (uintmax_t)pos);
	TEST("Hex UINTMAX_MAX %%jx", "|%jx|\n", ujm_max);
	TEST("Hex zero %%jx", "|%jx|\n", (uintmax_t)zero);
	TEST("Hex negative cast %%jx", "|%jx|\n", (uintmax_t)neg);
	TEST("Hex large %%jx", "|%jx|\n", (uintmax_t)9000000000000000000LL);
	
	TEST("Octal %%jo", "|%jo|\n", (uintmax_t)pos);
	TEST("Octal UINTMAX_MAX", "|%jo|\n", ujm_max);
	TEST("Octal zero", "|%jo|\n", (uintmax_t)zero);
	TEST("Octal large", "|%jo|\n", (uintmax_t)9000000000000000000LL);
	
	TEST("Width %%25jd", "|%25jd|\n", pos);
	TEST("Width %%25jd INTMAX_MAX", "|%25jd|\n", jm_max);
	TEST("Width %%25jd INTMAX_MIN", "|%25jd|\n", jm_min);
	TEST("Left align %%-25jd", "|%-25jd|\n", pos);
	TEST("Left align %%-25jd MIN", "|%-25jd|\n", jm_min);
	
	TEST("Precision %%.15jd", "|%.15jd|\n", pos);
	TEST("Precision %%.25jd MAX", "|%.25jd|\n", jm_max);
	TEST("Precision %%.25jd MIN", "|%.25jd|\n", jm_min);
	TEST("Precision %%.0jd zero", "|%.0jd|\n", zero);
	TEST("Precision %%.20ju", "|%.20ju|\n", (uintmax_t)pos);
	
	TEST("Plus %%+jd positive", "|%+jd|\n", pos);
	TEST("Plus %%+jd negative", "|%+jd|\n", neg);
	TEST("Plus %%+jd zero", "|%+jd|\n", zero);
	TEST("Plus %%+jd INTMAX_MAX", "|%+jd|\n", jm_max);
	TEST("Plus %%+jd INTMAX_MIN", "|%+jd|\n", jm_min);
	
	TEST("Space %% jd positive", "|% jd|\n", pos);
	TEST("Space %% jd negative", "|% jd|\n", neg);
	TEST("Space %% jd zero", "|% jd|\n", zero);
	TEST("Space %% jd INTMAX_MAX", "|% jd|\n", jm_max);
	
	TEST("Hash %%#jx", "|%#jx|\n", (uintmax_t)pos);
	TEST("Hash %%#jX", "|%#jX|\n", (uintmax_t)pos);
	TEST("Hash %%#jo", "|%#jo|\n", (uintmax_t)pos);
	TEST("Hash %%#jx zero", "|%#jx|\n", (uintmax_t)zero);
	TEST("Hash %%#jo zero", "|%#jo|\n", (uintmax_t)zero);
	
	TEST("Zero pad %%025jd", "|%025jd|\n", pos);
	TEST("Zero pad %%025jd MAX", "|%025jd|\n", jm_max);
	TEST("Zero pad %%025jd MIN", "|%025jd|\n", jm_min);
	TEST("Zero pad %%025ju", "|%025ju|\n", (uintmax_t)pos);
	TEST("Zero pad %%025jx", "|%025jx|\n", (uintmax_t)pos);
	
	TEST("Width+Precision %%30.20jd", "|%30.20jd|\n", pos);
	TEST("Width+Precision %%30.25jd MAX", "|%30.25jd|\n", jm_max);
	TEST("Width+Precision %%30.25jd MIN", "|%30.25jd|\n", jm_min);
	TEST("Width+Prec+Plus %%+30.20jd", "|%+30.20jd|\n", pos);
	TEST("Width+Prec+Space %% 30.20jd", "|% 30.20jd|\n", pos);
	
	TEST("Left+Plus %%-+25jd", "|%-+25jd|\n", pos);
	TEST("Left+Space %%- 25jd", "|%- 25jd|\n", pos);
	TEST("Left+Prec %%-25.15jd", "|%-25.15jd|\n", pos);
	
	TEST("Hash+Zero %%#025jx", "|%#025jx|\n", (uintmax_t)pos);
	TEST("Hash+Width %%#30jx", "|%#30jx|\n", (uintmax_t)pos);
	TEST("Hash+Prec %%#.20jx", "|%#.20jx|\n", (uintmax_t)pos);
	TEST("Hash+Width+Prec %%#30.20jx", "|%#30.20jx|\n", (uintmax_t)pos);
	
	TEST("Complex %%+#025.20jx", "|%+#025.20jx|\n", (uintmax_t)pos);
	TEST("Complex %%-+30.20jd", "|%-+30.20jd|\n", pos);
	TEST("Complex %%- 30.20jd", "|%- 30.20jd|\n", pos);
	
	TEST("Multiple %%jd values", "%jd %jd %jd\n", pos, neg, zero);
	TEST("Multiple types", "%jd %ju %jx %jo\n", 
		pos, (uintmax_t)pos, (uintmax_t)pos, (uintmax_t)pos);
	TEST("Mixed with regular", "%d %jd %u %ju\n", 42, pos, 100, (uintmax_t)neg);
	
	TEST("Very large positive", "|%jd|\n", (intmax_t)9000000000000000000LL);
	TEST("Very large negative", "|%jd|\n", (intmax_t)-9000000000000000000LL);
	TEST("Edge near max", "|%jd|\n", jm_max - 1);
	TEST("Edge near min", "|%jd|\n", jm_min + 1);
	
	TEST("Small values %%jd", "|%jd %jd %jd|\n", (intmax_t)1, (intmax_t)10, (intmax_t)100);
	TEST("Small negative %%jd", "|%jd %jd %jd|\n", (intmax_t)-1, (intmax_t)-10, (intmax_t)-100);
	
	TEST("All flags %%+#0- 35.25jd", "|%+#0- 35.25jd|\n", pos);
	TEST("Extreme width %%100jd", "|%100jd|\n", pos);
	TEST("Extreme prec %%.50jd", "|%.50jd|\n", pos);
	TEST("Both extreme %%100.50jd", "|%100.50jd|\n", jm_max);
}

void test_z_modifier(void)
{
	printf("--- Testing 'z' Length Modifier (size_t) ---\n");
	size_t z_max = SIZE_MAX;
	size_t zero = 0;
	size_t pos = 1234567890;
	size_t large = 9876543210987654UL;
	ssize_t signed_pos = 1234567890;
	ssize_t signed_neg = -1234567890;
	
	TEST("Basic %%zu positive", "|%zu|\n", pos);
	TEST("Basic %%zu zero", "|%zu|\n", zero);
	TEST("SIZE_MAX %%zu", "|%zu|\n", z_max);
	TEST("Large %%zu", "|%zu|\n", large);
	TEST("Small %%zu", "|%zu|\n", (size_t)42);
	
	TEST("Signed %%zd positive", "|%zd|\n", signed_pos);
	TEST("Signed %%zd negative", "|%zd|\n", signed_neg);
	TEST("Signed %%zd zero", "|%zd|\n", (ssize_t)0);
	TEST("Signed %%zi positive", "|%zi|\n", signed_pos);
	TEST("Signed %%zi negative", "|%zi|\n", signed_neg);
	
	TEST("Hex %%zx lowercase", "|%zx|\n", pos);
	TEST("Hex %%zX uppercase", "|%zX|\n", pos);
	TEST("Hex SIZE_MAX %%zx", "|%zx|\n", z_max);
	TEST("Hex zero %%zx", "|%zx|\n", zero);
	TEST("Hex large %%zx", "|%zx|\n", large);
	
	TEST("Octal %%zo", "|%zo|\n", pos);
	TEST("Octal SIZE_MAX", "|%zo|\n", z_max);
	TEST("Octal zero", "|%zo|\n", zero);
	TEST("Octal large", "|%zo|\n", large);
	
	TEST("Width %%20zu", "|%20zu|\n", pos);
	TEST("Width %%25zu SIZE_MAX", "|%25zu|\n", z_max);
	TEST("Width %%20zd", "|%20zd|\n", signed_pos);
	TEST("Left align %%-20zu", "|%-20zu|\n", pos);
	TEST("Left align %%-20zd", "|%-20zd|\n", signed_neg);
	
	TEST("Precision %%.15zu", "|%.15zu|\n", pos);
	TEST("Precision %%.25zu MAX", "|%.25zu|\n", z_max);
	TEST("Precision %%.0zu zero", "|%.0zu|\n", zero);
	TEST("Precision %%.15zd", "|%.15zd|\n", signed_pos);
	TEST("Precision %%.15zd neg", "|%.15zd|\n", signed_neg);
	
	TEST("Plus %%+zd positive", "|%+zd|\n", signed_pos);
	TEST("Plus %%+zd negative", "|%+zd|\n", signed_neg);
	TEST("Plus %%+zd zero", "|%+zd|\n", (ssize_t)0);
	TEST("Plus %%+zi positive", "|%+zi|\n", signed_pos);
	
	TEST("Space %% zd positive", "|% zd|\n", signed_pos);
	TEST("Space %% zd negative", "|% zd|\n", signed_neg);
	TEST("Space %% zd zero", "|% zd|\n", (ssize_t)0);
	TEST("Space %% zi positive", "|% zi|\n", signed_pos);
	
	TEST("Hash %%#zx", "|%#zx|\n", pos);
	TEST("Hash %%#zX", "|%#zX|\n", pos);
	TEST("Hash %%#zo", "|%#zo|\n", pos);
	TEST("Hash %%#zx zero", "|%#zx|\n", zero);
	TEST("Hash %%#zo zero", "|%#zo|\n", zero);
	
	TEST("Zero pad %%020zu", "|%020zu|\n", pos);
	TEST("Zero pad %%025zu MAX", "|%025zu|\n", z_max);
	TEST("Zero pad %%020zd", "|%020zd|\n", signed_pos);
	TEST("Zero pad %%020zd neg", "|%020zd|\n", signed_neg);
	TEST("Zero pad %%020zx", "|%020zx|\n", pos);
	
	TEST("Width+Precision %%25.15zu", "|%25.15zu|\n", pos);
	TEST("Width+Precision %%30.25zu MAX", "|%30.25zu|\n", z_max);
	TEST("Width+Precision %%25.15zd", "|%25.15zd|\n", signed_pos);
	TEST("Width+Prec+Plus %%+25.15zd", "|%+25.15zd|\n", signed_pos);
	TEST("Width+Prec+Space %% 25.15zd", "|% 25.15zd|\n", signed_pos);
	
	TEST("Left+Plus %%-+20zd", "|%-+20zd|\n", signed_pos);
	TEST("Left+Space %%- 20zd", "|%- 20zd|\n", signed_pos);
	TEST("Left+Prec %%-20.12zu", "|%-20.12zu|\n", pos);
	TEST("Left+Prec %%-20.12zd", "|%-20.12zd|\n", signed_neg);
	
	TEST("Hash+Zero %%#020zx", "|%#020zx|\n", pos);
	TEST("Hash+Width %%#25zx", "|%#25zx|\n", pos);
	TEST("Hash+Prec %%#.15zx", "|%#.15zx|\n", pos);
	TEST("Hash+Width+Prec %%#25.15zx", "|%#25.15zx|\n", pos);
	
	TEST("Complex %%+#020.15zx", "|%+#020.15zx|\n", pos);
	TEST("Complex %%-+25.15zd", "|%-+25.15zd|\n", signed_pos);
	TEST("Complex %%- 25.15zd", "|%- 25.15zd|\n", signed_pos);
	
	TEST("Multiple %%zu values", "%zu %zu %zu\n", pos, zero, large);
	TEST("Multiple types", "%zu %zx %zo\n", pos, pos, pos);
	TEST("Multiple signed", "%zd %zd %zd\n", signed_pos, signed_neg, (ssize_t)0);
	TEST("Mixed with regular", "%d %zu %u %zx\n", 42, pos, 100, pos);
	
	TEST("Array size", "Array[%zu]\n", (size_t)1024);
	TEST("Memory size", "Memory: %zu bytes\n", (size_t)4096);
	TEST("Pointer arithmetic", "Offset: %zd\n", (ssize_t)100);
	
	TEST("Edge values zu", "|%zu %zu %zu|\n", (size_t)1, (size_t)255, (size_t)256);
	TEST("Edge values zd", "|%zd %zd %zd|\n", (ssize_t)1, (ssize_t)-1, (ssize_t)0);
	
	TEST("All flags %%+#0- 30.20zu", "|%+#0- 30.20zu|\n", pos);
	TEST("Extreme width %%100zu", "|%100zu|\n", pos);
	TEST("Extreme prec %%.50zu", "|%.50zu|\n", pos);
	TEST("Both extreme %%100.50zu", "|%100.50zu|\n", z_max);
}

void test_t_modifier(void)
{
	printf("--- Testing 't' Length Modifier (ptrdiff_t) ---\n");
	
	int arr[100];
	int *p1 = &arr[50];
	int *p2 = &arr[10];
	int *p3 = &arr[0];
	int *p4 = &arr[99];
	
	ptrdiff_t diff_pos = p1 - p2;
	ptrdiff_t diff_neg = p2 - p1;
	ptrdiff_t diff_zero = p1 - p1;
	ptrdiff_t diff_large = p4 - p3;
	ptrdiff_t diff_one = &arr[1] - &arr[0];
	
	TEST("Basic %%td positive", "|%td|\n", diff_pos);
	TEST("Basic %%td negative", "|%td|\n", diff_neg);
	TEST("Basic %%td zero", "|%td|\n", diff_zero);
	TEST("Basic %%td large", "|%td|\n", diff_large);
	TEST("Basic %%td one", "|%td|\n", diff_one);
	
	TEST("Basic %%ti positive", "|%ti|\n", diff_pos);
	TEST("Basic %%ti negative", "|%ti|\n", diff_neg);
	TEST("Basic %%ti zero", "|%ti|\n", diff_zero);
	
	TEST("Unsigned %%tu positive", "|%tu|\n", (ptrdiff_t)diff_pos);
	TEST("Unsigned %%tu large", "|%tu|\n", (ptrdiff_t)diff_large);
	TEST("Unsigned %%tu zero", "|%tu|\n", (ptrdiff_t)diff_zero);
	TEST("Unsigned %%tu cast neg", "|%tu|\n", (ptrdiff_t)diff_neg);
	
	TEST("Hex %%tx lowercase", "|%tx|\n", (ptrdiff_t)diff_pos);
	TEST("Hex %%tX uppercase", "|%tX|\n", (ptrdiff_t)diff_pos);
	TEST("Hex %%tx zero", "|%tx|\n", (ptrdiff_t)diff_zero);
	TEST("Hex %%tx large", "|%tx|\n", (ptrdiff_t)diff_large);
	TEST("Hex %%tx 255", "|%tx|\n", (ptrdiff_t)255);
	
	TEST("Octal %%to", "|%to|\n", (ptrdiff_t)diff_pos);
	TEST("Octal %%to zero", "|%to|\n", (ptrdiff_t)diff_zero);
	TEST("Octal %%to large", "|%to|\n", (ptrdiff_t)diff_large);
	
	TEST("Width %%15td", "|%15td|\n", diff_pos);
	TEST("Width %%15td negative", "|%15td|\n", diff_neg);
	TEST("Width %%15td zero", "|%15td|\n", diff_zero);
	TEST("Left align %%-15td", "|%-15td|\n", diff_pos);
	TEST("Left align %%-15td neg", "|%-15td|\n", diff_neg);
	
	TEST("Precision %%.10td", "|%.10td|\n", diff_pos);
	TEST("Precision %%.10td neg", "|%.10td|\n", diff_neg);
	TEST("Precision %%.0td zero", "|%.0td|\n", diff_zero);
	TEST("Precision %%.8tu", "|%.8tu|\n", (ptrdiff_t)diff_pos);
	TEST("Precision %%.10tx", "|%.10tx|\n", (ptrdiff_t)diff_pos);
	
	TEST("Plus %%+td positive", "|%+td|\n", diff_pos);
	TEST("Plus %%+td negative", "|%+td|\n", diff_neg);
	TEST("Plus %%+td zero", "|%+td|\n", diff_zero);
	TEST("Plus %%+ti positive", "|%+ti|\n", diff_pos);
	
	TEST("Space %% td positive", "|% td|\n", diff_pos);
	TEST("Space %% td negative", "|% td|\n", diff_neg);
	TEST("Space %% td zero", "|% td|\n", diff_zero);
	TEST("Space %% ti positive", "|% ti|\n", diff_pos);
	
	TEST("Hash %%#tx", "|%#tx|\n", (ptrdiff_t)diff_pos);
	TEST("Hash %%#tX", "|%#tX|\n", (ptrdiff_t)diff_pos);
	TEST("Hash %%#to", "|%#to|\n", (ptrdiff_t)diff_pos);
	TEST("Hash %%#tx zero", "|%#tx|\n", (ptrdiff_t)diff_zero);
	TEST("Hash %%#to zero", "|%#to|\n", (ptrdiff_t)diff_zero);
	TEST("Hash %%#tx 255", "|%#tx|\n", (ptrdiff_t)255);
	
	TEST("Zero pad %%015td", "|%015td|\n", diff_pos);
	TEST("Zero pad %%015td neg", "|%015td|\n", diff_neg);
	TEST("Zero pad %%015td zero", "|%015td|\n", diff_zero);
	TEST("Zero pad %%015tu", "|%015tu|\n", (ptrdiff_t)diff_pos);
	TEST("Zero pad %%015tx", "|%015tx|\n", (ptrdiff_t)diff_pos);
	
	TEST("Width+Precision %%20.12td", "|%20.12td|\n", diff_pos);
	TEST("Width+Precision %%20.12td neg", "|%20.12td|\n", diff_neg);
	TEST("Width+Prec+Plus %%+20.12td", "|%+20.12td|\n", diff_pos);
	TEST("Width+Prec+Space %% 20.12td", "|% 20.12td|\n", diff_pos);
	
	TEST("Left+Plus %%-+15td", "|%-+15td|\n", diff_pos);
	TEST("Left+Space %%- 15td", "|%- 15td|\n", diff_pos);
	TEST("Left+Prec %%-15.10td", "|%-15.10td|\n", diff_pos);
	TEST("Left+Prec+Plus %%-+15.10td", "|%-+15.10td|\n", diff_neg);
	
	TEST("Hash+Zero %%#015tx", "|%#015tx|\n", (ptrdiff_t)diff_pos);
	TEST("Hash+Width %%#20tx", "|%#20tx|\n", (ptrdiff_t)diff_pos);
	TEST("Hash+Prec %%#.10tx", "|%#.10tx|\n", (ptrdiff_t)diff_pos);
	TEST("Hash+Width+Prec %%#20.10tx", "|%#20.10tx|\n", (ptrdiff_t)diff_pos);
	
	TEST("Complex %%+#015.10tx", "|%+#015.10tx|\n", (ptrdiff_t)diff_pos);
	TEST("Complex %%-+20.12td", "|%-+20.12td|\n", diff_pos);
	TEST("Complex %%- 20.12td", "|%- 20.12td|\n", diff_pos);
	
	TEST("Multiple %%td values", "%td %td %td\n", diff_pos, diff_neg, diff_zero);
	TEST("Multiple types", "%td %tu %tx %to\n", 
		diff_pos, (ptrdiff_t)diff_pos, (ptrdiff_t)diff_pos, (ptrdiff_t)diff_pos);
	TEST("Mixed with regular", "%d %td %u %tu\n", 42, diff_pos, 100, (ptrdiff_t)diff_large);
	
	char str[] = "Hello, World!";
	char *start = str;
	char *end = str + 13;
	char *comma = str + 5;
	
	TEST("String offset", "Offset: %td\n", comma - start);
	TEST("String length", "Length: %td\n", end - start);
	TEST("String compare", "%td vs %td\n", comma - start, end - comma);
	
	ptrdiff_t small_vals[] = {1, 5, 10, 50, 100};
	TEST("Small positive values", "%td %td %td %td %td\n", 
		small_vals[0], small_vals[1], small_vals[2], small_vals[3], small_vals[4]);
	
	TEST("Negative small values", "%td %td %td\n", 
		(ptrdiff_t)-1, (ptrdiff_t)-5, (ptrdiff_t)-10);
	
	TEST("Large positive", "|%td|\n", (ptrdiff_t)1000000);
	TEST("Large negative", "|%td|\n", (ptrdiff_t)-1000000);
	TEST("Very large", "|%td|\n", (ptrdiff_t)1000000000);
	
	TEST("Edge case 255", "|%td|\n", (ptrdiff_t)255);
	TEST("Edge case 256", "|%td|\n", (ptrdiff_t)256);
	TEST("Edge case -255", "|%td|\n", (ptrdiff_t)-255);
	TEST("Edge case -256", "|%td|\n", (ptrdiff_t)-256);
	
	TEST("Boundary 127", "|%td|\n", (ptrdiff_t)127);
	TEST("Boundary 128", "|%td|\n", (ptrdiff_t)128);
	TEST("Boundary 32767", "|%td|\n", (ptrdiff_t)32767);
	TEST("Boundary 32768", "|%td|\n", (ptrdiff_t)32768);
	
	TEST("All flags %%+#0- 25.15td", "|%+#0- 25.15td|\n", diff_pos);
	TEST("All flags negative", "|%+#0- 25.15td|\n", diff_neg);
	TEST("Extreme width %%80td", "|%80td|\n", diff_pos);
	TEST("Extreme prec %%.50td", "|%.50td|\n", diff_pos);
	TEST("Both extreme %%80.50td", "|%80.50td|\n", diff_large);
	
	TEST("Real world use case 1", "Array[%td]\n", p1 - p3);
	TEST("Real world use case 2", "Distance: %td elements\n", diff_pos);
	TEST("Real world use case 3", "Index %td of %td\n", (ptrdiff_t)50, (ptrdiff_t)100);
}

/* ========== EDGE CASES ========== */

void test_edge_limits(void)
{
	printf("--- Testing limit edge cases ---\n");
	TEST("INT_MIN %d", "%d\n", INT_MIN);
	TEST("INT_MAX %d", "%d\n", INT_MAX);
	TEST("UINT_MAX %u", "%u\n", UINT_MAX);
	TEST("INT_MIN+plus %+d", "%+d\n", INT_MIN);
	TEST("INT_MIN+space % d", "% d\n", INT_MIN);
	TEST("INT_MIN+width %20d", "|%20d|\n", INT_MIN);
	TEST("INT_MIN+precision %.20d", "|%.20d|\n", INT_MIN);
	TEST("INT_MIN+zero %020d", "|%020d|\n", INT_MIN);
	TEST("INT_MIN large prec %.50d", "|%.50d|\n", INT_MIN);
	TEST("UINT_MAX hex %x", "%x\n", UINT_MAX);
}

void test_edge_zero(void)
{
	printf("--- Testing zero edge cases ---\n");
	TEST("Zero basic %d", "%d\n", 0);
	TEST("Zero+plus %+d", "%+d\n", 0);
	TEST("Zero+space % d", "% d\n", 0);
	TEST("Zero+hash %#x", "%#x\n", 0);
	TEST("Zero+precision %.0d", "%.0d\n", 0);
	TEST("Zero+width %10d", "|%10d|\n", 0);
	TEST("Zero hex %.0x", "%.0x\n", 0);
	TEST("Zero unsigned %.0u", "%.0u\n", 0);
}

void test_edge_empty(void)
{
	printf("--- Testing empty/NULL ---\n");
	TEST("Empty string %s", "|%s|\n", "");
	TEST("NULL string %s", "|%s|\n", (char *)NULL);
	TEST("NULL ptr %p", "%p\n", NULL);
	TEST("NULL+width %20s", "|%20s|\n", (char *)NULL);
	TEST("NULL+precision %.5s", "|%.5s|\n", (char *)NULL);
	TEST("Empty+width %20s", "|%20s|\n", "");
}

void test_edge_extreme_values(void)
{
	printf("--- Testing extreme width/precision ---\n");
	TEST("Width 100 %100d", "|%100d|\n", 42);
	TEST("Width 200 %200d", "|%200d|\n", 1);
	TEST("Precision 100 %.100d", "|%.100d|\n", 42);
	TEST("Both extreme %150.100d", "|%150.100d|\n", 42);
	TEST("Minus extreme %-200d", "|%-200d|\n", 42);
	TEST("String width 100 %100s", "|%100s|\n", "x");
}

/* ========== MIXED SCENARIOS ========== */

void test_mixed_types(void)
{
	printf("--- Testing mixed types ---\n");
	TEST("All types", "%c %s %d %i %u %x %X %p %%\n", 
		'A', "test", 42, -42, 100, 255, 255, (void *)0x123);
	TEST("Multiple same", "%d %d %d %d %d\n", 1, 2, 3, 4, 5);
	TEST("Alternating", "a%db%sc%xd\n", 1, "2", 3);
	TEST("With text", "[%d] test [%s] hex [%x]\n", 42, "hello", 255);
	TEST("Complex mix", "%+10d %-20s %#010x %.5d\n", -42, "hi", 255, 7);
}

void test_real_world(void)
{
	printf("--- Testing real-world scenarios ---\n");
	TEST("Printf style", "Result: %d (0x%x)\n", 42, 42);
	TEST("Formatted table", "| %-10s | %5d |\n", "Item", 100);
	TEST("Error msg", "Error at %p: %s (code %d)\n", 
		(void *)0x1234, "Invalid", -1);
	TEST("Progress", "[%3d%%] %s\n", 75, "Complete");
	TEST("Hex dump", "%08x: %02x %02x %02x\n", 0x1000, 0xAB, 0xCD, 0xEF);
}

/* ========== STRESS TESTS ========== */

void test_stress(void)
{
	printf("--- Testing stress cases ---\n");
	TEST("Many args", "%d%d%d%d%d%d%d%d%d%d\n", 
		0,1,2,3,4,5,6,7,8,9);
	TEST("Long format", "%10d%10d%10d%10d\n", 1, 2, 3, 4);
	TEST("Complex", "%+#0- *.*d %*s %-#*.*x\n", 
		20, 10, 42, 15, "test", 20, 10, 255);
	TEST("Edge combo", "%.0d %#.0x % .0d %+.0d\n", 0, 0, 0, 0);
}

/* ========== MAIN ========== */

int main(void)
{
	printf("═══════════════════════════════════════════════\n");
	printf("       FT_PRINTF COMPREHENSIVE TESTER\n");
	printf("═══════════════════════════════════════════════\n\n");

	printf("══════════ BASIC CONVERSIONS ══════════\n");
	test_char();
	test_string();
	test_pointer();
	test_decimal();
	test_unsigned();
	test_hex();
	test_octal();
	test_percent();
	test_ll_modifier();
	test_l_modifier();
	test_h_modifier();
	test_hh_modifier();
	test_j_modifier();
	test_z_modifier();
	test_t_modifier();

	printf("\n══════════ FLAGS ══════════\n");
	test_flag_hash();
	test_flag_plus();
	test_flag_space();
	test_flag_minus();
	test_flag_zero();
	test_width();
	test_precision();
	test_wildcard();

	printf("\n══════════ COMBINATIONS ══════════\n");
	test_flag_precedence();
	test_complex_combinations();

	printf("\n══════════ EDGE CASES ══════════\n");
	test_edge_limits();
	test_edge_zero();
	test_edge_empty();
	test_edge_extreme_values();

	printf("\n══════════ MIXED & STRESS ══════════\n");
	test_mixed_types();
	test_real_world();
	test_stress();

	printf("\n═══════════════════════════════════════════════\n");
	printf("                  END OF TESTS\n");
	printf("═══════════════════════════════════════════════\n");
	
	return (0);
}

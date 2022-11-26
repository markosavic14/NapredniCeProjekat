#pragma CHECK_MISRA("none")
//#include <unistd.h>
#include <string.h>
#pragma CHECK_MISRA("all")
#include "my_print.h"

static void swap(char* a, char* b);
static void reverse(char str[], const int_least32_t* length);
static void itoa(int_least32_t num, char* str, const int_least8_t base, int_least32_t* str_len);

static void swap(char* a, char* b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

static void reverse(char str[], const int_least32_t* length)
{
	int_least32_t start = 0;
	int_least32_t end = *length -1;
	while (start < end)
	{
		char* ta = &str[start];
		char* tb = &str[end];
		swap(ta, tb);
		start++;
		end--;
	}
}

static void itoa(int_least32_t num, char* str, const int_least8_t base, int_least32_t* str_len)
{
	*str_len = 0;
	while (num != 0)
	{
		int_least32_t rem = num % base;
		str[(*str_len)] = (rem > 9) ? (rem-10) + 'a' : rem + '0';
		(*str_len)++;
		num = num / base;
	}
	str[*str_len] = '\0';
	reverse(str, str_len);
}


void print_num(const int_least32_t* brojac, const int_least32_t* palindomski_broj, const int_least32_t* bs)
{
	char str[64] = {0};
	int_least32_t str_len = 0;
	itoa(*brojac, str, 10, &str_len);
    write(1, str, str_len);
    write(1, ". palindromski broj:\t", 21);
	memset(str, 0, sizeof(str));
	itoa(*palindomski_broj, str, *bs, &str_len);
    write(1, str, str_len);
    write(1, "\n", 1);
}

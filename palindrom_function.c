#include "palindrom_function.h"
#include "my_print.h"

static const int_least32_t brojni_sistem[3] = {8, 10, 16};

static int_least32_t reverse_num(int_least32_t broj_koji_se_proverava, const int_least8_t bs);

static int_least32_t reverse_num(int_least32_t broj_koji_se_proverava, const int_least8_t bs)
{
    int_least32_t ostatak;
    int_least32_t suma = 0;

    while (broj_koji_se_proverava > 0)
    {
        ostatak = broj_koji_se_proverava % brojni_sistem[bs];
        suma = (suma * brojni_sistem[bs]) + ostatak;
        broj_koji_se_proverava = broj_koji_se_proverava / brojni_sistem[bs];
    }
    return suma;
}

void palindrom(const int_least32_t broj, const int_least8_t bs)
{
    int_least32_t brojac_palindroma = 1;
    int_least32_t i;
    for (i = 1; i < broj; i++)
    {
        if (reverse_num(i, bs) == i)
        {
            print_num(&brojac_palindroma, &i, &brojni_sistem[bs]);
            brojac_palindroma++;
        }
    }
}

/*

Marko Savic Ra41/2018

============Opis zadatka============
Napisati funkciju koja prima jedan prirodan broj kao parametar i na standardni izlaz ispisuje sve prirodne brojeve manje od tog broja ciji zapis je palindrom.
Funkcija ujedno prima i parametar koji govori u kom brojnom sistemu broj treba da bude palindrom, ali se moze samo birati izmedju tri brojna sistema: oktalnog, dekadnog i hex
Palindrom je niz koji je centralno simetrican, tj cita se isto i sa leva i sa desna.


============Opis resenja============
Funkcija palindrom prima dva argumenta: broj do kojeg ispisuje sve brojeve koji su palindromi i brojni sistem u kojem se dati broj nalazi.
Funkcija kroz for petlju proverava sve brojeve od 1 do unesenog broja tako da pozove funkciju koja za dati broj i vraca preobrnuto zapisan broj.
Ukoliko je broj koji je zapisan obrnuto isti kao i pocetni broj, dati broj je palindrom i njega ce ispisati.

Primer broj 123321 zapisan unzad je 123321.


============Napomene============
Kako bih izbegao printf funkciju i stdio biblioteku, implementovao sam my_print datoteke. Ono sto je vidljivo u .h datoteci je jedino funkcija print_num
koja prima 3 parametra: brojac palindroma, sam broj koji treba da ispise i brojni sistem u kojem se nalazi broj.
my_print je namenski napisana da ispisuje vrednost na standardni izlaz putem write funkcije iz unistd biblioteke.
Ovde je takodje implementovana funkcija itoa koja prima int broj i vraca ga kao niz charova.
Unistd pruza pristup API-ju operativnog sistema POSIX. Write funkcija pise u datoteku stdout koja je sistemska datoteka
Tester za misru mi za datoteke palindrom_function.c i .h ne izbacuje upozorenja.

============Testiranje============
Testiranje je predvidjeno funkcijom main koja preko standardnog unosa prima brojni sistem koji treba da se koristi kao i sami broj do kojeg se ispituje.
Posto je testiranje relativno trivijalno sem unosa sa tastature, nisam pravio test slucajeve, prosto se iz ispisa vidi da li je isti dobar ili nije.
Dodat je i ispis koji je palindromski broj po redu (taj broj je uvek u dekadnom sistemu). Na taj nacin moze da se proveri matematicki broj palindroma.
Jednocifrenih ima baza-1, dvoifernih baza-1, trocifrenih (baza-1) * baza, cetverocifernih (baza-1) * baza...

Na primer za dekadni broj 1000 treba da bude 108 palindroma (9 jednocifernih, 9 dvocifernih i 90 trocifernih).
Za hex broj 1000 treba da bude 270 palindroma (15 jednocifrenih, 15 dvocifrenih i 240 trocifrenih).
*/

#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
#include <stdint.h>

#include "palindrom_function.h"

void oct(int_least32_t* broj);
void dec(int_least32_t* broj);
void hex(int_least32_t* broj);


void oct(int_least32_t* broj)
{
    scanf("%"SCNoLEAST32, broj);
}

void dec(int_least32_t* broj)
{
    scanf("%"SCNdLEAST32, broj);
}

void hex(int_least32_t* broj)
{
    scanf("%"SCNxLEAST32, broj);
}

void main()
{
    void (*scn_ptr[])() = {oct, dec, hex};
    int_least8_t brojni_sistem;
    int_least32_t broj;
    printf("\nIspis palindroma.\n");
    printf("Koji brojni sistem zelite da koristite:\n\t1 - Oktalni\n\t2 - Dekadni\n\t3 - Heksadecimalni\n");
    printf("\nUnesite broj od 1 do 3:");
    scanf("%"SCNdLEAST8, &brojni_sistem);

    assert(brojni_sistem>=1 && brojni_sistem<=3);

    printf("\nUnesite broj do kojeg zelite da ispisete palindrome:");
    scn_ptr[brojni_sistem-1](&broj);

    palindrom(broj, brojni_sistem-1);
}

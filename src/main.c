#include <stdio.h>
// #define UNUSED(X) int unused## __LINE__ __attribute__(())
/* Globaalse pinu massiivi pikkus. */
#define stack_size 100

/* Globaalse pinu pikkus, ehk mitu elementi on pinus. Antud muutuja väärtust
   on võimalik kasutada massiivist viimase elemendi leidmiseks, mis asub indeksil
   stack_len - 1, sest massiivi indekseerimine algiab 0-st ja esimene vaba koht,
   kui see eksisteerib asub indeksil stack_len.
*/
int stack_len = 0;

/* Globaalne pinu int väärtustest pikkusega stack_size. Olulised indeksid:
   stack[stack_len - 1]    - pinu pealmine element, kui stack_len > 0,
   stack[stack_len]        - massiivi esimene "vaba" koht, kui stack_len < stack_size
*/
int stack[stack_size];

/* Funktsioon push saab parameetriks int tüüpi väärtuse, mille lisab globaalsesse pinusse, kui
 * selles on veel ruumi. Vastasel korral trükib ekkraanile vea. Funktsioon ei tagasta midagi.
 */

void stack_push(int element)
{
    /* Kontrollime kas pinus on veel ruumi, kui ei ole, siis trükime ekraanile veateate. */
    if (stack_len >= stack_size)
    {
        printf("Viga: pinusse rohkem elemente ei mahu\n");
        return;
    }

    /* Antud hetkel teame, et pinusse mahub veel vähemalt üks element. */
    stack[stack_len] = element;

    /* Suurendame pinusse lisatud elementide arvu. */
    stack_len++;

    return;
}

/* Funktsioon pop ei saa ühtegi parameetrit ja tagastab globaalse pinu pealmise elemendi, mille ta
 * pinust eemaldab. Kui pinu on juba tühi, siis funktsioon tagastab väärtuse 0.
 */
int stack_pop(void)
{
    /* Kontrollime, kas pinus on elemente. Kui ei ole, siis tagastame väärtuse 0. */
    if (stack_len == 0)
    {
        /* Pinu on tühi, tagastame väärtuse 0. */
        return 0;
    }

    /* Teame, et pinus on vähemalt üks element. */
    int element = stack[stack_len - 1];

    /* Vähendame pinu elementide arvu. */
    stack_len--;

    /* Tagastame eemaldatud väärtuse. */
    return element;
}

/* Funktsioon isEmpty tagastab tõeväärtuse (0-vale ja mitte 0 tõene) vastavalt sellele kas
 * pinu on tühi või mitte.
 */
int stack_isEmpty(void)
{
    return !(stack_len > 0);
}
/* Funktsioon peek tagastab pinu pealmise elemendi ilma seda eemaldamata.
 * Kui pinu on tühi, siis see tagastab 0 väärtuse.
 */
int stack_peek(void)
{
    if (!stack_isEmpty())
    {
        return stack[stack_len - 1];
    }
    return 0;
}

/* Funktsioon print_stack trükib ekraanile kõik pinu elemendid eraldi reale alustades ülemisest.
 */
void stack_print(void)
{
    printf("Stack:\n");
    for (int i = stack_len - 1; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }

    return;
}
int main(void)
{
    // /* Lisame pinusse väärtused 10, 8 ja -40 testimiseks. */
    // push(10);
    // push(8);
    // push(-40);

    // /* Lihtsalt eemaldame pealmise väärtuse (-40) ja ei salvesta seda muutujasse. */
    // pop();

    // /* Eemaldame pealmise väärtuse ja salvestame selle muutujasse, et saaksime seda ekraanil kuvada. */
    // int a = pop();
    // printf("%d\n", a);

    // /* Eemaldame veel ühe elemendi ja trükime selle välja sealjuures kasutades juba eelnevalt defineeritud muutujat a. */
    // a = pop();
    // printf("%d\n", a);
    // push(1);
    // int b = peek();
    // printf("%d\n", b);
    // print_stack();
    // printf("@@@@@@@@@@@@@@@@@@@@");
    int sisend = 0;

    /* Lõputu tsükkel, kus 1 on tõene tõeväärtus (võiks kirjutada ka näiteks 1 == 1 või 0 != 1, mis on alati tõesed. */
    while (1)
    {
        /* Trükime kasutajale instruktsiooni ja EI lisa selle lõppu reavahetust, et visuaal oleks parem. */
        printf("Palun sisesta number (lõpetamiseks sisesta 0): ");

        /* Loeme väärtuse funktsiooniga scanf, mis on sarnane funktsiooniga printf. */
        int unused __attribute__((unused));
        unused = scanf("%d", &sisend);

        if (sisend == 0)
        {
            /* Lõpetame tsükli ja seega ei täida järgnevat tsükli keha. */
            break;
        }

        /* Sellest hetkest alates teame, et sisend ei ole 0. */

        /* Väljastame loetud sisendi kui see polnud 0. */
        printf("Kasutaja sisestas: %d\n", sisend);
        /* Alles nüüd kontrollitakse kas sisend oli 0 või mitte. Kui ei olnud, siis käivitatakse tsükkel uuesti. */
    }

    return 0;
}
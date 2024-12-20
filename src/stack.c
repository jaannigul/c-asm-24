#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
/* Globaalse pinu massiivi pikkus. */
#define stack_size 100


/* Pinu struktuuri muutuja. */
//struct stack_st stack = { .len = 0, .size = 0, .arr = NULL};
//struct stack_st stack = EMPTY_STACK;
/* Globaalse pinu pikkus, ehk mitu elementi on pinus. Antud muutuja väärtust
   on võimalik kasutada massiivist viimase elemendi leidmiseks, mis asub indeksil
   stack_len - 1, sest massiivi indekseerimine algiab 0-st ja esimene vaba koht,
   kui see eksisteerib asub indeksil stack_len.
*/

/* Globaalne pinu int väärtustest pikkusega stack_size. Olulised indeksid:
   stack[stack_len - 1]    - pinu pealmine element, kui stack_len > 0,
   stack[stack_len]        - massiivi esimene "vaba" koht, kui stack_len < stack_size
*/
// int stack[stack_size];

/* Funktsioon push saab parameetriks int tüüpi väärtuse, mille lisab globaalsesse pinusse, kui
 * selles on veel ruumi. Vastasel korral trükib ekkraanile vea. Funktsioon ei tagasta midagi.
 */

/* Funktsioon push saab parameetriks int tüüpi väärtuse, mille lisab globaalsesse pinusse, kui
 * selles on veel ruumi. Vastasel korral trükib ekkraanile vea. Funktsioon ei tagasta midagi.
 */
void stack_push(struct stack_st *s, int element) {
    /* Teeme topelt kontrolli, kuigi piisaks vaid ühest, kas mälu on allokeeritud. */
    if (s->size == 0 || s->arr == NULL) {
        /* Mälu pole allokeeritud. */


        /* Alustame ühest elemendist. */
        s->size = 1;

        /* Allokeerime mälu vaid ühe (int tüüpi!!!) elemendi jaoks. */
        s->arr = malloc(sizeof(int) * s->size);

        /* Kontrollime kas mälu küsimine õnnestus. */
        if (s->arr == NULL) {
           printf("Mälu otsas!\n");
           return;
        }

        /* Antud hetkel ei saa elemente pinus olla. */
        s->len = 0;
    } else if (s->len == s->size) {
        /* Peame mälu suurendama 2x, aga kasutame ajutisi muutujaid, sest
           mälu suuruse muutmine võib ebaõnnestuda. */
        int tmp_size = s->size * 2;
        int *tmp_arr = NULL;

        tmp_arr = realloc(s->arr, tmp_size * sizeof(int));
        if (tmp_arr == NULL) {
            printf("Mäluala suuruse muutmine ebaõnnestus.\n");
            return;
        }
        /* Alles nüüd teame, et kõik õnnestus! */

        s->arr = tmp_arr;
        s->size = tmp_size;
    }

    /* Antud hetkel teame, et pinusse mahub veel vähemalt üks element. */
    s->arr[s->len] = element;

    /* Suurendame pinusse lisatud elementide arvu. */
    s->len++;

    return;
}

/* Funktsioon pop ei saa ühtegi parameetrit ja tagastab globaalse pinu pealmise elemendi, mille ta
 * pinust eemaldab. Kui pinu on juba tühi, siis funktsioon tagastab väärtuse 0.
 */
int stack_pop(struct stack_st *s)
{
    if (s->len == 0 || s->arr == 0)
    {
        return 0;
    }

    int element = s->arr[s->len - 1];

    s->len--;

    if (s->len > 0 && s->len <= s->size / 2)
    {
        int tmp_size = s->size / 2;
        int *tmp_arr = realloc(s->arr, tmp_size * sizeof(int));
        if (tmp_arr == NULL) {
            printf("Mäluala suuruse vähendamine ebaõnnestus.\n");
            return element; 
        }
        s->arr = tmp_arr;
        s->size = tmp_size;
    }
    else if (s->len == 0)
    {
        free(s->arr);
        s->arr = NULL;
        s->size = 0;
    }

    /* Tagastame eemaldatud väärtuse. */
    return element;
}

/* Funktsioon isEmpty tagastab tõeväärtuse (0-vale ja mitte 0 tõene) vastavalt sellele kas
 * pinu on tühi või mitte.
 */
int stack_isEmpty(struct stack_st *s)
{
    return !(s->len > 0);
}
/* Funktsioon peek tagastab pinu pealmise elemendi ilma seda eemaldamata.
 * Kui pinu on tühi, siis see tagastab 0 väärtuse.
 */
int stack_peek(struct stack_st *s)
{
    if (!stack_isEmpty(s))
    {
        return s->arr[s->len - 1];
    }
    return 0;
}

/* Funktsioon print_stack trükib ekraanile kõik pinu elemendid eraldi reale alustades ülemisest.
 */
void stack_print(struct stack_st *s)
{
    printf("Stack:\n");
    for (int i = s->len - 1; i >= 0; i--)
    {
        printf("%d\n", s->arr[i]);
    }

    return;
}

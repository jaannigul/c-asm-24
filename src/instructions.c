#include <stdio.h>
#include <stdlib.h>
#include "instructions.h"
#include "stack.h"
#include "mem.h"

struct BF_instruction_st *BF_increment_new(int increment) {
    struct BF_instruction_st *new = NULL;

    /* Kontrollime väärtust, et vältida hilisemaid vigu. */
    if (increment == 0) {
        printf("Liitmisinstruktsiooni parameeter ei saa olla 0!");

        /* Sisuliselt tagastab nüüd funktsioon NULL'i. */
        goto cleanup;
    }

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    /* Väärtustame inkremendi. */
    new->increment = increment;
    new->run = BF_increment_run;
cleanup:
    return new;
}

/* Funkctioon BF_increment_new on kood, mida käivitatakse konkreetse
   instruktsiooni käivitamisel. 
*/
void BF_increment_run(struct BF_instruction_st *instruction, int *index) {
    /* Suurendame mälu väärtust vastavalt konstruktoris seatud väärtusele! */
    mem_add(instruction->increment);

    /* Suurendame instruktsiooniloendurit ühe võrra. */
    ++*index;
}

/* Funktsiooni BF_beginLoop_run käivitatakse iga kord, kui jõutakse tsükli algusesse.
*/
void BF_beginLoop_run(struct BF_instruction_st *instruction, int *index) {
    int val = mem_get();

    if (instruction->loopForwardIndex < 0) {
        printf("Tsükli algus algväärtustamata!\n");
        return;
    }

    if (val == 0) {
        /* +1 lisamine on selleks, et me ei "hüppaks" tsükli lõpu instruktsioonile,
           vaid sellele järgnevale instruktsioonile. */
        *index = instruction->loopForwardIndex + 1;
    } else {
        ++*index;
    }
}

/* Konstruktor funktsioon BF_beginLoop_new loob uue struktuuri, mis implementeerib
   tsüklite algust. 

   NB! Oluline on märkida, et loopForwardIndex ei saa algväärtustatud
   sisulise väärtusega ja seda on vaja muuta hiljem! 
*/
struct BF_instruction_st *BF_beginLoop_new(void) {
    struct BF_instruction_st *new = NULL;

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    /* Hetkel pole teada kus asub tsükli lõpp, seega kasutame väärtust, mis
       ei saa korrektne olla.*/
    new->loopForwardIndex = -1;
    new->run = BF_beginLoop_run;
cleanup:
    return new;
}

void BF_endLoop_run(struct BF_instruction_st *instruction, int *index) {
    int val = mem_get();

    if (instruction->loopBackIndex < 0) {
        printf("Tsükli lõpp algväärtustamata!\n");
        return;
    }

    if (val == 0) {
        /* Pole mõtet tsükli algusesse tagasi hüpata, sest tsüklit enam ei täideta. */
        ++*index;
    } else {
        /* Mine tagasi tsükli algusesse. */
        *index = instruction->loopBackIndex;
    }
}

/* Konstruktor funktsioon BF_endLoop_new loob uue struktuuri, mis implementeerib
   tsüklite algust. 

   NB! Oluline on märkida, et loopForwardIndex ei saa algväärtustatud
   sisulise väärtusega ja seda on vaja muuta hiljem! 
*/
struct BF_instruction_st *BF_endLoop_new(void) {
    struct BF_instruction_st *new = NULL;

    new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        goto cleanup;
    }

    /* Hetkel pole teada kus asub tsükli lõpp, seega kasutame väärtust, mis
       ei saa korrektne olla.*/
    new->loopBackIndex = -1;
    new->run = BF_endLoop_run;
    new->printAsm = BF_endLoop_printAsm;
cleanup:
    return new;
}


void BF_print_run(struct BF_instruction_st *instruction, int *index) {
    char c = mem_get();  
    printf("%c\n", c);    
    ++*index;            
}

// , char input
void BF_read_run(struct BF_instruction_st *instruction, int *index) {
    printf("read run\n");
    int c = getc(stdin);
    if (c != EOF) {
        mem_set((char)c);
    }
    while ((c = getchar()) != '\n' && c != EOF);
    ++*index;
}

// mem move
void BF_move_run(struct BF_instruction_st *instruction, int *index) {
    //printf("numberpos %d\n",instruction->numberOfPositions);
    if (instruction->numberOfPositions > 0) {
            
            mem_right();
    } else {
            mem_left();
    }
    ++*index; 
}

struct BF_instruction_st *BF_move_new(int positions) {
    struct BF_instruction_st *new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        return NULL;
    }
    new->numberOfPositions = positions;
    new->run = BF_move_run;  
    return new;
}

struct BF_instruction_st *BF_print_new(void) {
    struct BF_instruction_st *new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        return NULL;
    }
    new->run = BF_print_run;
    return new;
}

struct BF_instruction_st *BF_read_new(void) {
    struct BF_instruction_st *new = malloc(sizeof(struct BF_instruction_st));
    if (new == NULL) {
        printf("Mälu küsimine ebaõnnestus.");
        return NULL;
    }
    new->run = BF_read_run;  // Ensure this function exists for handling input
    return new;
}

void BF_endLoop_printAsm(struct BF_instruction_st *instruction, int *index) {
    printf("    ;;;; Instruktsioon ]\n");
    printf("    jmp silt_%d\n", instruction->loopBackIndex);
    printf("silt_%d:\n", *index);
}
#ifdef DEBUG
  #define PRINT_PARAMS "'%c' (kood = %d)\n", c, c
#else
  #define PRINT_PARAMS "%c", c
#endif
#include <stdio.h>
#include "mem.h"
#include "stack.h"
#include "instructions.h"
#include <string.h>
#include <stdlib.h>



/* Selles enumeratsioonis on toodud kõik Brainfuck'i keele sümbolid. */
enum instructions_e {
    /* Liiguta mälu indeksit paremale. */
    BF_RIGHT      = '>',

    /* Liiguta mälu indeksit vasakule. */
    BF_LEFT       = '<',

    /* Suurenda mälu indeksil olevat väärtust. */
    BF_INCREASE   = '+',

    /* Vähenda mälu indeksil olevat väärtust. */
    BF_DECREASE   = '-',

    /* Loe kasutajalt sisendit ja salvesta see mäluindeksile. */
    BF_READ       = ',',

    /* Trüki välja mälu indeksil olev väärtus char'ina. */
    BF_PRINT      = '.',

    /* Tsükli algus. */
    BF_START_LOOP = '[',

    /* Tsükli lõpp. */
    BF_END_LOOP   = ']',

    /* Trüki silumise informatsioon. */
    BF_DEBUG      = '#'
};

void interpret(char *program) {
    int i = 0;
    struct stack_st stack = { .len = 0, .size = 0, .arr = NULL};
    while (program[i] != 0 ) {
                switch (program[i]) {
            case BF_INCREASE:
                mem_inc();
                break;
            case BF_DECREASE:
                mem_dec();
                break;
            case BF_RIGHT:
                mem_right();
                break;
            case BF_LEFT:
                mem_left();
                break;
            case BF_DEBUG:
                mem_printDebug();
                break;
            case BF_READ: {
                /* Loeme märgi standardsisendist (kasutaja sisestab konsooli). */
                int c = getc(stdin);
                if (EOF == c) {
                    /* Sisendi lõpu korral lõpetame interpretaatori töö. */
                    printf("Sisendi lõpp!\n");
                    return;
                }

                /* Lisame mällu loetud väärtuse. */
                mem_set((char) c);
                break;
             }
             case BF_PRINT: {
                char c = mem_get();
                printf(PRINT_PARAMS);
                break;
           }
            case BF_START_LOOP: {
                //kontrollime kas hetkel mälu viidatava väärtus on 0
                if (mem_get() == 0)
                {
                    int loop_level = 1;
                    while (loop_level > 0)
                    {
                        ++i;
                        if (program[i] == BF_START_LOOP)
                        {
                            ++loop_level; //mitmekordne tsükkel
                        }
                        else if (program[i] == BF_END_LOOP)
                        {
                            --loop_level;
                        }
                        
                    }
                      
                }
                else
                {
                    stack_push(&stack, i);
                }
                break;
           }
            case BF_END_LOOP: {
                if (mem_get()!=0)
                {
                    i = stack_peek(&stack); //mine tagasi loopi alguse juurde
                }
                else 
                {
                    stack_pop(&stack); //exit loop
                }
                
            break;
           }
            default:
                break;
        }

        i++;
    }
}

void parse(struct BF_instruction_st **inst_arr, char *program) {
    int i = 0;

    struct stack_st loopStack = EMPTY_STACK;

    while (program[i] != 0 ) {
        /* Algväärtustame kõik instruktsioonid eelnevalt NULL'iga. */
        inst_arr[i] = NULL;
        switch (program[i]) {
            case BF_INCREASE:
                inst_arr[i] = BF_increment_new(1);
                break;

            case BF_DECREASE:
                inst_arr[i] = BF_increment_new(-1);
                break;

            case BF_RIGHT:
                inst_arr[i] = BF_move_new(1);
                break;

            case BF_LEFT:
                inst_arr[i] = BF_move_new(-1);
                break;

            case BF_PRINT:
                //printf("printing \n");
                inst_arr[i] = BF_print_new();
                break;

            case BF_READ:
                inst_arr[i] = BF_read_new(); 
                break;

            case BF_START_LOOP:
                inst_arr[i] = BF_beginLoop_new();
                stack_push(&loopStack, i);
                break;

            case BF_END_LOOP: {
                int beginIndex = stack_pop(&loopStack);
                inst_arr[i] = BF_endLoop_new(beginIndex);

                /* Uuendame ka tsükli algust, et seal oleks olemas 
                   info kus asub tsükli lõpp! */
                inst_arr[beginIndex]->loopForwardIndex = i;

                break;

            }

            default:
                /* Ignoreerime sümboleid, mida me ei tunne. */
                break;
        }
        i++;
    }
}

void run(struct BF_instruction_st **inst_arr, int inst_arr_len) {
    int i = 0;
    while (i >= 0 && i < inst_arr_len) {  // Ensure i stays within bounds
        if (inst_arr[i] != NULL) {
            inst_arr[i]->run(inst_arr[i], &i);
        } else {
            i++;  // Manually advance if no instruction exists
        }
    }
}

void printAsm(struct BF_instruction_st **inst_arr, int inst_arr_len) {

     printf(
        "global main\n"
        "extern putchar\n"
        "section .bss\n"
        "mem    resb 30000\n"
        "section .text\n"
        "main:\n"
        "    mov edi, mem\n"
        "    xor eax, eax\n"
        "    mov ecx, 30000\n"
        "    rep stosb\n"
        "    xor ebx, ebx\n"
    );
    /* Käime läbi kõik instruktsioonid ja käivitame neil
       funktsiooni printAsm. */
    for (int i = 0; i < inst_arr_len; i++) {
       if (inst_arr[i] != NULL) {
           inst_arr[i]->printAsm(inst_arr[i], &i);
       }
    }

    /* Funktsiooni main lõpp. */
    printf("    xor eax, eax\n");
    printf("    ret\n");
}
void interpret2(char *program) {
    /* Leiame programmi lähtekoodi pikkuse. */
    int program_len = strlen(program);
    
    /* Teeme massiivi, mis hoiab viitasid, mida on kokku program_len tükku. Viitade
       algväärtustamine toimub parse() funktsioonis. Massiivi pikkus on võetud varuga */
    struct BF_instruction_st **inst_arr = malloc(sizeof(struct BF_instruction_st *) * program_len);

    /* Parsime sisendprogrammi, mille tulemus salvestatakse inst_arr massiivi. */
    parse(inst_arr, program);
    /* Käivitame programmi. */
    //run(inst_arr, program_len);
    printAsm(inst_arr,program_len);
    /** TODO! Mälu vajab vabastamist! **/
    for (int i = 0; i < program_len; i++) {
            free(inst_arr[i]);  // Vabastame iga instruksiooni jaoks eraldatud mälu
    }
    free(inst_arr);
}

int main(int argc, char **argv) {
    /* Kontrollime, et programmile anti täpselt üks parameeter (lisaks programmi nimele endale). */
    if (argc != 2) {
        printf("Programmil peab olema üks parameeter, milleks on BF programm!\n");

        /* Tagastame veakoodi. */
        return 1;
    }

    /* Käivitame programmi, mille kasutaja andis käsurealt. */
    interpret2(argv[1]);

    return 0;
}
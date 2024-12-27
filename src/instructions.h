#ifndef __INSTRUCTIONS_H__
#define __INSTRUCTIONS_H__
struct BF_instruction_st {
    /* Instruktsiooni väljakutse funktsioon. Esimene parameeter on instruktsiooni
       objekt ise ja teine on viit instruktsiooni indeksile, mida antud funktsioon
       peab kas suurendama või muutma (näiteks tsüklites). */
    void (*run)(struct BF_instruction_st *instruction, int *index);

    /* Assembleri implementatsiooni funktsioon. Trükib välja vastava instruktsiooni
       implementatsiooni assembleris. */
    void (*printAsm)(struct BF_instruction_st *instruction, int *index);
    void (*free)(struct BF_instruction_st *p);
    /* Implementatsiooni spetsiifilised väärtused. */
    union {
        /* Suurenda liitmisel väärtust selle võrra (võib olla ka negatiivne). */
        int increment;

        /* Mitu kohta tuleb mälu asukohta liigutada (võib olla ka negatiivne). */
        int numberOfPositions;

        /* Indeks kuhu hüpata tsükli alguses kui getMem() == 0. */
        int loopForwardIndex;

        /* Indeks kuhu hüpata tagasi tsükli lõpus kui getMem() != 0. */
        int loopBackIndex;
    };
};
struct BF_instruction_st *BF_increment_new(int increment);
struct BF_instruction_st *BF_beginLoop_new(void);
struct BF_instruction_st *BF_endLoop_new(int beginIndex);
struct BF_instruction_st *BF_move_new(int positions);
struct BF_instruction_st *BF_print_new(void);
struct BF_instruction_st *BF_read_new(void);

/* Function prototypes for run functions */
void BF_increment_run(struct BF_instruction_st *instruction, int *index);
void BF_beginLoop_run(struct BF_instruction_st *instruction, int *index);
void BF_endLoop_run(struct BF_instruction_st *instruction, int *index);
void BF_print_run(struct BF_instruction_st *instruction, int *index);
void BF_read_run(struct BF_instruction_st *instruction, int *index);
void BF_move_run(struct BF_instruction_st *instruction, int *index);
void BF_instruction_free(struct BF_instruction_st *instruction);

void BF_increment_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_beginLoop_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_endLoop_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_move_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_print_printAsm(struct BF_instruction_st *instruction, int *index);
void BF_read_printAsm(struct BF_instruction_st *instruction, int *index);

#endif
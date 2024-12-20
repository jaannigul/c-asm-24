#ifndef __MEM_H__
#define __MEM_H__

int mem_inc(void);
int mem_dec(void);
int mem_left(void);
int mem_right(void);
int mem_get(void);
int mem_set(char v);
void mem_printDebug(void);
int mem_add(int amount);
int mem_move(int numberOfPositions);
void mem_init();

#endif
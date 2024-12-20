#include <stdio.h>
#include "mem.h"
#define MEM_SIZE 30000
static int i = 0; // indeks
static char mem[MEM_SIZE] = {0};
// suurendab indeksiga viidatud massiivi elemendi väärtust ühe võrra. Tagastab uue väärtuse.
int mem_add(int amount){
    mem[i] += amount;
    return mem[i];
}
int mem_move(int numberOfPositions){
    i += numberOfPositions;
    if (0 > i) i = 0;
    else if (MEM_SIZE < i) i = MEM_SIZE - 1;
    return i;
}
void mem_init(){
    for (size_t ix = 0; ix < MEM_SIZE; ix++)
    {
        mem[ix] = 0;
    }
    i = 0;
    
}
int mem_inc() {
    return mem_add(1);
}


int mem_dec() {
    return mem_add(-1);
}

int mem_left() {
    return mem_move(-1);
}
int mem_right() {
    return mem_move(1);
}

int mem_get(void)
{
    //printf("mem get: %d\n",mem[i]);
    return mem[i];
}
int mem_set(char v)
{
    mem[i] = v;
    return mem[i];
}
void mem_printDebug(void)
{
    printf("index: %d mem [%d .. %d]: ", i, i, (i + 9) % MEM_SIZE);
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", mem[(i + j) % MEM_SIZE]);
    }
    printf("\n");
}
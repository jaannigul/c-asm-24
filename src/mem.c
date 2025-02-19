#include <stdio.h>
#include <string.h>
#include "mem.h"
#define MEM_SIZE 30000
static int i = 0; // indeks
static unsigned char mem[MEM_SIZE] = {0};
// suurendab indeksiga viidatud massiivi elemendi väärtust ühe võrra. Tagastab uue väärtuse.
int mem_add(int amount){
     mem[i] = (unsigned char)((mem[i] + amount) & 0xFF);
    return mem[i];
}
int mem_move(int numberOfPositions) {
    i = (i + numberOfPositions) % MEM_SIZE;
    if (i < 0) {
        i += MEM_SIZE;
    }
    return i;
}
void mem_init(){
    memset(mem, 0, sizeof(mem));
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
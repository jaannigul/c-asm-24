Kuidas kompileerida:
    make all

Kuidas käivitada interpretaator:
    Eemaldada kommentaar real 237 failis bfi.c, nii, et reale alles jääks "run(inst_arr, program_len);".
    make clean
    make all
    ./bfi <BF kood>

Kuidas käivitada kompilaator:
    Välja kommenteerida real 237 failis bfi.c kood "run(inst_arr, program_len);", muidu kirjutatakse bfi väljund asm faili algusesse.
    ./bfi <BF kood> > failinimi.asm
    nasm -felf32 failinimi.asm
    gcc -m32  failinimi.o -o failinimi
    ./failinimi
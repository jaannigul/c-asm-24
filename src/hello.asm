; See kood on transleeritud Brainfuck programmist:

; ++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.

global main
extern mem_add
extern mem_move
extern mem_inc
extern mem_dec
extern mem_left
extern mem_right
extern mem_get
extern mem_set
extern mem_printDebug

extern putchar
section .text

   ;;;; Instruktsioon [
silt_14:

    ; eax = mem_get();
    call mem_get

    ; if (eax == 0= goto silt_33
    cmp eax, 0
    je silt_33

    ; Kui ei olnud võrdsed, siis jätka jägmiselt realt

;;;; Instruktsioon ]
    ; Hüppa tsükli algusesse
    jmp silt_14
silt_33:


main:
    ;;;; Instruktsioon +++
    push dword 3
    call mem_add

    ; Puhastame magasini
    add esi, 4

    ;;;; Instruktsioon +
    call mem_inc

    ;;;; Instruktsioon +
    call mem_inc

    ;;;; Instruktsioon .
    ; eax = mem_get();
    call mem_get

    ; putchar(eax);
    push eax
    call putchar

    ; Puhastame magasini
    add esp, 4

    ;;;; Programmi lõpp
    ret
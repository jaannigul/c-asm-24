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
main:
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon [
silt_8:
    call mem_get
    cmp eax, 0
    je silt_48
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon [
silt_14:
    call mem_get
    cmp eax, 0
    je silt_33
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon ]
    call mem_get
    cmp eax, 0
    jne silt_14
silt_33:
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon [
silt_43:
    call mem_get
    cmp eax, 0
    je silt_45
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon ]
    call mem_get
    cmp eax, 0
    jne silt_43
silt_45:
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon ]
    call mem_get
    cmp eax, 0
    jne silt_8
silt_48:
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon <
    call mem_left
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon -
    mov eax, -1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    ;;;; Instruktsioon >
    call mem_right
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon +
    mov eax, 1
    call mem_add
    ;;;; Instruktsioon .
    call mem_get
    movzx eax, al
    call putchar
    xor eax, eax
    ret

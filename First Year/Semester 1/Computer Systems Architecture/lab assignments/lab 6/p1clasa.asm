bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s dd 127F5678h, 0ABCDABCDh
    d dd 0
; our code starts here
segment code use32 class=code
    start:
    ;TASK
    ;An array with doublewords containing packed data (4 bytes written as a single doubleword) is given. Write an asm program in order to obtain a new array of ;doublewords, where each doubleword will be composed by the rule: the sum of the bytes from an odd position will be written on the word from the odd position and ;the sum of the bytes from an even position will be written on the word from the even position. The bytes are considered to represent signed numbers, thus the ;extension of the sum on a word will be performed according to the signed arithmetic.
        ; ...
        mov esi, s
        mov edi, d
        mov bl, 0 ;sum of bytes from odd posititons
        mov cl, 0 ;sum of bytes from even positions
        lodsb ;al=primul byte din s, care e pe poz para, adica 0
        add cl, al
        lodsb ; al=al doilea byte din s, care e pe poz impara, adica 1
        add bl, al
        lodsb ;al=al treilea byte din s, care e pe poz para, adica 2
        add cl, al
        lodsb ;al=al patrulea byte din s, de pe poz impara, adica 3
        add bl, al
        
        ;daca tinem cont de little endian, in memorie primul dd din s este pus: 78 56 7F 12, si cand face lodsb, primul byte pe care il ia va fi 78, nu 12
        ;deci prima oara ar lua byte-ul de pe poz impara in scrierea naturala, pt ca in scrierea naturala 78 e byte-ul de pe poz 3 in dd, care e poz impara
        ;si ar 
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

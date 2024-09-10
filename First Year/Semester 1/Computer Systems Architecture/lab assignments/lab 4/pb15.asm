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
    c dd 0
    a dw 0100110100101001b
    b dw 1101001110001010b

    
    
; our code starts here
segment code use32 class=code
    start:
        ; ...
         ;TASK:
         ;Given the words A and B, compute the doubleword C as follows:
            ;the bits 0-2 of C have the value 0
            ;the bits 3-5 of C have the value 1
            ;the bits 6-9 of C are the same as the bits 11-14 of A
            ;the bits 10-15 of C are the same as the bits 1-6 of B
            ;the bits 16-31 of C have the value 1
            
            mov dword [c], 0 
            mov al, 00111000b
            or byte [c], al ;primii 3 biti se transforma in 0, bitii 3-5 sunt 1
            mov ax, [a]
            shr ax, 11 ;bitii 11-14 initiali sunt acum primii biti din ax, adica the lower biti, iar cei 11 biti pe care i-am shiftat sunt 0
            shl ax, 12 ;bitii 11-14 initiali sunt acum ultimii biti din ax, adica the higher biti, si acum toti bitii lower than these sunt 0
            shr ax, 6 ;pun bitii acestia, 11-14 initiali, pe pozitia 6-9
            or word [c], ax ;the bits 6-9 of C are the same as the bits 11-14 of A
            mov ax, [b]
            shr ax, 1 ;bitii 1-6 initiali sunt pe 0-5
            shl ax, 10; bitii 1-6 initali sunt acum the left most bits, the highest bits, pe pozitiile 10-15 pe care trebe sa ajunga si in c, si toti bitii
                      ;dinaintea lor sunt 0, cum au fost shiftati. fac shl 10 pt ca tre sa mut cei 6 biti din most right to most left, adica 16-6=10
            or word[c], ax;the bits 10-15 of C are the same as the bits 1-6 of B
            mov word[c+2], 0FFFFh
            
            
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

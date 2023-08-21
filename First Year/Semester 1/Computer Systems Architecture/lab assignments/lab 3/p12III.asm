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
    a db 2
    b dw 3
    c db 5
    d dd 4
    x dq 6
    
; our code starts here
segment code use32 class=code
    start:
        ;TASK: (a*b+2)/(a+7-c)+d+x; a,c-byte; b-word; d-doubleword; x-qword unsigned
        mov al, [a]
        mov ah, 0 ;ax=a
        mov bx, [b]
        mul bx 
        add ax, 2 ;ax=a*b+2
        mov bl, [a]
        add bl, 7
        sub bl, [c]
        mov bh, 0 ;bx=
        mov bh, 0 ;bx=a+7-c 
        div bx ;ax=(a*b+2)/(a+7-c)=2
        push ax
        mov eax, 0
        pop ax ;eax=(a*b+2)/(a+7-c)=2
        add eax, [d] ;=6
        mov edx, 0
        add eax, [x];=12
        adc edx, [x+4]
        ;e buuuun
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

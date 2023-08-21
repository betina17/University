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
    a db 4
    b db 2
    c db 5
    d dw 3
; our code starts here
segment code use32 class=code
    start:
        ; TASK: [(a-b)*3+c*2]-d
        mov al, [a] ;4
        mov bl, [b] ;2
        sub al, bl ; 4-2=2
        mov cl, 3 
        mul cl ; ax=al*3=2*3=6
        mov bx, ax ; bl=6=(a-b)*3
        mov al, [c] ;5
        mov cl, 2 
        mul cl ; ax=5*2=10=c*2  REZULTATUL INMULTIRILOR MEREU SE SALVEAZA IN AX, NU IN AL
        add bx, ax ; (a-b)*3+c*2=6+10=16
        mov ax, [d]
        mov bh, 0
        sub bx, ax ; [(a-b)*3+c*2]-d=16-3=13
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

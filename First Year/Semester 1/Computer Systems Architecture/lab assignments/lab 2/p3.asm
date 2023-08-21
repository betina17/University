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
    a dw 20
    b dw 40
    c dw 70
    d dw 30

; our code starts here
segment code use32 class=code
    start:
        ; TASK: b+a-(4-d+2)+c+(a-b)
        mov ax, [d]
        mov bx, 4
        add bx, 2
        sub bx, ax
        mov cx, [b]
        add cx, [a]
        sub cx, bx
        add cx, [c]
        mov ax, [a]
        mov bx, [b]
        sub ax, bx
        add cx, ax
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

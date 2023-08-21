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
    a db 3
    b dd 2
    c dq 4

; our code starts here
segment code use32 class=code
    start:
        ;TASK: c+(a*a-b+7)/(2+a), a-byte; b-doubleword; c-qword
        mov al, [a]
        mul byte [a]
        mov cx, ax
        mov eax, 0
        mov ax, cx
        sub eax, [b]
        add eax, 7 ;eax=(a*a-b+7)
        mov bl, [a] 
        mov bh, 0  ;sau puteam add bl, 2 si mov bh, 0 dar cum am scris cu albastru ma face sa vad mai bine ca 2+a e in bx
        add bx, 2 ;bx=2+a
        push eax ;face chestiile astea pt ca trb sa imaprtim la bx, iar impartirile nu se fac pe eax, ci pe ax;dx, care e egal cu eax. pt ca imi imparte si catul il pune in lower partu de la eax, care e ax, si restu in higher part, care e dx
        pop ax ;pe stiva cand dau push eax prima oara pune higher part, adica dx, deci pe el il scot dupa ax (first in last out)
        pop dx
        div bx
        mov cx, ax
        mov eax, 0
        mov ax, cx ;am extins ax in eax pt ca
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

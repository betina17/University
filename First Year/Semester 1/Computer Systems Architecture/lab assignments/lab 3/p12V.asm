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
        a db 10
        b dw 20
        c dd 30
        d dq 40

; our code starts here
segment code use32 class=code
    start:
        ;TASK: (a-b-c)+(d-b-c)-(a-d) signed
        mov al, [a]
        cbw ;ax=a
        sub ax, [b] ;ax=a-b
        cwde ;eax=a-b 
        sub eax, [c] ;eax=a-b-c
        push eax
        mov ax, [b]
        cwde 
        sub eax, [c] ;eax=b-c
        cdq
        mov ebx, [d] ;lower partu lui d
        mov ecx, [d+4]
        sub ebx, eax ;d-b-c
        sbb ecx, edx
        pop eax
        cdq
        add ebx, eax
        adc ecx, edx 
        mov al, [a]
        cbw
        cwde
        cdq
        sub eax, [d]
        sbb edx, [d+4]
        sub ebx, eax
        sbb ecx, edx
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

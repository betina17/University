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
        ;TASK:  (a+b+d)-(a-c+d)+(b-c) signed
        mov al, [a]
        cbw ;ax=a
        add ax, [b] ;ax=a+b
        cwde ;eax=a+b daca scriam cwd imi punea pe dx:ax
        cdq ;edx:eax=a+b 
        ;pun inainte sa folosesc adc(add carry) sau sbb(sub borrow)
        add eax, [d]
        adc edx, [d+4] ; edx:eax=a+b+d
        push edx
        push eax
        mov al, [a]
        cbw; ax=a
        cwde ;eax=a convert word to double word extended
        sub eax,  [c]
        cdq ;edx:eax=a-c convert double word to quad word
        add eax, [d] ; lower part a-c+d
        adc edx, [d+4] ; edx:eax=a-c+d higher part of a-c+d
        pop ebx ;lower part of a+b+d punem in ebx
        pop ecx ;higher part of a+b+d punem in ecx
        sub ebx, eax
        sub ecx, edx ;50=32 in hexa ;in ebx:ecx am (a+b+d)-(a-c+d)
        mov ax, [b]
        cwde ;eax=b dd
        sub eax,  [c] ;eax=b-c
        cdq ;edx:eax=b-c quad word  edx-higher part, eax-lower part
        add ebx, eax ;prima oara adunam lower partu tre sa fie 40 care e 28 in hexa
        adc ecx, edx ;dupa higher partu NU UITA CARRY UL-ADC NU ADD
        ;e buuun
        
        
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

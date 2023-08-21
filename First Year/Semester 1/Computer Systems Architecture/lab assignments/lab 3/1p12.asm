bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll 
;extern printf
;import printf msvcrt.dll   ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
        a db 10
        b dw 20
        c dd 30
        d dq 40
        ;printf_format db "%lld", 0
; our code starts here
segment code use32 class=code
    start:
        ;TASK: (a+b+d)-(a-c+d)+(b-c) unsigned
        mov al, [a]
        mov ah, 0 ;ax=a fac a dw
        mov dx, [b] 
        add ax, bx ;ax=a+b 
        push ax
        mov eax, 0
        pop ax ;eax=a+b am facut a+b dd
        mov edx, 0
        add eax, [d]
        adc edx, [d+4]
        ;push edx 
        ;push eax
        ;push printf_format
        ;call [printf]
        ;add ESP, 12
        
       
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
# created by virtualenv automatically
*

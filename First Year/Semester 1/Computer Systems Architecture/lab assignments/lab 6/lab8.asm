bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import printf msvcrt.dll     ; indicating to the assembler that the printf fct can be found in the msvcrt.dll library
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dd 0
    b dd 0 ;NEAPARAT TREBUIE SA DEFINIM DD, PENTRU CA CU %D EL ASTEAPTA SA CITIM UN INT, CARE E PE 4 BYTES, ADICA DD, NU POTI SPUNE BYTE SAU WORD
    message1 db "a*b=%d", 0
    message2 db "introduce the two numbers, separated by comma>", 0
    format db "%d %d", 0
; our code starts here
segment code use32 class=code
    start:
        ; ...TASK: READ 2 NUMBERS FROM THE KEYBOARD, MULTIPLY THEM AND PRINT THEM
        push dword message2
        call [printf]
        add esp, 4
        
        push dword a
        push dword b
        push dword format
        call [scanf]
        add esp, 4*3
        
        mov eax, 0
        mov al, [a]
        mov bl, [b]
        mul bl
        
        push dword eax
        push dword message1
        call [printf]
        add esp, 4*2
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        
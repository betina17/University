bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; 
    a dw 1000110001111111b
    b dw 0011000010111001b
    c dd 0

; our code starts here
segment code use32 class=code
    start:
        ;TASK: Given the words A and B, compute the doubleword C as follows:
        ;the bits 0-6 of C have the value 0
        ;the bits 7-9 of C are the same as the bits 0-2 of A
        ;the bits 10-15 of C are the same as the bits 8-13 of B
        ;the bits 16-31 of C have the value 1
        xor eax, eax ;face toti bitii din eax sa fie 0
        mov ax, [a]
        ;mov ah, 0 ;nu e bine asa, pt ca ax=ah:al, si am pus a pe ax, primii 8 bits din a sunt pe ah, si daca eu fac
        ;ah sa fie 0, pierd primii 8 biti din a pt ca se inlocuiesc cu 0
        xor ebx, ebx
        mov bx, [b]
        ;mov bh, 0 ;ebx=b
        mov ecx, 0
        and eax, 00000000000000000000000000000111b ;we isolate the bits 0-2 of a
        rol eax, 7
        or ecx, eax ;punem bitii in rezultat
        and ebx, 000000000000000000011111100000000b ; we isolate the bits 8-13 of b
        rol ebx, 2
        or ecx, ebx ; punem bitii in rezultat
        or ecx, 11111111111111110000000000000000b
        mov [c], ecx
        push dword 0
        call [exit]
        
        
        
        
        
        
            
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

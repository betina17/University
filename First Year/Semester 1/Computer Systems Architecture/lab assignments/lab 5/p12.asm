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
    s1 db "abcdef"l
    l1 equ $-s1 
    s2 db "12345"
    l2 equ $-s2 
    d times (l1 + l2 +1) // 2 db 0 

; our code starts here
segment code use32 class=code
    start:
        ; TASK: Two character strings S1 and S2 are given. Obtain the string D by concatenating the elements found on even positions in S2
        ;and the elements found on odd positions in S1.
        mov ecx, (l2+1)//2
        mov ebx, 0
        mov edx, 0
        Repeat1:
            mov al, [s2+ebx]
            mov [d+edx], al
            inc ebx
            inc ebx
            inc edx
        loop Repeat1
        
        mov ecx, (l1+1)//2
        mov ebx, 1
        
        Repeat2:
            mov al, [s1+ebx]
            mov [d+edx], al
            inc ebx
            inc ebx
            inc edx
        loop Repeat2   
            
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

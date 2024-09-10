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
        s db 1,2,3,4
        len equ $-s
        d times (len-1) dw 0
; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;TASk: Given a byte string S of length l, obtain the string D of length l-1 as D(i) = S(i) * S(i+1) (each element of D is the product of two consecutive elements of S).
;Example:
;S: 1, 2, 3, 4
;D: 2, 6, 12
        mov ecx, len-1
        mov esi, 0
        mov edi, 0
        jecxz end
        repeat_loop:
            mov al, byte[s+esi] ;al=s(i)
            mov bl, byte[s+esi+1] ;bl=s(i+1)
            mul bl ;ax=S(i) * S(i+1)
            mov [d+edi], ax ;punem primul produs in data
            inc esi
            add edi, 2
            loop repeat_loop
            
        end:    
        
        ; exit(0)
        INT 3
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
        
            
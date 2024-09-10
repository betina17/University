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
    
    input db 1,2,3,4,5,6
    N equ ($-input)
    src db 2,2,4,4,6,6
    dst db 1,1,3,3,5,5
    output times N db 0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;TASK
        ;A string of bytes 'input' is given together with two additional strings of N bytes each, 'src' and 'dst'. Obtain a new string of bytes called 'output' from ;the 'input' string, by replacing all the bytes with the value src[i] with the new value dst[i], for i=1..N.
        mov esi, input
        mov edi, src
        mov ecx, N
        jecxz done
        mov ebx, 0
        if:
            cmpsb 
            je replace ;daca sunt egale sare la replace
            mov dl, byte [esi-1]
            mov [output+ebx], dl      ;daca nu sunt, muta elem din input in output, esi-1 pt ca a incrementat deja 
            jmp endif 
            replace:
                mov dl, byte [dst +ebx]
                mov [output+ebx],  dl ;pune in output byte-ul din dst
            
            endif:
                inc ebx
            loop if
            
        
        
        done:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

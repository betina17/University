bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                      ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions'
import printf msvcrt.dll
import scanf msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    a dd 0
    b dd 0
    message1 db "introduce the two numbers in base 10, separated by comma>", 0
    format db "%d,%d", 0
    format_less db "<%d> < <%d>", 0
    format_equal db "<%d> = <%d>", 0
    format_higher db "<%d> > <%d>", 0
    
; our code starts here
segment code use32 class=code
    start:
        ; ...TASK: Read two numbers a and b (in base 10) from the keyboard and determine the order relation between them (either a < b, or a = b, or a > b). Display the result in the following format: "<a> < <b>, <a> = <b> or <a> > <b>".
        
        push dword message1
        call [printf]
        add esp, 4
        
        push dword b
        push dword a
        push dword format
        call [scanf]
        add esp, 4*3
        
        mov eax, 0
        mov ebx, 0
        mov al, [a]
        mov bl, [b]
        cmp al, bl
        jl a_is_lower
        je equal
        jg a_is_higher
     
        a_is_lower:
             push dword [b]
             push dword [a]
             push dword format_less
             call [printf]
             add esp, 4*3
             jmp end
             
        equal:
             push dword [b]
             push dword [a]
             push dword format_equal
             call [printf]
             add esp, 4*3
             jmp end
             
       a_is_higher:
             push dword [b]
             push dword [a]
             push dword format_higher
             call [printf]
             add esp, 4*3
             
             
             
             
        
        end:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

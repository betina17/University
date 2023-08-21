bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, printf, scanf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll        ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ;...
    a dd 0
    
    message db "a = <%d> (base 10), a = <%x> (base 16)", 0  ;cu d afisez val in baza 10, cu x afisez val in baza 16
    format db "%d", 0 ;o sa citesc o singura valoare
    
; our code starts here
segment code use32 class=code
    start:
        ;TASK: A negative number a (a: dword) is given. Display the value of that number in base 10 and in the base 16 in the following 
        ;format: "a = <base_10> (base 10), a = <base_16> (base 16)"
        push dword a 
        push dword format
        call [scanf]       
		add esp, 4 * 2 
        
        mov ebx, [a] ;pt ca am nevoie sa afisez 2 numere, dar care sa fie acelasi nr, doar ca in baze diferite, copiez a in ebx, si dau
                        ;push si la a si la ebx, ca sa le afisez
        push dword [a]
        push dword ebx ;cand dai call le afiseaza in mod invers de cum le scrii in code sgement, si normal pt ca le ia de pe stack
        push message 
        call [printf]
        add esp, 4*3
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

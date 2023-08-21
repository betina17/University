bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern scanf, printf
import scanf msvcrt.dll
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    s dq 1122334455667788h, 99AABBCCDDEEFF11h, 0hFF00000000000055, 0hFFFEFFFFFFFFEFFF, 450000AB000000ABh, 11113733555577ABh
    len_sir EQU $-s
    format db "%d",0
    n dd 0 ;dd pt ca punem pe stack la scanf
    sir resb 1000
    format_nou db "%s", 0
    

; our code starts here
segment code use32 class=code
    start:
        ; TASK: (a-b-c)+(d-b-c)-(a-d) signed
        push dword n
        push dword format
        call [scanf]
        add esp, 4*2
        
        cmp [n], dword 1
        jl bye
        cmp [n], dword 6
        jg bye
        
        
        mov esi, s
        
        mov edi, sir
        
        mov edx, 0
        mov eax, 0
        mov eax, len_sir
        div dword [n] ;in eax lunimea sirului impartita la nasm
        mov ecx, eax
        
        mov edx, 0
        
        Bucla:
            mov al, [esi + edx]
            mov [edi], al
            inc edi
            add edx, [n]
            loop Bucla
            
        mov edi, 0
            
        push dword sir
        push dword format_nou
        call [printf]
        add esp, 4*2
        
            
       
    bye:
       
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

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
    a db 2
    b db 3
    c db 4
    e dw 5
    f dw 6
    g dw 7
    h dw 8
    

; our code starts here
segment code use32 class=code
    start:
        ;TASK: (e + g) * 2 / (a * c) + (h – f) + b * 3
        mov al, [b]
        mov bl, 3
        mul bl 
        mov dl, al ;dl=b*3=9
        mov ax, [e]
        add ax, [g]
        mov bx, 2
        mul bx ;24
        push dx
        push ax
        pop ebx ;(e + g) * 2=24
        mov al, [a]
        mov cl, [c]
        mul cl 
        mov dl, al ;a*c=8
        mov eax, ebx ; (e + g) * 2=24
        mov ah, 0
        div dl ; (e + g) * 2 / (a * c)=24/8=3
        mov ecx, eax
        mov ch, 0 ;cx=3
        mov al, [b]
        mov bl, 3
        mul bl ;al=3*3=9
        mov ah, 0
        mov bx, [h]
        mov dx, [f]
        sub bx, dx ; bx=h-f=8-6=2
        add cx, bx ; cx=(e + g) * 2 / (a * c) + (h – f)=3+2=5
        add cx, ax; cx=(e + g) * 2 / (a * c) + (h – f) + b * 3=5+9=14
        
        
        
        
        
        
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

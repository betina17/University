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
        a db 10
        b dw 20
        c dd 30
        d dq 40
; our code starts here
segment code use32 class=code
    start:
        ; TASK: (a+b+d)-(a-c+d)+(b-c) unsigned
        mov al, [a]
        mov ah, 0 ;ax=a fac a word
        add ax, [b] ;ax=a+b 
        push ax
        mov eax, 0
        pop ax ;eax=a+b am facut a+b dd
        mov edx, 0
        add eax, [d]
        adc edx, [d+4] ; in eax si edx am a+b+d dq; eax e 70, adica 46 in baza 16, iar edx e 0, adica restu
        mov bl, [a]
        mov bh, 0 ;bx=a am fc a word
        push bx
        mov ebx, 0
        pop bx ;ebx=a am fc a dd, ca si c
        mov ecx, [c]
        sub ebx, ecx ;ebx=a-c, ecx e liber, ebx e dd, adica -20
        mov ecx, 0
        add ebx, [d]
        adc ecx, [d+4] ;in ebx-lower part cu dd=a-c si primii 4 bytes din d si ecx-higher part cu ultimii 4 bytes din d
        ;in ebx si ecx am dq a-c+d; rez e 20, adica ebx e 14, care e 20 in baza 16, si ecx e 1, adidca am rest 1
        sub eax, ebx ;scad din lower part de la a+b+d lower partu de la a-c+d
        sbb edx, ecx ;scad din higher part de la a+b+d higher partu de la a-c+d
        ;in edx:eax am (a+b+d)-(a-c+d)
        mov bx, [b]
        push bx
        mov ebx, 0
        pop bx ;ebx=b dd
        sub ebx,  [c] ;ebx=b-c
        add eax, ebx
        adc edx, 0 ;am adaugat la dq (a+b+d)-(a-c+d) dd ebx=b-c, fara sa il transform, efectiv direct, am pus ebx la lower partu
        ;de la dq, adica la eax, si 0 la higher part, adica la edx, pt ca ai doar 0 la higher partu de la dd cand il transformi
        ;in dq. cand aduni 2 dq, se aduna lower parturile lor, si daca ai carry, se pune in higher partu
        ;la dq (a+b+d)-(a-c+d) higher partu putea sa fie altu decat 0, daca aveai carry/borrow de la calculul anterior a doua dq, adica de la scaderea  (a+b+d)-(a-c+d). dar la dd b-c, higher partu din el transformat in dq sigur era 0. 
        ;sper ca intelegi :))
        ;e buuun 
        
        
        
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

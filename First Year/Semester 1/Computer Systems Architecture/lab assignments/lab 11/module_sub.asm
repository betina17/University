bits 32
global Concatenation
extern stringconcat

segment code use32 class=code
    Concatenation:
        mov edi, stringconcat 
        mov esi, eax 
        
        
    .stringconcatLoop:
        lodsb 
        test al, al
        jz .gata
        stosb 
        push esi
        mov esi, ebx
        lodsb
        inc ebx
        test al, al
        jz .gata
        stosb
        pop esi
        jmp .stringconcatLoop
    .gata:
        mov al, 0
        stosb
        ret
   
        
        
        
        

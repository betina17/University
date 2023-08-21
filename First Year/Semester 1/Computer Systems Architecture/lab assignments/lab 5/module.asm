bits 32
global _Concatenation
extern stringconcat
segment data use32 class=data
segment code use32 class=code
    ;toti registrii trb sa ramana la fel asa cum au fost la inceput inainte sa se intre in functie
    ;de asta o sa dau push si pop la toti registrii pe care ii folosesc, dar in afara de eax, edx si ecx, conform conventiei cdlec, care ne lasa sa nu mai
    ;facem procedura asta la regsitrii astia
    ;registrii folositi sunt ca niste parametri ai functiei, si cand se iese din functie trb sa le redai parametrulor, care s-au schimbat
    ;in timpul parcurgerii functiei, valoarea initiala, cu care au intrat in functie, chestia asta sa o faci manual
    ;also, valoarea pe care o returneaza functia functia trb sa fie salvata in eax, de aia eu o sa mut edi in eax la final
    
    _Concatenation:
        PUSHAD
        push ebp
        mov ebp, esp
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
        mov eax, stringconcat
        mov esp, ebp
        pop ebp
        POPAD
        ret
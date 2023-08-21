bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fprintf, fclose, scanf             ; tell nasm that exit exists even if we won't be defining it
import fopen msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fprintf msvcrt.dll       ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fclose msvcrt.dll 
import scanf msvcrt.dll
import exit msvcrt.dll 
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    file_name db "FileOpen.txt",0
    a dd 0
    format db "%c", 0 ;citesc ca si caracter pt ca asa si pun in fisiwer, ca si string
    access_mode db "w", 0 ;si de asta
    file_descriptor dd -1  ;ai nevoie de chestia asta 
    printf_format db "%c" ;printez ca si text
    ;text times 100 db 0
    
; our code starts here
segment code use32 class=code
    start:
        ; TASK: A file name is given (defined in the data segment). Create a file with the given name, then read numbers from the keyboard 
        ;and write those numbers in the file, until the value '0' is read from the keyboard.
        push dword access_mode     
        push dword file_name
        call [fopen]
        add esp, 4*2 
        mov [file_descriptor], eax ; store the file descriptor returned by fopen
        cmp eax, 0
        je final ; check if fopen() has successfully created the file (EAX != 0)
        numbers:
            push a
            push format
            call [scanf]
            add esp, 4*2
            cmp dword [a], '0' ;vrea sa vada daca numarul introdus e 0, l am scris '0' si nu 0 pt ca eu introduc caractere, string-uri
                                ;ca am pus format db "%c", 0, c de la character
            
            je zero
            
            push dword [a]
            push printf_format
            push dword [file_descriptor]
            call [fprintf]
            add esp, 4*3
            
        jmp numbers ;asta face loop ul sa fie infinit, pt ca eu nu stiu de cate ori sa execut loop-ul, ca trebe executat de atatea ori
                     ;cate numere vrea utilizatorul sa introduca, asa ca nu am ce val sa ii dau lui ecx, si jmp eticheta ma ajuta
                     ;sa efectuez loop ul cat timp nu ies din el. ies in momentul in care imi intra in je zero, ca iese din numbers
                     ;si se duce la zero: si nu se mai intoarce, si e perf
        zero:
            push dword [file_descriptor]
            call [fclose]
            add esp, 4
        final:
            
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

bits 32 
global stringconcat
extern Concatenation

extern exit, printf
import exit msvcrt.dll    
import printf msvcrt.dll       
global start                  

segment data use32 class=data
    
    string1 db 'Hello little angel',0
    string2 db 'Honey tastes great', 0
    stringconcat resb 1000
    format db '%s', 0
    
   

segment code use32 class=code
    start:
    ;TASK: Two strings of characters of equal length are given. Calculate and display the results of the interleaving of the letters,
    ;for the two possible interlaces (the letters of the first string in an even position, respectively the letters from the first
    ;string in an odd positions). Where no character exist in the source string, the ‘ ’ character will replace it in the 
    ;destination string.
        mov eax, string1
        mov ebx, string2
        call Concatenation
        push dword stringconcat
        push format
        call[printf]
        add esp, 2*4 
        mov eax, string2
        mov ebx, string1
        call Concatenation
        push dword stringconcat
        push format
        call[printf]
        add esp, 2*4
        push    dword 0      
        call    [exit]       
        
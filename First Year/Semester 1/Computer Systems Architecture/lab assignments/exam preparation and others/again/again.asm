bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern fopen, fclose, fread, fwrite, perror, fprintf
import fclose msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fwrite msvcrt.dll
import perror msvcrt.dll
import fprintf msvcrt.dll 
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    spaces_counter db 0
    file_descriptor_file_we_read_from dd -1
    file_descriptor_file_we_write_to dd -1
    item dd 0
    file_we_read_from db "input.txt", 0
    read_mode db "r", 0
    file_we_write_to db "output_[sustrean_roberta].txt", 0
    write_mode db "w", 0
    error_message db "error", 0
    format_int db "%d",0
    new_line db 10, 0
    length_text_counter db 0
    nr_of_characters db 0
    
    ;C CODE-pt inc byte cu 1 in loc sa ii faci xor cu 5
    ;int main(){
    ; FILE *fd_in, *fd_out;
    ;char c;
    ;int count=0;
    ;fd_in = fopen("in.txt", "r");
    ;if(fd_in>0) {
    ;   fd_out = fopen("out.txt","w");
    ;   if(fd_out>0){
    ;       do{
    ;           count = fread(&c, sizeof(char), 1, fd_in);
    ;           c=c+1;
    ;           fwrite(&c, sizeof(char), 1, fd_out); adresa de la care citeste-c, si file descriptoru fisierului in care scrie, adica fd_out
    ;        }  while(count>0);
    ;        fclose(fd_out);
    ;   else
    ;        perror("Error output file: ");
    ;   fclose(fd_in);
    ;} else
    ;       perror("Error input file:");
    ;exit(0);
    ;}
; our code starts here
segment code use32 class=code
    start:
        ; ...TASK: this program reads the content of a file , xors each chaaracter (byte) with xor, and the writes these transformed bytes in a new file
        push read_mode
        push file_we_read_from
        call [fopen]
        add esp, 4*2 ;eax=file_descriptor_file_we_read_from

        cmp eax, 0
        je end_1
        ;store the file descriptor in another place because eax is always used for smth else
        mov [file_descriptor_file_we_read_from], eax 
        mov ebx, 0
        mov ebx, eax 
        


        ;now we open the file to write in
        push write_mode
        push file_we_write_to
        call [fopen]
        add esp, 4*2; eax=file_descriptor_file_we_write_to

        cmp eax, 0
        je end_2  ;uita-te pe c code de ce sarim altundeva
        mov [file_descriptor_file_we_write_to], eax 
        mov ebx, 0
        
        read_loop:
            push dword [file_descriptor_file_we_read_from]
            push dword 1 ;size of one char, size of one item you read
            push dword 1 ;we read one byte at a time, so one char (the size of one char is a byte), how many items we read
            push item    ;citim fiecare item din fisier in "item", ca sa ii dam increase (dam increase la fiecare byte)
            call [fread]
            add esp, 4*4
            
            inc byte [length_text_counter]
            cmp eax, 0
            je out_of_loop0 
           
            mov bl, byte [item]
            cmp bl, ' '
            jmp inc_spaces
            jmp continue9
            inc_spaces:
               inc byte [spaces_counter]
            
            continue9:
            push dword [file_descriptor_file_we_write_to]
            push dword 1
            push dword 1
            push item
            call [fwrite]
            add esp, 4*4
            jmp read_loop

        out_of_loop0:
            push new_line
            push dword[file_descriptor_file_we_write_to]
            call [fprintf]
            add esp, 4*2

            push dword [length_text_counter]
            push dword format_int
            push dword [file_descriptor_file_we_write_to]
            call [fprintf] ;fprintf(file_descriptor, text_to_write_from)
            add esp, 4 * 2
            
            push new_line
            push dword[file_descriptor_file_we_write_to]
            call [fprintf]
            add esp, 4*2
            
            push dword [spaces_counter]
            push dword format_int
            push dword [file_descriptor_file_we_write_to]
            call [fprintf] ;fprintf(file_descriptor, text_to_write_from)
            add esp, 4 * 2


        read_loop1:
            push dword [file_descriptor_file_we_read_from]
            push dword 1 ;size of one char, size of one item you read
            push dword 1 ;we read one byte at a time, so one char (the size of one char is a byte), how many items we read
            push item    ;citim fiecare item din fisier in "item", ca sa ii dam increase (dam increase la fiecare byte)
            call [fread]
            add esp, 4*4

            cmp eax, 0 
            je out_of_loop
            mov bl, byte[item]
            cmp bl, ' '
            je one_more_space
            jmp not_space

            one_more_space:
                inc byte[spaces_counter]
            not_space:
                jmp read_loop1

        out_of_loop:   
            mov bl, byte[item]
            cmp bl, ' '
            je one_more_space
            jmp not_space1
            one_more_space1:
            inc byte[spaces_counter]
        not_space1:
            push dword [spaces_counter]
            push dword format_int
            push dword [file_descriptor_file_we_write_to]
            call [fprintf] ;fprintf(file_descriptor, text_to_write_from)
            add esp, 4 * 2
            
        push new_line
        push dword[file_descriptor_file_we_write_to]
        call [fprintf]
        add esp, 4*2
        jmp read_loop2
        
        mov ebx, 0
        read_loop2:
            
            push dword [file_descriptor_file_we_read_from]
            push dword 1 ;size of one char, size of one item you read
            push dword 1 ;we read one byte at a time, so one char (the size of one char is a byte), how many items we read
            push item    ;citim fiecare item din fisier in "item", ca sa ii dam increase (dam increase la fiecare byte)
            call [fread]
            add esp, 4*4

            cmp eax, 0
            je out_of_loop1
            
            mov bl, byte [item]
            cmp bl, '9'
            ja not_number
            jmp continue
            not_number:
                cmp bl, '-'
                je change_to_add1
                jmp continue1
                change_to_add1:
                    mov byte [item], '+' 
                    jmp continue
                continue1:
                    cmp bl, '/'
                    je change_to_add2
                    jmp continue2
                    change_to_add2:
                        mov byte[item], '+'
                        jmp continue
                continue2:
                    cmp bl, '*'
                    je change_to_add3
                    jmp continue
                    change_to_add3:
                        mov byte[item], '+'
                        jmp continue
            continue:

            push dword [file_descriptor_file_we_write_to]
            push dword 1
            push dword 1
            push item
            call [fwrite]
            add esp, 4*4
            jmp read_loop

        out_of_loop1:
        push dword [file_descriptor_file_we_write_to]
        call [fclose]
        add esp, 4
        end_2:
            push dword error_message
            call [perror]
            add esp, 4

            push dword [file_descriptor_file_we_read_from]
            call [fclose]
            add esp, 4

            jmp no_error
        end_1:
            push dword error_message
            call [perror]
            add esp, 4

        no_error:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program







        ; exit(0)
       
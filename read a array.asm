.model small

.stack
    print macro p
    lea dx,p 
    mov ah,09h
    int 21h
    endm

    printvar macro p
    mov dl,p 
    mov ah,02h
    int 21h
    endm

.data
    msg1 db 10,13,"enter size of array:$"
    msg2 db 10,13,"enter elements into array(0-9): $"
    msg3 db 10,13,"enter the element to search: $"
    msg4 db 10,13,"found$"
    msg5 db 10,13,"not found$"
    num db 1 dup(?)
    arr db 10 dup(?)
    key db 1 dup(?)

.code
    mov ax,@data
    mov ds,ax
    print msg1
    mov ah,01h
    int 21h
    sub al,30h
    mov num,al
    mov cl,num
    mov ch,00h
    print msg2
    lea si,arr
    input:  mov ah,01h
            int 21h
            sub al,30h
            mov [si],al
            inc si
            loop input
    print msg3
    mov ah,01h
    int 21h
    sub al,30h
    mov key,al
    
    lea si,arr
    mov cl,num
    mov ch,00h
    mov ah,key
    search: cmp ah,[si]
            jz found
            inc si
            loop search
    print msg5
    jmp endlabel
    found: print msg4

    endlabel: mov ah,4ch
    int 21h
    end 

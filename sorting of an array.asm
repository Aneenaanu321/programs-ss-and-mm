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
    msg3 db 10,13,"sorted array is: $"
    num db 1 dup(?)
    arr db 10 dup(?)

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
        
    mov dl,num
    dec dl
    mov dh,00h
    mov bx,dx
    l1: mov cx,dx
        lea si,arr
    l2: mov al,[si]
        cmp al,[si+1]
        jc l3
        xchg al,[si+1]
        mov [si],al
    l3: inc si
        loop l2
        dec bx
        jnz l1

    print msg3
    lea si,arr
    mov cl,num
    mov ch,00h
    pri:mov al,[si]
    add al,30h
    printvar al
    inc si
    loop pri

    mov ah,4ch
    int 21h
    end
    
    
    
    
    

.model small

.stack
    
    print macro p
    lea dx,p 
    mov ah,09h
    int 21h
    endm

.data
    msg1 db 10,13,"enter the string:$"
    msg2 db 10,13,"reveresed string is: $"
    buff db 26
         db ?
         db 26 dup(0)

.code
    mov ax,@data
    mov ds,ax

    print msg1
    mov ah,0ah
    mov dx, offset buff
    int 21h
    mov si,offset buff+1
    mov cl,[si]
    mov ch,00h
    inc cx
    add si,cx
    mov al,'$'
    mov [si],al

    mov si,offset buff+2
    mov cx,00h
    l1: mov ax,[si]
        cmp al,'$'
        je l2
        push [si]
        inc si
        inc cx
        jmp l1
    l2: mov di,offset buff+2
    l3: pop dx
        mov [di],dx
        inc di
        loop l3
    mov al,'$'
    mov[si],al

    print msg2
    mov dx,offset buff+2
    mov ah,09h
    int 21h

    mov ah,4ch
    int 21h
    end

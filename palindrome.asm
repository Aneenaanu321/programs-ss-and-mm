.model small

.stack
    
    print macro p
    lea dx,p 
    mov ah,09h
    int 21h
    endm

    printvar macro p
    mov dx,p 
    mov ah,02h
    int 21h
    endm

.data
    msg1 db 10,13,"enter the string:$"
    msg2 db 10,13,"is palindrome $"
    msg3 db 10,13,"not palindrome $"
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

    lea di, buff+2
    mov si, di
    mov cl, buff[1]
    sub cl, 1
    add si, cx
    shr cx, 1
    l3: mov al,[si]
        mov bl,[di]
        cmp al,bl
        jne out2
        inc di
        dec si
        loop l3

        print msg2
        jmp endlabel
    out2:print msg3
    endlabel: mov ah,4ch
        int 21h
        end

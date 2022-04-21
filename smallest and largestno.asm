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
	arr db 06h, 04h, 01h, 02h, 00h
	string1 db 10,13,"largest number is:$"
	string2 db 10,13,"smallest number is:$"

.code
	mov ax, @data
	mov ds, ax

	lea si, arr
	mov cx, 04h
    mov al, [si]
    mov bl, [si]
    loop1: inc si
    cmp al, [si]
    jnc l1
    mov al, [si]
    ;jmp l2 
    l1:cmp bl, [si]
    jc l2
    mov bl, [si]
    l2:loop loop1

    print string1
    add al,30h
    printvar al
    print string2
    add bl,30h
    printvar bl
    
    mov ah,4ch
    int 21h
    end

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

.DATA
        tmp db ?
        msg1 db 10,13,"enter 1st no:$"
        msg2 db 10,13,"enter 2nd no:$"
        msg3 db 10,13,"sum is : $"
        msg4 db 10,13,"diff is : $"
        msg5 db 10,13,"pdt is : $"
        msg6 db 10,13,"Quotient is: $"
        msg7 db 10,13,"Remainder is: $"

.code

        mov ax,@data
        mov ds,ax

        print msg1

        mov ah,01h
        int 21h

        sub al,30h
        mov bh,al

        print msg2
        mov ah,01h
        int 21h

        sub al,30h
        mov ch,al

        mov tmp,00
        add tmp,bh
        add tmp,ch
        mov al,tmp
        mov ah,00
        mov cl,0ah
        div cl
        add al,30h
        add ah,30h
        mov bl,ah
        print msg3
        printvar al
        printvar bl

        subt:
                mov tmp,bh
                sub tmp,ch
                add tmp,30h
                print msg4
                printvar tmp

        pdt:
                mov ah,00
                mov al,bh
                mov cl,ch
                mul cl
                mov ah,00
                mov cl,0ah
                div cl
                add al,30h
                add ah,30h
                mov bl,ah
                print msg5
                printvar al
                printvar bl
        divi:
                mov ah,00
                mov al,bh
                div ch
                mov bl,ah
                print msg6
                add al,30h
                printvar al
                print msg7
                add bl,30h
                printvar bl


        mov ah,4ch
        int 21h

        end

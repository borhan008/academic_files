title prg5 : Displaying CSTE Departments for 20 times
.model small
.stack 100H
.data
msg db 0dh, 0ah, 'CSTE Department $'
.code   
main proc
    mov ax,@data
    mov ds,ax

    mov cx, 20
    lea dx,msg
    mov ah,9

    level1:
    int 21h
    loop level1
    
    exit:
    mov ah,4ch
    int 21h
    main endp
end main

    
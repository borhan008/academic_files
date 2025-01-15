title prg7 : Displaying 25 starts in one column
.model small
.stack 100h
.data
msg db 0dh, 0ah, '* $'
.code   
main proc
    mov ax,@data
    mov ds,ax
    mov cx, 25
    lea dx,msg
    mov ah,9h
    
    again:
    int 21h
    loop again

    exit:
    mov ah,4ch
    int 21h
    main endp
end main

    
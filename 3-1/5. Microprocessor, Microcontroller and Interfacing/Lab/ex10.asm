title prg10: Displaying IBM 256 characters
.model small
.stack 100h 
.data
.code
main proc
    mov ah, 2h
    mov cx, 256
    mov dl,0
    again:
        int 21H
        inc dl
        dec cx
        jnz again
        jcxz exit
    exit:
        mov ah,4ch
        int 21h 
        main endp
end main

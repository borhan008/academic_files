title prg6: Displaying 80 starts
.model small
.stack 100h
.data
.code
main proc
    mov cx,80
    mov ah,2
    mov dl,'*'

    top:
    int 21h
    loop top

    exit:
    mov ah,4ch
    int 21h
    main endp
end main

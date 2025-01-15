title prg3: Displaying an one line messsage
.model small
.stack 100h
.data
msg db 'CSTE 16th Batch!$'
.code
main proc
    mov ax,@data
    mov ds, ax

    mov ah,2
    lea dx,msg
    mov ah,9h
    int 21h

    exit:
    mov ah,4ch
    int 21h
    main endp
end main

title prg9: Displaying the characters untill the SPACE KEY is pressed
.model medium
.stack 100h 
.data
.code
main proc
    mov ah,1
    again:
        int 21h 
        cmp al, ' '
        je exit
    loop again 
    exit:
        mov ah,4ch
        int 21h 
        main endp
end main
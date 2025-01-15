title prg8: Displaying the characters untill the ENTER KEY is pressed
.model medium
.stack 100h 
.data
.code
main proc
    mov ah,1
    again:
        cmp al, 0dh
        je exit
        int 21h 
    loop again 

    exit:
    mov ah,4ch
    int 21h 
    main endp
end main


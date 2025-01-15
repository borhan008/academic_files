title prg2: Showing a character in output
.model small
.stack 100h
.data
.code
main proc
 	mov ah,2
 	mov dl,'B'
        int 21h

	exit:
        mov ah,4ch
        int 21h
        main endp
end main

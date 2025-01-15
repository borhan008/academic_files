title prg1: Taking Input
.model small
.stack 100h
.data
.code
main proc
 	mov ah,1
 	int 21h
 	mov bl,al

	exit:
        mov ah,4ch
        int 21h
        main endp
end main

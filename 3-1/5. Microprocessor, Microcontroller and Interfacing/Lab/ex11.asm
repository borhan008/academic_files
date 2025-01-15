TITLE PRG10: Debug program for arithmetic operation
.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC
    MOV AX,4000H 
    ADD AX,AX 
    SUB AX,0001H 
    NEG AX 
    INC AX

    EXIT: 
    MOV AH,4CH 
    INT 21H 
    MAIN ENDP
END MAIN

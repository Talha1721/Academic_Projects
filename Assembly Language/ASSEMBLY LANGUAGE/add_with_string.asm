.MODEL SMALL
.STACK 100H 
.DATA
MSG1 DB 'ENTER VALUE 01 : $'
MSG2 DB 'ENTER VALUE 02 : $'
MMM DB 'THE SUBTRUCTION OF 2 NO IS : $'

.CODE
 
 MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,MSG1
    MOV AH,9     ;print message
    INT 21H
    
    MOV AH,1
    INT 21H  ; INPUT 01 NUMBER
    MOV BL,AL
    
    MOV AH,2
    MOV DL,0AH
    INT 21H        ;\n
    MOV DL,0DH
    INT 21H 
    
    
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,MSG2
    MOV AH,9     ;print message
    INT 21H 
    
    
    MOV AH,1
    INT 21H           ;input 02 number
    MOV CL,AL  
    
    ;SUB BL,CL
    ;ADD BL,48
    
    
     MOV AH,2
    MOV DL,0AH
    INT 21H        ;\n
    MOV DL,0DH
    INT 21H 
    
     MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,MMM
    MOV AH,9     ;print message
    INT 21H
    
    
    MOV AH,2 
    MOV DL,BL
    INT 21H
    
    EXIT:
   
   MOV AH, 4CH
   INT 21H  
   MAIN ENDP
 END MAIN   
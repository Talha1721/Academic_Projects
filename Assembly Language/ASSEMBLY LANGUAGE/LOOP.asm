.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
 
 MOV AX,0
 MOV DX,10
 MOV CX,DX
 
BACK : ADD AX,CX
LOOP BACK
  
  ;MOV AX,2 
  ;MOV DX,AX
  ;INT 21H
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
   EXIT:
     
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN
 
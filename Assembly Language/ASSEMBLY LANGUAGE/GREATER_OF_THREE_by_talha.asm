.MODEL SMALL
.STACK 100H
.CODE
MAIN PROC
  
    
     MOV AH,1
     INT 21H
  MOV BL,AL       ; input bl
     INT 21H     
     MOV BH,AL    ; input bh
     INT 21H     
     MOV CL,AL    ; input cl
    
     CMP BL,BH    ; if(bl>bh)
     JGE L1       ;go>>L1
     CMP BH,CL
     JGE L2
     MOV AH,2
     MOV DL,CL
     INT 21H
     JMP EXIT
            
  L2: 
       MOV AH,2
       MOV DL,BH
       INT 21H
       JMP EXIT
        
     
  L1: 
      CMP BL,CL
      JGE LL1
  LL1: 
      MOV AH,2
      MOV DL,BL
      INT 21H
      JMP EXIT
      
        
     
     
     EXIT:
     
    MOV AH,4CH
    INT 21H        ;
    MAIN ENDP
 END MAIN
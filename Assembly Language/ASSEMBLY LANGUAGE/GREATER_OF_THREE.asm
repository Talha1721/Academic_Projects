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
     JGE L2       ;go>>l2
    
    L1:
     
     CMP BH,CL    ; if(bh>cl)
     JGE LL1      ; go ll1 
     MOV AH,2
     MOV DL,CL    ;else print cl
     INT 21H
     
     JMP EXIT
     
    LL1:  
     
     MOV AH,2
     MOV DL,BH     ;print bh
     INT 21H
     
     JMP EXIT
     
    L2:
     
     CMP BL,CL     ;if(bl>cl)
     JGE LL2       ;go>>ll2
     MOV AH,2
     MOV DL,CL     ;else print cl
     INT 21H
     
     JMP EXIT
     
    LL2:
    
      MOV AH,2
      MOV DL,BL    ;print bl
      INT 21H         
      
      JMP EXIT
     
     
     
     EXIT:
     
    MOV AH,4CH
    INT 21H        ;
    MAIN ENDP
 END MAIN
        INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA 
     
     S DW 1000 DUP(?)
     K DW 0
     MAX DW 0
      
     
     
.CODE

MAIN PROC 
     MOV DX,0
     PUSH DX 
     CALL SCANNER
     POP DX 
     MOV K,BX
     MOV CX,0
     PRINTN
     MOV SI,0
      
 LOOP1: 
       PUSH DX
       PUSH CX
       CALL SCANNER
       POP CX
       POP DX
       MOV S[SI],BX
       PRINTN
       CMP S[SI],DX
       JG NEXT
       JMP FALSE
       
   NEXT:MOV DX,S[SI]
   
   FALSE:
         ADD SI,2
         INC CX
         CMP CX,K
         JL LOOP1
         
         MOV BX,DX
         CALL PRINTER 
         
         JMP LAST
             
       
       
               
      
      
SCANNER PROC    
MOV CX,0                     ; CX=0

INPUT:
    MOV AH,1
    INT 21H
    CMP AL,13               ;INPUT IN AL
    JNE CALC
    JMP EXIT
    

CALC:
    MOV AH,0
    SUB AL,48          ;ASCI TO NUMERIC
    MOV BX,AX         ;INPUT IN BX // AX IN BX
    MOV AX,CX         ;AX HAS CX
    MOV DX,10         ;DX IS ASSIGNED 10
    MUL DX                ;AX=AX*DX
    ADD BX,AX          ;INPUT IS IN BX
    MOV CX,BX         ;INPUT IS IN CX
    JMP INPUT
  
    EXIT:   
      RET      
SCANNER ENDP            



; IT IS THE OUTPUT SECTION
        
 
 
 PRINTER PROC
    MOV AH,2
    MOV DL,10
    INT 21H         ;NEWLINE PRINT 
    MOV DL,13
    INT 21H

    MOV AX,BX       ;THE INPUT NUMBER IS IN BX & AX 
    MOV BX,0000H
    MOV CX,10       ;CX IS ASSIGNED 10  
    MOV DX,0        ;DX CONTAINS REMAINDER,INITIALLY 0

OUTPUT:
    DIV CX          ;AX=AX/CX ,AX CONTAINS QUESSION 
    CMP AX,0                  ;DX CONTAINS REMAINDER
    JNE STORE
    JMP STORE_LAST
    
STORE:
    MOV [0000H+BX],DX        ;STORE THE REMAINDER
    ADD BX,2                 ;INCREMENT LOCATION
    MOV DX,0                 ;REMAINDER 0
    JMP OUTPUT

   
    
STORE_LAST:
    MOV [0000H+BX],DX         ;STORE THE LAST DIGIT
    ADD BX,2                             ;INCREMENT MEMORY


PRINT:
    SUB BX,2                            ;FIRST DECREMENT AS LAST INCREMENT WAS DONE
    MOV DL,[0000H+BX]         ;DIGIT STORE IN DL 
    ADD DL,48
    MOV AH,2
    INT 21H                   ;PRINT DL
    CMP BX,0
    JNE PRINT
         RET
PRINTER ENDP         
             
EXITT:

   LAST:
     MOV AH,4CH
     INT 21H 
   
    
END MAIN      
      
      
      
      
      
      
      
      
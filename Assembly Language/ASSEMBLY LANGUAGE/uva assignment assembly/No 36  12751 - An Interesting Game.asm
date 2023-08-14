                                 INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA 
 
 N DW ?
 K DW ?
 X DW ?
 S DW ?
 COUNT DW 0
 
.CODE

MAIN PROC 
        
      PRINT "N:" 
      CALL SCANNER
      MOV N,BX
      PRINTN
      PRINT "K:" 
      CALL SCANNER
      MOV K,BX 
      PRINTN
      PRINT "X:"
      CALL SCANNER
      MOV X,BX
      PRINTN
      MOV COUNT,0 
      MOV AX,1
      LAB1:
           ADD COUNT,AX
           PUSH AX
           MOV BX,COUNT
           CALL PRINTER
           POP AX
           INC AX
           CMP AX,X
           JL LAB1
      
       MOV DX,X
       ADD DX,K
     
       LAB2:
            ADD COUNT,DX
             PUSH DX
           MOV BX,COUNT
           CALL PRINTER
           POP DX
            INC DX
            CMP DX,N
            JLE LAB2              
      MOV BX,COUNT
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
      
      
      
      
      
      
      
      
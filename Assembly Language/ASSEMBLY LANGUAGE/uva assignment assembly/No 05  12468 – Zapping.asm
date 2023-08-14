                                 INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA 
  
  A DW ?
  B DW ?
  S DW ?
  
  
.CODE

MAIN PROC 
             
      CALL SCANNER
      MOV A,BX
      PRINTN
      CALL SCANNER
      MOV B,BX
      PRINTN
      
      CMP A,-1
      JE CMPP
      JMP CAL
      CMPP: CMP B,-1
            JE ENDING
            JMP CAL
      ENDING:JMP LAST 
      
      
      CAL:CMP A,BX
          JG A_B
          JMP B_A
          
          A_B:SUB A,BX
              MOV BX,A
              MOV S,BX
              JMP CHEQ
              
          B_A:MOV BX,B
              SUB BX,A 
              MOV S,BX
              JMP CHEQ                  
          CHEQ:CMP S,50
               JG S_
               MOV BX,S
               CALL PRINTER
               JMP LAST 
          S_:MOV BX,S
             CALL PRINTER
             JMP LAST        
           
      JMP LAST             
      
SCANNER PROC    
MOV CX,0                     ; CX=0

INPUT:
    MOV AH,1
    INT 21H 
    CMP AL,"-"
    JE MINUS
    CMP AL,13               ;INPUT IN AL
    JNE CALC
    JMP EXIT
 MINUS:MOV SI,1
       JMP INPUT   

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
    
     CMP SI,1
    JE PRT 
    JMP NOPRT
    PRT:PRINT "-" 
    
   NOPRT: MOV AX,BX       ;THE INPUT NUMBER IS IN BX & AX 
    MOV BX,0000H
    MOV CX,10       ;CX IS ASSIGNED 10  
    MOV DX,0        ;DX CONTAINS REMAINDER,INITIALLY 0

OUTPUT:
    DIV CX          ;AX=AX/CX ,AX CONTAINS QUESSION 
    CMP AX,0                  ;DX CONTAINS REMAINDER
    JNE STORE
    JMP STORE_LAST
    
STORE:
    MOV [BX],DX        ;STORE THE REMAINDER
    ADD BX,2                 ;INCREMENT LOCATION
    MOV DX,0                 ;REMAINDER 0
    JMP OUTPUT

   
    
STORE_LAST:
    MOV [BX],DX         ;STORE THE LAST DIGIT
    ADD BX,2                             ;INCREMENT MEMORY


PRINT:
    SUB BX,2                            ;FIRST DECREMENT AS LAST INCREMENT WAS DONE
    MOV DL,[BX]         ;DIGIT STORE IN DL 
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
   
    
END 

                                 INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA 
     
  STR DB 80 DUP(?)
  N DW ?
.CODE

MAIN PROC 
          
      MOV AX,@DATA
      MOV DS,AX
      
      LEA SI,STR 
      XOR BX,BX  
     
      MOV AH,1
      INT 21H      
            
      WHILE: CMP AL,0DH
             JE ENDWHILE
             MOV STR[SI],AL
             INC SI
             INC BX 
            
             INT 21H
             JMP WHILE
             
             ENDWHILE:
             
             PRINTN
                     
           
           

          LEA SI,STR       
            MOV CX,BX
           
         TP:
            CMP STR[SI],"A"
            JE PR1
            CMP STR[SI],"B"
            JE PR1
            CMP STR[SI],"C"
            JE PR1   
             JMP LABEL1
         PR1: PRINT "1"  
             JMP SES
             
             
       LABEL1:CMP STR[SI],"D"
            JE PR2
            CMP STR[SI],"E"
            JE PR2
            CMP STR[SI],"F"
            JE PR2
            JMP LABEL2
         PR2: PRINT "2" 
          JMP SES 
          
      LABEL2:CMP STR[SI],"G"
            JE PR3
            CMP STR[SI],"H"
            JE PR3
            CMP STR[SI],"I"
            JE PR3
           JMP LABEL3 
         PR3: PRINT "3" 
          JMP SES 
          
      LABEL3:CMP STR[SI],"J"
            JE PR4
            CMP STR[SI],"K"
            JE PR4
            CMP STR[SI],"L"
            JE PR4
            JMP LABEL4
         PR4: PRINT "4" 
          JMP SES
          
     LABEL4:CMP STR[SI],"M"
            JE PR5
            CMP STR[SI],"N"
            JE PR5
            CMP STR[SI],"O"
            JE PR5
            JMP LABEL5
         PR5: PRINT "5" 
          JMP SES             
   
    LABEL5:CMP STR[SI],"P"
            JE PR6
            CMP STR[SI],"Q"
            JE PR6
            CMP STR[SI],"R"
            JE PR6 
            CMP STR[SI],"S"
            JE PR6
            JMP LABEL6
         PR6: PRINT "6" 
          JMP SES            
            
     LABEL6:CMP STR[SI],"T"
            JE PR7
            CMP STR[SI],"U"
            JE PR7
            CMP STR[SI],"V"
            JE PR7
            JMP LABEL7
         PR7: PRINT "7" 
          JMP SES
          
     LABEL7:CMP STR[SI],"W"
            JE PR8
            CMP STR[SI],"X"
            JE PR8
            CMP STR[SI],"Y"
            JE PR8  
            CMP STR[SI],"Z"
            JE PR8
            JMP LABEL8
         PR8: PRINT "8" 
          JMP SES          
                     
      LABEL8:
             MOV AH,2
             MOV DL,STR[SI]  
             INT 21H
            
               
          SES:  
            INC SI
           
            LOOP TP    
           
           
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
      
      
      
      
      
      
      
      
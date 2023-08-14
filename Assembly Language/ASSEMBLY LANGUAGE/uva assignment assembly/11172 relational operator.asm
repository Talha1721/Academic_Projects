                INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA 
     A DW 0
     B DW 0
     N DW 0 
     I DW 0 
     
.CODE

MAIN PROC 
       
    
     CALL SCAN
     MOV N,BX
     MOV CX,1
     PRINTN
     
     OPERATOR:
              CALL SCAN 
              MOV A,BX
              PRINTN
              CALL SCAN
              MOV B,BX
              CMP A,BX
              JG PRINTGRT
              JE PRINTEQL
              PRINTN
              MOV AH,2
              MOV DL,3CH
              INT 21H
              PRINTN
              JMP LAST          
 
    PRINTGRT: 
             PRINTN
             MOV AH,2
             MOV DL,3EH 
             INT 21H
             PRINTN
             JMP LAST          
                 
    PRINTEQL:
             PRINTN
             MOV AH,2
             MOV DL,3DH 
             INT 21H
             PRINTN
             JMP LAST             
                 
                 
                 
                 
                 
                 
       LAST:             
            INC CX
            CMP CX,N 
            JE SES   
            JMP OPERATOR  
   
   SES:      
       JMP DRAIN     
         
                 
  ;----------------------------------------------------------------------                 
SCAN proc
mov cx,0     ; cx=0
        
input:
    mov ah,1
    INT 21h
    cmp al,13 ;input in al
    jne calc
    jmp exit
    


calc:
    mov ah,0
    sub al,48
    mov bx,ax   ;input in bx
    mov ax,cx   ;ax has cx
    mov dx,10
    mul dx
    add bx,ax
    mov cx,bx   ;input is in bx
    jmp input


        
exit: 
    ret
SCAN endp     
; ----------------------------------------------------------------------------------

;--------------------------------------------------------------------------------------------
PRINTER proc
   
mov ah,2
mov dl,10
INT 21h   ;new 
mov dl,13
INT 21h

mov ax,bx  ;input in ax 
mov bx,0000h
mov cx,10   ;cx has 10  
mov dx,0

output:
    div cx
    cmp ax,0
    jne print
    jmp exit1
    
print:
    mov [0000h+bx],dx
    add bx,2
    mov dx,0
    jmp output

   
    
exit1:
    mov [0000h+bx],dx
    add bx,2


print1:
    sub bx,2
    mov dl,[0000h+bx]
    add dl,48
    mov ah,2
    INT 21h
    cmp bx,0
    jne print1  
                
    ret            
PRINTER endp  
;--------------------------------------------------------------------------------------------

                        
     DRAIN:
        

     MOV AH,4CH
     INT 21H
END MAIN
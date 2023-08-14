INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA 
    A DW 5 DUP (?) 
    FIND DW ?
    
.CODE
MAIN PROC 
     MOV AX,@DATA
     MOV DS,AX 
    
     XOR BX,BX  ;bX=0
     MOV CX,5
     
     INPUT_LOOP: 
     push bx 
     push cx
               CALL Taking_input
               mov ax,bx
      pop cx
      pop bx 
               
               
               MOV A[bX],ax
               PRINTN
               ADD bx,2
     LOOP INPUT_LOOP
               
     PRINTN  
     
     CALL Taking_input
     MOV FIND,bX  
     
         
     XOR bX,bX  ;bX=0
     MOV CX,5
     
     SEARCHING:
              MOV AX,A[bX]
              CMP AX,FIND
              JE FOUND_PRINT
              
              ADD bX,2
     LOOP SEARCHING
     
     PRINTN
     PRINT "NOT FOUND"
     PRINTN
     JMP EXIT1
     
     FOUND_PRINT:
               PRINTN
               PRINT "FOUND"
               PRINTN
                        
     

     EXIT1:
     MOV AH,4CH
     INT 21H
MAIN ENDP 
 
     
Taking_input proc
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
Taking_input endp    

 
 
 MOV AH,4CH
 INT 21H
 
 END MAIN
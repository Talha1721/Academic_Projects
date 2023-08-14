                               INCLUDE "EMU8086.INC"
.MODEL SMALL
.STACK 100H
.DATA 
     A DW 0
     B DW 1
     C DW 0 
     SUM DW 0 
     CAP DW 0
     TOTAL DW 1
    
    
.CODE

MAIN PROC 
     MOV AX,@DATA
     MOV DS,AX 
    
    PRINT "SERIES IS:" 
   CALL SCAN 
   MOV CX,BX
   SUB CX,2
   PRINTN
   PRINT "0" 
   PRINTN
   PRINT "1" 
  
  ; MOV AX,A
   PRINT " "
   
   
     MOV BX,B 
     
     FIBBO_LOOP:   
     
     MOV AX,C
     
     ADD SUM,AX 
     MOV C,BX 
     ADD SUM,BX 
     
      
     MOV BX,SUM 
     
     
     PUSH AX 
     MOV AX,SUM
     ADD TOTAL,AX    ;  calculating total 
     POP AX
    
     
     
     
     
     MOV SUM,0  
     
    
    
    
     PUSH AX 
     push BX
     PUSH CX
     
     CALL  PRINT_NUM  
     POP CX
     POP BX
     POP AX
     
     PRINT " "
     CMP  CX,1
       JE DRAIN
     
     
            
      LOOP   FIBBO_LOOP  
             
 
               
 
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
PRINT_NUM proc
   
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
PRINT_NUM endp  
;--------------------------------------------------------------------------------------------

                        
     DRAIN:
        PRINTN
        PRINT "TOTAL SUM:"
     
       MOV BX,TOTAL
       CALL  PRINT_NUM 

     MOV AH,4CH
     INT 21H
END MAIN
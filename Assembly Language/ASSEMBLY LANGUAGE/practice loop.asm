                           INCLUDE "EMU8086.INC"

; THE MULTIPLE INPUT AND OUTPUT ASSEMBLY CODE
.model small
.stack 100h
.data
.code  

 n dw ?
 sum dw 0 
 s dw 0
main proc
 
       
             
         call scanner
         mov n,bx    
            
              
             
         mov cx,n  
         
         
             for:
             
             cmp cx,0
             je exitt
                
                
          
               
               
               mov bx,cx
               push cx
               call printer
               pop cx
             
             
             loop for
       
             
       
                       
       
 
        


scanner proc    
mov cx,0                     ; cx=0

input:
    mov ah,1
    INT 21h
    cmp al,13               ;input in al
    jne calc
    jmp exit
    

calc:
    mov ah,0
    sub al,48          ;asci to numeric
    mov bx,ax         ;input in bx // ax in bx
    mov ax,cx         ;ax has cx
    mov dx,10         ;dx is assigned 10
    mul dx                ;ax=ax*dx
    add bx,ax          ;input is in bx
    mov cx,bx         ;input is in cx
    jmp input
  
    exit:   
      ret      
scanner endp            



; IT IS THE OUTPUT SECTION
        
 
 
 printer proc
    mov ah,2
    mov dl,10
    INT 21h         ;newline print 
    mov dl,13
    INT 21h

    mov ax,bx       ;the input number is in bx & ax 
    mov bx,0000h
    mov cx,10       ;cx is assigned 10  
    mov dx,0        ;dx contains remainder,initially 0

output:
    div cx          ;ax=ax/cx ,ax contains quession 
    cmp ax,0                  ;dx contains remainder
    jne store
    jmp store_last
    
store:
    mov [0000h+bx],dx        ;store the remainder
    add bx,2                 ;increment location
    mov dx,0                 ;remainder 0
    jmp output

   
    
store_last:
    mov [0000h+bx],dx         ;store the last digit
    add bx,2                             ;increment memory


print:
    sub bx,2                            ;first decrement as last increment was done
    mov dl,[0000h+bx]         ;digit store in dl 
    add dl,48
    mov ah,2
    INT 21h                   ;print dl
    cmp bx,0
    jne print
         ret
printer endp         
             
exitt:
     ;mov ah,4ch
     ;INT 21h 
   
    
end main

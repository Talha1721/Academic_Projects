.model small
.stack 100h
.data
.code  
    sum dw 0
    a dw ?
    b dw ?


main proc 
      call Taking_input
      mov a,bx
      
      mov ah,2
      mov dl,10
      INT 21h   ;new 
      mov dl,13
      INT 21h 
      
      call Taking_input
      mov b,bx
      
      mov ah,2
      mov dl,10
      INT 21h   ;new 
      mov dl,13
      INT 21h
      
      mov ax,a
      add ax,bx
      mov sum,ax
      
      mov bx,sum 
      
      mov ah,2
      mov dl,10
      INT 21h   ;new 
      mov dl,13
      INT 21h
      call Show_output
      
      mov ah,4ch
      int 21h
main endp        
    
     
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



; code goes here 
;input is in bx




;output has to be put in bx

Show_output proc
    
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
Show_output endp    

end main
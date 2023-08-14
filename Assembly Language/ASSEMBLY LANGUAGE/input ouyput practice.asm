.model small                              ;an exampe is :
.stack 100h                               ;0*10=0       0+1=1
.data                                     ;1*10=10      10+2=12
.code                                     ;12*10=120    120+3=123
                                          ;123*10=1230  1230+4=1234

main proc   
    
    mov cx,0
    mov dx,10
    
    mov ah,1
    int 21h
    cmp al,13
    jne calculate
    jmp output
    
calculate:
             
             mov ah,0
             mov bx,ax      ;bx contains new digit 
             mov ax,cx      ;ax contain the multipication(*10) result
             mul dx
             add bx,ax      ;new digit+mult result
             mov cx,bx      ;cx contains final result
                         
output:
                                
  
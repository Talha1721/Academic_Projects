
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; add your code here
mov ah,1
int 21h
add al,10
mov dl,al
mov ah,2
int 21h

ret





assume cs:code

code segment

		dw 0100h,0101h,0102h,0103h,0104h,0105h,0106h,0107h

start:	mov ax,0
		mov ds,ax
		mov bx,0
		mov cx,8

s:		mov ax,ds:[bx]
		mov cs:[bx],ax
		add bx,2
		loop s

		mov ax,4c00H
		int 21H

code ends
end start
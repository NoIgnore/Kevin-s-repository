assume cs:code,ds:data,ss:stack
data segment
		dw 0100h,0101h,0102h,0103h,0104h,0105h,0106h,0107h
data ends

stack segment stack;这里后面的stack是防止debug出现warming
		dw 0,0,0,0,0,0,0,0
		dw 0,0,0,0,0,0,0,0
stack ends

code segment

start:	mov ax,stack
		mov ss,ax
		mov sp,32

		mov ax,data
		mov ds,ax

		mov bx,0
		mov cx,8
pushdata:
		push ds:[bx]
		add bx,2
		loop pushdata


		mov bx,0
		mov cx,8
popdata:
		pop ds:[bx]
		add bx,2
		loop popdata

		mov ax,4c00H
		int 21H

code ends
end start
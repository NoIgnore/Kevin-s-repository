assume cs:code,ds:data ,ss:stack
data segment
		db		'BaSic'
		db		'MinIR' 
data ends

stack segment stack
		dw		0,0,0,0
		dw		0,0,0,0
		dw		0,0,0,0
		dw		0,0,0,0

stack ends

code segment
	start:	mov bx ,stack
			mov ss ,bx
			mov sp ,128

			mov bx ,data
			mov ds ,bx
			mov bx ,0
			mov cx ,5

changeLetter :
			mov al,ds:[bx]
			and al,11011111B
			mov ds:[bx],al
			mov al,ds:[bx+5]
			or  al,00100000B
			mov ds:[bx+5],al
			inc bx
			loop changeLetter

			mov ax,4c00h
			int 21h

code ends

end start

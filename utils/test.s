MOV %RAX,$1
MOV %RDI,$1
LEA %RSI,[.+24]
MOV %RDX,$11
SYSCALL
MOV %RAX,$60
SYSCALL
.ascii hello_world
.byte 62

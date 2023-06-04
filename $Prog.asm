TITLE $Prog.asm

PILE SEGMENT STACK
DW 1000 dup (?)
base_pile dw ?
PILE ENDS

DATA segment
$i DW ?
$j DW ?
DATA ends

CODE segment
start:
ASSUME CS:CODE, DS:DATA, SS:segment_pile
MOV AX, DATA
MOV DS, AX
MOV AX, PILE
MOV SS, AX
MOV SP, base_pile
mov BP, base_pile


etiq_1:
MOV AH, 4Ch
INT 21h
CODE ends
END start


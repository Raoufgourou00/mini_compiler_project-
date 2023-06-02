TITLE #Prog.asm

PILE SEGMENT STACK
DW 1000 dup (?)
base_pile dw ?
PILE ENDS

DATA segment
#x DW ?
#y DW ?
#k DW 5 dup (?)
#l DW 6 dup (?)
#z DW ?
#s1_t1 DW ?
#s1_t2 DW ?
#i DW ?
#j DW ?
#c EQU 15.1
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
MOV AX, 2
MOV BP[2], AX
etiq_2:
MOV AX, 5
CMP AX, BP[2]
JLE etiq_5
etiq_3:
MOV AX, 1
MOV BP[4], AX
etiq_4:
JMP etiq_6
etiq_5:
MOV AX, 0
MOV BP[4], AX
etiq_6:
MOV AX, 1
AND AX, 1
JZ etiq_10
etiq_7:
MOV AX, BP[4]
MOV BP[6], AX
etiq_8:
MOV AX, BP[4]
MOV z, AX
etiq_9:
JMP etiq_12
etiq_10:
MOV AX, BP[2]
MOV BP[8], AX
etiq_11:
MOV AX, BP[2]
MOV z, AX

etiq_12:
MOV AH, 4Ch
INT 21h
CODE ends
END start


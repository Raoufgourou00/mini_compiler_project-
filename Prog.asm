TITLE Prog.asm

segment_pile SEGMENT stack
DW   500 dup (?)
base_pile EQU 500
segment_pile ENDS

DATA segment
x DW ?
y DW ?
k DW 5 dup (?)
l DW 6 dup (?)
z DW ?
s1_t1 DW ?
s1_t2 DW ?
i DW ?
j DW ?
c EQU 15
temporaires DW 500 DUP (?)
DATA ends

CODE segment
start:
ASSUME CS:CODE, DS:DATA, SS:segment_pile
MOV AX, DATA
MOV DS, AX
MOV AX, segment_pile
MOV SS, AX
MOV SP, base_pile

etiq_0:
MOV AX, y
MOV temporaires[0], AX
etiq_1:
MOV AX, 3
MOV temporaires[2], AX
etiq_2:
MOV AX, temporaires[0]
ADD AX, temporaires[2]
MOV temporaires[4], AX
etiq_3:
MOV AX, 8
MOV temporaires[6], AX
etiq_4:
etiq_5:
MOV AX, 1
MOV temporaires[8], AX
etiq_6:
etiq_7:
MOV AX, 0
MOV temporaires[8], AX
etiq_8:
etiq_9:
MOV AX, 320
MOV temporaires[10], AX
etiq_10:
MOV AX, temporaires[10]
MOV x, AX
etiq_11:
etiq_12:
MOV AX, 5
MOV temporaires[12], AX
etiq_13:
MOV AX, temporaires[12]
MOV z, AX

MOV AH, 4Ch
INT 21h
CODE ends
END start


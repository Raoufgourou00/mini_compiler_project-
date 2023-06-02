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
MOV AX, 5
MOV temporaires[0], AX
etiq_1:
MOV AX, 9
MOV temporaires[2], AX
etiq_2:
ADD AX, temporaires[0]
MOV temporaires[4], AX
etiq_3:
MOV AX, 2
MOV temporaires[6], AX
etiq_4:
MOV AX, temporaires[4]
SUB AX, temporaires[6]
MOV temporaires[8], AX
etiq_5:
MOV AX, 2
MOV temporaires[10], AX
etiq_6:
MOV AX, 7
MOV temporaires[12], AX
etiq_7:
MUL temporaires[10]
MOV temporaires[14], AX
etiq_8:
MOV AX, 25
MOV temporaires[16], AX
etiq_9:
MOV AX, temporaires[14]
DIV temporaires[16]
MOV temporaires[18], AX
etiq_10:
ADD AX, temporaires[8]
MOV temporaires[20], AX
etiq_11:
MOV y, AX

etiq_12:
MOV AH, 4Ch
INT 21h
CODE ends
END start


flex ra.l
bison -d ra.y --report=states,itemsets --debug
gcc lex.yy.c  ra.tab.c TS.c QUAD.c RS.c -o comp.exe
all: gerador_fi entrada.txt
	./gerador_fi < entrada.txt

gerador_fi: lex.yy.c y.tab.c
	g++ -Wall -g -std=c++11 y.tab.c -o gerador_fi
	
lex.yy.c: mini_js.l
	flex mini_js.l
	
y.tab.c: mini_js.y
	bison -y mini_js.y
	
clean: 
	rm -f lex.yy.c y.tab.c gerador_fi
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m' # No Color


all:
	@echo -${YELLOW}Generating symtable...${NC};
	@make symtable
	@echo -e ${GREEN}OK${NC}
	
	@echo -${YELLOW}Generating yacc output files...${NC};
	@make bison
	@echo -e ${GREEN}OK${NC}

	@echo -${YELLOW}Generating flex output files...${NC};
	@make flex
	@echo -e ${GREEN}OK${NC}

	@echo -${YELLOW}Generating executable...${NC};
	@make alpha
	@echo -e ${GREEN}OK${NC}

symtable: symtable.c Variable.c Function.c
	gcc Variable.c -o Variable.o -c
	gcc Function.c -o Function.o -c
	gcc symtable.c -o symtable.o -c

bison:	parser.y
	bison --yacc --defines --output=parser.c parser.y

flex:	scanner.l
	flex --outfile=scanner.c scanner.l

alpha:	scanner.c parser.c

	gcc -o alpha scanner.c parser.c Variable.o Function.o symtable.o

clean:
	@echo -${YELLOW}Cleaning files...${NC};
	@rm -f *.o;
	@rm -f parser.h;
	@rm -f parser.c; 
	@rm -f scanner.c; 
	@rm -f alpha;
	@rm -f parser.output
	@rm -f alpha.out
	@echo ${GREEN}OK${NC};

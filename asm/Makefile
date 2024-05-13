##
## EPITECH PROJECT, 2023
## B-CPE-200-TLS-2-1-corewar-lucien.pineau
## File description:
## Makefile for the asm binary
##

NAME			=	asm

SRCS			=	main_tools.c\
					assembler.c\
					assembler_tools.c\
					size_tools.c\
					assemble_file/assemble_file.c\
					label/label_factory.c\
					label/label_tools.c\
					label/label_scanner.c\
					parsing/parse_header_tools.c\
					parsing/parse_instru_type_tools.c\
					parsing/parse_instructions_tools.c\
					parsing/parse_args_tools.c\
					parsing/parse_size_tools.c\
					code_tools.c

TSRCS			=	label_tests.c\
					assembler_tests.c\
					parse_header_tests.c\
					parse_instruction_tests.c\
					code_tools_tests.c\
					main.c\
					assemble_file.c\

TPATH			=	../tests/

LIBS			=	mycode mywar

LIBINC			=	$(addsuffix /include, $(addprefix -I../lib/, $(LIBS)))

CFLAGS			=	-W -Wall -Wextra -Wpedantic -Iinclude $(LIBINC)

LDFLAGS			=	-L../lib -lmycode -lmywar

TSRCS			:=	$(addprefix $(TPATH)utests/asm/, $(TSRCS))

SRCS			:=	$(addprefix src/, $(SRCS))

TOBJS			=	$(TSRCS:.c=.o)

OBJS			=	$(SRCS:.c=.o)

Y				=	\033[1;33m
B				=	\033[1;34m
G				=	\033[1;32m
R				=	\033[1;31m
RST				=	\033[0m

$(NAME):	$(OBJS) src/main.o
	@gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)
	@printf "$(G)$(NAME) $(Y)[$(G)✓$(Y)]$(RST)\n"

all:		$(NAME)

%.o:		%.c
	@gcc -o $@ -c $< $(CFLAGS) $(LDFLAGS)
	@printf "$(Y)$(notdir $(@:.o=))[$(G)✓$(Y)]$(RST) "

clean:
	@rm -f $(OBJS) $(TOBJS) src/main.o vgcore.* coding-style-reports.log
	@rm -f src/vgcore.* test.cor
	@find src -name "*.gc*" -delete
	@rm -f $(TPATH)utests/vgcore.*
	@find $(TPATH)utests -name "*.gc*" -delete
	@printf "$(Y)Temp_$(NAME)_files[$(R)✗$(Y)]$(RST) "

fclean:		clean
	@rm -f $(NAME) unit_tests debug btests
	@printf "\n$(R)$(NAME) $(Y)[$(R)✗$(Y)]$(RST)\n"

re:			fclean all

unit_tests:	CFLAGS += -lcriterion -lgcov --coverage
unit_tests:	clean $(TOBJS) $(OBJS)
	@gcc -o $@ $(TOBJS) $(OBJS) $(CFLAGS) $(LDFLAGS)
	@printf "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)\n"

tests_run:	unit_tests
	@./$<

debug:		CFLAGS += -g3
debug:		clean $(OBJS) src/main.o
	@gcc -o $@ $(OBJS) src/main.o $(CFLAGS) $(LDFLAGS)
	@printf "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)\n"

val_run:	debug
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$<

btests:		$(NAME)
	./$< -h

covr:		tests_run
	@gcovr
	@gcovr --branches

.PHONY: all clean fclean re tests_run val_run run_btests covr

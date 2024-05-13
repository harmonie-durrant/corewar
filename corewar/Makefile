##
## EPITECH PROJECT, 2023
## B-CPE-200-TLS-2-1-corewar-lucien.pineau
## File description:
## Makefile for the corewar binary
##

NAME			=	corewar

SRCS			=	main_tools.c\
					corewar.c\
					corewar_loop.c\
					flag_handler.c\
					corewar_info_tools.c\
					parse_arguments.c\
					flag_checker.c\
					process/process_factory.c\
					process/process_loop.c\
					vm/vm_factory.c\
					vm/vm_loop.c\
					op/op_live.c\
					op/op_tools.c\
					op/op_zjmp.c\
					op/op_add.c\
					op/op_st.c\
					op/op_fork.c\
					op/op_aff.c\
					op/op_and.c\
					op/op_ld.c\
					op/op_lld.c\
					op/op_ldi.c\
					op/op_lldi.c\
					champ_mem_tools.c\

TSRCS			=	process_factory_tests.c\
					process_loop_tests.c\
					vm_factory_tests.c\
					vm_loop_tests.c\
					flag_handler_tests.c\
					main_tools_tests.c\
					champ_mem_tests.c\
					corewar_tests.c\
					op/op_tools_tests.c

TPATH			=	../tests/

LIBS			=	mycode mywar

LIBINC			=	$(addsuffix /include, $(addprefix -I../lib/, $(LIBS)))

CFLAGS			=	-W -Wall -Wextra -Wpedantic -Iinclude $(LIBINC)

LDFLAGS			=	-L../lib -lmycode -lmywar

TSRCS			:=	$(addprefix $(TPATH)utests/corewar/, $(TSRCS))

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
	@rm -f src/vgcore.*
	@find src -name "*.gc*" -delete
	@rm -f $(TPATH)utests/vgcore.*
	@find $(TPATH)utests -name "*.gc*" -delete
	@printf "$(Y)Temp_$(NAME)_files[$(R)✗$(Y)]$(RST) "

fclean:		clean
	@rm -f $(NAME) unit_tests debug btests libmycorewar.a
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

bonus:		$(OBJS)
	@ar rc libmycorewar.a $(OBJS)
	@printf "\n$(G)libmycorewar.a $(Y)[$(G)✓$(Y)]$(RST)\n"

.PHONY: all clean fclean re tests_run val_run run_btests covr

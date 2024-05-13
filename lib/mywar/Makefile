##
## EPITECH PROJECT, 2023
## Public_Library
## File description:
## Template Makefile for a library
##

Y				=	\033[1;33m
B				=	\033[1;34m
G				=	\033[1;32m
R				=	\033[1;31m
RST				=	\033[0m

SRCS			=	instru_factory.c	\
					instru_tools.c	\
					instru_data.c	\
					instru_checks.c	\
					circ_mem.c	\
					header_factory.c	\
					champ_factory.c	\
					champ_tools.c	\
					cbyte_factory.c	\
					op.c  \
					put_cor_nbr.c

TSRCS 			=	instru_factory_tests.c	\
					instru_tools_tests.c	\
					instru_data_tests.c	\
					instru_checks_tests.c	\
					champ_factory_tests.c	\
					champ_tools_tests.c	\
					cbyte_factory_tests.c \
					put_cor_nbr_tests.c\
					circ_mem_tests.c

CFLAGS			=	-W -Wall -Wextra -Wpedantic -Iinclude

LNAME			=	libmywar.a

LIBINC			=	-I../mycode/include/

TPATH 			=	../../tests/utests/mywar/

TSRCS			:=	$(addprefix $(TPATH), $(TSRCS))

SRCS			:=	$(addprefix src/, $(SRCS))

TOBJS			=	$(TSRCS:.c=.o)

OBJS			=	$(SRCS:.c=.o)

$(LNAME):	$(OBJS)
	@ar rcs $@ $(OBJS)
	@printf "$(G)$(LNAME) $(Y)[$(G)✓$(Y)]$(RST)\n"

all:		$(LNAME)

%.o:		%.c
	@gcc -o $@ -c $< $(CFLAGS) $(LIBINC)
	@printf "$(Y)$(notdir $(@:.o=))[$(G)✓$(Y)]$(RST) "

clean:
	@rm -f $(OBJS) $(TOBJS) vgcore.* coding-style-reports.log
	@rm -f src/vgcore.*
	@find src -name "*.gc*" -delete
	@rm -f $(TPATH)/vgcore.*
	@find $(TPATH) -name "*.gc*" -delete
	@printf "$(Y)Temp_$(LNAME)_files[$(R)✗$(Y)]$(RST) "

fclean:		clean
	@rm -f $(LNAME) unit_tests debug
	@printf "\n$(R)$(LNAME) $(Y)[$(R)✗$(Y)]$(RST)\n"

re:			fclean all

unit_tests:	CFLAGS += -lcriterion -lgcov --coverage
unit_tests:	clean $(TOBJS) $(OBJS)
	@gcc -o $@ $(TOBJS) $(OBJS) $(CFLAGS) $(LIBINC)
	@printf "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)\n"

tests_run:	unit_tests
	@./$<

debug:		CFLAGS += -g3
debug:		re
	@printf "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)"

covr:		tests_run
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branches

.PHONY: all clean fclean re tests_run

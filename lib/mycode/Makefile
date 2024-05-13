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

SRCS			=	char_anum.c								\
					char_print.c							\
					foo_to_sort.c							\
					talloc.c								\
					len.c									\
					quicks.c								\
					schange.c								\
					scopy.c									\
					slen.c									\
					smake.c									\
					ssearch.c								\
					read_int.c							\
					read_dou.c						\
					sgf.c									\
					sgf_type.c						\
					fpf.c									\
					spf.c									\
					ftos.c                \
					sp_int.c							\
					sp_dou.c							\
					sp_char.c							\
					linked/list_create.c				\
					linked/list_handle.c				\
					check_files.c						\
					charset.c							\
					sanum.c								\

CFLAGS			=	-W -Wall -Wextra -Wpedantic -Iinclude

LNAME			=	libmycode.a

TPATH 			=	../../tests/utests/mycode/

TSRCS			:=	$(addprefix $(TPATH), $(SRCS:.c=_tests.c))

SRCS			:=	$(addprefix src/, $(SRCS))

TOBJS			=	$(TSRCS:.c=.o)

OBJS			=	$(SRCS:.c=.o)

$(LNAME):	$(OBJS)
	@ar rcs $@ $(OBJS)
	@printf "$(G)$(LNAME) $(Y)[$(G)✓$(Y)]$(RST)\n"

all:		$(LNAME)

%.o:		%.c
	@gcc -o $@ -c $< $(CFLAGS)
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

unit_tests: CFLAGS += -lcriterion -lgcov --coverage
unit_tests: clean $(TOBJS) $(OBJS)
	@gcc -o $@ $(TOBJS) $(OBJS) $(CFLAGS)
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

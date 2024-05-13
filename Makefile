##
## EPITECH PROJECT, 2022
## B-CPE-200-TLS-2-1-corewar-lucien.pineau
## File description:
## Main Makefile for the corewar project
##

# Compiling functions
BINS	=	asm corewar

LIBS	=	mycode mywar

BT_CW_A	=	"-dump 1 tests/champions/abel.cor tests/champions/42.cor"

BT_CW	=	-b ./corewar/corewar -r ./tests/corewar_ref -a $(BT_CW_A)

BT_ASM	=	-b ./asm/asm -r ./tests/asm_ref -f tests/champions/src/abel.s

all: compile

lbuild:
	@for i in $(LIBS); do make -C lib/$$i -s && cp lib/$$i/lib$$i.a lib/; done

compile: lbuild
	@for i in $(BINS); do make -C $$i -s; done

debug: lbuild
	@for i in $(BINS); do make debug -C $$i -s; done

unit_tests: lbuild
	@for i in $(LIBS); do make -C lib/$$i unit_tests -s; done
	@for i in $(BINS); do make -C $$i unit_tests -s; done

tests_run: fclean lbuild
	@for i in $(LIBS); do make -C lib/$$i tests_run -s; done
	@for i in $(BINS); do make -C $$i tests_run -s; done

bonus: lbuild
	@make -C corewar bonus -s
	@make -C bonus -s

# Cleaning functions

clean:
	@make -C bonus/documentation clean -s
	@make -C bonus clean -s
	@for bin in $(BINS); do make -C $$bin clean -s; done
	@for lib in $(LIBS); do make -C lib/$$lib clean -s; done
	@printf "\n"

fclean:
	@make -C bonus/documentation fclean -s
	@make -C bonus fclean -s
	@for bin in $(BINS); do make -C $$bin fclean -s; done
	@for lib in $(LIBS); do make -C lib/$$lib fclean -s; done
	@rm -f lib/lib*.a

# re functions
re: fclean all

btests: re
	@./tests/btests/btest_asm $(BT_ASM)
	@./tests/btests/btest_asm
	@./tests/btests/btest_corewar $(BT_CW)

# Other
gcovr: tests_run
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branches

docs:
	@make -C bonus/documentation
	@firefox ./bonus/documentation/docs/html/index.html

docs-install:
	@echo "Please run this command with sudo if not already done."
	@make install -C bonus/documentation

docs-remove:
	@echo "Please run this command with sudo if not already done."
	@make uninstall -C bonus/documentation
	@make fclean -C bonus/documentation

gource:
	@sh ./bonus/gource/fancy_gource.sh

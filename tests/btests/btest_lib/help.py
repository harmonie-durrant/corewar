# help.py

def print_help_corewar():
    print("USAGE:")
    print("\t./btest_corewar [-h] -b \{corewar binary\}", end="")
    print("-r \{corewar reference binary\}", end="")
    print("[-a \{arguments\}] ...\n")
    print("\t-b the path to the compiled corewar binary. (alias -binary)")
    print("\t-r the path to reference corewar binary. (alias -reference) ", end="")
    print("(can be found in \{project-root\}/tests/btests/bin-ref/corewar)")
    print("\t-a the arguments to pass to the corewar binary. (alias -arguments) ", end="")
    print("(repeat the -a flag for each test)")

def print_help_asm():
    print("USAGE:")
    print("\t./btest_asm [-h] [[-b asm binary] [-r asm reference binary] [-f .s file]]")
    print("\t-b the path to the compiled asm binary. (alias -binary)")
    print("\t-r the path to reference asm binary. (alias -reference)")
    print("\t-f the path to a .s file to test. (alias -help)")
    print("\t(all arguments can have either a '-' or '--' prefix)")
    print("DESCRIPTION:")
    print("\tCompares the output of the asm binary with the reference binary.", end="")
    print("If no arguments are given, the script will test all the .s files in the", end="")
    print("default folder (tests/champions/src/).")
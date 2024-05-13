# check_args.py

from btest_lib.help import print_help_corewar, print_help_asm 
from btest_lib.utils import does_file_exist

def check_args_corewar(ac, av):
    i = 1
    binary = ""
    binary_ref = ""
    arguments = []
    while (i < ac):
        if i in ["-h", "--help", "-help", "--h"]:
            print_help_corewar()
            return (1, None, None, None)
        elif av[i] == "-b" or av[i] == "--binary":
            if i + 1 < ac:
                if av[i + 1][0] == "-":
                    print("Error: No binary file specified.")
                    return (84, None, None, None)
                if does_file_exist(av[i + 1]):
                    binary = av[i + 1]
                    i += 1
                else:
                    print("Error: File " + av[i + 1] + " not found.")
                    return (84, None, None, None)
            else:
                print("Error: No binary file specified.")
                return (84, None, None, None)
        elif av[i] == "-r" or av[i] == "--reference":
            if i + 1 < ac:
                if does_file_exist(av[i + 1]):
                    binary_ref = av[i + 1]
                    i += 1
                else:
                    print("Error: File " + av[i + 1] + " not found.")
                    return (84, None, None, None)
            else:
                print("Error: No reference binary file specified.")
                return (84, None, None, None)
        elif av[i] == "-a" or av[i] == "--arguments":
            if i + 1 < ac:
                arguments.append(av[i + 1])
                i += 1
            else:
                print("Error: No arguments specified.")
                return (84, None, None, None)
        else:
            return (84, None, None, None)
        i += 1
    if binary == "" or binary_ref == "":
        print("Error: No binary or reference binary specified.")
        return (84, None, None, None)
    return (0, binary, binary_ref, arguments)

def check_args_asm(ac, av):
    i = 1
    binary = ""
    binary_ref = ""
    file = ""
    checks = [0,0,0]

    while (i < ac):
        if av[i] in ["-h", "--help", "-help", "--h"]:
            print_help_asm()
            return (1, None, None, None)
        elif av[i] in ["-b", "--binary, '-binary", "--b"]:
            if i + 1 < ac:
                if does_file_exist(av[i + 1]):
                    binary = av[i + 1]
                    i += 1
                    checks[0] = 1
                else:
                    print("Error: File " + av[i + 1] + " not found.")
                    return (84, None, None, None)
            else:
                print("Error: No binary file specified.")
                return (84, None, None, None)
        elif av[i] in ["-r", "--reference", "-reference", "--r"]:
            if i + 1 < ac:
                if does_file_exist(av[i + 1]):
                    binary_ref = av[i + 1]
                    i += 1
                    checks[1] = 1
                else:
                    print("Error: File " + av[i + 1] + " not found.")
                    return (84, None, None, None)
            else:
                print("Error: No reference binary file specified.")
                return (84, None, None, None)
        elif av[i] in ["-f", "--file", "-file", "--f"]:
            if i + 1 < ac:
                if does_file_exist(av[i + 1]):
                    file = av[i + 1]
                    i += 1
                    checks[2] = 1
                else:
                    print("Error: File " + av[i + 1] + " not found.")
                    return (84, None, None, None)
            else:
                print("Error: No file specified.")
                return (84, None, None, None)
        else:
            print("Error: Wrong argument '" + av[i] + "'.")
            return (84, None, None, None)
        i += 1
    if checks == [0,0,0]:
        return (0, binary, binary_ref, file)
    if checks[0] == 0:
        print("Error: No binary file specified. (-b)")
        return (84, None, None, None)
    if checks[1] == 0:
        print("Error: No reference binary file specified. (-r)")
        return (84, None, None, None)
    if checks[2] == 0:
        print("Error: No file specified. (-f)")
        return (84, None, None, None)
    return (0, binary, binary_ref, file)

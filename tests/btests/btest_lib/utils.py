# utils.py

import os
import subprocess
import filecmp

def does_file_exist(path):
    if os.path.isfile(path):
        return True
    else:
        return False

def run_file(bin, args, output_file):
    return_code = 0

    try:
        with open(os.devnull, 'w') as devnull:
            subprocess.check_call([bin] + args, stdout=open(output_file, 'w'), stderr=devnull)
    except subprocess.CalledProcessError as e:
        return_code = e.returncode
    return return_code

def run_file_in_dir(dir, bin, args, output_file):
    os.chdir(dir)
    ret = run_file(bin, args, output_file)
    os.chdir("../../")
    return ret

def print_results(passed, failed, total):
    print(f"✅ {passed} / {total} tests passed.")
    print(f"❌ {failed} / {total} tests failed.")

def is_diff_files(file1, file2):
    return filecmp.cmp(file1, file2)

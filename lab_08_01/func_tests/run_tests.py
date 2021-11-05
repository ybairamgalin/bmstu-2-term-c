import subprocess

from os import listdir, remove
from os.path import isfile, join

ARGS_WAY = "func_tests/in_args/"
OUT_WAY = "func_tests/out/"
RES_FILE = "output.txt"


def run_test(args_filename, out_filename):
    args_file = open(args_filename, "r")
    args = args_file.readline().split()
    args_file.close()

    exec = subprocess.run(args, capture_output=True)
    res = None
    out = None

    if "neg" in args_filename and exec.returncode != 0:
        print("TEST {} \033[32mPASSED\033[0m. RETURN CODE {}".format(args_filename,
                                                                     exec.returncode))
        return 1

    if "pos" in args_filename and exec.returncode == 0:
        out = open(out_filename, "r").readlines()
        res = open(RES_FILE, "r").readlines()
        remove(RES_FILE)

        if out == res:
            print("TEST {} \033[32mPASSED\033[0m".format(args_filename))
            return 1

    print("TEST {} \033[31mFAILED\033[0m.\nEXPECTED\n{}\nRECEIVED\n{}\nRETURN CODE\n{}\n".format(
        args_filename, out, res, exec.returncode))

    return 0


def main():
    args_file_names = [ARGS_WAY + file for file in listdir(ARGS_WAY)
                       if isfile(join(ARGS_WAY, file))]
    args_file_names.sort()

    out_file_names = [OUT_WAY + file for file in listdir(OUT_WAY)
                      if isfile(join(OUT_WAY, file))]
    out_file_names.sort()

    total_tests = 0
    total_passed = 0

    for in_filename, out_filename in zip(args_file_names, out_file_names):
        total_tests += 1
        total_passed += run_test(in_filename, out_filename)

    print("FUNCTIONAL TESTING {}. PASSED {} of {}".format(
        "\033[32mPASSED\033[0m" if (total_tests == total_passed) else "\033[31mFAILED\033[0m",
        total_passed, total_tests))


if __name__ == '__main__':
    main()

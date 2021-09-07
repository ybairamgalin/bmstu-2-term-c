import subprocess

from os import listdir
from os.path import isfile, join

POS_ARGS_WAY = "func_tests/pos/in/args/"
POS_TESTS_OUT = "func_tests/pos/out/"


def parse_args(args_str):
    args = list(args_str.split())
    target = args[0]
    file = args[1]
    field = args[2]
    key = (" ".join(args[3:])).replace("\"", "") if len(args) >= 4 else None

    args_arr = [target, file, field]

    if key is not None:
        args_arr.append(key)

    return args_arr


def main():
    args_file_names = [file for file in listdir(POS_ARGS_WAY)
                       if isfile(join(POS_ARGS_WAY, file))]
    args_file_names.sort()

    out_file_names = [file for file in listdir(POS_TESTS_OUT)
                      if isfile(join(POS_TESTS_OUT, file))]
    out_file_names.sort()

    total_tests = 0
    total_passed = 0

    for in_filename, out_filename in zip(args_file_names, out_file_names):
        total_tests += 1

        try:
            in_args_file = open(POS_ARGS_WAY + in_filename, "r")
            args = in_args_file.readline()
            in_args_file.close()

            args = parse_args(str(args))

            exec_result = subprocess.run(args, capture_output=True)
            return_code = exec_result.returncode
            reality = list((str(exec_result.stdout)[2:-1]).split("\\n"))
            reality = "\n".join(reality)

            out_file = open(POS_TESTS_OUT + out_filename, "r")
            expected = out_file.read()
            out_file.close()

            if reality == expected and return_code == 0:
                print("POS_TEST_{} PASSED".format(total_tests))
                total_passed += 1
            else:
                print("POS_TEST_{} FAILED".format(total_tests))
                print("\treturn code {}".format(return_code))
                print("\texpected\n{}".format(expected))
                print("\treality\n{}".format(reality))

        except FileNotFoundError:
            # TODO
            pass


if __name__ == '__main__':
    main()
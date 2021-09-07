import subprocess

from os import listdir
from os.path import isfile, join

NEG_ARGS_WAY = "func_tests/neg/in/args/"
NEG_TESTS_OUT = "func_tests/neg/out/"


def parse_args(args_str):
    args = list(args_str.split())
    target = args[0] if len(args) >= 1 else None
    file = args[1] if len(args) >= 2 else None
    field = args[2] if len(args) >= 3 else None
    key = (" ".join(args[3:])).replace("\"", "") if len(args) >= 4 else None

    args_arr = []

    if target is not None:
        args_arr.append(target)

    if file is not None:
        args_arr.append(file)

    if field is not None:
        args_arr.append(field)

    if key is not None:
        args_arr.append(key)

    return args_arr


def parse_data(output):
    data = list((str(output)[2:-1]).split("\\n"))
    data = "\n".join(data)
    return data


def main():
    args_file_names = [file for file in listdir(NEG_ARGS_WAY)
                       if isfile(join(NEG_ARGS_WAY, file))]
    args_file_names.sort()

    out_file_names = [file for file in listdir(NEG_TESTS_OUT)
                      if isfile(join(NEG_TESTS_OUT, file))]
    out_file_names.sort()

    total_tests = 0
    total_passed = 0

    for in_filename, out_filename in zip(args_file_names, out_file_names):
        total_tests += 1

        try:
            in_args_file = open(NEG_ARGS_WAY + in_filename, "r")
            args = in_args_file.readline()
            in_args_file.close()

            args = parse_args(str(args))

            exec_result = subprocess.run(args, capture_output=True)
            return_code = exec_result.returncode
            reality = parse_data(exec_result.stdout)

            out_file = open(NEG_TESTS_OUT + out_filename, "r")
            expected = out_file.read()
            out_file.close()

            if reality == expected and return_code != 0:
                print("NEG_TEST_{}\tPASSED".format(total_tests))
                print("\treturn code {}".format(return_code))
                total_passed += 1
            else:
                print("NEG_TEST_{}\tFAILED".format(total_tests))
                print("\treturn code {}".format(return_code))
                print("\texpected\n{}".format(expected))
                print("\treality\n{}".format(reality))

        except FileNotFoundError:
            print("Check files!")


if __name__ == '__main__':
    main()

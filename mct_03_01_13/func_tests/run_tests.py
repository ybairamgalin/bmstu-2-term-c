import subprocess
from os import listdir, remove
from os.path import isfile, join


def main():
    in_files = ["func_tests/in/" + file for file in listdir("func_tests/in/")]
    out_files = ["func_tests/out/" + file for file in listdir("func_tests/out/")]

    for in_cont, out_cont in zip(in_files, out_files):
        execution = subprocess.run("./app.exe < {} > out.txt".format(in_cont),
                                   capture_output=True, shell=True)
        expected = open(out_cont, "r").readlines()
        reality = open("out.txt", "r").readlines()[1:]

        if "pos" in in_cont:
            print("{} {}".format(in_cont, "PASSED" if expected == reality and execution.returncode == 0 else "FAILED"))
        else:
            print("{} {}".format(in_cont, "PASSED" if expected == reality and execution.returncode != 0 else "FAILED"))


if __name__ == '__main__':
    main()

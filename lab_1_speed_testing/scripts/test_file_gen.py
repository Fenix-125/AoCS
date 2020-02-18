#! /bin/python3.8
# Script that generates text file with double values to test performance
# of double-string casting function.

from random import uniform


def generate_text(file_name: str, f_size: int):
    """
    Function generates a text file (of size larger than 'size' in MB) of double values.
    If the file already exist will raise an ERROR.

    :param file_name: the name file to create
    :param f_size: minimal size of the generated file in MB
    """
    with open(file_name, 'w+', encoding="ASCII") as f:
        file_size = 0
        while file_size < f_size * 1000000:
            str_num = "%.14f" % uniform(-100, 100)
            print(str_num, file=f)
            file_size += len(str_num)


if __name__ == '__main__':
    try:
        generate_text("tmp/doubles_1MB.txt", 1)
    except IOError as e:
        print(f"Error file {str(e).split()[-1]} already exist! Use other file name or delete this file.")

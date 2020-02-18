#! /bin/python3.8

from os.path import isfile
from subprocess import Popen, PIPE
from sys import argv
from typing import List


class InvaliCommandLineArgs(Exception):
    pass


class InvalidData(Exception):
    pass


class InvalidMerge(Exception):
    pass


class InvalidResultConfig(Exception):
    pass


class TestResult:
    def __init__(self, text_list: List[str] = None, other=None):
        self.name = None
        self.sec = None
        self.m_sec = None
        self.u_sec = None
        self.data = None
        self.char_count = None
        self.avg_len = None
        if text_list is not None:
            self._pars_result(text_list)

        if other is not None:
            self.merge(other)

    def __swap_and_del_other(self, other):
        self.name = other.name
        self.sec = other.sec
        self.m_sec = other.m_sec
        self.u_sec = other.u_sec
        self.data = other.data
        self.char_count = other.char_count
        self.avg_len = other.avg_len
        del other

    def __get_best_res(self, other):
        if other.sec < other.m_sec < other.u_sec and self.sec < self.m_sec < self.u_sec:
            self.sec = min(other.sec, self.sec)
            self.m_sec = min(other.m_sec, self.m_sec)
            self.u_sec = min(other.u_sec, self.u_sec)
        else:
            raise InvalidResultConfig("Invalid test time measurement!")

    def merge(self, other):
        if other.is_none():
            return self
        if self.is_none():
            self.__swap_and_del_other(other)
            return self

        if self.name != other.name:
            raise InvalidMerge("Names of methods differ. Different test can not be merged!")
        if self.avg_len != other.avg_len or self.char_count != other.char_count:
            raise InvalidMerge(f"Results differ for tested method '{self.name}' !")
        if not self.__check_data(self.data, other.data):
            raise InvalidMerge(f"Results differ for tested method '{self.name}' !")
        self.__get_best_res(other)
        del other
        return self

    @staticmethod
    def __check_data(data_1: List[str], data_2: List[str]) -> bool:
        if len(data_1) != len(data_2):
            return False

        for el_1, el_2 in zip(data_1, data_2):
            if el_1 != el_2:
                return False
        return True

    def is_none(self):
        if self.name is None and self.sec is None and self.m_sec is None and self.u_sec is None \
                and self.data is None and self.char_count is None and self.avg_len is None:
            return True
        elif self.name is None or self.sec is None or self.m_sec is None or self.u_sec is None \
                or self.data is None or self.char_count is None or self.avg_len is None:
            raise InvalidResultConfig()
        else:
            return False

    def _pars_result(self, res_in: List[str]):
        self.name = res_in[1].strip().split()[-1]
        speed_test_index = self._find_start_with(res_in, "Speed test")
        char_info_index = self._find_start_with(res_in, "Characters number")
        data_start_index = self._find_start_with(res_in, "#$DATA_START$#")

        if speed_test_index is None:
            raise InvalidData("Data has no 'Speed test' line!")
        if char_info_index is None:
            raise InvalidData("Data has no 'Characters number' line!")
        if data_start_index is None:
            raise InvalidData("Data has no '#$DATA_START$#' line!")

        self.sec = int(res_in[speed_test_index + 1].strip().split()[-1])
        self.m_sec = int(res_in[speed_test_index + 2].strip().split()[-1])
        self.u_sec = int(res_in[speed_test_index + 3].strip().split()[-1])
        self.char_count = int(res_in[char_info_index].strip().split()[-1])
        self.avg_len = float(res_in[char_info_index + 1].strip().split()[-1])
        self.data = [el.strip() for el in res_in[data_start_index + 1:]]

    @staticmethod
    def _find_start_with(data: List[str], start: str):
        for index in range(len(data)):
            if data[index].strip().startswith(start):
                return index
        return None


def test_mode(mode_id: int, times: int, f_in: str, f_out: str) -> (str, int):
    res = TestResult()
    for _ in range(times):
        with Popen(["cmake-build-debug/double_cast_test", str(mode_id), f_in, f_out], stdout=PIPE):
            pass
        with open(f_out, 'r') as f:
            res = TestResult(f.readlines()).merge(res)
    return res


def render_result(res: TestResult) -> str:
    valid = check_valid_res(res.data)
    return f"{res.name}({res.char_count} chars):\t{res.u_sec}  {'VALID' if valid else 'INVALID'}"


def check_valid_res(data: List[str]) -> bool:
    if len(data) != len(origin_data):
        return False
    for el_1, el_2 in zip(data, origin_data):
        # if el_1 != el_2:
        if round(float(el_1), 14) != round(float(el_2), 14):
            return False
    return True


if __name__ == '__main__':
    if len(argv) != 4:
        raise InvaliCommandLineArgs("Expected 3 arguments (number of tests, input file, output file)!")
    elif not argv[1].isnumeric() and int(argv[1]) > 0:
        raise InvaliCommandLineArgs("First argument (number of tests) should be an positive integer!")
    elif not isfile(argv[2]):
        raise InvaliCommandLineArgs(f"File {argv[2]} do not exist. No source data got!")

    n = int(argv[1])
    file_in = argv[2]
    file_out = argv[3]

    with open(file_in, 'r') as file:
        origin_data = [line.strip() for line in file.readlines()]
    print("Test cast double to string by:")
    for mode in range(1, 5):
        result = test_mode(mode, n, file_in, file_out)
        print(render_result(result))

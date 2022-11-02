import abc, random
from abc import ABC


class SortStrategy(abc.ABC):
    @abc.abstractmethod
    def __init__(self, arr, size):
        return

    @abc.abstractmethod
    def __del__(self):
        return


def is_sorted(arr):
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            return False
    return True


class BogoSort(SortStrategy):
    def __init__(self, arr, size):
        super().__init__(arr, size)
        print('bogosort called')

    def __del__(self):
        return

    @staticmethod
    def sort(arr, size):
        print('sort method called')
        while not is_sorted(arr):
            random.shuffle(arr)


class Sort:
    ptr_to_bogosort = BogoSort

    def __init__(self):
        return

    @staticmethod
    def set_strategy(strategy):
        return Sort.ptr_to_bogosort


if __name__ == '__main__':
    testarr = [1, 3, 2, 4]
    Sort.set_strategy(BogoSort).sort(testarr, len(testarr))
    print(testarr)

import abc, random


class SortStrategy(abc.ABC):  # абстрактный класс
    @abc.abstractmethod
    def __init__(self, arr, size):  # пустой конструктор
        return

    @abc.abstractmethod  # пустой деструктор
    def __del__(self):
        return


def is_sorted(arr):
    for i in range(len(arr) - 1):
        if arr[i] > arr[i + 1]:
            return False
    return True


class BogoSort(SortStrategy):
    def __init__(self, arr, size):  # пустой конструктор, который мы переопределили
        print('bogosort called')  # так и не вызывается кста

    def __del__(self):  # пустой деструктор, который мы переопределили
        return

    @staticmethod
    def sort(arr, size):  # алгоритм сортировки. статичный потому что всё равно у класса своих полей нет
        print('sort method called')
        while not is_sorted(arr):
            random.shuffle(arr)


class Sort:
    def __init__(self):  # пустой конструктор
        return

    def __del__(self):
        return

    # из класса сорт вызываем сеттер, указывающий на наследника сорт стратеджи
    @staticmethod
    def set_strategy(strategy: SortStrategy.__subclasses__()):  # ооп функциональное метапрогромирование
        return strategy


if __name__ == '__main__':
    testarr = [1, 3, 2, 4]
    sort_algorythm = Sort.set_strategy(BogoSort)  # выбрали
    sort_algorythm.sort(testarr, len(testarr))  # вызвали метод сорт у нужного класса
    print(testarr)
    # оно нет хз
    # я бы просто написал класс сорт и у него добавил бы разные методы сортировок без етой вот абстракщины

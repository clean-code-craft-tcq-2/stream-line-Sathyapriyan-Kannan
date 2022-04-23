class BMSManagement:
    def __init__(self, current, temperature, no_of_bits):
        self.__max_current = current
        self.__max_temp = temperature
        self.__max_bits = no_of_bits

    @property
    def max_current(self):
        return self.__max_current

    @property
    def max_temp(self):
        return self.__max_temp

    @property
    def max_bits(self):
        return self.__max_bits


import random
import bms_ranges


def print_readings_in_console(data_sets):
    for data_set in data_sets:
        print('{},{}'.format(data_set['Current'], data_set['Temperature']))


class BMSDataSimulator:
    def __init__(self, threshold_obj, no_of_samples):
        self.__thershold_obj = threshold_obj
        self.__max_possible_reading = self.get_max_possible_reading()
        self.__no_of_samples = no_of_samples

    @property
    def threshold_obj(self):
        return self.__thershold_obj

    @property
    def max_reading(self):
        return self.__max_possible_reading

    @property
    def no_of_samples(self):
        return self.__no_of_samples

    def get_max_possible_reading(self):
        return pow(2, self.__thershold_obj.max_bits) - 1

    def convert_a2d_to_amp(self, current_data_samples):
        current_data_samples = [
            round(current_data_sample * self.__thershold_obj.max_current / self.__max_possible_reading)
            for current_data_sample in current_data_samples]

        return current_data_samples

    def generate_random_data(self, max_value):
        data_set = []
        for i in range(0, self.__no_of_samples):
            sample = random.randint(0, max_value)
            data_set.append(sample)
        return data_set

    def generate_samples_for_a2d_sensor(self):
        bms_data = []
        current_data_samples = self.generate_random_data(self.__max_possible_reading)
        current_data_samples = self.convert_a2d_to_amp(current_data_samples)
        temperature_data_samples = self.generate_random_data(self.__thershold_obj.max_temp)

        for i in range(0, self.__no_of_samples):
            bms_data.append({'Current': current_data_samples[i], 'Temperature': temperature_data_samples[i]})
        print_readings_in_console(bms_data)
        return bms_data


bms_range = bms_ranges.BMSManagement(30, 40, 10)
bms_data = BMSDataSimulator(bms_range, 50)
bms_data.generate_samples_for_a2d_sensor()

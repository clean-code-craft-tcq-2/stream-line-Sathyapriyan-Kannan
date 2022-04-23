import unittest
import bms_ranges
import bms_data_simulator


class TestDrivenRangesTest(unittest.TestCase):
    def test_bms_range_data(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        self.assertEqual(bms_range.max_current, 30)
        self.assertEqual(bms_range.max_temp, 40)
        self.assertEqual(bms_range.max_bits, 10)

    def test_bms_data_simulator(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        bms_data = bms_data_simulator.BMSDataSimulator(bms_range, 50)
        self.assertEqual(bms_data.threshold_obj, bms_range)

    def test_get_maximum_possible_reading(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        bms_data = bms_data_simulator.BMSDataSimulator(bms_range, 50)
        self.assertEqual(bms_data.max_reading, 1023)

    def test_no_of_samples(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        bms_data = bms_data_simulator.BMSDataSimulator(bms_range, 50)
        self.assertEqual(bms_data.no_of_samples, 50)

    def test_generate_random_data(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        bms_data = bms_data_simulator.BMSDataSimulator(bms_range, 50)
        self.assertLessEqual(max(bms_data.generate_random_data(bms_range.max_temp)), bms_range.max_temp)
        self.assertLessEqual(max(bms_data.generate_random_data(bms_range.max_current)), bms_range.max_current)

    def test_convert_a2d_to_amp(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        bms_data = bms_data_simulator.BMSDataSimulator(bms_range, 50)
        self.assertEqual(bms_data.convert_a2d_to_amp([0, 100, 200]), [0, 3, 6])
        self.assertEqual(bms_data.convert_a2d_to_amp([]), [])

    def test_generate_samples_for_a2d_sensor(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        bms_data = bms_data_simulator.BMSDataSimulator(bms_range, 50)
        self.assertTrue(len(bms_data.generate_samples_for_a2d_sensor()), 50)

    def test_data_sample_type(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        bms_data = bms_data_simulator.BMSDataSimulator(bms_range, 50)
        self.assertTrue(type(bms_data.generate_samples_for_a2d_sensor()), list)
        self.assertTrue(type(bms_data.generate_samples_for_a2d_sensor()[0]), dict)


unittest.main()

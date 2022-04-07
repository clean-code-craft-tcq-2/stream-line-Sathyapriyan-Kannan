import unittest
import bms_ranges


class TestDrivenRangesTest(unittest.TestCase):
    def test_bms_range_data(self):
        bms_range = bms_ranges.BMSManagement(30, 40, 10)
        self.assertEqual(bms_range.max_current, 30)
        self.assertEqual(bms_range.max_temp, 40)
        self.assertEqual(bms_range.max_bits, 10)

unittest.main()


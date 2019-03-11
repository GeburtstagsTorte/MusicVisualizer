import RPi.GPIO as GPIO
from LEDsGPIO import LEDsGPIO as LEDs


class EightLEDs(LEDs):

    def __init__(self, pin_list):
        super().__init__(pin_list)

    def visualize(self, data):
        pin_states = self.convert(data)
        self.update(pin_states)

    def convert(self, data):
        return self.wave_form(data, 1024, 128)

    def wave_form(self, data, chunk_size, step):
        pin_states = []
        max_value = max(data)
        for i in range(0, chunk_size, step):
            pin_states.append(self.is_valid(data[i:i+step], max_value, 0.4))

        return pin_states

    @staticmethod
    def is_valid(data, max_value, threshold):
        count = 0
        for d in data:
            if abs(d) > max_value * threshold:
                count += 1
        return count >= 64


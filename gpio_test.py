import RPi.GPIO as GPIO
from time import sleep


def setup_pins(pin_list, modifier, init):
    for pin in pin_list:
        GPIO.setup(pin, modifier, initial=init)


def default_iteration(pin_list):
    for pin in pin_list:
        GPIO.output(pin, GPIO.HIGH)
        sleep(0.5)
        GPIO.output(pin, False)


def blink(pin_list, times):
    for _ in range(times):
        for pin in pin_list:
            GPIO.output(pin, True)

        sleep(0.5)

        for pin in pin_list:
            GPIO.output(pin, False)

        sleep(0.5)


def binary_counter(pin_list):
    for i in range(2 ** len(pin_list)):
        states = [int(j) for j in [int(x) for x in format(i, '#0{}b'.format(len(pin_list)+2))[2:]]]  # hf

        for pin, state in zip(pin_list, states):
            GPIO.output(pin, state)

        sleep(0.05)


def main():
    GPIO.setmode(GPIO.BOARD)
    pin_list = [13, 15, 7, 29, 31, 33, 35, 37]

    setup_pins(pin_list, GPIO.OUT, False)

    print("starting script...")
    print("sleep 2 sec.")

    sleep(2)

    print("executing light show...")

    default_iteration(pin_list)

    sleep(2)

    blink(pin_list, 5)

    sleep(1)

    binary_counter(pin_list)

    print("light show finished.")


if __name__ == '__main__':
    main()
    GPIO.cleanup()
    print("script terminated successfully")

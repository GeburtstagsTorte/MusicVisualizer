import pyaudio
import numpy as np
import time


class Listener:

    def __init__(self):
        self.CHUNK = 1024 * 2
        self.FORMAT = pyaudio.paInt16
        self.CHANNELS = 1
        self.RATE = 44100

        self.p = pyaudio.PyAudio()

        self.stream = self.p.open(
                        format=self.FORMAT,
                        input=True,
                        output=False,
                        channels=self.CHANNELS,
                        rate=self.RATE,
                        frames_per_buffer=self.CHUNK
        )

    def get_stream_chunk(self):
        print("get stream chunk...")
        data = self.stream.read(self.CHUNK, exception_on_overflow=False)
        return np.frombuffer(data, dtype=np.int16)[::2]

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        print("Listener was closed with \n"
              "exc_type : {} \n"
              "exc_val  : {} \n"
              "exc_tb   : {}".format(exc_type, exc_val, exc_tb))
        self.stream.close()


def loop():
    print("before init")
    listener = Listener()
    print("after init")
    t1 = time.time()

    while True:
        print(listener.get_stream_chunk())
        if time.time() - t1 >= 20:
            break


def with_version():
    with Listener() as listener:
        t1 = time.time()
        while True:
            print(listener.get_stream_chunk())
            if time.time()-t1 >= 20:
                break


def main():
    with_version()


if __name__ == '__main__':
    main()

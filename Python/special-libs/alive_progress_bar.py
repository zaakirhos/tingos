from asyncio.log import logger
from alive_progress import alive_it, alive_bar
from alive_progress.styles import showtime, Show
import logging
import time


# with logging
def with_logging():
    logging.basicConfig(level=logging.INFO)
    logger = logging.getLogger("alive_progress")
    sum = 0
    with alive_bar(total=1000) as bar:
        for i in range(1000):
            time.sleep(0.01)
            sum += i
            bar()
        logger.info("Finished! Sum: %s", sum)


# with logging and custom stuff
def with_logging_customized():
    logging.basicConfig(level=logging.INFO)
    logger = logging.getLogger("alive_progress")
    sum = 0
    with alive_bar(
        total=1000, title="Processing...", bar="checks", spinner="twirls"
    ) as bar:
        for i in range(1000):
            time.sleep(0.01)
            sum += i
            bar()
        logger.info("Finished! Sum: %s", sum)


# Just with an iterable
def with_iterable():
    sum = 0
    for i in alive_it(range(1000)):  # <<-- wrapped items
        for j in range(i * 100, i * 2000):
            sum += j
    print(sum)


# No total, no progress. Only counts the operation indefinitely
def no_total():
    sum = 0
    with alive_bar() as bar:
        for i in range(1000):
            for j in range(i * 100, i * 2000):
                sum += j
                bar()
    print(sum)


def all_styles():
    showtime()
    # exit the program to runt the next line, as this is an infinite loop
    showtime(Show.THEMES)
    # exit the program to runt the next line, as this is an infinite loop
    showtime(Show.SPINNERS)
    # exit the program to runt the next line, as this is an infinite loop
    showtime(Show.BARS)


def main():
    # with_logging()
    # with_logging_customized()
    # with_iterable()
    # no_total()
    all_styles()


if __name__ == "__main__":
    main()

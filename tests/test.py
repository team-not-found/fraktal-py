from pylab import *
import time

import fraktal_py as fp


def timer(func):
    """
    This decorator will print out
    the execution time in seconds.
    """
    def wrapper(*args, **kwargs):
        before = time.time()
        value = func(*args, **kwargs)
        print('Function execution took: ', time.time() - before, 'seconds')
        return value
    
    return wrapper


@timer
def generate_fractal(fern):
    fern.generateFractal(1920, 1080, 100000000)


@timer
def save_fractal(fern, filename):
    fern.saveFractal(filename)


@timer
def read_density_map_from_file(fern, filename):
    a = fromfile(filename, dtype=float64).reshape((fern.nX, fern.nY))
    
    return a


@timer
def read_density_map_from_memory(fern):
    a = fern.density_map

    return np.asarray(a)


@timer
def process_density_map(a):
    print(np.sum(a))
    print(np.min(a))
    a+=1.0
    a=np.log(a)

    return a

def main():
    filename = "plot.bin"
    fern = fp.Fern()

    generate_fractal(fern)
    # uncomment of you want to test the time it takes to read the map from file
    # save_fractal(fern, filename)
    # a = read_density_map_from_file(fern, filename)

    a = read_density_map_from_memory(fern)
    a = process_density_map(a)

    plt.matshow(a)
    plt.show()


if __name__ == "__main__":
    main()
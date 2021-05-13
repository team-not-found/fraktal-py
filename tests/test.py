from pylab import *
import time

import fraktal_py as fp


def timer(func):
    """
    This decorator will print out
    the execution time in seconds.
    """
    def wrapper(*args, **kwargs):
        print('Executing ', func.__name__)
        before = time.time()
        value = func(*args, **kwargs)
        print('Function execution took: ', time.time() - before, 'seconds')
        return value
    
    return wrapper


@timer
def generate_fern(fern):
    fern.generateFractal(1920, 1080, 100000000)


@timer
def generate_mandelbrot(mandelbrot):
    mandelbrot.generateFractal(1333, 1000, -2.0, -1.0, 1.0, 1.0, 1000)


@timer
def save_fern(fern, filename):
    fern.saveFractal(filename)


@timer
def read_fern_density_map_from_file(fern, filename):
    a = fromfile(filename, dtype=float64).reshape((fern.nX, fern.nY))
    
    return a


@timer
def read_fern_density_map_from_memory(fern):
    a = fern.density_map

    return np.asarray(a)


@timer
def read_mandelbrot_density_map_from_memory(mandelbrot):
    a = mandelbrot.density_map


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
    mandelbrot = fp.Mandelbrot()

    generate_fern(fern)
    generate_mandelbrot(mandelbrot)
    # uncomment of you want to test the time it takes to read the map from file
    # save_fractal(fern, filename)
    # a = read_fern_density_map_from_file(fern, filename)

    a = read_fern_density_map_from_memory(fern)
    a = process_density_map(a)

    b = read_mandelbrot_density_map_from_memory(mandelbrot)
    b = process_density_map(b)

    plt.matshow(a)
    plt.show()

    plt.matshow(b)
    plt.show()


if __name__ == "__main__":
    main()
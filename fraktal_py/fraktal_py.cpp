#include <pybind11/pybind11.h>

#include <string>

#include "dummy/dummy.hpp"
#include "fern/fern.hpp"
#include "mandelbrot/mandelbrot.hpp"
#include "utility/matrix2d.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(fraktal_py, m) {

  py::class_<Matrix2d<double>>(m, "Matrix2d", py::buffer_protocol())
      .def(py::init<>())
      .def(py::init<int, int>())
      .def("print", &Matrix2d<double>::print)
      .def_buffer([](Matrix2d<double> &matrix) -> py::buffer_info {
        return py::buffer_info(
            matrix.getData(),                        /* Pointer to buffer */
            sizeof(double),                          /* Size of one scalar */
            py::format_descriptor<double>::format(), /* Python struct-style
                                                        format descriptor */
            2,                                       /* Number of dimensions */
            {matrix.getN(), matrix.getM()},          /* Buffer dimensions */
            {sizeof(double) *
                 matrix.getM(), /* Strides (in bytes) for each index */
             sizeof(double)});
      });

  py::class_<Fern>(m, "Fern")
      .def(py::init<>())
      .def_readwrite("nX", &Fern::nX)
      .def_readwrite("nY", &Fern::nY)
      .def_readwrite("density_map", &Fern::densityMap)
      .def("generateFractal", &Fern::generateFractal)
      .def("saveFractal", &Fern::saveFractal);

  py::class_<Mandelbrot>(m, "Mandelbrot")
      .def(py::init<>())
      .def_readwrite("nX", &Mandelbrot::nX)
      .def_readwrite("nY", &Mandelbrot::nY)
      .def_readwrite("density_map", &Mandelbrot::densityMap)
      .def("generateFractal", &Mandelbrot::generateFractal)
      .def("saveFractal", &Mandelbrot::saveFractal);

  m.def("hello", &hello);
  /// Dont ask me what this does 'cuz i have no idea.
  m.doc() = R"pbdoc(
            Pybind11 example plugin
            -----------------------
            .. currentmodule:: fraktal_py
            .. autosummary::
            :toctree: _generate

            Matrix2d
            Fern
            hello
        )pbdoc";

#ifdef VERSION_INFO
  m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
  m.attr("__version__") = "dev";
#endif
}
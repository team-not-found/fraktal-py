#include <pybind11/pybind11.h>

#include<string>

#include "dummy.hpp"
#include "fern.hpp"
#include "utility/matrix2d.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

PYBIND11_MODULE(fraktal_py, m) {

    py::class_<Matrix2d<double>>(m, "Matrix2d")
        .def(py::init<>())
        .def(py::init<int, int>())
        .def("print", &Matrix2d<double>::print)
        .def("__call__", 
            [](Matrix2d<double> &m, int i, int j) {
                return m(i, j);
            })
        .def("set", 
            [](Matrix2d<double> &m, int i, int j, double value) {
                m(i, j) = value;
            });

    py::class_<Fern>(m, "Fern")
        .def(py::init<>())
        .def_readwrite("nX", &Fern::nX)
        .def_readwrite("nY", &Fern::nY)
        .def("generateFractal", &Fern::generateFractal)
        .def("saveFractal", &Fern::saveFractal);

    m.def("hello", &hello);
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
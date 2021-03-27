#include <pybind11/pybind11.h>

#include "fraktal.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)


namespace py = pybind11;

PYBIND11_MODULE(fraktal_py, m) {
    py::class_<Fraktal>(m, "Fraktal")
        .def(py::init<>())
        .def("hello", &Fraktal::hello);

    m.doc() = R"pbdoc(
            Pybind11 example plugin
            -----------------------
            .. currentmodule:: fraktal_py
            .. autosummary::
            :toctree: _generate
            hello
        )pbdoc";

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
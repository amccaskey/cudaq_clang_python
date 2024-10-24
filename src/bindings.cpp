#include <pybind11/pybind11.h>
#include "noise_wrapper.h"

namespace py = pybind11;

PYBIND11_MODULE(noise_model_wrapper, m) {
    m.doc() = "CUDA-Q noise model wrapper using pybind11";

    py::class_<NoiseWrapper>(m, "NoiseWrapper")
        .def(py::init<>())
        .def("apply_noise_model", &NoiseWrapper::apply_noise_model, 
             "Apply a CUDA-Q noise model")
        .def("get_noise_info", &NoiseWrapper::get_noise_info,
             "Get information about the current noise model");
}
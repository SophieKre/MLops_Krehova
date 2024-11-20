#include "min_max_scaling.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(mse_core, m) {
  m.doc() = R"doc(
    Python bindings for MeanSquaredError library
  )doc";

  py::class_<MeanSquaredError>(m, "MeanSquaredError")
      .def_static("MSE", &MeanSquaredError::MSE, R"doc(
          Compute mean squared error using pure C++.

          Parameters:
            a : list of float
                The first vector.
            b : list of float
                The second vector.

          Returns:
            float
                The mean squared error between two vectors.
      )doc");
}

#include "min_max_scaling.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(mse_core, m) {
  m.doc() = R"doc(
    Python bindings for MinMaxScaling library
  )doc";

  py::class_<MeanSquaredError>(m, "MinMaxScaling")
      .def_static("MMS", &MinMaxScaling::MMS, R"doc(
          Compute min max scaling using pure C++.

          Parameters:
            a : list of float vector.
          
          Returns:
            float
                The min max scaling of the vector.
      )doc");
}

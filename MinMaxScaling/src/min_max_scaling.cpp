#include "min_max_scaling.h"

#include <iostream>
#include <vector>

double MinMaxScaling::MMS(const std::vector<double> &a) {
  if (a.empty()) {
    throw std::invalid_argument("Input vector is empty");
  }

  double min_val = *std::min_element(a.begin(), a.end());
  double max_val = *std::max_element(a.begin(), a.end());
  if (min_val == max_val) {
        throw std::invalid_argument("Input vector has identical values; standardization is not possible.");
    }
  std::vector<double> standard;
    standard.reserve(a.size());

    for (double val : a) {
        standard.push_back((val - min_val) / (max_val - min_val));
    }

    return standard;
}


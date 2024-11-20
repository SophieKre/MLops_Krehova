import time
from typing import Callable

import numpy as np
import scikit-learn
from sklearn.preprocessing import MinMaxScaler


import MinMaxScaling as mse

def test_timings(func: Callable, *args):
    _ = func(*args)
    start_time = time.time()
    _ = func(*args)
    end_time = time.time()
    return round(end_time - start_time, 5)


if __name__ == "__main__":
    scaler = MinMaxScaler()
    for l in [5, 10, 50, 100, 500, 1000, 5000]:
        a = np.random.rand(l)
        print("Min Max Scaling (Pure C++), size={0}: {1} seconds".format(l, test_timings(mse.MeanSquaredError.MSE, a)))
        print("Min Max Scaling (Python sklearn), size={0}: {1} seconds\n".format(l, test_timings(scaler.fit_transform, a)))

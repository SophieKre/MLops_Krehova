CXX=g++
CXXFLAGS=-std=c++11 -O3 -march=native -Wall -I$(SRC_DIR) $(shell python3 -m pybind11 --includes)
PY_LDFLAGS=$(shell python3-config --ldflags) -shared -fPIC
GTEST_FLAGS=-lgtest -lgtest_main -pthread
LDFLAGS=-lopenblas
SRC_DIR=MinMaxScaling/src
TESTS_DIR=MinMaxScaling/tests
PYTHON_DIR=MinMaxScaling/python

all: MeanSquaredError test

MeanSquaredError: $(PYTHON_DIR)/bindings.o $(SRC_DIR)/min_max_scaling.o
	$(CXX) $^ -o $(PYTHON_DIR)/mms_core`python3-config --extension-suffix` $(PY_LDFLAGS) $(CXXFLAGS)

$(PYTHON_DIR)/bindings.o: $(PYTHON_DIR)/bindings.cpp $(SRC_DIR)/min_max_scaling.h
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

$(SRC_DIR)/min_max_scaling.o: $(SRC_DIR)/min_max_scaling.cpp $(SRC_DIR)/min_max_scaling.h
	$(CXX) $(CXXFLAGS) -fPIC -c $< -o $@

test: $(TESTS_DIR)/test_mms.o $(SRC_DIR)/min_max_scaling.o
	$(CXX) $^ -o $(TESTS_DIR)/test_mms $(GTEST_FLAGS) $(LDFLAGS)

$(TESTS_DIR)/test_mms.o: $(TESTS_DIR)/test_mms.cpp $(SRC_DIR)/min_max_scaling.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run_tests: test
	./$(TESTS_DIR)/test_mms

clean:
	rm -f $(PYTHON_DIR)/*.o $(SRC_DIR)/*.o $(TESTS_DIR)/*.o $(PYTHON_DIR)/mms_core`python3-config --extension-suffix` $(TESTS_DIR)/test_mms

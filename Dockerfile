FROM ubuntu:22.04

RUN apt update
RUN apt-get install -y g++ python3 libopenblas-dev pip vim git tree
RUN apt-get install -y libgtest-dev
RUN apt-get install -y python3.10-venv

RUN pip install setuptools
RUN pip install pybind11
RUN pip install build
RUN pip install numpy
RUN pip install scikit-learn

RUN https://github.com/SophieKre/MLops_Krehova.git
WORKDIR /MLops_Krehova

from setuptools import setup, find_packages
from glob import glob

so_files = glob("MinMaxScaling/python/mms_core*.so")

setup(
    name="MinMaxScaling",
    version="0.1",
    description="Min max scaling utility with Python bindings",
    packages=find_packages(),
    package_data={
        "MinMaxScaling": ["python/*.so"],
    },
)

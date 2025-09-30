from setuptools import find_packages
from setuptools import setup

setup(
    name='referee_pkg',
    version='0.0.0',
    packages=find_packages(
        include=('referee_pkg', 'referee_pkg.*')),
)

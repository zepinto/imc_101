#!/bin/bash

# Install dependencies
sudo apt install -y python3-pip cmake g++ git ant
pip3 install setuptools
pip3 install imctrans    

# Get latest IMC
git clone https://github.com/lsts/imc.git imc_src

# Generate IMC/ bindings for C++
imctrans translate -x imc_src/IMC.xml -l cpp -o .

# Generate documentation/
python3 imc_src/doc/generate.py && mv imc_src/doc/reference documentation



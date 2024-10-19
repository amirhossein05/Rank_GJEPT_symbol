# Rank_GJEPT - Symbol Rank Calculation for Noisy Channels
This repository contains a C++ project that calculates symbol rank using a Gaussian Jordan Elimination algorithm, which is particularly useful for noisy communication channels. The symbol rank calculated by this project can be applied to channel codes such as Reed-Solomon codes to enhance error correction performance.
## Features
* Rank Calculation: The project computes the rank of symbols, which is a critical metric in error correction and detection in communication systems.
* Support for Noisy Channels: The rank calculation is optimized for channels with noise, improving the accuracy and efficiency of error detection in practical use cases.
* Channel Coding Support: The symbol rank calculations work well with error-correcting codes, including Reed-Solomon codes, to protect data integrity.


## Directory Structure

- **Main Source Files**:
  - `GF_rank_sym.cpp`: Main file for Gaussian elimination-based rank calculation.
  - `GJETP.cpp`: Additional processing for Gaussian Jordan Elimination.
  - `newtest.cpp`, `test.cpp`: Test files for rank calculation and correctness verification.
  - `testcsv.cpp`: CSV-based test file for reading and writing matrix data from CSV.

- **Header Files**:
  - `Identity.h`: Defines identity matrix operations.
  - `Mod.h`: Modular arithmetic operations for finite field calculations.
  - `Readcsv.h`: Handles CSV file reading.
  - `Vec2Mat.h`: Converts vectors to matrices for rank calculations.
  - `ZerosMatrix.h`: Matrix initialization with zeroes.
  - `bitxor.h`, `xorBinaryData.h`: XOR operations for binary data.

- **CSV Files**:
  - `matrix.csv`: Sample matrix file used in rank calculations.
  - `e2p.csv`, `p2e.csv`, `e2pCSV.csv`: Example CSV files for matrix data.

- **Project Files**:
  - `Rank_GJEPT.vcxproj`: Visual Studio project file for compiling the project.
  - `.sln`: Visual Studio solution file.
  - `.gitignore`: Ignored files for Git tracking.

## Requirements

- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., g++, clang, or MSVC).
- **CSV Library**: The project uses CSV files for matrix input/output, so a CSV reading/writing library or functionality is required.

## Contributions
Feel free to open issues and submit pull requests. Contributions are welcome!
  

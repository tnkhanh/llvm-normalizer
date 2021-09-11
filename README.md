Llvm-normalizer
====================
*A LLVM bitcode normalizer to support the Discover analyzer*


# Prerequisites:

## External libraries:

- For backward-cpp:

  ``` bash
  # install LLVM and Clang 11 (or the suitable version)
  sudo apt-get install llvm-11-dev clang-11 libclang-11-dev

  # install other libraries
  sudo apt-get install libedit-dev
  ```

## This tool:

- LLVM framework

# Installation

- Modify the file `CMakeLists.txt` to update `LLVM_CMAKE_PATH_HINTS` to the
  CMake folder corresponding the installed LLVM, (version 11.1 is preferred).
  For examples:

  ``` cmake
  set(LLVM_CMAKE_PATH_HINTS
  "$HOME/llvm/llvm-11/lib/cmake/llvm"              # manually installed
  "/usr/lib/llvm-11/lib/cmake/llvm/"               # Ubuntu installed
  ...)
  ```

- Add the llvm bin path to PATH

- Eg: Add export `PATH=/usr/local/opt/llvm/bin:$PATH` in `/.bash_profile`.

- Build by CMake:

  ``` bash
  mkdir build
  cd build
  cmake ../
  make
  ```

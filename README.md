llvm-normalizer
====================
*A LLVM bitcode normalizer to support the Discover analyzer*

# Compiling llvm-Normalizer

## Prerequisites

- LLVM and Clang 11.1

  + Install from Linux repositories:

    ```sh
    # Ubuntu, Linux Mint
    sudo apt-get install llvm-11 llvm-11-dev clang-11 libclang-11-dev

    # Arch Linux, Manjaro
    sudo pacman -S llvm11 clang11
    ```
  + If LLVM and Clang cannot be installed automatically, then in Ubuntu-based
    operating systems, user can download a [pre-built LLVM and Clang 11.1](https://github.com/llvm/llvm-project/releases/download/llvmorg-11.1.0/clang+llvm-11.1.0-x86_64-linux-gnu-ubuntu-20.10.tar.xz)
    from the LLVM project, and extract it to `$HOME/llvm/llvm-11`.

    Then, run the following commands to update the environment variables:

    ``` sh
    # Assume that LLVM + Clang 11.1 binaries are stored at $HOME/llvm/llvm-11/
    export PATH=$HOME/llvm/llvm-11/bin:$PATH
    export LD_LIBRARY_PATH=$HOME/llvm/llvm-11/lib:$LD_LIBRARY_PATH
    ```

  + Otherwise, LLVM and Clang 11 can be downloaded and built from source code.
    To do this, download the [source code of LLVM and Clang 11.1](https://github.com/llvm/llvm-project/releases/download/llvmorg-11.1.0/llvm-project-11.1.0.src.tar.xz) and extract
    it to `$HOME/llvm/src/llvm-project-11/`:

    ``` sh
    # Assume that LLVM 11.1 source code is stored at $HOME/llvm/src/llvm-project/
    mkdir -p $HOME/llvm/llvm-11
    cd $HOME/llvm/src/llvm-project/
    mkdir -p build; cd build
    cmake ../llvm -DLLVM_ENABLE_PROJECTS=clang -DCMAKE_BUILD_TYPE=Release \
          -DCMAKE_INSTALL_PREFIX=$HOME/llvm/llvm-11 -Wno-dev -G Ninja
    ninja
    ninja install
    export PATH=$HOME/llvm/llvm-11/bin:$PATH
    export LD_LIBRARY_PATH=$HOME/llvm/llvm-11/lib:$LD_LIBRARY_PATH
    ```

- Dependencies of the external library [`backward-cpp`](https://github.com/bombela/backward-cpp) for pretty printing
  back-trace during the development.

  + Quick installation:

    ```sh
    sudo apt install binutils-dev libdw-dev libdwarf-dev

    ```

  + Full tutorial: please refer to the homepage of [`backward-cpp`](https://github.com/bombela/backward-cpp) for
    detailed explanation on the installation of its dependencies.

## Compilation

- Modify the file `CMakeLists.txt` to update `LLVM_CMAKE_PATH_HINTS` to the
  CMake folder corresponding the installed LLVM, (version 11.1 is preferred).
  For examples:

  ``` cmake
  set(LLVM_CMAKE_PATH_HINTS
  "$HOME/llvm/llvm-11/lib/cmake/llvm"              # manually installed
  "/usr/lib/llvm-11/lib/cmake/llvm/"               # Ubuntu installed
  ...)
  ```

- Make sure the binary `clang` version 11.1 appears in your system's $PATH.

- Compile `llvm-normalizer`

  ``` bash
  mkdir build
  cd build
  cmake ../
  make
  ```

- After compilation, copy the output file `llvm-normalizer` to the same folder
  with the main tool `discover`.

# Running llvm-normalizer

- (TODO: write detailed tutorial).

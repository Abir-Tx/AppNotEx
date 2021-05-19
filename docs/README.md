[![CMake-Linux](https://github.com/Abir-Tx/AppNotEx/actions/workflows/cmake-ci-linux.yml/badge.svg)](https://github.com/Abir-Tx/AppNotEx/actions/workflows/cmake-ci-linux.yml) [![Run Tests](https://github.com/Abir-Tx/AppNotEx/actions/workflows/runTest.yml/badge.svg)](https://github.com/Abir-Tx/AppNotEx/actions/workflows/runTest.yml)

# AppNotEx

Linux personal apps/packages quick terminal based note keeper which can be exported later.

## Install

### Arch Linux

```bash
yay -S appnotex
```


## Build Process

Issue these commands step by step to build the **AppNotEx** binary. 

```bash
git clone https://github.com/Abir-Tx/AppNotEx.git && cd AppNotEx
git submodule init && git submodule update
make builddir && make
```

You will find the binary in the **bin** folder after the compilation

## Usage

Running **appnotex** without any extra option will run the save info phase by default. You can issue one of these available commands as arguments to run diffrent parts of the app. Available commands are - 

```
-h --help               Prints the help menu
-p --print              Prints all the saved apps info  in a nice format
-e --export             Exports the saved apps info to a text file in current directory
-v --version            Prints the apps current version and developement informations

```

### Examples

```bash
./appnotex --print
```


# Xml-Security-C++ with CMake support

This is a forked repository of santuario-cpp/xml-security-c++ with CMake build system support.
The original source is under `trunk` branch. The CMake build system inspired from Xerces-C++.

## Build

**Initialize cmake build**
```bash
$ cmake -S . -B build
```

**Initialize cmake build for Debug build**
```bash
$ cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

**Initialize cmake build for shared library**
```bash
$ cmake -S . -B build -DBUILD_SHARED_LIBS=ON
```

**Build the library**
```bash
$ cmake --build build
```

**Build the library with Xalan**
```bash
$ cmake -S . -B build -DUSE_XALAN=ON
$ cmake --build build
```

**Build the samples**
```bash
$ cmake --build build --target samples
```

**Build the tools**
```bash
$ cmake --build build --target tools
```

**Install the library files(headers, .a/.so, cmake configs)**
```bash
$ cmake --install build
```

## What is not ported?
- Experimental crypto libraries support, NSS and WinCAPI
- XKMS support

# xml-security-c++

## Build
```bash
$ cmake -S . -B build
$ cmake --build build
```

### With Xalan
```bash
$ cmake -S . -B build -DUSE_XALAN=ON
$ cmake --build build
```

## What is not ported?
- Support for NSS as crypto library.
    - CMake support(find_package) is not readily available
    - NSS support is experimental in Xml-Security-C++

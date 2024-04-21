# Xml-Security-C++ with CMake support

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
- Experimental crypto libraries support, NSS and WinCAPI
- XKMS support

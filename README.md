# Learning CMake

Small, runnable C++ examples for learning CMake one step at a time. The examples are organized by chapter and can be configured independently.

> These are personal learning examples inspired by topics in *Professional CMake*. They are not affiliated with the book's author or publisher, and do not reproduce the book's text.

## Chapters

| Directory | Topics |
| --- | --- |
| [`chapter-01/`](./chapter-01/) | Your first CMake project |
| [`chapter-02/`](./chapter-02/) | Separate source and header files; build and link a library |
| [`chapter-03/`](./chapter-03/) | Debug and release build behavior |
| [`chapter-04/01-executable-types/`](./chapter-04/01-executable-types/) | Executable target options |
| [`chapter-04/02-library-types/`](./chapter-04/02-library-types/) | Static, shared, module, and configurable libraries |
| [`chapter-04/03-library-usage-requirements/`](./chapter-04/03-library-usage-requirements/) | Libraries, target dependencies, and usage requirements |
| [`chapter-04/04-linking-inputs/`](./chapter-04/04-linking-inputs/) | Draft: linking system and external libraries |

Each chapter directory with a `CMakeLists.txt` is a standalone project. The 4.4 draft expects a local library at `/opt/custom_libs/libSecret.so` and is not yet a self-contained build.

## Requirements

- CMake 3.15 or newer
- A C++ compiler supported by CMake

## Build an example

From the repository root, configure and build any completed example in a separate build directory:

```sh
cmake -S chapter-01 -B build/chapter-01
cmake --build build/chapter-01
./build/chapter-01/hello-cmake
```

For another chapter, replace `chapter-01` with its directory. For example:

```sh
cmake -S chapter-02 -B build/chapter-02
cmake --build build/chapter-02
./build/chapter-02/greeting-app
```

Build directories are ignored by Git. Keep generated files out of the chapter source directories.

## Learning path

Start with chapters 1–3, then explore the individual examples in chapter 4. Each example focuses on a small set of CMake concepts so you can inspect the configuration, change it, and rebuild.

## Contributing

Corrections, clearer examples, and additional small exercises are welcome. Keep examples independently buildable where possible, and document any required tools or external libraries.

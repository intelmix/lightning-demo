# lightning-demo
A jumpstart project for GNU lightning + Required files + Makefile

This project can be used as a starting point for working on GNU lightning based JIT compilers.

Everything is inside `work` directory and is organized as follows:

- Makefile: running `make` command will compile all source files and link them with GNU Lightning object files, producing executable output.
- `src` directory: Contains all `.c` files.
- `inc` directory: For include `.h` files.
- `obj` directory: Stores intermediate compilation output files
- `app` directory: Contains final executable file.
- `lib` directory: Contains GNU Lightning object files which need to be linked with your object files.

##Build##

The project comes with an initial source file `incr.c` which will implement a JIT-compiled method for adding two numbers.

You can create output using this command:

```
make
```

And to run it:

```
./app/work
```

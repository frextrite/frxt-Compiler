# frxt-Compiler

## Introduction
compiler for frxt language - nothing more than a tool to learn Compiler Design

The main goal is to create a full-fledged compiler which will compile `sample.frxt`
to underlying C language.

Note: If this seems interesting I may even compile it down to x86 assembly, but I don't
have any motive to do that as of now.

## frxt Language Details
### Keywords
* int
* float
* func

### Primitives
* int
* float

### Function details
* func must be used to tell the compiler we are working with a function
* main() is the entrypoint
* Currently, frxt supports 2 types of function declarations as shown in `sample.frxt` - C like, and assignment.
* Function return type is omitted (direct contradiction with `statically typed language`), however, if frxt is compiled down to C, I don't know how we can obtain the return value. (Same case if it is compiled down to x86)

### Comments
Supports C like comments
* multiline - `/* */`
* single line - `//`

### Other details
* Statically typed language
* Every statement must be terminated with a semi-colon `;`
* Strict type-checking
* Am I re-inventing some other language? Probably.

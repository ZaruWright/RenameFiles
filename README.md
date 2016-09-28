Rename files
===========

Simple c++ program to rename all files from a directory.

Usage
=====
You doesn't need to compile anything, the binaries there are into the *Exes* folder.

Windows
-------
```batch
cd RenameFiles
cd Exes
wRenameFiles
```

OS X
----
```bash
cd RenameFiles
cd Exes
./mRenameFiles
```

Linux
----
```bash
cd RenameFiles
cd Exes
./lRenameFiles
```

Compilation
===========
If you want to compile it, the only prerequisite that you need is CMake. When you have installed it, follow the next steps:

Windows
-------
```batch
wclean /*This is to remove the _build folder*/
wbuild /*Create Visual Studio 12 proyect*/
```

OS X
----
```bash
mclean /*This is to remove the _build folder*/
mbuild /*Create XCode proyect*/
```

Linux
----
```bash
lclean /*This is to remove the _build folder*/
lbuild /*Create a Makefile*/
```
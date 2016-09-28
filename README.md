Rename files
===========

Simple c++ program to rename all files from a directory.

Windows
-------
```batch
cd RenameFiles
wclean
wbuild

```

OS X
----
```bash
cd RenameFiles
sh mclean
sh mbuild

```

**TIP: If you have a hierarchy like this:
	doc copia.txt
	doc1.txt
And you want to rename them with the 'doc' name, the result will be this:
	doc copia.txt -> doc1.txt
	doc1.txt      -> doc2.txt
Explain it a little:
	the first doc will be rename with 'doc1.txt', but there is a file with the same name, because that the program overwrite the doc1.txt old file with the new file. and later this file rename with the doc2.txt name.


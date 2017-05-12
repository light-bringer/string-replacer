# string-replacer

Reads two files, compares the strings in them and removes the strings present in the target file which are already present in the reference file.

** Build the binary
`
g++ --std=c++11 replacer.cpp -o stringreplacer
`

** Run the Binary
`
./stringreplacer -r <reffilename> -t <targetfilename>
`

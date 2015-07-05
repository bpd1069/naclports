Native Client provides a cross-platform POSIX like environment. A range of projects from  zlib to python to SDL have been ported to run under NaCl. This project captures any NaCl specific build process and patches required to compile these project in one place, allowing them to be gradually up-streamed.

A list of all currently available is published [here](PortList.md).

**Important:** In order to build anything in naclports, you must have `NACL_SDK_ROOT` defined in your shell environment. Please see the README.txt file for more details.

**Note to Windows developers:** You must use [Cygwin](http://www.cygwin.com/) to build anything in naclports. From a Cygwin shell, use `gmake` to build the Native Client executables.

To try some of these ports in Chrome you can browse directly the products of the
[continuous builder](http://gsdview.appspot.com/naclports/builds/).  You will
need to have either NaCl or PNaCl enabled to run the these examples.  For example, try
a build of [Lua 5.2 for PNaCl](http://storage.googleapis.com/naclports/builds/pepper_37/1341/publish/lua/pnacl/index.html).


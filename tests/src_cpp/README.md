# ![he2](https://user-images.githubusercontent.com/34447743/121752164-da28ff80-cb0f-11eb-9172-3b678d40b3a5.png)Hoopoe-Engine
##### <h3>Content</h3>
 - [Introduction](#introduction)<br/>
 - [Building](#building)
      - [On GNU/Linux](#building-linux)
           - [Requirements](#building-linux-requirements)
           - [Compiling](#building-linux-compiling)
           - [Builder flags](#building-linux-builder-flags)
           - [Cmake flags](#building-cmake-flags)
      - [On Windows](#building-windows)

<a name="introduction"><h1>Introduction</h1></a>
Hoopoe engine is designed to create a simple simulated world.

<a name="building"><h1>Building</h1></a>
<a name="building-linux"><h3>On GNU/Linux</h3></a>
<a name="building-linux-requirements"><h4>Requirements</h4></a>

```no-highlight
sudo apt-get install build-essential cmake unzip zip
```
<a name="building-linux-compiling"><h4>Compiling</h4></a>

```no-highlight
bash builder.sh
```
<a name="building-linux-builder-flags"><h4>Builder flags</h4></a>
<code>--engine</code> or <code>-e</code> - build engine only.<br/>
<code>--sandbox</code> or <code>-s</code> - build sandbox only.<br/>
<code>--update-tests</code> or <code>-u</code> - update UTest resources.<br/>
<code>--pack-resources</code> or <code>-p</code> - pack the resources in the zip archives.<br/>
<code>--default</code> or <code>-d</code> - build with default settings.<br/>

<a name="building-cmake-flags"><h4>CMake flags</h4></a>
<code>-DUTEST=1</code> - build with the unit-tests<br/>
<code>-DSANDBOX_ONLY=1</code> - compiling only Sandbox (only for /Sandbox/CMakeLists.txt)<br/>

<a name="building-windows"><h3>On Windows</h3></a>
At the moment windows is not supported.


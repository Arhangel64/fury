Library and light widgets for KDE plasma 5
===

## Widgets

### GeeckClock 0.1.1

Lightweight widget showing current time in dec-binary format. Presentation use QSG-api, it doesn't load CPU at all!

### to build (temporary!):

```sh
$ cd library/
$ qmake -o build/Makefile
$ cd build
# make install

cd ../../plasmoids/geeckClock
plasmapkg2 --install package
```
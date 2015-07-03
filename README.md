Library and light widgets for KDE plasma 5
===

## Widgets

### GeeckClock 0.1.0

Lightweight widget showing current time in dec-binary format. Presentation use QSG-api, it doesn't load CPU at all!
There is some bugs.
1 - Sometimes it crashes kwin
2 - if you drag it from one monitor to another or if you attach it to the panel and drag back to the workspace - time will drop to 00:00:00
There should be some improovements
1 - optimise watchmodel - need to use pragma pack to avoid dublicating data
2 - need to optimise and devide application. Now there's two different instances with two different timers to track the time (for some reason plasmaCore.Datasouce time work not synchronusly, i decided not to use it, or sychronise widgets time with it less often)
3 - sometimes it falls into a lag, time refreshes once in 1000 ms by QObject::startTimer(), and it gets new system time. Probably it's lack of accuracy

### to build (temporary!):

```sh
cd library/
qmake
cd build
sudo cp qmldir /lib64/qt5/qml/ru/radiow/fury
sudo cp libDecBinaryWatch.so /lib64/qt5/qml/ru/radiow/fury

cd ../../plasmoids/geeckClock
plasmapkg2 --install package
```
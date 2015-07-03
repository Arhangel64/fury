import QtQuick 2.4
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.core 2.0 as PlasmaCore
import ru.radiow.fury 0.1
 
Item {
    Plasmoid.compactRepresentation: DecBinaryWatch {
        anchors.fill: parent
        id: clock
        time: new Date()
        onColor: theme.viewTextColor
        offColor: theme.viewBackgroundColor
    }
    Plasmoid.fullRepresentation: DecBinaryWatch {
        anchors.fill: parent
        id: clock
        time: new Date()
        onColor: theme.viewTextColor
        offColor: theme.viewBackgroundColor
    }
}
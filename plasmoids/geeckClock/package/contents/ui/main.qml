import QtQuick 2.4
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.core 2.0 as PlasmaCore
import ru.radiow.fury 0.1
 
Item {
    id: root
    property date time: ds.data.Local.DateTime
    PlasmaCore.DataSource {
        id: ds
        engine: "time"
        connectedSources: ["Local"]
        interval: 500
    }
    
    Component {
        id: watch
        DecBinaryWatch {
            id: view
            anchors.fill: parent
            time: root.time
            onColor: theme.viewTextColor
            offColor: theme.viewBackgroundColor
        }
    }
    
    Plasmoid.compactRepresentation: watch
    Plasmoid.fullRepresentation: watch
}
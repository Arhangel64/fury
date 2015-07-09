import QtQuick 2.4
import QtQuick.Layouts 1.1
import org.kde.plasma.plasmoid 2.0
import org.kde.plasma.core 2.0 as PlasmaCore
import org.kde.plasma.calendar 2.0 as PlasmaCalendar
import ru.radiow.fury 0.1
 
Item {
    id: root
    property date time: ds.data.Local.DateTime
    PlasmaCore.DataSource {
        id: ds
        engine: "time"
        connectedSources: ["Local"]
        interval: 1000
    }
    
    Component {
        id: watch
        DecBinaryWatch {
            id: view
            anchors.fill: parent
            time: root.time
            onColor: theme.viewTextColor
            offColor: theme.viewBackgroundColor
            opacity: 0.9
            
            MouseArea {
            anchors.fill: parent
            onClicked: plasmoid.expanded = !plasmoid.expanded
        }
        }
    }
    
    Plasmoid.backgroundHints: "NoBackground";
    Plasmoid.preferredRepresentation: Plasmoid.compactRepresentation
    Plasmoid.toolTipMainText: Qt.formatDate(root.time,"dddd")
    Plasmoid.toolTipSubText: Qt.formatDate(root.time, Qt.locale().dateFormat(Locale.LongFormat).replace(/(^dddd.?\s)|(,?\sdddd$)/, ""))
    
    Plasmoid.compactRepresentation: watch
    
    Plasmoid.fullRepresentation: PlasmaCalendar.MonthView {
        Layout.minimumWidth: units.gridUnit * 20
        Layout.minimumHeight: units.gridUnit * 20

        today: root.time
    }
}
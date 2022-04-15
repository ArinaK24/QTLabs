QT += qml quick widgets
DEFINES += QT_QML_DEBUG_NO_WARNING

CONFIG += c++11

SOURCES += \
    main.cpp \
    apartment.cpp \
    apartmentlist.cpp

HEADERS += \
    apartment.h \
    apartmentlist.h

FORMS +=

RESOURCES += qml.qrc \
    qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    DelegateForApartment.qml \
    DialogForAdd.qml \
    DialogForAnswer.qml \
    DialogForEdit.qml \
    main.qml

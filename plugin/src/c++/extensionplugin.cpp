#include "extensionplugin.h"

#include <QtQml>
#include "qmlcxxcomponent.h"
#include "qmlcxxcomponent2.h"

void ExtensionPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<QmlCxxComponent>(uri, 1, 0, "QmlCxxComponent");
    qmlRegisterType<QmlCxxComponent2>(uri, 1, 0, "QmlCxxComponent2");
    qmlRegisterType(QUrl("qrc:/ButtonWithIcon.qml"), uri, 1, 0, "ButtonWithIcon");
    // qmlRegisterType(QUrl("qrc:/AnyRectangle/GreenRectangle.qml"), uri, 1, 0, "ColorRectangles");
}

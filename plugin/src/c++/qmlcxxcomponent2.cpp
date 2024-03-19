#include "qmlcxxcomponent2.h"


QmlCxxComponent2::QmlCxxComponent2(QObject *parent)
    : QObject{parent}
{

}

QString QmlCxxComponent2::name() const
{
    return m_name;
}

void QmlCxxComponent2::setname(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

#include "qmlcxxcomponent.h"

QmlCxxComponent::QmlCxxComponent(QObject *parent)
    : QObject{parent}
{}

QString QmlCxxComponent::name() const
{
    return m_name;
}

void QmlCxxComponent::setname(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

#pragma once

#include <QtCore/QString>
#include <QtCore/QObject>

class QmlCxxComponent2: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setname NOTIFY nameChanged FINAL)
public:
    explicit QmlCxxComponent2(QObject *parent = nullptr);


    QString name() const;
    void setname(const QString &newName);
signals:
    void nameChanged();
private:
    QString m_name;
};


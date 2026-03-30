#ifndef DATESHORTCUTKEY_H
#define DATESHORTCUTKEY_H

#include <QObject>
#include <QKeySequence>
#include <QClipboard>
#include <QShortcut>

class DateShortcutKey : public QObject
{
    Q_OBJECT
public:
    explicit DateShortcutKey(QObject *parent = nullptr);

private:
    QShortcut* m_GlobalShortcut = nullptr;
};

#endif // DATESHORTCUTKEY_H

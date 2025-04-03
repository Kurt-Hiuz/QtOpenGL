#ifndef I_DIALOGWINDOW_H
#define I_DIALOGWINDOW_H

#include <QDialog>
#include <QObject>

class I_DialogWindow : public QDialog
{
    Q_OBJECT
public:
    I_DialogWindow();

    virtual void createInterface() = 0;
};

#endif // I_DIALOGWINDOW_H

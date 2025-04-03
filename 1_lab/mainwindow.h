#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "appMenu/appmenu.h"

#include "dialogWindows/i_dialogwindow.h"
#include "dialogWindows/addNewFigureDialogWindow/addnewfiguredialogwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    void extracted();
    MainWindow(QWidget *parent = nullptr);
    
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    AppMenu *appMenu;
    I_DialogWindow* addNewPointDialogWindow;

private slots:
    void showAddNewFigureDialogWindow();
};
#endif // MAINWINDOW_H

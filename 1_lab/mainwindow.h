#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "appMenu/appmenu.h"

#include "dialogWindows/addNewFigureDialogWindow/addnewfiguredialogwindow.h"
#include "oglpainter/figure/figure.h"
#include "oglpainter/oglpainter.h"

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
    AddNewFigureDialogWindow* addNewFigureDialogWindow;
    OGLPainter* openGL_painter;

private slots:
    void showAddNewFigureDialogWindow();
    void paintNewFigure(Figure *newFigure);
    void changeScalePainter();
};
#endif // MAINWINDOW_H

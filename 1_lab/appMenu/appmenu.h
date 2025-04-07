#ifndef APPMENU_H
#define APPMENU_H

#include "oglpainter/figure/figure.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>

class AppMenu : public QWidget
{
    Q_OBJECT
public:
    AppMenu(QWidget *parent = nullptr);
    void createInterface();
    QPushButton* getClearPainterBtn() const { return clearPainterBtn; }
    QPushButton* getAddNewFigureBtn() const { return addNewFigureBtn; }
    QComboBox* getScalePainterComboBox() const {return scalePainter;}

private:
    QPushButton *addNewFigureBtn;
    QPushButton *editRedoBtn;
    QPushButton *editUndoBtn;
    QPushButton *clearPainterBtn;

    QComboBox *scalePainter;

    QVBoxLayout *verticalLayout;
};

#endif // APPMENU_H

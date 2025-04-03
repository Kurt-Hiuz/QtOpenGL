#ifndef ADDNEWFIGUREDIALOGWINDOW_H
#define ADDNEWFIGUREDIALOGWINDOW_H

#include "dialogWindows/i_dialogwindow.h"

#include <QColorDialog>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class AddNewFigureDialogWindow : public I_DialogWindow
{
public:
    AddNewFigureDialogWindow();

    void createInterface() override;

private:
    QColorDialog* backgroundColorInput;
    QColorDialog* borderColorInput;
    QPushButton* chooseBackgroundColorBtn;
    QPushButton* chooseBorderColorBtn;
    QPushButton* addPointBtn;
    QPushButton* deletePointBtn;
    QLabel* hint_X;
    QLabel* hint_Y;
    QLabel* hint_border;
    QSpinBox* pointSpinBox_X;
    QSpinBox* pointSpinBox_Y;
    QSpinBox* borderWidthSpinBox;
    QComboBox* currentPointsComboBox;
    QComboBox* oglModeComboBox;
    QVBoxLayout* mainVLayout = nullptr;

private slots:
    void showBackgroundColorInput();
    void showBorderColorInput();
    void changeColorBtnBackgroundColor();
    void changeColorBtnBorderColor();
    void addPointBtnIntoCurrentPointsComboBox();
};

#endif // ADDNEWFIGUREDIALOGWINDOW_H

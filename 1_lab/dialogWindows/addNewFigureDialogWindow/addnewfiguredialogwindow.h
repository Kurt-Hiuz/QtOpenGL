#ifndef ADDNEWFIGUREDIALOGWINDOW_H
#define ADDNEWFIGUREDIALOGWINDOW_H

#include "dialogWindows/i_dialogwindow.h"
#include "oglpainter/figure/figure.h"

#include <QObject>
#include <QColorDialog>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class AddNewFigureDialogWindow : public I_DialogWindow
{
    Q_OBJECT
public:
    AddNewFigureDialogWindow();
    ~AddNewFigureDialogWindow();

    void createInterface() override;
    QPushButton *getSaveFigureBtn() const { return saveFigureBtn; }

signals:
    void newFigureCreated(Figure *newFigure);

private:
    QColorDialog* backgroundColorInput;
    QColorDialog* borderColorInput;
    QPushButton* chooseBackgroundColorBtn;
    QPushButton* chooseBorderColorBtn;
    QPushButton* addPointBtn;
    QPushButton* deletePointBtn;
    QPushButton* saveFigureBtn;
    QPushButton* clearInputsBtn;
    QLabel* hint_X;
    QLabel* hint_Y;
    QLabel* hint_Z;
    QLabel* hint_W;
    QLabel* hint_border;
    QDoubleSpinBox* pointSpinBox_X;
    QDoubleSpinBox* pointSpinBox_Y;
    QDoubleSpinBox* pointSpinBox_Z;
    QDoubleSpinBox* pointSpinBox_W;
    QSpinBox* borderWidthSpinBox;
    QComboBox* dimensionComboBox;
    QComboBox* currentPointsComboBox;
    QComboBox* oglModeComboBox;
    QVBoxLayout* mainVLayout = nullptr;

    void setInterfaceDisabled(bool flag);

private slots:
    void showBackgroundColorInput();
    void showBorderColorInput();
    void changeColorBtnBackgroundColor();
    void changeColorBtnBorderColor();
    void addPointBtnIntoCurrentPointsComboBox();
    void deleteSelectedPoint();
    void activateInterface();
    void activateSaveBtn();
    void saveNewFigure();
    void clearInputs();
};

#endif // ADDNEWFIGUREDIALOGWINDOW_H

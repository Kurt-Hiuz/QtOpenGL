#include "addnewfiguredialogwindow.h"

#include <QHBoxLayout>

AddNewFigureDialogWindow::AddNewFigureDialogWindow() {

}

void AddNewFigureDialogWindow::createInterface()
{
    if(mainVLayout != nullptr){ return; }

    backgroundColorInput = new QColorDialog();
    connect(backgroundColorInput, &QColorDialog::colorSelected, this, &AddNewFigureDialogWindow::changeColorBtnBackgroundColor);

    borderColorInput = new QColorDialog();
    connect(borderColorInput, &QColorDialog::colorSelected, this, &AddNewFigureDialogWindow::changeColorBtnBorderColor);

    chooseBackgroundColorBtn = new QPushButton("Цвет заливки");
    chooseBorderColorBtn = new QPushButton("Цвет рамки");
    addPointBtn = new QPushButton("Добавить точку");
    deletePointBtn = new QPushButton("Удалить точку");

    hint_X = new QLabel("Коорд. х: ");
    hint_Y = new QLabel("Коорд. у: ");
    hint_border = new QLabel("Рамка, px");

    pointSpinBox_X = new QSpinBox();                                    //  TODO: сделать шаг в 0.01
    pointSpinBox_X->setMinimum(-3);
    pointSpinBox_X->setSuffix(" f");

    pointSpinBox_Y = new QSpinBox();                                    //  TODO: сделать шаг в 0.01
    pointSpinBox_Y->setMinimum(-3);
    pointSpinBox_Y->setSuffix(" f");

    borderWidthSpinBox = new QSpinBox();
    borderWidthSpinBox->setSuffix(" px");

    currentPointsComboBox = new QComboBox();
    currentPointsComboBox->setPlaceholderText("Точки фигуры");

    oglModeComboBox = new QComboBox();
    oglModeComboBox->setPlaceholderText("Формат рисования");

    QHBoxLayout* pointHLayout_X = new QHBoxLayout();
    pointHLayout_X->addWidget(hint_X);
    pointHLayout_X->addWidget(pointSpinBox_X);

    QHBoxLayout* pointHLayout_Y = new QHBoxLayout();
    pointHLayout_Y->addWidget(hint_Y);
    pointHLayout_Y->addWidget(pointSpinBox_Y);

    QVBoxLayout* pointsVLayout = new QVBoxLayout();
    pointsVLayout->addLayout(pointHLayout_X);
    pointsVLayout->addLayout(pointHLayout_Y);

    QHBoxLayout* managePointHLayout = new QHBoxLayout();
    managePointHLayout->addLayout(pointsVLayout);
    managePointHLayout->addWidget(addPointBtn);
    managePointHLayout->addWidget(currentPointsComboBox);
    managePointHLayout->addWidget(deletePointBtn);
    managePointHLayout->addWidget(oglModeComboBox);

    QHBoxLayout* colorHLayout = new QHBoxLayout();
    colorHLayout->addWidget(chooseBackgroundColorBtn);
    colorHLayout->addWidget(chooseBorderColorBtn);
    colorHLayout->addWidget(hint_border);
    colorHLayout->addWidget(borderWidthSpinBox);

    mainVLayout = new QVBoxLayout();
    mainVLayout->addLayout(managePointHLayout);
    mainVLayout->addLayout(colorHLayout);

    this->setLayout(mainVLayout);
    this->setWindowTitle("Добавление фигуры");

    connect(chooseBackgroundColorBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::showBackgroundColorInput);
    connect(chooseBorderColorBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::showBorderColorInput);
    connect(addPointBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::addPointBtnIntoCurrentPointsComboBox);
}

void AddNewFigureDialogWindow::showBackgroundColorInput()
{
    backgroundColorInput->open();
}

void AddNewFigureDialogWindow::showBorderColorInput()
{
    borderColorInput->open();
}

void AddNewFigureDialogWindow::changeColorBtnBackgroundColor()
{
    chooseBackgroundColorBtn->setStyleSheet("background-color: "+qobject_cast<QColorDialog* >(sender())->selectedColor().name());
}

void AddNewFigureDialogWindow::changeColorBtnBorderColor()
{
    chooseBorderColorBtn->setStyleSheet("background-color: "+qobject_cast<QColorDialog* >(sender())->selectedColor().name());
}

void AddNewFigureDialogWindow::addPointBtnIntoCurrentPointsComboBox()
{
    // TODO: сделать сохранение координат точек по массивам, чтобы потом можно было удобно выбирать
    // currentPointsComboBox->addItem(QString("x: "+pointSpinBox_X->cleanText()+", y: "+pointSpinBox_Y->cleanText()), GLfloat());
}

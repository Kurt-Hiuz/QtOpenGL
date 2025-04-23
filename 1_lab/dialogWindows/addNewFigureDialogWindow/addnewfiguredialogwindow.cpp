#include "addnewfiguredialogwindow.h"

#include <GL/gl.h>
#include <QHBoxLayout>

#include "oglpainter/point/point.h"

AddNewFigureDialogWindow::AddNewFigureDialogWindow() {

}

AddNewFigureDialogWindow::~AddNewFigureDialogWindow()
{
    qDebug() << "Вызван деструктор AddNewFigureDialogWindow";
    // TODO: сделать удаление интерфейса
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
    saveFigureBtn = new QPushButton("Сохранить фигуру");
    clearInputsBtn = new QPushButton("Очистить форму");

    hint_X = new QLabel("Коорд. х: ");
    hint_Y = new QLabel("Коорд. у: ");
    hint_Z = new QLabel("Коорд. z: ");
    hint_W = new QLabel("Коорд. w: ");
    hint_border = new QLabel("Рамка");
    hint_radius = new QLabel("Радиус");
    hint_height = new QLabel("Высота");

    pointSpinBox_X = new QDoubleSpinBox();
    pointSpinBox_X->setSingleStep(0.01);
    pointSpinBox_X->setRange(-30.0, 30.0);
    pointSpinBox_X->setSuffix(" f");

    pointSpinBox_Y = new QDoubleSpinBox();
    pointSpinBox_Y->setSingleStep(0.01);
    pointSpinBox_Y->setRange(-30.0, 30.0);
    pointSpinBox_Y->setSuffix(" f");

    pointSpinBox_Z = new QDoubleSpinBox();
    pointSpinBox_Z->setSingleStep(0.01);
    pointSpinBox_Z->setRange(-30.0, 30.0);
    pointSpinBox_Z->setSuffix(" f");
    pointSpinBox_Z->setDisabled(true);

    pointSpinBox_W = new QDoubleSpinBox();
    pointSpinBox_W->setSingleStep(0.01);
    pointSpinBox_W->setRange(-30.0, 30.0);
    pointSpinBox_W->setSuffix(" f");
    pointSpinBox_W->setDisabled(true);

    borderWidthSpinBox = new QSpinBox();
    borderWidthSpinBox->setSuffix(" px");

    radiusSpinBox = new QDoubleSpinBox();
    radiusSpinBox->setSuffix(" f");

    heightSpinBox = new QDoubleSpinBox();
    heightSpinBox->setSuffix(" f");

    dimensionComboBox = new QComboBox();
    dimensionComboBox->setPlaceholderText("Выбор размерности фигуры");
    dimensionComboBox->currentData(-1);
    dimensionComboBox->addItem("2D", 2);
    dimensionComboBox->addItem("3D", 3);
    dimensionComboBox->addItem("4D", 4);

    currentPointsComboBox = new QComboBox();
    currentPointsComboBox->setPlaceholderText("Точки фигуры");
    currentPointsComboBox->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    currentPointsComboBox->setMinimumWidth(200);

    oglModeComboBox = new QComboBox();
    oglModeComboBox->setPlaceholderText("Способ рисования");
    oglModeComboBox->currentData(-1);
    oglModeComboBox->addItem("Точки", GL_POINTS);
    oglModeComboBox->addItem("Линии", GL_LINES);
    oglModeComboBox->addItem("Незамкнутая ломаная", GL_LINE_STRIP);
    oglModeComboBox->addItem("Замкнутая ломаная", GL_LINE_LOOP);
    oglModeComboBox->addItem("Окружность", GL_LINE_LOOP);
    oglModeComboBox->addItem("Выпукл. многоуг.", GL_POLYGON);
    oglModeComboBox->addItem("Треугольники", GL_TRIANGLES);
    oglModeComboBox->addItem("Полоса труег.", GL_TRIANGLE_STRIP);
    oglModeComboBox->addItem("Веер треугол.", GL_TRIANGLE_FAN);
    oglModeComboBox->addItem("Четвёрка вершин", GL_QUADS);
    oglModeComboBox->addItem("Полоса четырёхуг.", GL_QUAD_STRIP);
    oglModeComboBox->insertSeparator(oglModeComboBox->count());
    oglModeComboBox->addItem("Куб", -GL_QUADS);

    setInterfaceDisabled(true);

    QHBoxLayout* pointHLayout_X = new QHBoxLayout();
    pointHLayout_X->addWidget(hint_X);
    pointHLayout_X->addWidget(pointSpinBox_X);

    QHBoxLayout* pointHLayout_Y = new QHBoxLayout();
    pointHLayout_Y->addWidget(hint_Y);
    pointHLayout_Y->addWidget(pointSpinBox_Y);

    QHBoxLayout* pointHLayout_Z = new QHBoxLayout();
    pointHLayout_Z->addWidget(hint_Z);
    pointHLayout_Z->addWidget(pointSpinBox_Z);

    QHBoxLayout* pointHLayout_W = new QHBoxLayout();
    pointHLayout_W->addWidget(hint_W);
    pointHLayout_W->addWidget(pointSpinBox_W);

    QVBoxLayout* pointsVLayout = new QVBoxLayout();
    pointsVLayout->addWidget(dimensionComboBox);
    pointsVLayout->addLayout(pointHLayout_X);
    pointsVLayout->addLayout(pointHLayout_Y);
    pointsVLayout->addLayout(pointHLayout_Z);
    pointsVLayout->addLayout(pointHLayout_W);

    QHBoxLayout* managePointHLayout = new QHBoxLayout();
    managePointHLayout->addLayout(pointsVLayout);
    managePointHLayout->addWidget(addPointBtn);
    managePointHLayout->addWidget(currentPointsComboBox);
    managePointHLayout->addWidget(deletePointBtn);
    managePointHLayout->addWidget(oglModeComboBox);

    QHBoxLayout* borderHLayout = new QHBoxLayout();
    borderHLayout->addWidget(hint_border);
    borderHLayout->addWidget(borderWidthSpinBox);

    QHBoxLayout* radiusHLayout = new QHBoxLayout();
    radiusHLayout->addWidget(hint_radius);
    radiusHLayout->addWidget(radiusSpinBox);

    QHBoxLayout* heightHLayout = new QHBoxLayout();
    heightHLayout->addWidget(hint_height);
    heightHLayout->addWidget(heightSpinBox);

    QVBoxLayout* otherFigureSettingsVLayout = new QVBoxLayout();
    otherFigureSettingsVLayout->addLayout(borderHLayout);
    otherFigureSettingsVLayout->addLayout(radiusHLayout);
    otherFigureSettingsVLayout->addLayout(heightHLayout);

    QHBoxLayout* colorHLayout = new QHBoxLayout();
    colorHLayout->addWidget(chooseBackgroundColorBtn);
    colorHLayout->addWidget(chooseBorderColorBtn);
    colorHLayout->addLayout(otherFigureSettingsVLayout);
    colorHLayout->addWidget(saveFigureBtn);
    colorHLayout->addWidget(clearInputsBtn);

    mainVLayout = new QVBoxLayout();
    mainVLayout->addLayout(managePointHLayout);
    mainVLayout->addLayout(colorHLayout);

    this->setLayout(mainVLayout);
    this->setWindowTitle("Добавление фигуры");

    connect(dimensionComboBox, &QComboBox::currentIndexChanged, this, &AddNewFigureDialogWindow::activateInterface);
    connect(oglModeComboBox, &QComboBox::currentIndexChanged, this, &AddNewFigureDialogWindow::activateSaveBtnAndCheckFigure);

    connect(chooseBackgroundColorBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::showBackgroundColorInput);
    connect(chooseBorderColorBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::showBorderColorInput);
    connect(addPointBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::addPointBtnIntoCurrentPointsComboBox);
    connect(deletePointBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::deleteSelectedPoint);
    connect(saveFigureBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::saveNewFigure);
    connect(clearInputsBtn, &QPushButton::clicked, this, &AddNewFigureDialogWindow::clearInputs);
}

void AddNewFigureDialogWindow::setInterfaceDisabled(bool flag)
{
    chooseBackgroundColorBtn->setDisabled(flag);
    chooseBorderColorBtn->setDisabled(flag);
    addPointBtn->setDisabled(flag);
    deletePointBtn->setDisabled(flag);
    saveFigureBtn->setDisabled(flag);
    pointSpinBox_X->setDisabled(flag);
    pointSpinBox_Y->setDisabled(flag);
    pointSpinBox_Z->setDisabled(flag);
    pointSpinBox_W->setDisabled(flag);
    borderWidthSpinBox->setDisabled(flag);
    radiusSpinBox->setDisabled(flag);
    heightSpinBox->setDisabled(flag);
    currentPointsComboBox->setDisabled(flag);
    oglModeComboBox->setDisabled(flag);
    clearInputsBtn->setDisabled(flag);
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
    if(dimensionComboBox->currentData() == 2){
        currentPointsComboBox->addItem(QString("x: "+pointSpinBox_X->cleanText()+", y: "+pointSpinBox_Y->cleanText()), QVariant::fromValue(QList<QVariant>({pointSpinBox_X->value(), pointSpinBox_Y->value()})));
        qDebug() << "Добавлена новая точка в список" << currentPointsComboBox->itemData(0);
    }
    if(dimensionComboBox->currentData() == 3){
        currentPointsComboBox->addItem(QString("x: "+pointSpinBox_X->cleanText()+", y: "+pointSpinBox_Y->cleanText()+", z: "+pointSpinBox_Z->cleanText()), QVariant::fromValue(QList<QVariant>({pointSpinBox_X->value(), pointSpinBox_Y->value(), pointSpinBox_Z->value()})));
        qDebug() << currentPointsComboBox->itemData(0);
    }
    // if(dimensionComboBox->currentData() == 4){
    //     currentPointsComboBox->addItem(QString("x: "+pointSpinBox_X->cleanText()+", y: "+pointSpinBox_Y->cleanText()+", z: "+pointSpinBox_W->cleanText()+", w: "+pointSpinBox_W->cleanText()), Point(pointSpinBox_X->value(), pointSpinBox_Y->value(), pointSpinBox_Z->value(), pointSpinBox_W->value()));
    // }
    pointSpinBox_X->setValue(0);
    pointSpinBox_Y->setValue(0);
    pointSpinBox_Z->setValue(0);
    pointSpinBox_W->setValue(0);
}

void AddNewFigureDialogWindow::deleteSelectedPoint()
{
    currentPointsComboBox->removeItem(currentPointsComboBox->currentIndex());
}

void AddNewFigureDialogWindow::activateInterface()
{
    setInterfaceDisabled(false);
    saveFigureBtn->setDisabled(true);               //  пока не выберется формат рисования, кнопка должна быть отключена
    radiusSpinBox->setDisabled(true);               //  пока не выберется формат рисования Окружность, кнопка должна быть отключена
    heightSpinBox->setDisabled(true);               //  пока не выберется формат рисования готовых фигур
    currentPointsComboBox->clear();
    if(dimensionComboBox->currentData() == 2){
        pointSpinBox_Z->setDisabled(true);
        pointSpinBox_W->setDisabled(true);
        return;
    }
    if(dimensionComboBox->currentData() == 3){
        pointSpinBox_Z->setDisabled(false);
        pointSpinBox_W->setDisabled(true);
        return;
    }
    if(dimensionComboBox->currentData() == 4){
        pointSpinBox_Z->setDisabled(false);
        pointSpinBox_W->setDisabled(false);
        return;
    }
}

void AddNewFigureDialogWindow::activateSaveBtnAndCheckFigure()
{
    saveFigureBtn->setDisabled(false);
    radiusSpinBox->setDisabled(oglModeComboBox->currentText() != "Окружность");

    heightSpinBox->setDisabled(oglModeComboBox->currentText() != "Куб");
}

void AddNewFigureDialogWindow::saveNewFigure()
{
    Figure *newFigure = new Figure();

    newFigure->setPaintMode(oglModeComboBox->currentData().value<GLenum>());
    newFigure->setBorderWidth(borderWidthSpinBox->value());
    newFigure->setBorderColor(new QColor(chooseBorderColorBtn->palette().button().color()));
    newFigure->setDimensional(dimensionComboBox->currentData().toInt());
    newFigure->setBackgroundColor(new QColor(chooseBackgroundColorBtn->palette().button().color()));

    QList<QVariant> ComboBoxListOfPoints{};
    if(oglModeComboBox->currentText() == "Окружность"){
        newFigure->setIsCicle(true);
        ComboBoxListOfPoints = currentPointsComboBox->itemData(0).toList();
        newFigure->addNewPoint(new Point(ComboBoxListOfPoints.value(0).toFloat(), ComboBoxListOfPoints.value(1).toFloat()));
        newFigure->setRadius(radiusSpinBox->value());
        qDebug() << "Центр в точке: " << ComboBoxListOfPoints.value(0).toFloat() << ", " << ComboBoxListOfPoints.value(1).toFloat();
        emit newFigureCreated(newFigure);
        return;
    }

    if(oglModeComboBox->currentText() == "Куб"){
        newFigure->setIsCube(true);
        ComboBoxListOfPoints = currentPointsComboBox->itemData(0).toList();
        newFigure->addNewPoint(new Point(ComboBoxListOfPoints.value(0).toFloat(), ComboBoxListOfPoints.value(1).toFloat(), ComboBoxListOfPoints.value(2).toFloat()));
        newFigure->setHeight(heightSpinBox->value());
        qDebug() << "Начало куба в: " << ComboBoxListOfPoints.value(0).toFloat() << ", " << ComboBoxListOfPoints.value(1).toFloat()<< ", " << ComboBoxListOfPoints.value(2).toFloat();
        emit newFigureCreated(newFigure);
        return;
    }

    for(int index = 0; index < currentPointsComboBox->count(); index++){
        Point *newPoint = new Point();
        ComboBoxListOfPoints = currentPointsComboBox->itemData(index).toList();
        qDebug() << "Количество координат: " << ComboBoxListOfPoints.length();
        if(ComboBoxListOfPoints.length() == 2){
            newPoint->set_x(ComboBoxListOfPoints.value(0).toFloat());
            qDebug() << "X: " << ComboBoxListOfPoints.value(0).toFloat();
            newPoint->set_y(ComboBoxListOfPoints.value(1).toFloat());
        }
        if(ComboBoxListOfPoints.length() == 3){
            newPoint->set_x(ComboBoxListOfPoints.value(0).toFloat());
            newPoint->set_y(ComboBoxListOfPoints.value(1).toFloat());
            newPoint->set_z(ComboBoxListOfPoints.value(2).toFloat());
        }
        if(ComboBoxListOfPoints.length() == 4){
            newPoint->set_x(ComboBoxListOfPoints.value(0).toFloat());
            newPoint->set_y(ComboBoxListOfPoints.value(1).toFloat());
            newPoint->set_z(ComboBoxListOfPoints.value(2).toFloat());
            newPoint->set_w(ComboBoxListOfPoints.value(3).toFloat());
        }

        newFigure->addNewPoint(newPoint);
        // delete newPoint;
    }


    // TODO сделать сохранение цвета

    emit newFigureCreated(newFigure);
    // delete newFigure;
}

void AddNewFigureDialogWindow::clearInputs()
{
    pointSpinBox_X->setValue(0);
    pointSpinBox_Y->setValue(0);
    pointSpinBox_Z->setValue(0);
    pointSpinBox_W->setValue(0);
    borderWidthSpinBox->setValue(0);
    dimensionComboBox->setPlaceholderText("Выбор размерности фигуры");
    currentPointsComboBox->clear();
    oglModeComboBox->setPlaceholderText("Формат рисования");
    chooseBackgroundColorBtn->setStyleSheet("background-color: ");
    chooseBorderColorBtn->setStyleSheet("background-color: ");
}

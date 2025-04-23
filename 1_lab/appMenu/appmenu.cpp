#include "appmenu.h"

#include <QHBoxLayout>

AppMenu::AppMenu(QWidget *parent){

}

void AppMenu::createInterface()
{
    xAnimCheckbox = new QCheckBox("Вращение X");
    yAnimCheckbox = new QCheckBox("Вращение Y");
    zAnimCheckbox = new QCheckBox("Вращение Z");

    addNewFigureBtn = new QPushButton("Добавить фигуру");
    editRedoBtn = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::EditRedo), "Назад");
    editUndoBtn = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo), "Вперёд");
    clearPainterBtn = new QPushButton("Очистить");

    scalePainter = new QComboBox();
    scalePainter->setPlaceholderText("Масштаб полотна");
    scalePainter->addItem("1 x", 1);
    scalePainter->addItem("0.5 x", 2);
    scalePainter->addItem("0.2 x", 5);
    scalePainter->addItem("0.1 x", 10);
    scalePainter->addItem("0.05 x", 20);

    angleYSceneSlider = new QSlider(Qt::Horizontal, this);
    angleYSceneSlider->setMinimum(0);
    angleYSceneSlider->setMaximum(360);
    angleYSceneSlider->setSingleStep(15);
    angleYLabel = new QLabel("Поворот вдоль Y");
    QHBoxLayout *angelYHLayout = new QHBoxLayout();
    angelYHLayout->addWidget(angleYLabel);
    angelYHLayout->addWidget(angleYSceneSlider);

    angleXSceneSlider = new QSlider(Qt::Horizontal, this);
    angleXSceneSlider->setMinimum(0);
    angleXSceneSlider->setMaximum(360);
    angleXSceneSlider->setSingleStep(15);
    angleXLabel = new QLabel("Поворот вдоль X");
    QHBoxLayout *angelXHLayout = new QHBoxLayout();
    angelXHLayout->addWidget(angleXLabel);
    angelXHLayout->addWidget(angleXSceneSlider);

    angleZSceneSlider = new QSlider(Qt::Horizontal, this);
    angleZSceneSlider->setMinimum(0);
    angleZSceneSlider->setMaximum(360);
    angleZSceneSlider->setSingleStep(15);
    angleZLabel = new QLabel("Поворот вдоль Z");
    QHBoxLayout *angelZHLayout = new QHBoxLayout();
    angelZHLayout->addWidget(angleZLabel);
    angelZHLayout->addWidget(angleZSceneSlider);

    verticalLayout = new QVBoxLayout();
    this->setLayout(verticalLayout);

    verticalLayout->addWidget(xAnimCheckbox);
    verticalLayout->addWidget(yAnimCheckbox);
    verticalLayout->addWidget(zAnimCheckbox);
    verticalLayout->addWidget(addNewFigureBtn);
    // verticalLayout->addWidget(editRedoBtn);
    // verticalLayout->addWidget(editUndoBtn);
    verticalLayout->addSpacing(30);
    verticalLayout->addWidget(clearPainterBtn);
    verticalLayout->addWidget(scalePainter);
    verticalLayout->addLayout(angelXHLayout);
    verticalLayout->addLayout(angelYHLayout);
    verticalLayout->addLayout(angelZHLayout);

    connect(xAnimCheckbox, &QCheckBox::checkStateChanged, this, &AppMenu::startXAnim);
    connect(yAnimCheckbox, &QCheckBox::checkStateChanged, this, &AppMenu::startYAnim);
    connect(zAnimCheckbox, &QCheckBox::checkStateChanged, this, &AppMenu::startZAnim);

    animationAngleXSceneSlider = new QPropertyAnimation(angleXSceneSlider, "value");
    animationAngleXSceneSlider->setDuration(3000); // Длительность анимации (3 секунды)
    animationAngleXSceneSlider->setStartValue(0);
    animationAngleXSceneSlider->setEndValue(360);
    animationAngleXSceneSlider->setLoopCount(-1);

    animationAngleYSceneSlider = new QPropertyAnimation(angleYSceneSlider, "value");
    animationAngleYSceneSlider->setDuration(3000); // Длительность анимации (3 секунды)
    animationAngleYSceneSlider->setStartValue(0);
    animationAngleYSceneSlider->setEndValue(360);
    animationAngleYSceneSlider->setLoopCount(-1);

    animationAngleZSceneSlider = new QPropertyAnimation(angleZSceneSlider, "value");
    animationAngleZSceneSlider->setDuration(3000); // Длительность анимации (3 секунды)
    animationAngleZSceneSlider->setStartValue(0);
    animationAngleZSceneSlider->setEndValue(360);
    animationAngleZSceneSlider->setLoopCount(-1);
}

void AppMenu::startXAnim(Qt::CheckState state)
{
    if(state == Qt::Checked){
        animationAngleXSceneSlider->start();
    } else {
        animationAngleXSceneSlider->stop();  // Остановка при выключении
    }
}

void AppMenu::startYAnim(Qt::CheckState state)
{
    if(state == Qt::Checked){
        animationAngleYSceneSlider->start();
    } else {
        animationAngleYSceneSlider->stop();  // Остановка при выключении
    }
}

void AppMenu::startZAnim(Qt::CheckState state)
{
    if(state == Qt::Checked){
        animationAngleZSceneSlider->start();
    } else {
        animationAngleZSceneSlider->stop();  // Остановка при выключении
    }
}

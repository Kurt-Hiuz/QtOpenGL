#include "appmenu.h"

AppMenu::AppMenu(QWidget *parent){

}

void AppMenu::createInterface()
{
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

    verticalLayout = new QVBoxLayout();
    this->setLayout(verticalLayout);

    verticalLayout->addWidget(addNewFigureBtn);
    verticalLayout->addWidget(editRedoBtn);
    verticalLayout->addWidget(editUndoBtn);
    verticalLayout->addSpacing(30);
    verticalLayout->addWidget(clearPainterBtn);
    verticalLayout->addWidget(scalePainter);
}

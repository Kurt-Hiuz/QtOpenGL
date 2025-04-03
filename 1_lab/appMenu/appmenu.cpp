#include "appmenu.h"

AppMenu::AppMenu(QWidget *parent){

}

void AppMenu::createInterface()
{
    addNewFigureBtn = new QPushButton("Добавить фигуру");
    editRedoBtn = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::EditRedo), "Назад");
    editUndoBtn = new QPushButton(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo), "Вперёд");
    clearPainterBtn = new QPushButton("Очистить");

    verticalLayout = new QVBoxLayout();
    this->setLayout(verticalLayout);

    verticalLayout->addWidget(addNewFigureBtn);
    verticalLayout->addWidget(editRedoBtn);
    verticalLayout->addWidget(editUndoBtn);
    verticalLayout->addSpacing(30);
    verticalLayout->addWidget(clearPainterBtn);
}

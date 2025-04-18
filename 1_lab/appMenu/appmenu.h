#ifndef APPMENU_H
#define APPMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QSlider>
#include <QLabel>

class AppMenu : public QWidget
{
    Q_OBJECT
public:
    AppMenu(QWidget *parent = nullptr);
    void createInterface();
    QPushButton* getClearPainterBtn() const { return clearPainterBtn; }
    QPushButton* getAddNewFigureBtn() const { return addNewFigureBtn; }
    QComboBox* getScalePainterComboBox() const {return scalePainter;}
    QSlider* getAngleXSceneSlider() const {return angleXSceneSlider;}
    QSlider* getAngleYSceneSlider() const {return angleYSceneSlider;}
    QSlider* getAngleZSceneSlider() const {return angleZSceneSlider;}

private:
    QPushButton *addNewFigureBtn;
    QPushButton *editRedoBtn;
    QPushButton *editUndoBtn;
    QPushButton *clearPainterBtn;

    QComboBox *scalePainter;

    QSlider *angleYSceneSlider;
    QLabel *angleYLabel;

    QSlider *angleXSceneSlider;
    QLabel *angleXLabel;

    QSlider *angleZSceneSlider;
    QLabel *angleZLabel;

    QVBoxLayout *verticalLayout;
};

#endif // APPMENU_H

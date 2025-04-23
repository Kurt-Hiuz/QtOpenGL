#ifndef APPMENU_H
#define APPMENU_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QSlider>
#include <QLabel>
#include <QPropertyAnimation>

class AppMenu : public QWidget
{
    Q_OBJECT
public:
    AppMenu(QWidget *parent = nullptr);
    void createInterface();
    QCheckBox* getXAnimCheckbox() const {return xAnimCheckbox;}
    QCheckBox* getYAnimCheckbox() const {return yAnimCheckbox;}
    QCheckBox* getZAnimCheckbox() const {return zAnimCheckbox;}
    QPushButton* getClearPainterBtn() const { return clearPainterBtn; }
    QPushButton* getAddNewFigureBtn() const { return addNewFigureBtn; }
    QComboBox* getScalePainterComboBox() const {return scalePainter;}
    QSlider* getAngleXSceneSlider() const {return angleXSceneSlider;}
    QSlider* getAngleYSceneSlider() const {return angleYSceneSlider;}
    QSlider* getAngleZSceneSlider() const {return angleZSceneSlider;}

private:
    QPropertyAnimation *animationAngleXSceneSlider;
    QPropertyAnimation *animationAngleYSceneSlider;
    QPropertyAnimation *animationAngleZSceneSlider;

    QCheckBox *xAnimCheckbox;
    QCheckBox *yAnimCheckbox;
    QCheckBox *zAnimCheckbox;

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

private slots:
    void startXAnim(Qt::CheckState state);
    void startYAnim(Qt::CheckState state);
    void startZAnim(Qt::CheckState state);
};

#endif // APPMENU_H

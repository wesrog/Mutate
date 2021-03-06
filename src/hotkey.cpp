#include "hotkey.h"
#include "ui_hotkey.h"

hotkey::hotkey(QWidget *parent) :
    s(s),
    QWidget(parent),
    ui(new Ui::hotkey)
{
    ui->setupUi(this);
}

hotkey::~hotkey()
{
    delete ui;
}

void hotkey::keyPressEvent(QKeyEvent *event)
{
    int uKey = event->key();
    Qt::Key key = static_cast<Qt::Key>(uKey);
    if(key == Qt::Key_unknown)
    {
       return;
    }
    if(key == Qt::Key_Control || key == Qt::Key_Shift || key == Qt::Key_Alt )
    {
        return ;
    }
    Qt::KeyboardModifiers modifiers = event->modifiers();
    if(modifiers & Qt::ShiftModifier)
        uKey += Qt::SHIFT;
    if(modifiers & Qt::ControlModifier)
        uKey += Qt::CTRL;
    if(modifiers & Qt::AltModifier)
        uKey += Qt::ALT;
    ui->label_2->setText(QKeySequence(uKey).toString());
    this->s->setText(QKeySequence(uKey).toString());
}

void hotkey::keyReleaseEvent(QKeyEvent *event)
{
    this->~hotkey();
}

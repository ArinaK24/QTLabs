#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "apartment.h"

class EditDialog : public QDialog
{
  Q_OBJECT

private:
    QLineEdit* editID;
    QLineEdit* editArea;
    QLineEdit* editSpace;
    QLineEdit* editRooms;
    QLineEdit* editFloor;
    QLineEdit* editMaterial;

public:
    EditDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString area() const;
    QString space() const;
    QString rooms() const;
    QString floor() const;
    QString material() const;

    void SetUpDialog(QString id, QString area, QString space, QString rooms, QString floor, QString material);
};

#endif


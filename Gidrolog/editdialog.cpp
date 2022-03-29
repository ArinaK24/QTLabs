#include "editdialog.h"
#include "apartment.h"
EditDialog::EditDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editArea = new QLineEdit();
    editSpace = new QLineEdit();
    editRooms = new QLineEdit();
    editFloor = new QLineEdit();
    editMaterial = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Район города"),2,1);
    mainLayout->addWidget(editArea,2,2);
    mainLayout->addWidget(new QLabel("Площадь, м^2"),3,1);
    mainLayout->addWidget(editSpace,3,2);
    mainLayout->addWidget(new QLabel("Количество комнат"),4,1);
    mainLayout->addWidget(editRooms,4,2);
    mainLayout->addWidget(new QLabel("Этаж"),5,1);
    mainLayout->addWidget(editFloor,5,2);
    mainLayout->addWidget(new QLabel("Материал стен"),6,1);
    mainLayout->addWidget(editMaterial,6,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о квартире");


    //Располагаем диалог над основным окном
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditDialog::id() const
{
    return editID->text();
}
QString EditDialog::area() const
{
    return editArea->text();
}
QString EditDialog::space() const
{
    return editSpace->text();
}
QString EditDialog::rooms() const
{
    return editRooms->text();
}
QString EditDialog::floor() const
{
    return editFloor->text();
}
QString EditDialog::material() const
{
    return editMaterial->text();
}

void EditDialog::SetUpDialog(QString id, QString area, QString space, QString rooms, QString floor, QString material)
{
    editID->setText(id);
    editArea->setText(area);
    editSpace->setText(space);
    editRooms->setText(rooms);
    editFloor->setText(floor);
    editMaterial->setText(material);
}

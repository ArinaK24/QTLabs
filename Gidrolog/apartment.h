#ifndef APARTMENT_H
#define APARTMENT_H
#include "QString"
#include <QObject>

class Apartment: public QObject
{
    Q_OBJECT

public:
    Apartment(QString ID, QString Area, QString Space, QString Rooms, QString Floor, QString Material, QObject *parent = nullptr );
    virtual ~Apartment();
    void SetID(QString ID);
    void SetArea(QString Area);
    void SetSpace(QString Space);
    void SetRooms(QString Rooms);
    void SetFloor(QString Floor);
    void SetMaterial(QString Material);

    QString ID();
    QString Area();
    QString Space();
    QString Rooms();
    QString Floor();
    QString Material();
private:
    QString id;
    QString area;
    QString space;
    QString rooms;
    QString floor;
    QString material;
};
#endif

#ifndef APARTMENT_H
#define APARTMENT_H
#include "QString"


class Apartment
{

public:
    Apartment();
    virtual ~Apartment();
    void SetID(const QString ID);
    void SetArea(const QString Area);
    void SetSpace(const QString Space);
    void SetRooms(const QString Rooms);
    void SetFloor(const QString Floor);
    void SetMaterial(const QString Material);

    QString getID() const;
    QString getArea() const;
    QString getSpace() const;
    QString getRooms() const;
    QString getFloor() const;
    QString getMaterial() const;
private:
    QString id;
    QString area;
    QString space;
    QString rooms;
    QString floor;
    QString material;
};
#endif

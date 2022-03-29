#include "apartment.h"

Apartment::Apartment(QString ID, QString Area, QString Space, QString Rooms, QString Floor, QString Material, QObject *parent): QObject(parent)
{
    id = ID;
    area = Area;
    space = Space;
    rooms = Rooms;
    floor = Floor;
    material = Material;
}

void Apartment::SetID(QString ID)
{
    id = ID;
}
void Apartment::SetArea(QString Area)
{
    area = Area;
}
void Apartment::SetSpace(QString Space)
{
    space = Space;
}
void Apartment::SetRooms(QString Rooms)
{
    rooms = Rooms;
}
void Apartment::SetFloor(QString Floor)
{
    floor = Floor;
}
void Apartment::SetMaterial(QString Material)
{
    material = Material;
}
QString Apartment::ID()
{
    return id;
}
QString Apartment::Area()
{
    return area;
}
QString Apartment::Space()
{
    return space;
}
QString Apartment::Rooms()
{
    return rooms;
}
QString Apartment::Floor()
{
    return floor;
}
QString Apartment::Material()
{
    return material;
}
 Apartment::~Apartment()
{
}

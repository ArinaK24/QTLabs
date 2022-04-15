#include "apartment.h"

Apartment::Apartment()
{

}

void Apartment::SetID(const QString ID)
{
    id = ID;
}
void Apartment::SetArea(const QString Area)
{
    area = Area;
}
void Apartment::SetSpace(const QString Space)
{
    space = Space;
}
void Apartment::SetRooms(const QString Rooms)
{
    rooms = Rooms;
}
void Apartment::SetFloor(const QString Floor)
{
    floor = Floor;
}
void Apartment::SetMaterial(const QString Material)
{
    material = Material;
}
QString Apartment::getID() const
{
    return id;
}
QString Apartment::getArea() const
{
    return area;
}
QString Apartment::getSpace() const
{
    return space;
}
QString Apartment::getRooms() const
{
    return rooms;
}
QString Apartment::getFloor() const
{
    return floor;
}
QString Apartment::getMaterial() const
{
    return material;
}
 Apartment::~Apartment()
{
}

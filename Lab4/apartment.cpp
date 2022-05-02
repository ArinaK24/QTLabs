#include "apartment.h"
#include <utility>
using std::move;
const QStringList Apartment::SQL_IDS = {
    QString("area"),
    QString("space"),
    QString("rooms"),
    QString("floor"),
    QString("material"),
};

Apartment::Apartment(QString area,
                     double space,
                     double rooms,
                     double floor,
                     QString material)
    : a_area(move(area)),
      a_space(space),
      a_rooms(rooms),
      a_floor(floor),
      a_material(move(material)){}

const QString& Apartment::area() const {
return a_area;
}
void Apartment::area(QString area) {
a_area = move(area);
}
double Apartment::space() const { return a_space;
}
void Apartment::space(double space) { a_space = space;
}
double Apartment::rooms() const { return a_rooms;
}
void Apartment::rooms(double rooms) { a_rooms = rooms;
}
double Apartment::floor() const { return a_floor;
}
void Apartment::floor(double floor) { a_floor = floor;
}
const QString& Apartment::material() const {
return a_material;
}
void Apartment::material(QString material) {
a_material = move(material);
}


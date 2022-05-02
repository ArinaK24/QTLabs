#pragma once
#include <QString>
#include <QStringList>
class Apartment {
    QString a_area;
    double a_space;
    double a_rooms;
    double a_floor;
    QString a_material;
public:
static const QStringList SQL_IDS;
enum Columns {
    Area,
    Space,
    Rooms,
    Floor,
    Material,
    Count,
};
Apartment(QString area,
          double space,
          double rooms,
          double floor,
          QString material);

const QString& area() const; void area(QString area);
double space() const; void space(double);
double rooms() const;void rooms(double);
double floor() const; void floor(double);
const QString& material() const; void material(QString);};







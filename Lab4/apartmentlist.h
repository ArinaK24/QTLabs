#pragma once
#include <QAbstractListModel>
#include <QSqlDatabase>
#include "apartment.h"

class ApartmentList : public QAbstractTableModel { Q_OBJECT
QList<Apartment> a_apartments;
QSqlDatabase a_database;

public:
ApartmentList();
void add(const Apartment& apartment);
Q_INVOKABLE void add(QString area,
                     double space,
                     double rooms,
                     double floor,
                     QString material);

Q_INVOKABLE void remove(int index);
Q_INVOKABLE QVariant get(int row, int col);
public:
int rowCount(const QModelIndex&) const override;
int columnCount(const QModelIndex&) const override;
QVariant headerData(int, Qt::Orientation, int) const override; QHash<int, QByteArray> roleNames() const override;
QVariant data(const QModelIndex&, int) const override; Qt::ItemFlags flags(const QModelIndex&) const override;
bool setData(const QModelIndex&, const QVariant&, int) override; };







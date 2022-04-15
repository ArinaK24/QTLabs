#include "apartmentlist.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QApplication>

ApartmentList::ApartmentList(QObject* parent):QAbstractListModel(parent)
{
    add("Волга", "3530", "Каспийское море", "254", "1360");
    add("Сена", "776", "Ла-Манш", "34", "78");
    add("Турнеэльвен", "565", "Ботанический залив", "27", "40");
}

ApartmentList::~ApartmentList()
{

}

int ApartmentList::rowCount(const QModelIndex&) const
{
    return listOfApartments.size();
}


QVariant ApartmentList::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= listOfApartments.size())
            return QVariant();
      {
        switch (role) {
                case area:
                    return QVariant(listOfApartments.at(index.row()).getArea());
                case space:
                    return QVariant(listOfApartments.at(index.row()).getSpace());
                case rooms:
                    return QVariant(listOfApartments.at(index.row()).getRooms());
                case floor:
                    return QVariant(listOfApartments.at(index.row()).getFloor());
                case material:
                    return QVariant(listOfApartments.at(index.row()).getMaterial());

                default:
                    return QVariant();
            }

    }
}

QHash<int, QByteArray> ApartmentList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[area] = "areaOfApartment";
    roles[space] = "spaceOfApartment";
    roles[rooms] = "roomsOfApartment";
    roles[floor] = "floorOfApartment";
    roles[material] = "materialOfApartment";
       return roles;
}

void ApartmentList::add(const QString& areaAp, const QString& spaceAp, const QString& roomsAp, const QString& floorAp, const QString& materialAp){
     Apartment apartment;
     apartment.SetArea(areaAp);
     apartment.SetSpace(spaceAp);
     apartment.SetRooms(roomsAp);
     apartment.SetFloor(floorAp);
     apartment.SetMaterial(materialAp);

    beginInsertRows(QModelIndex(),listOfApartments.size(),listOfApartments.size());
    listOfApartments.append(apartment);
    endInsertRows();

}

QAbstractListModel* ApartmentList::getModel(){
    return this;
}

void ApartmentList::del(const int index){

     if (index >= 0 && index < listOfApartments.size())
     {

         beginRemoveRows(QModelIndex(), index, index);
        listOfApartments.removeAt(index);
              endRemoveRows();
     }
     else qDebug() << "Error index";

}

QString ApartmentList::count(const QString& textSpace){
    int count = 0;
    for(int i = 0; i < listOfApartments.size(); i++)
        if(listOfApartments[i].getSpace().toInt() <= textSpace.toInt())
            count++;
    QString c = QString::number(count);
    return c;
}

void ApartmentList::edit(const QString& areaAp, const QString& spaceAp, const QString& roomsAp, const QString& floorAp, const QString& materialAp, const int index) {
     if(index >= 0 && index < listOfApartments.size() )
     {
        auto& currentApartment = listOfApartments[index];
        if (currentApartment.getArea().compare(areaAp)!=0 || currentApartment.getSpace() != spaceAp || currentApartment.getRooms() != roomsAp
                || currentApartment.getFloor() != floorAp || currentApartment.getMaterial() != materialAp)
        {
            currentApartment.SetArea(areaAp);
            currentApartment.SetSpace(spaceAp);
            currentApartment.SetRooms(roomsAp);
            currentApartment.SetFloor(floorAp);
            currentApartment.SetMaterial(materialAp);

            auto modelIndex = createIndex(index, 0);
            emit dataChanged(modelIndex, modelIndex);
            qDebug() << listOfApartments[index].getSpace();
        }

     }
      else qDebug() << "Error index";
}

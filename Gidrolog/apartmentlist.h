#ifndef APARTMENTLIST_H
#define APARTMENTLIST_H

#include <QAbstractListModel>
#include <QVariant>
#include <QList>
#include <QModelIndex>
#include <QItemSelectionModel>
#include "apartment.h"

class ApartmentList : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(QAbstractListModel* apartmentModel READ getModel CONSTANT)  /* первый параметр - тип свойства (property)
                                                                     второй параметр - имя свойства, по которому будем обращаться к реальной модели в qml-файле
                                                                     третий параметр - метод С++ для получения значения свойства (получим саму модель)
                                                                     CONSTANT - qml получит свойство однократно, и в процессе работы это свойство изменяться не будет */
private:
    QList<Apartment> listOfApartments; // непосредственно данные
    QAbstractListModel *getModel();

public:
    ApartmentList(QObject *parent = nullptr);
    ~ApartmentList() override;

    // количество колонок
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;

     // возвращение данных модели по указанному индексу и роли
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    enum ResentRoles {
            area = Qt::DisplayRole,
            space = Qt::DisplayRole + 1,
            rooms = Qt::DisplayRole + 2,
            floor = Qt::DisplayRole + 3,
            material = Qt::DisplayRole + 4
       };

    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void add(const QString& areaAp, const QString& spaceAp, const QString& roomsAp, const QString& floorAp, const QString& materialAp);  // макрос указывает, что к методу можно обратиться из QML
    Q_INVOKABLE void del(const int index);
    Q_INVOKABLE QString count(const QString& textSpace);
    Q_INVOKABLE void edit(const QString& areaAp, const QString& spaceAp, const QString& roomsAp, const QString& floorAp, const QString& materialAp, const int index);
};

#endif


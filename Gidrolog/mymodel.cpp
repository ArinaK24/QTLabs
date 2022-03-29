#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    Apartment* std1 = new Apartment("101","Енисей","5550","Байкал","19800","2580",this);
    Apartment* std2 = new Apartment("102","Обь","5410","Иртыш","12300","2990",this);
    Apartment* std3 = new Apartment("103","Волга","3731","Ока","8060","1360",this);
    AddApartment(std1);
    AddApartment(std2);
    AddApartment(std3);
}

int MyModel::rowCount(const QModelIndex &) const
{
   return apartments.count();
}

int MyModel::columnCount(const QModelIndex &) const
{
    return 6;
}


QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Apartment* std = apartments.at(index.row());
        if (index.column() == 0){Value = std->ID();}
        else if (index.column() == 1){Value = std->Area();}
        else if (index.column() == 2){Value = std->Space();}
        else if (index.column() == 3){Value = std->Rooms();}
        else if (index.column() == 4){Value = std->Floor();}
        else if (index.column() == 5){Value = std->Material();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Район города");
            case 2:
                return QString("Площадь, м^2");
            case 3:
                return QString("Количество комнат");
            case 4:
                return QString("Этаж");
            case 5:
                return QString("Материал стен");
            }
        }
    }
    return QVariant();
}


bool MyModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Apartment* std = apartments.at(index.row());
        if (index.column() == 0){std->SetID(value.toString());}
        else if (index.column() == 1){std->SetArea(value.toString());}
        else if (index.column() == 2){std->SetSpace(value.toString());}
        else if (index.column() == 3){std->SetRooms(value.toString());}
        else if (index.column() == 4){std->SetFloor(value.toString());}
        else if (index.column() == 5){std->SetMaterial(value.toString());}
    }
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void MyModel::AddApartment(Apartment* apartment)
{
    beginInsertRows(QModelIndex(),apartments.size(),apartments.size());
    apartments.append(apartment);
    endInsertRows();
}

void MyModel::DeleteApartment(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    apartments.removeAt(row);
    endRemoveRows();
    //emit layoutChanged();
}


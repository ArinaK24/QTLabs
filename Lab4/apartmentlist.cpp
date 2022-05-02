#include "apartmentlist.h"
#include "apartment.h"
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
using std::move;
using VSC = Apartment::Columns;
auto& SQL_IDS = Apartment::SQL_IDS;


ApartmentList::ApartmentList()
: a_database(QSqlDatabase::addDatabase("QSQLITE")) { a_database.setDatabaseName("qtlab.sqlite");
if (!a_database.open()) return;
QSqlQuery(a_database)
.exec(
"CREATE TABLE apartment ("
+ SQL_IDS[VSC::Area] + " VARCHAR(255) PRIMARY KEY NOT NULL, "
+ SQL_IDS[VSC::Space] + " DOUBLE NOT NULL, "
+ SQL_IDS[VSC::Rooms] + " DOUBLE NOT NULL, "
+ SQL_IDS[VSC::Floor] + " DOUBLE NOT NULL, "
+ SQL_IDS[VSC::Material] + " VARCHAR(255) NOT NULL)");

auto query = QSqlQuery(a_database);
if (query.exec("SELECT * FROM apartment")) {
beginInsertRows({}, 0, query.size());
while (query.next())
a_apartments.append(Apartment(
query.value(SQL_IDS[VSC::Area]).toString(),
query.value(SQL_IDS[VSC::Space]).toDouble(),
query.value(SQL_IDS[VSC::Rooms]).toDouble(),
query.value(SQL_IDS[VSC::Floor]).toDouble(),
query.value(SQL_IDS[VSC::Material]).toString()));
endInsertRows();
}
}

void ApartmentList::add(const Apartment& apartment) {
auto new_row = rowCount({});
   if (QSqlQuery(a_database)
    .exec(
   (QString()
+ "INSERT INTO apartment("
+ SQL_IDS[VSC::Area] + ", "
+ SQL_IDS[VSC::Space] + ", "
+ SQL_IDS[VSC::Rooms] + ", "
+ SQL_IDS[VSC::Floor] + ", "
+ SQL_IDS[VSC::Material] + ") "
+ "VALUES ('%1','%2','%3','%4','%5')")
.arg(apartment.area())
.arg(apartment.space())
.arg(apartment.rooms())
.arg(apartment.floor())
.arg(apartment.material()))){

beginInsertRows({}, new_row, new_row);
a_apartments.append(apartment);
endInsertRows();
}
}

void ApartmentList::add(QString area,
double space,
double rooms,
double floor,
QString material) {
add(Apartment(move(area), space, rooms, floor,move(material))); }
void ApartmentList::remove(int index) {
auto& apartment = a_apartments[index];
if (QSqlQuery(a_database)
.exec(
(QString()
+ "DELETE FROM apartment WHERE "
+ SQL_IDS[VSC::Area] + " = '%1'")
.arg(apartment.area()))) {
beginRemoveRows({}, index, index);
a_apartments.removeAt(index);
endRemoveRows();
}
}
QVariant ApartmentList::get(int row, int col) { return
ApartmentList::data(QAbstractTableModel::index(row, col), Qt::DisplayRole);
}
int ApartmentList::rowCount(const QModelIndex& parent) const {
return static_cast<int>(a_apartments.size());
}
int ApartmentList::columnCount(const QModelIndex& parent) const {
return VSC::Count;
}
QVariant ApartmentList::headerData(int section, Qt::Orientation orientation, int role) const {
if (orientation != Qt::Horizontal
|| role != Qt::DisplayRole)
return {};
switch (section) {
case VSC::Area:
return "Район города";
case VSC::Space:
return "Площадь, м^2";
case VSC::Rooms:
return "Кол-во комнат";
case VSC::Floor:
return "Этаж";
case VSC::Material:
return "Материал стен";
default:
return {};
}
}
QVariant ApartmentList::data(const QModelIndex& index, int role) const {
auto col = index.column();
const auto start = Qt::UserRole + 1;
if (role >= start
&& role < start + VSC::Count) {
col = role - start;
role = Qt::DisplayRole;
}
if (!index.isValid()
|| index.row() >= a_apartments.size()
|| role != Qt::DisplayRole && role != Qt::EditRole)
return {};
auto& apartment = a_apartments[index.row()];
switch (col) {
case VSC::Area:
return apartment.area();
case VSC::Space:
return apartment.space();
case VSC::Rooms:
return apartment.rooms();
case VSC::Floor:
return apartment.floor();
case VSC::Material:
return apartment.material();
default:
return {};
}
}
Qt::ItemFlags ApartmentList::flags(const QModelIndex& index) const {
if (!index.isValid())
return Qt::ItemIsEnabled;
return QAbstractTableModel::flags(index) | Qt::ItemIsEditable; }
bool ApartmentList::setData(const QModelIndex& index, const QVariant& value, int role) {
auto col = index.column();
const auto start = Qt::UserRole + 1;
if (role >= start
&& role < start + VSC::Count) {
col = role - start;
role = Qt::EditRole;
}
if (!index.isValid()
|| role != Qt::EditRole)
return false;
auto& apartment = a_apartments[index.row()];
if (!QSqlQuery(a_database)
.exec(
(QString()
+ "UPDATE apartment SET "
+ SQL_IDS[col] + " = '%1' WHERE "
+ SQL_IDS[VSC::Area] + " = '%2'")
.arg(value.toString())
.arg(apartment.area())))
return false;
switch (col) {
case VSC::Area:
apartment.area(value.toString());
break;
case VSC::Space:
apartment.space(value.toDouble());
break;
case VSC::Rooms:
apartment.rooms(value.toDouble());
break;
case VSC::Floor:
apartment.floor(value.toDouble());
break;
case VSC::Material:
apartment.material(value.toString());
break;
default:
return false;
}
emit dataChanged(index, index, {role});
return true;
}
QString roleName(int i) {
switch (i) {
case VSC::Area:
return "area";
case VSC::Space:
return "space";
case VSC::Rooms:
return "rooms";
case VSC::Floor:
return "floor";
case VSC::Material:
return "material";
default:
return {};
}
}
QHash<int, QByteArray> ApartmentList::roleNames() const { auto roles = QHash<int, QByteArray>();
for (auto i = 0; i < VSC::Count; i++)
roles.insert(
Qt::UserRole + i + 1,
roleName(i).toUtf8());
return roles;
}


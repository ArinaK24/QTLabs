#pragma once
#define MYMODEL_H

#include "QtWidgets"

class FacultyDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    FacultyDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;

};

#include "dialogdelegate.h"
#include "QtWidgets"
#include "editdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;

}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditDialog* editDialog = new EditDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Area = model->data(model->index(index.row(),1,index)).toString();
        QString Space = model->data(model->index(index.row(),2,index)).toString();
        QString Rooms = model->data(model->index(index.row(),3,index)).toString();
        QString Floor = model->data(model->index(index.row(),4,index)).toString();
        QString Material = model->data(model->index(index.row(),5,index)).toString();

        editDialog->SetUpDialog(ID, Area, Space, Rooms, Floor, Material);

        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->area());
            model->setData(model->index(index.row(),2,index),editDialog->space());
            model->setData(model->index(index.row(),3,index),editDialog->rooms());
            model->setData(model->index(index.row(),4,index),editDialog->floor());
            model->setData(model->index(index.row(),5,index),editDialog->material());

            editDialog->deleteLater();
        }
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}

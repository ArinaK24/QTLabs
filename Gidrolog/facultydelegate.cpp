#include "facultydelegate.h"
#include "QtWidgets"
#include "river.h"
FacultyDelegate::FacultyDelegate(QObject *parent): QItemDelegate(parent)
{

}


QWidget *FacultyDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    QComboBox* cmb = new QComboBox(parent);
    //QStringList faculties = Student::GetFaculties();
    foreach  (QString fc, faculties)
    {
        cmb->addItem(fc);
    }
    return cmb;
}

void FacultyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QComboBox *myeditor = static_cast<QComboBox*>(editor);

    QString value = myeditor->currentText();

    model->setData(index, value, Qt::EditRole);
}

void FacultyDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QComboBox *myeditor = qobject_cast<QComboBox *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    const int cbIndex = myeditor->findText(currentText);
    if (cbIndex >= 0)
       myeditor->setCurrentIndex(cbIndex);
}




#ifndef REQUESTLIST_H
#define REQUESTLIST_H

#include <QDialog>

namespace Ui {
class requestList;
}

class requestList : public QDialog
{
    Q_OBJECT

public:
    explicit requestList(QWidget *parent = nullptr);
    ~requestList();

private:
    Ui::requestList *ui;
};

#endif // REQUESTLIST_H

#ifndef RECORDS_H
#define RECORDS_H

#include <QWidget>

namespace Ui {
class records;
}

class records : public QWidget
{
    Q_OBJECT

public:
    explicit records(QWidget *parent = nullptr);
    ~records();

private:
    Ui::records *ui;
};

#endif // RECORDS_H

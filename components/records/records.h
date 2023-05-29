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

private slots:
    void on_homeButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::records *ui;
};

#endif // RECORDS_H

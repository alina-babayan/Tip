#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow (QWidget * parent = nullptr);

private slots:
    void calculate();

private:
    QLabel* billAmount;
    QLabel* tipPercentage;
    QLabel* number;
    QLabel* tipAmount;
    QLabel* totalAmount;
    QLabel* person;

    QLineEdit* bAm;
    QLineEdit* tipprc;
    QLineEdit* numberPeople;

    QPushButton* calc;
};

#endif // MAINWINDOW_H

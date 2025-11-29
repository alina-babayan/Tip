#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Tip Calculator");
    this->setFixedSize(400, 400);

    QLabel* title = new QLabel("Tip Calculator", this);
    title->setGeometry(60, 10, 280, 40);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 22px; font-weight: bold;");

    billAmount = new QLabel("Bill Amount ($):", this);
    billAmount->setGeometry(30, 70, 140, 30);

    tipPercentage = new QLabel("Tip Percentage (%):", this);
    tipPercentage->setGeometry(30, 110, 140, 30);

    number = new QLabel("Number of People:", this);
    number->setGeometry(30, 150, 140, 30);

    tipAmount = new QLabel("Tip Amount: $0.00", this);
    tipAmount->setGeometry(30, 240, 340, 30);
    tipAmount->setAlignment(Qt::AlignCenter);
    tipAmount->setStyleSheet("font-size: 16px; font-weight: bold;");

    totalAmount = new QLabel("Total Amount: $0.00", this);
    totalAmount->setGeometry(30, 280, 340, 30);
    totalAmount->setAlignment(Qt::AlignCenter);
    totalAmount->setStyleSheet("font-size: 16px; font-weight: bold;");

    person = new QLabel("Per Person: $0.00", this);
    person->setGeometry(30, 320, 340, 30);
    person->setAlignment(Qt::AlignCenter);
    person->setStyleSheet("font-size: 16px; font-weight: bold;");


    bAm = new QLineEdit(this);
    bAm->setGeometry(180, 70, 180, 30);
    bAm->setPlaceholderText("Enter bill amount");

    tipprc = new QLineEdit(this);
    tipprc->setGeometry(180, 110, 180, 30);
    tipprc->setPlaceholderText("Enter tip percentage");

    numberPeople = new QLineEdit(this);
    numberPeople->setGeometry(180, 150, 180, 30);
    numberPeople->setPlaceholderText("Enter number of people");

    calc = new QPushButton("Calculate", this);
    calc->setGeometry(130, 190, 140, 32);
    calc->setStyleSheet("font-size: 14px;");

    connect(calc, &QPushButton::clicked, this, &MainWindow::calculate);
}

void MainWindow::calculate()
{

    double bill = bAm->text().toDouble();
    double tipPerc = tipprc->text().toDouble();
    double numPeople = numberPeople->text().toDouble();


    double tip = bill * (tipPerc / 100.0);
    double total = bill + tip;
    double per = total / numPeople;

    tipAmount->setText("Tip Amount:" + QString::number(tip));
    totalAmount->setText("Total Amount:" + QString::number(total));
    person->setText("Per Person:" + QString::number(per));
}

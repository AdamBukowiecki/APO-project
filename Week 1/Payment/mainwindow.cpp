#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    setGeometry(150, 150, 300, 250);

    createMainGroupBox();
    createCashGroupBox();
    createCardGroupBox();
    createPrepaidGroupBox();

    cashGroup->setVisible(false);
    cardGroup->setVisible(false);
    prepaidGroup->setVisible(false);

}

MainWindow::~MainWindow() {

}

void MainWindow::createMainGroupBox() {

    mainGroup = new QGroupBox("Płatność", this);
    mainGroup->setGeometry(0,0,300,250);

    chooseLabel = new QLabel("Wybierz metodę płatności", mainGroup);
    chooseLabel->setAlignment(Qt::AlignCenter);
    chooseLabel->setFont(QFont("Helvetica", 16));

    cashButton = new QPushButton("Gotówka", mainGroup);
    QObject::connect(cashButton, SIGNAL(clicked()), this, SLOT(openCashBox()));

    cardButton = new QPushButton("Karta kredytowa", mainGroup);
    QObject::connect(cardButton, SIGNAL(clicked()), this, SLOT(openCardBox()));

    prepaidButton = new QPushButton("Karta prepaid", mainGroup);
    QObject::connect(prepaidButton, SIGNAL(clicked()), this, SLOT(openPrepaidBox()));

    mainLayout = new QGridLayout(mainGroup);
    mainLayout->addWidget(chooseLabel, 0, 0);
    mainLayout->addWidget(cashButton, 1, 0);
    mainLayout->addWidget(cardButton, 2, 0);
    mainLayout->addWidget(prepaidButton, 3, 0);

    mainLayout->setRowStretch(2, 20);
    mainLayout->setSpacing(15);
    //mainLayout->setVerticalSpac;

    mainGroup->setLayout(mainLayout);
}

void MainWindow::createCashGroupBox() {

    cashGroup = new QGroupBox("Płatność gotówką", this);
    cashGroup->setGeometry(0,0,300,250);

    requireCash = new QLabel("Do zapłaty: 0", cashGroup);
    requireCash->setAlignment(Qt::AlignCenter);
    requireCash->setFont(QFont("Helvetica", 16));

    paidCash = new QLabel("Pozostało: 0", cashGroup);
    paidCash->setAlignment(Qt::AlignCenter);
    paidCash->setFont(QFont("Helvetica", 16));

    fromCashBackButton = new QPushButton("Zmień metodę płacenia", cashGroup);
    QObject::connect(fromCashBackButton, SIGNAL(clicked()), this, SLOT(openMainBox()));

    cashLayout = new QGridLayout(cashGroup);
    cashLayout->addWidget(requireCash, 1, 0);
    cashLayout->addWidget(paidCash, 2, 0);
    cashLayout->addWidget(fromCashBackButton, 3, 0);

    cashGroup->setLayout(cashLayout);
}

void MainWindow::createCardGroupBox() {

    cardGroup = new QGroupBox("Płatność kartą kredytową", this);
    cardGroup->setGeometry(0,0,300,250);

    cardLabel = new QLabel("Włóż kartę lub przybliż do czytnika PayPass", cardGroup);
    cardLabel->setAlignment(Qt::AlignCenter);
    cardLabel->setFont(QFont("Helvetica", 9));

    fromCardBackButton = new QPushButton("Zmień metodę płacenia", cashGroup);
    QObject::connect(fromCardBackButton, SIGNAL(clicked()), this, SLOT(openMainBox()));

    pinLine = new QLineEdit(cardGroup);
    pinLine->setEchoMode(QLineEdit::Password);

    cardLog = new QTextBrowser(cardLog);
    cardLog->insertPlainText(">>> Oczekiwanie na kartę...");

    cardLayout = new QFormLayout(cardGroup);
    cardLayout->addRow(cardLabel);
    cardLayout->addRow("PIN: ", pinLine);
    cardLayout->addRow(fromCardBackButton);
    cardLayout->addRow(cardLog);

    cardGroup->setLayout(cardLayout);
}

void MainWindow::createPrepaidGroupBox() {

    prepaidGroup = new QGroupBox("Płatność kartą prepaid", this);
    prepaidGroup->setGeometry(0,0,300,250);

    prepaidLabel = new QLabel("Włóż kartę lub zaloguj się, by zapłacić", prepaidGroup);

    fromPrepaidBackButton = new QPushButton("Zmień metodę płacenia", cashGroup);
    QObject::connect(fromPrepaidBackButton, SIGNAL(clicked()), this, SLOT(openMainBox()));

    prepaidLayout = new QFormLayout(prepaidGroup);
    prepaidLayout->addRow(prepaidLabel);

    QLineEdit* login = new QLineEdit(prepaidGroup);
    prepaidLayout->addRow("Login: ", login);

    QLineEdit* pass = new QLineEdit(prepaidGroup);
    pass->setEchoMode(QLineEdit::Password);
    prepaidLayout->addRow("Hasło: ", pass);

    prepaidLayout->addRow(new QPushButton("Zatwierdź transakcję", prepaidGroup));
    prepaidLayout->addRow(fromPrepaidBackButton);

    prepaidLog = new QTextBrowser(prepaidGroup);
    prepaidLog->insertPlainText(">>> Oczekiwanie na kartę lub zalogowanie...");
    prepaidLayout->addRow(prepaidLog);

    prepaidGroup->setLayout(mainLayout);
}

void MainWindow::openMainBox() {
    mainGroup->setVisible(true);
    cashGroup->setVisible(false);
    cardGroup->setVisible(false);
    prepaidGroup->setVisible(false);

}

void MainWindow::openCashBox() {
    mainGroup->setVisible(false);
    cashGroup->setVisible(true);
    cardGroup->setVisible(false);
    prepaidGroup->setVisible(false);
}

void MainWindow::openCardBox() {
    mainGroup->setVisible(false);
    cashGroup->setVisible(false);
    cardGroup->setVisible(true);
    prepaidGroup->setVisible(false);
}

void MainWindow::openPrepaidBox() {
    mainGroup->setVisible(false);
    cashGroup->setVisible(false);
    cardGroup->setVisible(false);
    prepaidGroup->setVisible(true);
}

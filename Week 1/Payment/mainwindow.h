#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFormLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>

class MainWindow : public QMainWindow {

    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QGroupBox *mainGroup, *cashGroup, *cardGroup, *prepaidGroup;
    QGridLayout *frameLayout, *mainLayout, *cashLayout;
    QFormLayout *prepaidLayout, *cardLayout;
    QLineEdit *pinLine;
    QLabel *chooseLabel, *requireCash, *paidCash, *cardLabel, *prepaidLabel;
    QPushButton *cashButton, *cardButton, *prepaidButton, *fromCashBackButton,
                *fromCardBackButton, *fromPrepaidBackButton;
    QTextBrowser *cardLog, *prepaidLog;

private:

    void createMainGroupBox();
    void createCashGroupBox();
    void createCardGroupBox();
    void createPrepaidGroupBox();

public slots:

    void openMainBox();
    void openCashBox();
    void openCardBox();
    void openPrepaidBox();

};

#endif // MAINWINDOW_H

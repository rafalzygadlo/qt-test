#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>

class loginView : public QDialog
{
    Q_OBJECT
public:
    loginView(QWidget* parent = nullptr);

private slots:
    void handleLogin();

private:
    QLabel* errorLabel;
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    QPushButton* loginButton;
};

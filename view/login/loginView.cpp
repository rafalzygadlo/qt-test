#include "loginView.h"

loginView::loginView(QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle("Login");
    setModal(true); 

    QLabel* errorLabel = new QLabel();
    QLabel* userLabel = new QLabel("Username:");
    usernameEdit = new QLineEdit();

    QLabel* passLabel = new QLabel("Password:");
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);

    loginButton = new QPushButton("Login");
    connect(loginButton, &QPushButton::clicked, this, &loginView::handleLogin);

    QVBoxLayout* vBox = new QVBoxLayout();
    vBox->addWidget(userLabel);
    vBox->addWidget(usernameEdit);
    vBox->addWidget(passLabel);
    vBox->addWidget(passwordEdit);

    QHBoxLayout *hBox = new QHBoxLayout();
    hBox->addStretch(1);
    hBox->addWidget(loginButton, 0, Qt::AlignRight);
    vBox->addLayout(hBox);

    setLayout(vBox);
    resize(300, 150);
}

void loginView::handleLogin()
{
    QString user = usernameEdit->text();
    QString pass = passwordEdit->text();

    if (user == "admin" && pass == "1234") 
    {    
        accept(); 
    } else {
        errorLabel->
        return false;
    }
}

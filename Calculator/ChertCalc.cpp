#include "ChertCalc.h"
#include "ui_ChertCalc.h"
#include <QDebug>
#include <iostream>
#include <string>>

char firstNum;
bool user_is_typing_secondNumber=false;
int selectedBaseIndex;
int selectedBaseIndexRes;

ChertCalc::ChertCalc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChertCalc)
{
    ui->setupUi(this);

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_A,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_B,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_C,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_D,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_E,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_F,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_Power,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_Power->setCheckable(true);
    setFixedSize(441,432);
}

ChertCalc::~ChertCalc()
{
    delete ui;
}

void ChertCalc::digit_pressed()
{
   // qDebug() << "test";
    QPushButton * button = (QPushButton *)sender();
    QString input;
    QString labelNUM;
    double labelnumber;

    if((ui->pushButton_add->isChecked() || ui->pushButton_divide->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() || ui->pushButton_Power->isChecked()) && (!user_is_typing_secondNumber))
    {
        user_is_typing_secondNumber=true;
        labelNUM = button->text();
        int base;

        switch (selectedBaseIndex) {
        case 0: // 2-ная
            base = 2;
            break;
        case 1: // 3-ная
            base = 3;
            break;
        case 2:
            base = 4;
            break;
        case 3:
            base = 5;
            break;
        case 4:
            base = 6;
            break;
        case 5:
            base = 7;
            break;
        case 6:
            base = 8;
            break;
        case 7:
            base = 9;
            break;
        case 8:
            base = 10;
            break;
        case 9:
            base = 11;
            break;
        case 10:
            base = 12;
            break;
        case 11:
            base = 13;
            break;
        case 12:
            base = 14;
            break;
        case 13:
            base = 15;
            break;
        case 14:
            base = 16;
            break;
        }
        labelnumber = labelNUM.toInt(nullptr, base);
        input = QString::number(labelnumber,'g',15);
    }

    else
    {
        if(ui->label->text().contains(".") && button->text() == "0")
        {
            input=ui->label->text() + button->text();
        }
        else
        {
            labelnumber = (ui->label->text() + button->text()).toDouble();
            input = QString::number(labelnumber,'g',15);
        }
        //labelnumber = (ui->label->text() + button->text()).toDouble();
    }
    ui->label->setText(input);

}

void ChertCalc::on_pushButton_dot_released()
{

    // check for appearance of decimal, exit function if there is one
    if(ui->label->text().contains(".")){

            return;

}
    ui->label->setText(ui->label->text() + ".");

}

void ChertCalc::unary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    double labelnumber;
    QString input;

    if(button->text() == "+/-")
    {
        labelnumber = (ui->label->text()).toDouble();
        labelnumber *= -1;
        input = QString::number(labelnumber,'g',15);
        ui->label->setText(input);
    }

    //error correction codse is still missing
}

void ChertCalc::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_Power->setChecked(false);
    user_is_typing_secondNumber=false;

    ui->label->setText("0");
}

void ChertCalc::on_pushButton_equals_released()
{
    int labelnumber,secondNum;
    QString input;
    labelnumber=0;

    secondNum = ui->label->text().toDouble();

    if(ui->pushButton_add->isChecked())
    {
        labelnumber = firstNum + secondNum;
        ui->pushButton_add->setChecked(false);
    }

    else if(ui->pushButton_minus->isChecked())
    {
        labelnumber = firstNum - secondNum;
        ui->pushButton_minus->setChecked(false);
    }

    else if(ui->pushButton_multiply->isChecked())
    {
        labelnumber = firstNum * secondNum;
        ui->pushButton_multiply->setChecked(false);
    }

    else if(ui->pushButton_divide->isChecked())
    {
        labelnumber = firstNum / secondNum;
        ui->pushButton_divide->setChecked(false);
    }

    else if(ui->pushButton_Power->isChecked())
    {
        labelnumber = pow(firstNum,secondNum);
        ui->pushButton_Power->setChecked(false);
    }

    int baseRes;

    switch (selectedBaseIndexRes) {
    case 0: // 2-ная
        baseRes = 2;
        break;
    case 1: // 3-ная
        baseRes = 3;
        break;
    case 2:
        baseRes = 4;
        break;
    case 3:
        baseRes = 5;
        break;
    case 4:
        baseRes = 6;
        break;
    case 5:
        baseRes = 7;
        break;
    case 6:
        baseRes = 8;
        break;
    case 7:
        baseRes = 9;
        break;
    case 8:
        baseRes = 10;
        break;
    case 9:
        baseRes = 11;
        break;
    case 10:
        baseRes = 12;
        break;
    case 11:
        baseRes = 13;
        break;
    case 12:
        baseRes = 14;
        break;
    case 13:
        baseRes = 15;
        break;
    case 14:
        baseRes = 16;
        break;
    }

    QString result = from_decimal(input, baseRes, labelnumber);
    input = QString::number(labelnumber,'g',15);
    ui->label->setText(result);

    user_is_typing_secondNumber=false;
}

void ChertCalc::binary_operation_pressed()
{
    QPushButton* button = (QPushButton *)sender();
    //double labelnumber;
    //QString input;

    firstNum = ui->label->text().toDouble();
    button->setChecked(true);

}

void ChertCalc::on_comboBox_1_activated(int index) {
    selectedBaseIndex = index; // Запомнили СС
}

void ChertCalc::on_comboBox_3_activated(int index) {
    selectedBaseIndexRes = index;
}

char re_value(int num) {
    if ((num >= 0) && (num <= 9))
        return static_cast<char>(num + '0');
    return static_cast<char>(num - 10 + 'A');
}

int value(char c) {
    if ((c >= '0') && (c <= '9'))
        return static_cast<int>(c) - '0';
    return static_cast<int>(c) - 'A' + 10;
}

int to_decimal(std::string str, int base) {
    int len = str.size();
    int power = 1;
    int num = 0;

    for (int i = len - 1; i >= 0; i--) {
        if (value(str[i]) >= base) {
            std::cout << "Invalid Number";
            return -1;
        }

        num += value(str[i]) * power;
        power *= base;
    }

    return num;
}

std::string from_decimal(std::string& res, int base, int input) {
    int index = 0;

    while (input > 0) {
        res.push_back(re_value(input % base));
        index++;
        input /= base;
    }

    std::reverse(res.begin(), res.end());

    return res;
}

#ifndef CHERTCALC_H
#define CHERTCALC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ChertCalc; }
QT_END_NAMESPACE

class ChertCalc : public QMainWindow
{
    Q_OBJECT

public:
    ChertCalc(QWidget *parent = nullptr);
    ~ChertCalc();

private:
    Ui::ChertCalc *ui;

private slots:
    void digit_pressed();

    void on_pushButton_dot_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();
    void on_comboBox_1_activated(int index);
    void on_comboBox_2_activated(int index);
    void on_comboBox_3_activated(int index);
    std::string from_decimal(std::string& res, int base, int input);
    int to_decimal(std::string str, int base);
    int value(char c);
    char re_value(int num);
};
#endif // CHERTCALC_H

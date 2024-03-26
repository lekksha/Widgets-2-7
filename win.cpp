#include "win.h"

#include <QMessageBox>
#include <QVBoxLayout>

Win::Win(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Возведение в квадрат"); // поставить название окна
    frame = new QFrame(this);   // создать рамку
    frame->setFrameShadow(QFrame::Raised);  // задать тень рамки
    frame->setFrameShape(QFrame::Panel);    // задать форму рамки
    inputLabel = new QLabel("Введите число:",
                            this);  // создать текст и передать его в this
    inputEdit = new QLineEdit("",this); // создать текстовое поле и передать его в this
    StrValidator *v = new StrValidator(inputEdit);  // создать StrValidator с родителем inputEdit
    inputEdit->setValidator(v); // задать валидатор v для inputEdit
    outputLabel = new QLabel("Результат:",  // создать текст и передать его в this
                             this);
    outputEdit = new QLineEdit("",this);    // создать текстовое поле и передать его в this
    nextButton = new QPushButton("Следующее",   // создать кнопку и передать ее в this
                                 this);
    exitButton = new QPushButton("Выход",   // создать кнопку и передать ее в this
                                 this);
    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
        // создать вертикальную компоновку и поместить ее в рамку
    vLayout1->addWidget(inputLabel); // добавить в компоновку
    vLayout1->addWidget(inputEdit); // добавить в компоновку
    vLayout1->addWidget(outputLabel);   // добавить в компоновку
    vLayout1->addWidget(outputEdit);    // добавить в компоновку
    vLayout1->addStretch(); // "выталкививать" вверх вышедобавленные элем. с помощью пространства
    QVBoxLayout *vLayout2 = new QVBoxLayout();
        // создать вертикальную компоновку и поместить ее в рамку
    vLayout2->addWidget(nextButton);    // добавить в компоновку
    vLayout2->addWidget(exitButton);    // добавить в компоновку
    vLayout2->addStretch(); // "выталкививать" вверх вышедобавленные элем. с помощью пространства
    QHBoxLayout *hLayout = new QHBoxLayout(this);
        // создать горизонтальную компоновку и поместить ее в рамку
    hLayout->addWidget(frame);  // добавить в компоновку
    hLayout->addLayout(vLayout2);   // добавить в компоновку
    begin();    // установить начальный интерфейс
    connect(exitButton, &QPushButton::clicked,   // добавить логику для кнопки выхода
            this, &QWidget::close);
    connect(nextButton, &QPushButton::clicked, // добавить логику для кнопки следующего числа
            this, &Win::begin);
    connect(inputEdit, &QLineEdit::returnPressed,  // добавить логику для кнопки вычисления значения
            this, &Win::calc);
}

void Win::begin()   // метод начальной настройки интерфейса
{
    inputEdit->clear(); // очистить поле ввода
    nextButton->setEnabled(false);  // отключить кнопку
    nextButton->setDefault(false);  // поставить нажатие на эту кнопку по умолчанию
    inputEdit->setEnabled(true);    // включить поле ввода
    outputLabel->setVisible(false); // сделать невидимым текст
    outputEdit->setVisible(false);  // сделать невидимыым поле
    outputEdit->setEnabled(false);  // сделать невозможным взаимодействие с полем
    inputEdit->setFocus();
        // сделать ввод с клавиатуры в текстовом поле возможным сразу после запуска
}

void Win::calc()    // метод для вычисления значения и обновления UI
{
    bool Ok = true; // инициализировать //TODO: true можно убрать
    float r, a; // результат, введеное число
    QString str = inputEdit->text();    // объявить переменную с значением поля ввода
    a = str.toDouble(&Ok);    // если преобразование будет неуспешным Ok изменит значение
    if (Ok)
    {
        r = a * a;  // вычислить результат
        str.setNum(r);  // присвоить переменной значение результата
        outputEdit->setText(str);   // дать полю вывода значение переменной
        inputEdit->setEnabled(false);   // включить кнопку
        outputLabel->setVisible(true);  // сделать видимым
        outputEdit->setVisible(true);   // сделать видимым
        nextButton->setDefault(true);   // поставить нажатие на эту кнопку по умолчанию
        nextButton->setEnabled(true);   // включить кнопку
        nextButton->setFocus(); // поставить фокус на кнопку
    }
    else
        if (!str.isEmpty()) // если строка не пустая
        {
            QMessageBox msgBox(QMessageBox::Warning,    // Поставить иконку предупреждения
                               "Возведение в квадрат.", //  Задать название окна
                               "Введено неверное значение.",    // Описание ошибки
                               QMessageBox::Ok);    // добавить кнопку ОК
                // создать окно ошибки
            msgBox.exec();
                // запустить окно ошибки
        }
}

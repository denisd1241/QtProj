#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QGridLayout>
#include <QColor>
#include <QGraphicsScene>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gridLayoutWidget->setStyleSheet("background-color: #a8a8a8; border: 1px solid #333;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Функция для создания симметричной матрицы размером 3x3
QVector<QVector<int>> createSymmetricMatrix() {
    srand(time(0));

    QVector<QVector<int>> matrix(3, QVector<int>(3, 0));

    // Заполнение матрицы случайными значениями 0 или 1
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < 3; ++j) {
            int randomValue = rand() % 2;
            matrix[i][j] = randomValue;
            matrix[j][i] = randomValue; // Симметричное значение относительно диагонали
        }
    }

    return matrix;
}

void MainWindow::on_pushButton_clicked(){
    QGridLayout *gridLayout = ui->gridLayout;
    clearGridLayout(gridLayout);
    QVector<QVector<int>> symmetricMatrix = createSymmetricMatrix();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QLabel *label = new QLabel(QString::number(symmetricMatrix[i][j]));
            label->setStyleSheet("border: none;");
            label->setAlignment(Qt::AlignCenter);

            // Установка размеров минимального и максимального размеров для ячейки
            label->setMinimumSize(30, 30);
            label->setMaximumSize(30, 30);
            gridLayout->addWidget(label, i, j);
        }
    }

}
void MainWindow::clearGridLayout(QGridLayout *layout)
{
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    QGraphicsScene graphicView = ui->graphicsView;

}


#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QString>
#include <QVector>

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVector<QVector<int>> symmetricMatrix = createSymmetricMatrix();
    QWidget w;
    w.setWindowTitle("Symmetric Matrix Example");

    // Создаем макет сетки для размещения QLabel
    QGridLayout *gridLayout = new QGridLayout(&w);

    // Выводим матрицу в QLabel
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QLabel *label = new QLabel(QString::number(symmetricMatrix[i][j]));
            gridLayout->addWidget(label, i, j);
        }
    }

    w.show();
    return a.exec();
}

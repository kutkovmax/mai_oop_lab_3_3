#include <iostream>
#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "figure_array.h"

int main() {
    FigureArray figures;

    int n;
    std::cout << "Введите количество фигур: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "\nВыберите тип фигуры (1-Rectangle, 2-Trapezoid, 3-Rhombus): ";
        int type;
        std::cin >> type;

        if (type == 1) {
            double w, h;
            std::cout << "Введите ширину и высоту прямоугольника: ";
            std::cin >> w >> h;
            figures.add(new Rectangle(w, h, "Rectangle"));
        } 
        else if (type == 2) {
            double a, b, h;
            std::cout << "Введите основания и высоту трапеции: ";
            std::cin >> a >> b >> h;
            figures.add(new Trapezoid(a, b, h, "Trapezoid"));
        } 
        else if (type == 3) {
            double d1, d2;
            std::cout << "Введите диагонали ромба: ";
            std::cin >> d1 >> d2;
            figures.add(new Rhombus(d1, d2, "Rhombus"));
        } 
        else {
            std::cout << "Неверный тип фигуры.\n";
            --i;
        }
    }

    std::cout << "\nСписок фигур:\n";
    figures.printAll();

    std::cout << "\nСуммарная площадь всех фигур: " << figures.totalArea() << "\n";

    std::cout << "\nВведите индекс фигуры для удаления: ";
    int index;
    std::cin >> index;
    try {
        figures.remove(index);
        std::cout << "Фигура удалена.\n";
    } catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }

    std::cout << "\nОбновленный список фигур:\n";
    figures.printAll();

    std::cout << "\nОбновленная суммарная площадь: " << figures.totalArea() << "\n";

    return 0;
}

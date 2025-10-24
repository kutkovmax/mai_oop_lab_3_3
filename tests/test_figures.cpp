#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include <cmath>
#include "../include/rectangle.h"
#include "../include/rhombus.h"
#include "../include/trapezoid.h"
#include "../include/figure_array.h"

// ========== RECTANGLE TESTS ==========

TEST(Rectangle, ConstructorAndBasicProperties) {
    Rectangle r(4, 2, "Test Rectangle");
    
    // Тест площади
    EXPECT_NEAR(static_cast<double>(r), 8.0, 1e-6);
    
    // Тест центра
    auto center = r.computeCenter();
    EXPECT_NEAR(center.first, 2.0, 1e-6);  // width/2
    EXPECT_NEAR(center.second, 1.0, 1e-6); // height/2
}

TEST(Rectangle, CopyConstructor) {
    Rectangle r1(3, 5, "Original");
    Rectangle r2(r1);
    
    EXPECT_TRUE(r2.equals(r1));
    EXPECT_NEAR(static_cast<double>(r2), 15.0, 1e-6);
}

TEST(Rectangle, MoveConstructor) {
    Rectangle r1(6, 4, "Move Test");
    Rectangle r2(std::move(r1));
    
    EXPECT_NEAR(static_cast<double>(r2), 24.0, 1e-6);
    EXPECT_NEAR(static_cast<double>(r1), 0.0, 1e-6); // После перемещения должно быть 0
}

TEST(Rectangle, CopyAssignment) {
    Rectangle r1(2, 3, "Original");
    Rectangle r2(1, 1, "Target");
    
    r2 = r1;
    EXPECT_TRUE(r2.equals(r1));
    EXPECT_NEAR(static_cast<double>(r2), 6.0, 1e-6);
}

TEST(Rectangle, MoveAssignment) {
    Rectangle r1(5, 7, "Source");
    Rectangle r2(1, 1, "Target");
    
    r2 = std::move(r1);
    EXPECT_NEAR(static_cast<double>(r2), 35.0, 1e-6);
    EXPECT_NEAR(static_cast<double>(r1), 0.0, 1e-6);
}

TEST(Rectangle, Equality) {
    Rectangle r1(4, 3, "Rect1");
    Rectangle r2(4, 3, "Rect2");
    Rectangle r3(3, 4, "Rect3");
    
    EXPECT_TRUE(r1.equals(r2));
    EXPECT_FALSE(r1.equals(r3));
}

TEST(Rectangle, Clone) {
    Rectangle r1(7, 8, "Clone Test");
    std::unique_ptr<Figure> clone(r1.clone());
    
    EXPECT_TRUE(r1.equals(*clone));
    EXPECT_NEAR(static_cast<double>(*clone), 56.0, 1e-6);
}

TEST(Rectangle, OutputOperator) {
    Rectangle r(3, 4, "Output Test");
    std::stringstream ss;
    ss << r;
    
    std::string output = ss.str();
    EXPECT_TRUE(output.find("(0,0)") != std::string::npos);
    EXPECT_TRUE(output.find("(3,0)") != std::string::npos);
    EXPECT_TRUE(output.find("(3,4)") != std::string::npos);
    EXPECT_TRUE(output.find("(0,4)") != std::string::npos);
}

TEST(Rectangle, InputOperator) {
    Rectangle r;
    std::stringstream ss("5 6");
    ss >> r;
    
    EXPECT_NEAR(static_cast<double>(r), 30.0, 1e-6);
}

// ========== TRAPEZOID TESTS ==========

TEST(Trapezoid, ConstructorAndBasicProperties) {
    Trapezoid t(6, 4, 3, "Test Trapezoid");
    
    // Тест площади: (a + b) * h / 2 = (6 + 4) * 3 / 2 = 15
    EXPECT_NEAR(static_cast<double>(t), 15.0, 1e-6);
    
    // Тест центра
    auto center = t.computeCenter();
    EXPECT_NEAR(center.first, 2.5, 1e-6);  // (a + b) / 4 = (6 + 4) / 4 = 2.5
    EXPECT_NEAR(center.second, 1.5, 1e-6); // height / 2 = 3 / 2 = 1.5
}

TEST(Trapezoid, CopyConstructor) {
    Trapezoid t1(8, 2, 4, "Original");
    Trapezoid t2(t1);
    
    EXPECT_TRUE(t2.equals(t1));
    EXPECT_NEAR(static_cast<double>(t2), 20.0, 1e-6);
}

TEST(Trapezoid, MoveConstructor) {
    Trapezoid t1(10, 6, 5, "Move Test");
    Trapezoid t2(std::move(t1));
    
    EXPECT_NEAR(static_cast<double>(t2), 40.0, 1e-6);
    EXPECT_NEAR(static_cast<double>(t1), 0.0, 1e-6);
}

TEST(Trapezoid, CopyAssignment) {
    Trapezoid t1(5, 3, 2, "Original");
    Trapezoid t2(1, 1, 1, "Target");
    
    t2 = t1;
    EXPECT_TRUE(t2.equals(t1));
    EXPECT_NEAR(static_cast<double>(t2), 8.0, 1e-6);
}

TEST(Trapezoid, MoveAssignment) {
    Trapezoid t1(7, 5, 3, "Source");
    Trapezoid t2(1, 1, 1, "Target");
    
    t2 = std::move(t1);
    EXPECT_NEAR(static_cast<double>(t2), 18.0, 1e-6);
    EXPECT_NEAR(static_cast<double>(t1), 0.0, 1e-6);
}

TEST(Trapezoid, Equality) {
    Trapezoid t1(6, 4, 3, "Trap1");
    Trapezoid t2(6, 4, 3, "Trap2");
    Trapezoid t3(4, 6, 3, "Trap3");
    
    EXPECT_TRUE(t1.equals(t2));
    EXPECT_FALSE(t1.equals(t3));
}

TEST(Trapezoid, Clone) {
    Trapezoid t1(9, 3, 6, "Clone Test");
    std::unique_ptr<Figure> clone(t1.clone());
    
    EXPECT_TRUE(t1.equals(*clone));
    EXPECT_NEAR(static_cast<double>(*clone), 36.0, 1e-6);
}

TEST(Trapezoid, OutputOperator) {
    Trapezoid t(6, 4, 3, "Output Test");
    std::stringstream ss;
    ss << t;
    
    std::string output = ss.str();
    EXPECT_TRUE(output.find("(0,0)") != std::string::npos);
    EXPECT_TRUE(output.find("(6,0)") != std::string::npos);
    EXPECT_TRUE(output.find("(5,3)") != std::string::npos);
    EXPECT_TRUE(output.find("(1,3)") != std::string::npos);
}

TEST(Trapezoid, InputOperator) {
    Trapezoid t;
    std::stringstream ss("8 4 5");
    ss >> t;
    
    EXPECT_NEAR(static_cast<double>(t), 30.0, 1e-6);
}

// ========== RHOMBUS TESTS ==========

TEST(Rhombus, ConstructorAndBasicProperties) {
    Rhombus r(4, 6, "Test Rhombus");
    
    // Тест площади: d1 * d2 / 2 = 4 * 6 / 2 = 12
    EXPECT_NEAR(static_cast<double>(r), 12.0, 1e-6);
    
    // Тест центра
    auto center = r.computeCenter();
    EXPECT_NEAR(center.first, 2.0, 1e-6);  // d1 / 2 = 4 / 2 = 2
    EXPECT_NEAR(center.second, 3.0, 1e-6); // d2 / 2 = 6 / 2 = 3
}

TEST(Rhombus, CopyConstructor) {
    Rhombus r1(5, 8, "Original");
    Rhombus r2(r1);
    
    EXPECT_TRUE(r2.equals(r1));
    EXPECT_NEAR(static_cast<double>(r2), 20.0, 1e-6);
}

TEST(Rhombus, MoveConstructor) {
    Rhombus r1(6, 10, "Move Test");
    Rhombus r2(std::move(r1));
    
    EXPECT_NEAR(static_cast<double>(r2), 30.0, 1e-6);
    EXPECT_NEAR(static_cast<double>(r1), 0.0, 1e-6);
}

TEST(Rhombus, CopyAssignment) {
    Rhombus r1(3, 7, "Original");
    Rhombus r2(1, 1, "Target");
    
    r2 = r1;
    EXPECT_TRUE(r2.equals(r1));
    EXPECT_NEAR(static_cast<double>(r2), 10.5, 1e-6);
}

TEST(Rhombus, MoveAssignment) {
    Rhombus r1(4, 9, "Source");
    Rhombus r2(1, 1, "Target");
    
    r2 = std::move(r1);
    EXPECT_NEAR(static_cast<double>(r2), 18.0, 1e-6);
    EXPECT_NEAR(static_cast<double>(r1), 0.0, 1e-6);
}

TEST(Rhombus, Equality) {
    Rhombus r1(4, 6, "Rho1");
    Rhombus r2(4, 6, "Rho2");
    Rhombus r3(6, 4, "Rho3");
    
    EXPECT_TRUE(r1.equals(r2));
    EXPECT_FALSE(r1.equals(r3));
}

TEST(Rhombus, Clone) {
    Rhombus r1(8, 12, "Clone Test");
    std::unique_ptr<Figure> clone(r1.clone());
    
    EXPECT_TRUE(r1.equals(*clone));
    EXPECT_NEAR(static_cast<double>(*clone), 48.0, 1e-6);
}

TEST(Rhombus, OutputOperator) {
    Rhombus r(4, 6, "Output Test");
    std::stringstream ss;
    ss << r;
    
    std::string output = ss.str();
    EXPECT_TRUE(output.find("(0,3)") != std::string::npos);
    EXPECT_TRUE(output.find("(2,0)") != std::string::npos);
    EXPECT_TRUE(output.find("(4,3)") != std::string::npos);
    EXPECT_TRUE(output.find("(2,6)") != std::string::npos);
}

TEST(Rhombus, InputOperator) {
    Rhombus r;
    std::stringstream ss("5 8");
    ss >> r;
    
    EXPECT_NEAR(static_cast<double>(r), 20.0, 1e-6);
}

// ========== FIGURE ARRAY TESTS ==========

TEST(FigureArray, DefaultConstructor) {
    FigureArray arr;
    EXPECT_EQ(arr.size(), 0);
    EXPECT_NEAR(arr.totalArea(), 0.0, 1e-6);
}

TEST(FigureArray, AddFigures) {
    FigureArray arr;
    
    // Добавляем фигуры
    arr.add(new Rectangle(3, 4, "Rect"));
    arr.add(new Trapezoid(6, 4, 3, "Trap"));
    arr.add(new Rhombus(4, 6, "Rho"));
    
    EXPECT_EQ(arr.size(), 3);
    EXPECT_NEAR(arr.totalArea(), 12.0 + 15.0 + 12.0, 1e-6);
}

TEST(FigureArray, CopyConstructor) {
    FigureArray arr1;
    arr1.add(new Rectangle(2, 3, "Rect"));
    arr1.add(new Rhombus(4, 5, "Rho"));
    
    FigureArray arr2(arr1);
    
    EXPECT_EQ(arr2.size(), 2);
    EXPECT_NEAR(arr2.totalArea(), 6.0 + 10.0, 1e-6);
    EXPECT_TRUE(arr2.equals(arr1));
}

TEST(FigureArray, MoveConstructor) {
    FigureArray arr1;
    arr1.add(new Rectangle(3, 4, "Rect"));
    arr1.add(new Trapezoid(5, 3, 2, "Trap"));
    
    FigureArray arr2(std::move(arr1));
    
    EXPECT_EQ(arr2.size(), 2);
    EXPECT_NEAR(arr2.totalArea(), 12.0 + 8.0, 1e-6);
    EXPECT_EQ(arr1.size(), 0);
}

TEST(FigureArray, RemoveFigure) {
    FigureArray arr;
    arr.add(new Rectangle(2, 3, "Rect1"));
    arr.add(new Trapezoid(4, 2, 3, "Trap"));
    arr.add(new Rhombus(3, 4, "Rho"));
    
    EXPECT_EQ(arr.size(), 3);
    
    // Удаляем средний элемент
    arr.remove(1);
    EXPECT_EQ(arr.size(), 2);
    EXPECT_NEAR(arr.totalArea(), 6.0 + 6.0, 1e-6);
    
    // Удаляем первый элемент
    arr.remove(0);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_NEAR(arr.totalArea(), 6.0, 1e-6);
}

TEST(FigureArray, RemoveOutOfRange) {
    FigureArray arr;
    arr.add(new Rectangle(1, 1, "Rect"));
    
    EXPECT_THROW(arr.remove(5), std::out_of_range);
    EXPECT_THROW(arr.remove(1), std::out_of_range);
}

TEST(FigureArray, PolymorphicBehavior) {
    FigureArray arr;
    
    // Добавляем разные типы фигур через указатели на базовый класс
    Figure* rect = new Rectangle(4, 5, "Rect");
    Figure* trap = new Trapezoid(6, 4, 3, "Trap");
    Figure* rho = new Rhombus(4, 6, "Rho");
    
    arr.add(rect);
    arr.add(trap);
    arr.add(rho);
    
    EXPECT_EQ(arr.size(), 3);
    
    // Проверяем полиморфное поведение через totalArea
    double totalArea = arr.totalArea();
    EXPECT_GT(totalArea, 0.0);
    
    EXPECT_NEAR(totalArea, 20.0 + 15.0 + 12.0, 1e-6);
}

TEST(FigureArray, PrintAll) {
    FigureArray arr;
    arr.add(new Rectangle(2, 3, "Rect"));
    arr.add(new Rhombus(4, 4, "Rho"));
    
    // Тестируем, что printAll не падает
    testing::internal::CaptureStdout();
    arr.printAll();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(output.find("Rect") != std::string::npos);
    EXPECT_TRUE(output.find("Rho") != std::string::npos);
}

// ========== EDGE CASES AND ERROR HANDLING ==========

TEST(EdgeCases, ZeroDimensions) {
    Rectangle r(0, 0, "Zero Rect");
    EXPECT_NEAR(static_cast<double>(r), 0.0, 1e-6);
    
    Trapezoid t(0, 0, 0, "Zero Trap");
    EXPECT_NEAR(static_cast<double>(t), 0.0, 1e-6);
    
    Rhombus rho(0, 0, "Zero Rho");
    EXPECT_NEAR(static_cast<double>(rho), 0.0, 1e-6);
}

TEST(EdgeCases, NegativeDimensions) {
    // Тестируем с отрицательными размерами (должны работать как положительные)
    Rectangle r(-3, -4, "Neg Rect");
    EXPECT_NEAR(static_cast<double>(r), 12.0, 1e-6);
    
    Trapezoid t(-6, -4, -3, "Neg Trap");
    EXPECT_NEAR(static_cast<double>(t), 15.0, 1e-6);
    
    Rhombus rho(-4, -6, "Neg Rho");
    EXPECT_NEAR(static_cast<double>(rho), 12.0, 1e-6);
}

TEST(EdgeCases, VerySmallNumbers) {
    Rectangle r(1e-6, 1e-6, "Tiny Rect");
    EXPECT_NEAR(static_cast<double>(r), 1e-12, 1e-18);
    
    Trapezoid t(1e-6, 1e-6, 1e-6, "Tiny Trap");
    EXPECT_NEAR(static_cast<double>(t), 1e-12, 1e-18);
    
    Rhombus rho(1e-6, 1e-6, "Tiny Rho");
    EXPECT_NEAR(static_cast<double>(rho), 5e-13, 1e-18);
}

TEST(EdgeCases, VeryLargeNumbers) {
    Rectangle r(1e6, 1e6, "Huge Rect");
    EXPECT_NEAR(static_cast<double>(r), 1e12, 1e6);
    
    Trapezoid t(1e6, 1e6, 1e6, "Huge Trap");
    EXPECT_NEAR(static_cast<double>(t), 1e12, 1e6);
    
    Rhombus rho(1e6, 1e6, "Huge Rho");
    EXPECT_NEAR(static_cast<double>(rho), 5e11, 1e6);
}

// ========== COMPREHENSIVE INTEGRATION TESTS ==========

TEST(Integration, AllFiguresInArray) {
    FigureArray arr;
    
    // Добавляем по одной фигуре каждого типа
    arr.add(new Rectangle(3, 4, "Rect1"));
    arr.add(new Trapezoid(5, 3, 2, "Trap1"));
    arr.add(new Rhombus(4, 6, "Rho1"));
    arr.add(new Rectangle(2, 5, "Rect2"));
    arr.add(new Trapezoid(8, 4, 3, "Trap2"));
    
    EXPECT_EQ(arr.size(), 5);
    
    // Проверяем общую площадь
    double expectedTotal = 12.0 + 8.0 + 12.0 + 10.0 + 18.0;
    EXPECT_NEAR(arr.totalArea(), expectedTotal, 1e-6);
    
    // Проверяем, что все фигуры можно распечатать
    testing::internal::CaptureStdout();
    arr.printAll();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_FALSE(output.empty());
    EXPECT_TRUE(output.find("Rectangle") != std::string::npos);
    EXPECT_TRUE(output.find("Trapezoid") != std::string::npos);
    EXPECT_TRUE(output.find("Rhombus") != std::string::npos);
}

TEST(Integration, CopyAndModifyArray) {
    FigureArray arr1;
    arr1.add(new Rectangle(2, 3, "Rect"));
    arr1.add(new Rhombus(4, 5, "Rho"));
    
    // Копируем массив
    FigureArray arr2 = arr1;
    
    // Модифицируем оригинал
    arr1.add(new Trapezoid(3, 2, 4, "Trap"));
    
    // Проверяем, что копия не изменилась
    EXPECT_EQ(arr1.size(), 3);
    EXPECT_EQ(arr2.size(), 2);
    EXPECT_NEAR(arr1.totalArea(), 6.0 + 10.0 + 10.0, 1e-6);
    EXPECT_NEAR(arr2.totalArea(), 6.0 + 10.0, 1e-6);
}

TEST(Integration, MoveAndModifyArray) {
    FigureArray arr1;
    arr1.add(new Rectangle(3, 4, "Rect"));
    arr1.add(new Trapezoid(5, 3, 2, "Trap"));
    
    // Перемещаем массив
    FigureArray arr2 = std::move(arr1);
    
    // Проверяем, что данные переместились
    EXPECT_EQ(arr1.size(), 0);
    EXPECT_EQ(arr2.size(), 2);
    EXPECT_NEAR(arr2.totalArea(), 12.0 + 8.0, 1e-6);
    
    // Добавляем в перемещенный массив
    arr2.add(new Rhombus(4, 6, "Rho"));
    EXPECT_EQ(arr2.size(), 3);
    EXPECT_NEAR(arr2.totalArea(), 12.0 + 8.0 + 12.0, 1e-6);
}

// ========== DEMONSTRATION TESTS ==========

TEST(Demonstration, UserInputSimulation) {
    // Симулируем пользовательский ввод для демонстрации
    FigureArray figures;
    
    // Добавляем фигуры как в main.cpp
    figures.add(new Rectangle(4, 5, "Rectangle"));
    figures.add(new Trapezoid(6, 4, 3, "Trapezoid"));
    figures.add(new Rhombus(4, 6, "Rhombus"));
    
    EXPECT_EQ(figures.size(), 3);
    
    // Проверяем, что все фигуры добавлены корректно
    double totalArea = figures.totalArea();
    EXPECT_NEAR(totalArea, 20.0 + 15.0 + 12.0, 1e-6);
    
    // Тестируем удаление фигуры
    figures.remove(1); // Удаляем трапецию
    EXPECT_EQ(figures.size(), 2);
    EXPECT_NEAR(figures.totalArea(), 20.0 + 12.0, 1e-6);
    
    // Тестируем обработку ошибки при удалении
    EXPECT_THROW(figures.remove(5), std::out_of_range);
}

TEST(Demonstration, AllRequiredFeatures) {
    FigureArray arr;
    
    // 1. Добавляем фигуры всех типов
    arr.add(new Rectangle(3, 4, "Rect1"));
    arr.add(new Trapezoid(5, 3, 2, "Trap1"));
    arr.add(new Rhombus(4, 6, "Rho1"));
    arr.add(new Rectangle(2, 5, "Rect2"));
    
    // 2. Проверяем вычисление геометрического центра для каждой фигуры
    // Создаем отдельные фигуры для тестирования
    Rectangle testRect(3, 4, "Test");
    Trapezoid testTrap(5, 3, 2, "Test");
    Rhombus testRho(4, 6, "Test");
    
    auto centerRect = testRect.computeCenter();
    auto centerTrap = testTrap.computeCenter();
    auto centerRho = testRho.computeCenter();
    
    EXPECT_GE(centerRect.first, 0.0);
    EXPECT_GE(centerRect.second, 0.0);
    EXPECT_GE(centerTrap.first, 0.0);
    EXPECT_GE(centerTrap.second, 0.0);
    EXPECT_GE(centerRho.first, 0.0);
    EXPECT_GE(centerRho.second, 0.0);
    
    // 3. Проверяем вывод координат вершин через перегрузку оператора <<
    std::stringstream ss1, ss2, ss3;
    ss1 << testRect;
    ss2 << testTrap;
    ss3 << testRho;
    
    EXPECT_FALSE(ss1.str().empty());
    EXPECT_FALSE(ss2.str().empty());
    EXPECT_FALSE(ss3.str().empty());
    
    // 4. Проверяем чтение из потока через перегрузку оператора >>
    Rectangle rect;
    std::stringstream input("7 8");
    input >> rect;
    EXPECT_NEAR(static_cast<double>(rect), 56.0, 1e-6);
    
    // 5. Проверяем вычисление площади через перегрузку оператора приведения к double
    double totalArea = arr.totalArea();
    EXPECT_NEAR(totalArea, 12.0 + 8.0 + 12.0 + 10.0, 1e-6);
    
    // 6. Проверяем переопределенные операции копирования, перемещения и сравнения
    FigureArray copy = arr;
    EXPECT_TRUE(copy.equals(arr));
    EXPECT_EQ(copy.size(), arr.size());
    
    FigureArray moved = std::move(copy);
    EXPECT_EQ(moved.size(), arr.size());
    EXPECT_EQ(copy.size(), 0);
    
    // 7. Проверяем вычисление общей площади фигур в массиве
    EXPECT_NEAR(arr.totalArea(), 42.0, 1e-6);
    
    // 8. Проверяем удаление фигуры по индексу
    arr.remove(0);
    EXPECT_EQ(arr.size(), 3);
    EXPECT_NEAR(arr.totalArea(), 30.0, 1e-6);
}

#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <iostream>
#include <utility>

class Rhombus : public Figure
{
public:
    Rhombus() = default;
    Rhombus(double diag1, double diag2, std::string_view description);

    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;
    ~Rhombus() override = default;

    std::pair<double, double> computeCenter() const override;
    void printVertices(std::ostream& os) const override;
    operator double() const override;
    bool equals(const Figure& other) const override;
    Figure* clone() const override;

    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;

    friend std::istream& operator>>(std::istream& is, Rhombus& r);
    friend std::ostream& operator<<(std::ostream& os, const Rhombus& r);

private:
    double m_diag1{0.0};
    double m_diag2{0.0};
};

#endif // RHOMBUS_H

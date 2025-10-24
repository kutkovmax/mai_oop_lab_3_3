#include "rhombus.h"
#include <iomanip>

Rhombus::Rhombus(double diag1, double diag2, std::string_view description)
    : Figure(description), m_diag1(diag1), m_diag2(diag2) {}

Rhombus::Rhombus(const Rhombus& other)
    : Figure(other), m_diag1(other.m_diag1), m_diag2(other.m_diag2) {}

Rhombus::Rhombus(Rhombus&& other) noexcept
    : Figure(std::move(other)), m_diag1(other.m_diag1), m_diag2(other.m_diag2) 
{
    other.m_diag1 = 0; other.m_diag2 = 0;
}

std::pair<double, double> Rhombus::computeCenter() const {
    return { m_diag1 / 2.0, m_diag2 / 2.0 };
}

void Rhombus::printVertices(std::ostream& os) const {
    double x1 = 0, y1 = m_diag2/2.0;
    double x2 = m_diag1/2.0, y2 = 0;
    double x3 = m_diag1, y3 = m_diag2/2.0;
    double x4 = m_diag1/2.0, y4 = m_diag2;
    os << "(" << x1 << "," << y1 << "), (" << x2 << "," << y2 << "), ("
       << x3 << "," << y3 << "), (" << x4 << "," << y4 << ")";
}

Rhombus::operator double() const {
    return 0.5 * m_diag1 * m_diag2;
}

bool Rhombus::equals(const Figure& other) const {
    const Rhombus* r = dynamic_cast<const Rhombus*>(&other);
    return r && m_diag1 == r->m_diag1 && m_diag2 == r->m_diag2;
}

Figure* Rhombus::clone() const {
    return new Rhombus(*this);
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        m_diag1 = other.m_diag1;
        m_diag2 = other.m_diag2;
    }
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        m_diag1 = other.m_diag1;
        m_diag2 = other.m_diag2;
        other.m_diag1 = 0; other.m_diag2 = 0;
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Rhombus& r) {
    return is >> r.m_diag1 >> r.m_diag2;
}

std::ostream& operator<<(std::ostream& os, const Rhombus& r) {
    r.printVertices(os);
    return os;
}

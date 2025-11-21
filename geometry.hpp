#include <cmath>

const double EPSILON = 1e-9;

struct Double {
    double value;

    bool is_equal(Double other)
    {
        double difference = value - other.value;
        double maximum = std::max(std::fabs(value), std::fabs(other.value));

        if (maximum > 1) {
            difference /= maximum;
        }

        return std::fabs(difference) < EPSILON;
    }

    bool is_less(Double other)
    {
        return (value < other.value) && !is_equal(other);
    }
};

enum class Kind {
    Line,
    Ray,
    Segment
};

struct Point2D {
    Double x, y;

    Point2D sub(Point2D other)
    {
        Double newX = { x.value - other.x.value };
        Double newY { y.value - other.y.value };
        return Point2D { newX, newY };
    }

    Point2D add(Point2D other)
    {
        Double newX = { x.value + other.x.value };
        Double newY { y.value + other.y.value };
        return Point2D { newX, newY };
    }

    Double distance(Point2D other)
    {
        double dx = { x.value - other.x.value };
        double dy = { y.value - other.y.value };
        return Double { std::sqrt(dx * dx + dy * dy) };
    }
};

struct Geometry {
    Kind kind;
    Point2D begin, end;
};

Double distance(Geometry g1, Geometry g2) {
    double dx1 = g1.end.x.value - g1.begin.x.value;
    double dy1 = g1.end.y.value - g1.begin.y.value;

    double dx2 = g2.end.x.value - g2.begin.x.value;
    double dy2 = g2.end.y.value - g2.begin.y.value;

    double pseydo_vect_proizv = dx1 * dy2 - dy1 * dx2;

    if (std::abs(pseydo_vect_proizv) > EPSILON) {
        return Double{ 0.0 };
    }

    double dx_diff = g1.begin.x.value - g2.begin.x.value;
    double dy_diff = g1.begin.y.value - g2.begin.y.value;

    double area = std::abs(dx_diff * dy2 - dy_diff * dx2);

    double length2 = std::sqrt(dx2 * dx2 + dy2 * dy2);

    return Double{ area / length2 };
}

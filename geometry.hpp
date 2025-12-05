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

Double dot(Point2D a, Point2D b)
{
    return Double{ a.x.value * b.x.value + a.y.value * b.y.value };
}

Double cross(Point2D a, Point2D b)
{
    return Double{ a.x.value * b.x.value - a.y.value * b.y.value };
}

Double norm2(Point2D a)
{
    return Double{ a.x.value * a.x.value + a.y.value * a.y.value };
}

Point2D mul(Point2D a, double k)
{
    return Point2D{ Double{ a.x.value * k }, Double{ a.y.value * k } };
}

bool between(Double t)
{
    return (!t.is_less(Double{0.0}) && !Double{1.0}.is_less(t));
}


bool project_on_line(Point2D A, Point2D B, Point2D P, double &t_out)
{
    Point2D AB = B.sub(A);
    Point2D AP = P.sub(A);
    double ab2 = AB.x.value * AB.x.value + AB.y.value * AB.y.value;

    if (ab2 < EPSILON) {
        t_out = 0;
        return false;
    }

    t_out = (AP.x.value * AB.x.value + AP.y.value * AB.y.value) / ab2;
    return true;
}


bool valid_t(double t, Kind k)
{
    if (k == Kind::Line) return true;
    if (k == Kind::Ray)  return t >= -EPSILON;
    if (k == Kind::Segment) return t >= -EPSILON && t <= 1.0 + EPSILON;
    return false;
}


Double point_to_geometry(Point2D P, Geometry g)
{
    Point2D A = g.begin;
    Point2D B = g.end;

    double t;
    if (!project_on_line(A, B, P, t))
        return P.distance(A);

    if (!valid_t(t, g.kind)) {
        if (g.kind == Kind::Ray)
            return P.distance(A);
        if (g.kind == Kind::Segment)
            return (P.distance(A).value < P.distance(B).value ? P.distance(A) : P.distance(B));
    }

    Point2D proj = Point2D{
        Double{ A.x.value + (B.x.value - A.x.value) * t },
        Double{ A.y.value + (B.y.value - A.y.value) * t }
    };

    return P.distance(proj);
}


bool infinite_intersect(Point2D A, Point2D B, Point2D C, Point2D D, double &t1, double &t2)
{
    double x1 = A.x.value, y1 = A.y.value;
    double x2 = B.x.value, y2 = B.y.value;
    double x3 = C.x.value, y3 = C.y.value;
    double x4 = D.x.value, y4 = D.y.value;

    double dx1 = x2 - x1, dy1 = y2 - y1;
    double dx2 = x4 - x3, dy2 = y4 - y3;

    double det = dx1 * dy2 - dy1 * dx2;
    if (std::fabs(det) < EPSILON) return false; 

    t1 = ((x3 - x1) * dy2 - (y3 - y1) * dx2) / det;
    t2 = ((x3 - x1) * dy1 - (y3 - y1) * dx1) / det;

    return true;
}

Double distance(Geometry g1, Geometry g2)
{
   Point2D A = g1.begin, B = g1.end;
    Point2D C = g2.begin, D = g2.end;

    
    double t1, t2;
    if (infinite_intersect(A, B, C, D, t1, t2)) {
        if (valid_t(t1, g1.kind) && valid_t(t2, g2.kind))
            return Double{ 0.0 };
    }


    Double d1 = point_to_geometry(A, g2);
    Double d2 = point_to_geometry(B, g2);
    Double d3 = point_to_geometry(C, g1);
    Double d4 = point_to_geometry(D, g1);

    Double mn = d1;
    if (d2.is_less(mn)) mn = d2;
    if (d3.is_less(mn)) mn = d3;
    if (d4.is_less(mn)) mn = d4;

    return mn;
}

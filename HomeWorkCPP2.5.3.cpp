#include <iostream>
#include <locale.h>

class Figure {
public:
    int get_quanfig() {
        return _quanfig;
    }
    std::string get_name() {
        return _name;
    }
    virtual bool check() {
        if (_quanfig == 0) {
            return true;
        } else {
            return false;
        }
    }
    virtual void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        } else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << "\n" << std::endl;
    }
    Figure() :Figure("Фигура:", 0) {}
protected:
    Figure(std::string name_, int quanfig_) {
        _quanfig = quanfig_;
        _name = name_;
    }
private:
    int _quanfig = 0;
    std::string _name;
};  

class Triangle :public Figure {
public:
    int get_side_a() {
        return _side_a;
    }
    int get_side_b() {
        return _side_b;
    }
    int get_side_c() {
        return _side_c;
    }
    int get_angle_a() {
        return _angle_a;
    }
    int get_angle_b() {
        return _angle_b;
    }
    int get_angle_c() {
        return _angle_c;
    }
    bool check() override {
        if (get_angle_a() + get_angle_b() + get_angle_c() == 180 && get_quanfig() == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() override {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << "\n" << std::endl;
    }
    Triangle() :Triangle("Треугольник:", 3, 10, 20, 30, 50, 60, 70) {}
protected:
    Triangle(std::string name_, int quanfig_, int side_a_, int side_b_, int side_c_, int angle_a_, int angle_b_, int angle_c_) :Figure( name_, quanfig_) {
        _side_a = side_a_;
        _side_b = side_b_;
        _side_c = side_c_;
        _angle_a = angle_a_;
        _angle_b = angle_b_;
        _angle_c = angle_c_;
    }
private:
    int _side_a = 0;
    int _side_b = 0;
    int _side_c = 0;
    int _angle_a = 0;
    int _angle_b = 0;
    int _angle_c = 0;
};

class TriangleRight :public Triangle {
public:
    bool check() override {
        if (get_angle_c() == 90 && get_quanfig() == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << "\n" << std::endl;
    }
    TriangleRight() :TriangleRight("Прямоугольный треугольник:", 3, 10, 20, 30, 30, 60) {}
private:
    TriangleRight(std::string name_, int quanfig_, int side_a_, int side_b_, int side_c_, int angle_a_, int angle_b_) :Triangle(name_, quanfig_, side_a_, side_b_, side_c_, angle_a_, angle_b_, 90) {
    }
};

class TriangleIsos :public Triangle {
public:
    bool check() override {
        if (get_side_a() == get_side_c() && get_angle_a() == get_angle_c() && get_quanfig() == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << "\n" << std::endl;
    }
    TriangleIsos() :TriangleIsos("Равнобедренный треугольник:", 3, 10, 20, 50, 60) {}
private:
    TriangleIsos(std::string name_, int quanfig_, int side_a_c_, int side_b_, int angle_a_c_, int angle_b_) :Triangle(name_, quanfig_, side_a_c_, side_b_, side_a_c_, angle_a_c_, angle_b_, angle_a_c_) {
    }
};

class TriangleEquil :public Triangle {
public:
    bool check() override {
        if (get_side_a() == get_side_b() && get_side_a() == get_side_c() && get_angle_a() == get_angle_b() && get_angle_a() == get_angle_c() && get_quanfig() == 3) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << "\n" << std::endl;
    }
    TriangleEquil() :TriangleEquil("Равносторонний треугольник:", 3, 30) {}
private:
    TriangleEquil(std::string name_, int quanfig_, int side_a_b_c_) :Triangle(name_, quanfig_, side_a_b_c_, side_a_b_c_, side_a_b_c_, 60, 60, 60) {
    }
};

class Quadrilateral :public Triangle {
public:
    int get_side_d() {
        return _side_d;
    }
    int get_angle_d() {
        return _angle_d;
    }
    bool check() override {
        if (get_angle_a() + get_angle_b() + get_angle_c() + get_angle_d() == 360 && get_quanfig() == 4) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() override {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << " D=" << get_angle_d() << "\n" << std::endl;
    }
    Quadrilateral() :Quadrilateral("Четырехугольник:", 4, 10, 20, 30, 40, 50, 60, 70, 80) {}
protected:
    Quadrilateral(std::string name_, int quanfig_, int side_a_, int side_b_, int side_c_, int side_d_, int angle_a_, int angle_b_, int angle_c_, int angle_d_) :Triangle(name_, quanfig_, side_a_, side_b_, side_c_, angle_a_, angle_b_, angle_c_) {
        _side_d = side_d_;
        _angle_d = angle_d_;
    }
private:
    int _side_d = 0;
    int _angle_d = 0;
};

class Parallelogram :public Quadrilateral {
public:
    bool check() override {
        if (get_side_a() == get_side_c() && get_side_b() == get_side_d() && get_angle_a() == get_angle_c() && get_angle_b() == get_angle_d() && get_quanfig() == 4) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << " D=" << get_angle_d() << "\n" << std::endl;
    }
    Parallelogram() :Parallelogram("Параллелограмм:",4, 20, 30, 30, 40) {}
protected:
    Parallelogram(std::string name_, int quanfig_, int side_a_c_, int side_b_d_, int angle_a_c_, int angle_b_d_) :Quadrilateral(name_, quanfig_, side_a_c_, side_b_d_, side_a_c_, side_b_d_, angle_a_c_, angle_b_d_, angle_a_c_, angle_b_d_) {
    }
};

class Rhombus :public Parallelogram {
public:
    bool check() override {
        if (get_side_a() == get_side_b() && get_side_a() == get_side_c() && get_side_a() == get_side_d() && get_angle_a() == get_angle_c() && get_angle_b() == get_angle_d() && get_quanfig() == 4) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << " D=" << get_angle_d() << "\n" << std::endl;
    }
    Rhombus() :Rhombus("Ромб:", 4, 30, 30, 40) {}
private:
    Rhombus(std::string name_, int quanfig_, int side_a_b_c_d_, int angle_a_c_, int angle_b_d_) :Parallelogram(name_, quanfig_, side_a_b_c_d_, side_a_b_c_d_, angle_a_c_, angle_b_d_) {
    }
};

class Rectrangle :public Parallelogram {
public:
    bool check() override {
        if (get_side_a() == get_side_c() && get_side_b() == get_side_d() && get_angle_a() == 90 && get_angle_c() == 90 && get_angle_b() == 90 && get_angle_d() == 90 && get_quanfig() == 4) {
            return true;
        }
        else {
            return false;
        } 
    }
    void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << " D=" << get_angle_d() << "\n" << std::endl;
    }
    Rectrangle() :Rectrangle("Прямоугольник:", 4, 10, 20) {}
protected:
    Rectrangle(std::string name_, int quanfig_, int side_a_c_, int side_b_d_) :Parallelogram(name_, quanfig_, side_a_c_, side_b_d_, 90, 90) {
    }
};

class Square :public Rectrangle {
public:
    bool check() override {
        if (get_side_a() == get_side_b() && get_side_a() == get_side_c() && get_side_a() == get_side_d() && get_angle_a() == 90 && get_angle_c() == 90 && get_angle_b() == 90 && get_angle_d() == 90 && get_quanfig() == 4) {
            return true;
        }
        else {
            return false;
        }
    }
    void print_info() {
        std::cout << get_name() << std::endl;
        if (check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << "Количество сторон: " << get_quanfig() << std::endl;
        std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << " d=" << get_side_d() << std::endl;
        std::cout << "Углы: A=" << get_angle_a() << " B=" << get_angle_b() << " C=" << get_angle_c() << " D=" << get_angle_d() << "\n" << std::endl;
    }
    Square() :Square("Квадрат:", 4, 20) {}
private:
    Square(std::string name_, int quanfig_, int side_a_b_c_d_) :Rectrangle(name_, quanfig_, side_a_b_c_d_, side_a_b_c_d_) {
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Figure figure;
    Triangle triangle;
    TriangleRight triangleRight;
    TriangleIsos triangleIsos;
    TriangleEquil triangleEquil;
    Quadrilateral quadrilateral;
    Parallelogram parallelogram;
    Rhombus rhombus;
    Rectrangle rectrangle;
    Square square;
    Figure* par_triangleRight = &triangleRight;
    Figure* par_triangleIsos = &triangleIsos;
    Figure* par_triangleEquil = &triangleEquil;
    Figure* par_parallelogram = &parallelogram;
    Figure* par_rhombus = &rhombus;
    Figure* par_rectrangle = &rectrangle;
    Figure* par_square = &square;
    figure.print_info();
    triangle.print_info();
    par_triangleRight->print_info();
    par_triangleIsos->print_info();
    par_triangleEquil->print_info();
    quadrilateral.print_info();
    par_parallelogram->print_info();
    par_rhombus->print_info();
    par_rectrangle->print_info();
    par_square->print_info();
}
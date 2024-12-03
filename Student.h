#pragma once

#include <iostream>
#include <string>
#include "Grade.h"

class Student {
    std::string m_name{};
    int m_rollNum{};
    int m_papers{};
    double m_marks{};
    double m_total{};
    double m_perc{};
public:

    GradeType getGrade();

    std::string getGradeString(GradeType g);

    Student(const std::string& name, int roll, int papers, double marks, double total, double perc)
        : m_name{ name }, m_rollNum{ roll }, m_papers{ papers }, m_marks{ marks }, m_total{ total }, m_perc{ perc } {

    }

    void print();
};

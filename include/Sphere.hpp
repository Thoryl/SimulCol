#pragma once

#include <vector>
#include <c3ga/Mvec.hpp>
#include "c3gaTools.hpp"

#include "common.hpp"

// Représente une sphère discrétisée centrée en (0, 0, 0) (dans son repère local)
// Son axe vertical est (0, 1, 0) et ses axes transversaux sont (1, 0, 0) et (0, 0, 1)
class Sphere {

public:
    // Constructeur: alloue le tableau de données et construit les attributs des vertex
    Sphere(GLfloat radius, GLsizei discLat, GLsizei discLong):
        m_nVertexCount(0),
        m_radius(radius),
        m_discLat(discLat),
        m_discLong(discLong){
        m_centerPt = c3ga::point(0., -10., 0.);
        build(radius, discLat, discLong); // Construction (voir le .cpp)
    }

    // Alloue et construit les données (implantation dans le .cpp)
    void build(GLfloat radius, GLsizei discLat, GLsizei discLong);

    void translateFrontOrBack(int direction){
        c3ga::Mvec<double> T = (direction * 10) - (0.5 * c3ga::e2<double>() * c3ga::ei<double>());
        m_centerPt = T * m_centerPt * T.inv();
        m_centerPt.roundZero(1e-10);
        std::cout << "X : " << m_centerPt[c3ga::E1] << " Y : " << m_centerPt[c3ga::E2] << " Z : " << m_centerPt[c3ga::E3] << std::endl;
        build(m_radius, m_discLat, m_discLong);
    }

    void translateLeftOrRight(int direction){
        c3ga::Mvec<double> T = (direction * 10) - (0.5 * c3ga::e1<double>() * c3ga::ei<double>());
        m_centerPt = T * m_centerPt * T.inv();
        m_centerPt.roundZero(1e-10);
        std::cout << "X : " << m_centerPt[c3ga::E1] << " Y : " << m_centerPt[c3ga::E2] << " Z : " << m_centerPt[c3ga::E3] << std::endl;
        build(m_radius, m_discLat, m_discLong);
    }

    void translateUpOrDown(int direction){
        c3ga::Mvec<double> T = (direction * 10) - (0.5 * c3ga::e3<double>() * c3ga::ei<double>());
        m_centerPt = T * m_centerPt * T.inv();
        m_centerPt.roundZero(1e-10);
        std::cout << "X : " << m_centerPt[c3ga::E1] << " Y : " << m_centerPt[c3ga::E2] << " Z : " << m_centerPt[c3ga::E3] << std::endl;
        build(m_radius, m_discLat, m_discLong);
    }

    // Renvoit le pointeur vers les données
    const ShapeVertex* getDataPointer() const {
        return &m_Vertices[0];
    }
    
    // Renvoit le nombre de vertex
    GLsizei getVertexCount() const {
        return m_nVertexCount;
    }

private:
    c3ga::Mvec<double> m_centerPt;
    c3ga::Mvec<double> m_sphere;
    std::vector<ShapeVertex> m_Vertices;
    GLsizei m_nVertexCount; // Nombre de sommets
    GLfloat m_radius;
    GLsizei m_discLat;
    GLsizei m_discLong;
};
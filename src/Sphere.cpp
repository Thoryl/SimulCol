#include <cmath>
#include <vector>
#include "../include/common.hpp"
#include "../include/Sphere.hpp"

void Sphere::build(GLfloat r, GLsizei discLat, GLsizei discLong) {
    // Equation paramétrique en (r, phi, theta) de la sphère 
    // avec r >= 0, -PI / 2 <= theta <= PI / 2, 0 <= phi <= 2PI
    //
    // x(r, phi, theta) = r sin(phi) cos(theta)
    // y(r, phi, theta) = r sin(theta)
    // z(r, phi, theta) = r cos(phi) cos(theta)
    //
    // Discrétisation:
    // dPhi = 2PI / discLat, dTheta = PI / discLong
    //
    // x(r, i, j) = r * sin(i * dPhi) * cos(-PI / 2 + j * dTheta)
    // y(r, i, j) = r * sin(-PI / 2 + j * dTheta)
    // z(r, i, j) = r * cos(i * dPhi) * cos(-PI / 2 + j * dTheta)

    auto dualSphere = m_centerPt - ((r*r)/2 * c3ga::ei<double>());

    m_sphere = !dualSphere;

    GLfloat rcpLat = 1.f / discLat, rcpLong = 1.f / discLong;
    GLfloat dPhi = 2 * glm::pi<float>() * rcpLat, dTheta = glm::pi<float>() * rcpLong;
    
    std::vector<ShapeVertex> data;
    
    // Construit l'ensemble des vertex
    for(GLsizei j = 0; j <= discLong; ++j) {
        GLfloat cosTheta = cos(-glm::pi<float>() / 2 + j * dTheta);
        GLfloat sinTheta = sin(-glm::pi<float>() / 2 + j * dTheta);
        
        for(GLsizei i = 0; i <= discLat; ++i) {
            ShapeVertex vertex;
            
            vertex.texCoords.x = i * rcpLat;
            vertex.texCoords.y = 1.f - j * rcpLong;

            vertex.normal.x = sin(i * dPhi) * cosTheta;
            vertex.normal.y = sinTheta;
            vertex.normal.z = cos(i * dPhi) * cosTheta;
            
            vertex.position = r * vertex.normal + glm::vec3(m_centerPt[c3ga::E1], m_centerPt[c3ga::E3], m_centerPt[c3ga::E2]);
            
            data.push_back(vertex);
        }
    }

    m_nVertexCount = discLat * discLong * 6;

    m_Vertices.clear();

    // Construit les vertex finaux en regroupant les données en triangles:
    // Pour une longitude donnée, les deux triangles formant une face sont de la forme:
    // (i, i + 1, i + discLat + 1), (i, i + discLat + 1, i + discLat)
    // avec i sur la bande correspondant à la longitude
    for(GLsizei j = 0; j < discLong; ++j) {
        GLsizei offset = j * (discLat + 1);
        for(GLsizei i = 0; i < discLat; ++i) {
            m_Vertices.push_back(data[offset + i]);
            m_Vertices.push_back(data[offset + (i + 1)]);
            m_Vertices.push_back(data[offset + discLat + 1 + (i + 1)]);
            m_Vertices.push_back(data[offset + i]);
            m_Vertices.push_back(data[offset + discLat + 1 + (i + 1)]);
            m_Vertices.push_back(data[offset + i + discLat + 1]);
        }
    }
    
    // Attention ! dans cette implantation on duplique beaucoup de sommets. Une meilleur stratégie est de passer
    // par un Index Buffer Object, que nous verrons dans les prochains TDs
}

bool Sphere::willCollide(c3ga::Mvec<double> centerPt, std::vector<c3ga::Mvec<double>> circles) {
    auto dualSphere = centerPt - ((m_radius*m_radius)/2 * c3ga::ei<double>());
    c3ga::Mvec<double> tmpSphere = !dualSphere;

    std::vector<c3ga::Mvec<double>> boundPoints;

    c3ga::Mvec<double> T = -1 - (0.5 * c3ga::e2<double>() * c3ga::ei<double>());
    c3ga::Mvec<double> pt = T * centerPt * T.inv();
    boundPoints.push_back(pt);

    T = 1 - (0.5 * c3ga::e1<double>() * c3ga::ei<double>());
    pt = T * centerPt * T.inv();
    boundPoints.push_back(pt);

    T = 1 - (0.5 * c3ga::e2<double>() * c3ga::ei<double>());
    pt = T * centerPt * T.inv();
    boundPoints.push_back(pt);

    T = -1 - (0.5 * c3ga::e1<double>() * c3ga::ei<double>());
    pt = T * centerPt * T.inv();
    boundPoints.push_back(pt);

    T = -1 - (0.5 * c3ga::e3<double>() * c3ga::ei<double>());
    pt = T * centerPt * T.inv();
    boundPoints.push_back(pt);

    T = 1 - (0.5 * c3ga::e3<double>() * c3ga::ei<double>());
    pt = T * centerPt * T.inv();
    boundPoints.push_back(pt);

    for(auto circle : circles) {
        c3ga::Mvec<double> interCircleSphere = !(!circle ^ !tmpSphere);
        auto interCircleSphereRadius = interCircleSphere | interCircleSphere;
        if (interCircleSphereRadius >= 0) {
            std::cout << "inter : " << interCircleSphereRadius << std::endl;
            return true;
        }
    }
    for(int i = 0; i < 6; i++) {
        c3ga::Mvec<double> centerCircle, direction;
        double radiusCircle;
        extractDualCircle(!circles[i], radiusCircle, centerCircle, direction);
        auto dotProductPointCircle = (boundPoints[i] ^ centerCircle) | !circles[i];
        unsigned int count = 0;
        auto euclidienDistance = sqrt(
                ((centerCircle[c3ga::E1] - boundPoints[i][c3ga::E1]) * (centerCircle[c3ga::E1] - boundPoints[i][c3ga::E1])) +
                ((centerCircle[c3ga::E2] - boundPoints[i][c3ga::E2]) * (centerCircle[c3ga::E2] - boundPoints[i][c3ga::E2])) +
                ((centerCircle[c3ga::E3] - boundPoints[i][c3ga::E3]) * (centerCircle[c3ga::E3] - boundPoints[i][c3ga::E3])));
        if(euclidienDistance <= radiusCircle) {
            if (dotProductPointCircle >= 0) {
                std::cout << "Index : " << i << std::endl;
                std::cout << "Radius : " << radiusCircle << std::endl;
                std::cout << "Distance : " << euclidienDistance << std::endl;
                std::cout << "Point Bound X : " << boundPoints[i][c3ga::E1] << " Y : " << boundPoints[i][c3ga::E2] << " Z : " << boundPoints[i][c3ga::E3] << std::endl;
                std::cout << "Circle X : " << centerCircle[c3ga::E1] << " Y : " << centerCircle[c3ga::E2] << " Z : " << centerCircle[c3ga::E3] << std::endl;
                for(auto circle : circles) {
                    c3ga::Mvec<double> centerCircle, direction;
                    double radiusCircle;
                    extractDualCircle(!circle, radiusCircle, centerCircle, direction);
                    auto dotProductPointCircle = (boundPoints[i] ^ centerCircle) | !circle;
                    if(dotProductPointCircle >= 0) {
                        count++;
                    }
                }
            }
            if (count == 6) {
                return true;
            }
        }
        //std::cout << "dot : " << i << " " << dotProductPointCircle << std::endl;

    }
    return false;
}

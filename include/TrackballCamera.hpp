//
// Created by Matthias Hudelot on 23/12/2019.
//

#pragma once

#include <c3ga/Mvec.hpp>
#include "common.hpp"

class TrackballCamera {
public :
    TrackballCamera():
        m_fDistance(5),
        m_fAngleX(0),
        m_fAngleY(0),
        m_eye(glm::vec3(0.,0.,5.)),
        m_center(glm::vec3(0.,0.,0.)),
        m_up(glm::vec3(0., 1., 0.)){
        const auto front = m_center - m_eye;
        const auto left = glm::cross(m_up, front);
        assert(left != glm::vec3(0));
        m_up = glm::normalize(glm::cross(front, left));
    }

    TrackballCamera(float distance, float angleX, float angleY):
            m_fDistance(distance),
            m_fAngleX(angleX),
            m_fAngleY(angleY) {

    }

    void rotateLeft(float degrees);

    void rotateUp(float degrees);

    const glm::vec3 front() {
        return m_center - m_eye;
    }

    const glm::vec3 left() {
        const auto f = front();
        const auto l = glm::cross(m_up, f);
        return l;
    }

    void update(float deltaX, float deltaY);

    glm::mat4 getViewMatrix() const;




private:
    float m_fDistance; //Distance par rapport au centre de la scène
    float m_fAngleX; //Angle effectue par la camera autour de l'axe des X
    float m_fAngleY; //Angle effectue par la camera autour de l'axe des Y
    glm::vec3 m_eye;
    glm::vec3 m_center;
    glm::vec3 m_up;
};

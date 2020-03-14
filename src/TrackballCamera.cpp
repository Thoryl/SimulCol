//
// Created by Matthias Hudelot on 23/12/2019.
//

#include <cmath>
#include <vector>
#include <iostream>
#include "../include/common.hpp"
#include "../include/TrackballCamera.hpp"

void TrackballCamera::rotateLeft(float degrees) {
    m_fAngleY += degrees;
}

void TrackballCamera::rotateUp(float degrees) {
    m_fAngleX += degrees;
}

void TrackballCamera::update(float deltaX, float deltaY) {
    const float verticalAngle = 0.01f * deltaY;
    const float horizontalAngle = -0.01f * deltaX;

    const auto hasMoved = verticalAngle || horizontalAngle;

    if(hasMoved) {
        const auto depthAxis = m_eye - m_center;
        const auto horizontalAxis = left();

        const auto verticalRotationMatrix = glm::rotate(glm::mat4(1), verticalAngle, horizontalAxis);
        const auto rotatedVerticalVector = glm::vec3(verticalRotationMatrix * glm::vec4(depthAxis, 0));

        const auto horizontalRotationMatrix = glm::rotate(glm::mat4(1), horizontalAngle, m_up);

        const auto finalDepthAxis = glm::vec3(horizontalRotationMatrix * glm::vec4(rotatedVerticalVector, 0));

        m_eye = m_center + finalDepthAxis;
    }
}

glm::mat4 TrackballCamera::getViewMatrix() const {
    glm::mat4 VMatrix = glm::mat4(1.f);
    VMatrix = glm::translate(VMatrix, glm::vec3(5., 5., -m_fDistance));
    VMatrix = glm::rotate(VMatrix, m_fAngleX, glm::vec3(1, 0, 0));
    VMatrix = glm::rotate(VMatrix, m_fAngleY, glm::vec3(0, 1, 0));
    //glm::mat4 VMatrix = glm::lookAt(m_eye, m_center, m_up);
    return VMatrix;
}

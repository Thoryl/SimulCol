//
// Created by Matthias Hudelot on 30/12/2019.
//
#include <vector>
#include <c3ga/Mvec.hpp>
#include "c3gaTools.hpp"
#include "common.hpp"
/**
 * Represents an elementary cube forged from triangles.
 *
 */
class Cube {

public:
    /**
     * Constructor of the cube
     */
    Cube() : m_nVertexCount(0) {
        build();
    }

    /**
     * Getter on the pointer data on vertices.
     * @return
     */
    const ShapeVertex *getDataPointer() const;

    /**
     * Getter on the number of vertices in the cube
     * @return the number of vertices in the cube
     */
    GLsizei getVertexCount() const;

    std::vector<c3ga::Mvec<double>> getCircles() {
        return m_Circles;
    }

private:
    /**
     * A vector of ShapeVertex
     */
    std::vector<ShapeVertex> m_Vertices;

    /**
     * The number of vertex
     */
    GLsizei m_nVertexCount;

    std::vector<c3ga::Mvec<double>> m_Points;

    std::vector<c3ga::Mvec<double>> m_Lines;

    std::vector<c3ga::Mvec<double>> m_Circles;

    /**
     * Function building the cube (the face are created clockwise)
     */
    void build();

    /**
     * Generate the front face of the cube
     */
    void generateFrontFace();

    /**
     * Generate the left face of the cube
     */
    void generateLeftFace();

    /**
     * Generate the back face of the cube
     */
    void generateBackFace();

    /**
     * Generate the right face of the cube
     */
    void generateRightFace();

    /**
     * Generate the top face of the cube
     */
    void generateTopFace();

    /**
     * Generate the bottom face of the cube
     */
    void generateBottomFace();
};


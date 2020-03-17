//
// Created by Matthias Hudelot on 30/12/2019.
//

#include "../include/Cube.hpp"

void Cube::build() {
  generateFrontFace();
  m_nVertexCount += 6;
  generateLeftFace();
  m_nVertexCount += 6;
  generateBackFace();
  m_nVertexCount += 6;
  generateRightFace();
  m_nVertexCount += 6;
  generateTopFace();
  m_nVertexCount += 6;
  generateBottomFace();
  m_nVertexCount += 6;
}

void Cube::generateFrontFace() {
  // FACE 1 (FRONT) (4 vertices (SQUARE) --> 6 vertices (2 TRIANGLES)

  // Triangle 1
  ShapeVertex vertex;
  // TOP LEFT CORNER

  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 1.f;

  vertex.position = glm::vec3(-1.f, 1.f, 1.f);

  c3ga::Mvec<double> point1 = c3ga::point(-1., 1., 1.);

  m_Vertices.push_back(vertex);

  m_Points.push_back(point1);

  // BOTTOM LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 1.f;

  vertex.position = glm::vec3(-1.f, -1.f, 1.f);

  c3ga::Mvec<double> point2 = c3ga::point(-1., 1., -1.);

  m_Vertices.push_back(vertex);

  m_Points.push_back(point2);

  c3ga::Mvec<double> line1 = point1 ^ point2 ^ c3ga::ei<double>();

  m_Lines.push_back(line1);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 1.f;

  vertex.position = glm::vec3(1.f, -1.f, 1.f);

  m_Vertices.push_back(vertex);

  c3ga::Mvec<double> point3 = c3ga::point(1., 1., -1.);

  m_Points.push_back(point3);

  c3ga::Mvec<double> line2 = point2 ^ point3 ^ c3ga::ei<double>();

  m_Lines.push_back(line2);

  // Triangle 2
  // TOP RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 1.f;

  vertex.position = glm::vec3(1.f, 1.f, 1.f);
  m_Vertices.push_back(vertex);

  c3ga::Mvec<double> point4 = c3ga::point(1., 1., 1.);

  m_Points.push_back(point4);

  c3ga::Mvec<double> line3 = point3 ^ point4 ^ c3ga::ei<double>();

  m_Lines.push_back(line3);

  c3ga::Mvec<double> line4 = point4 ^ point1 ^ c3ga::ei<double>();

  m_Lines.push_back(line4);

    c3ga::Mvec<double> circle = point1 ^ point2 ^ point3;

    m_Circles.push_back(circle);

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 1.f;

  vertex.position = glm::vec3(-1.f, 1.f, 1.f);

  m_Vertices.push_back(vertex);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 1.f;

  vertex.position = glm::vec3(1.f, -1.f, 1.f);

  m_Vertices.push_back(vertex);
}

void Cube::generateLeftFace() {
  // FACE LEFT (4 vertices (SQUARE) --> 6 vertices (2 TRIANGLES)
  // Triangle 1
  // TOP LEFT CORNER
  ShapeVertex vertex;

  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = -1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, 1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point1 = c3ga::point(-1., -1., 1.);

    m_Points.push_back(point1);

  // BOTTOM LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = -1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, -1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point2 = c3ga::point(-1., -1., -1.);

    m_Points.push_back(point2);

    c3ga::Mvec<double> line1 = point1 ^ point2 ^ c3ga::ei<double>();

    m_Lines.push_back(line1);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = -1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, -1.f, 1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point3 = c3ga::point(-1., 1., -1.);

    m_Points.push_back(point3);

    c3ga::Mvec<double> line2 = point2 ^ point3 ^ c3ga::ei<double>();

    m_Lines.push_back(line2);

  // Triangle 2
  // TOP RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = -1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, 1.f, 1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point4 = c3ga::point(-1., 1., 1.);

    m_Points.push_back(point4);

    c3ga::Mvec<double> line3 = point3 ^ point4 ^ c3ga::ei<double>();

    m_Lines.push_back(line3);

    c3ga::Mvec<double> line4 = point4 ^ point1 ^ c3ga::ei<double>();

    m_Lines.push_back(line4);

    c3ga::Mvec<double> circle = point1 ^ point2 ^ point3;

    m_Circles.push_back(circle);

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = -1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, 1.f, -1.f);

  m_Vertices.push_back(vertex);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = -1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, -1.f, 1.f);

  m_Vertices.push_back(vertex);
}

void Cube::generateBackFace() {
  // FACE 1 (FRONT) (4 vertices (SQUARE) --> 6 vertices (2 TRIANGLES)
  ShapeVertex vertex;

  // Triangle 1

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = -1.f;

  vertex.position = glm::vec3(1.f, 1.f, -1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point1 = c3ga::point(1., -1., 1.);

    m_Points.push_back(point1);

  // BOTTOM LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = -1.f;

  vertex.position = glm::vec3(1.f, -1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point2 = c3ga::point(1., -1., -1.);

    m_Points.push_back(point2);

    c3ga::Mvec<double> line1 = point1 ^ point2 ^ c3ga::ei<double>();

    m_Lines.push_back(line1);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = -1.f;

  vertex.position = glm::vec3(-1.f, -1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point3 = c3ga::point(-1., -1., -1.);

    m_Points.push_back(point3);

    c3ga::Mvec<double> line2 = point2 ^ point3 ^ c3ga::ei<double>();

    m_Lines.push_back(line2);

  // Triangle 2

  // TOP RIGHT CORNER

  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = -1.f;

  vertex.position = glm::vec3(-1.f, 1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point4 = c3ga::point(-1., -1., 1.);

    m_Points.push_back(point4);

    c3ga::Mvec<double> line3 = point3 ^ point4 ^ c3ga::ei<double>();

    m_Lines.push_back(line3);

    c3ga::Mvec<double> line4 = point4 ^ point1 ^ c3ga::ei<double>();

    m_Lines.push_back(line4);

    c3ga::Mvec<double> circle = point1 ^ point2 ^ point3;

    m_Circles.push_back(circle);

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = -1.f;

  vertex.position = glm::vec3(1.f, 1.f, -1.f);
  m_Vertices.push_back(vertex);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = -1.f;

  vertex.position = glm::vec3(-1.f, -1.f, -1.f);

  m_Vertices.push_back(vertex);
}

void Cube::generateRightFace() {
  // FACE LEFT (4 vertices (SQUARE) --> 6 vertices (2 TRIANGLES)
  // Triangle 1

  ShapeVertex vertex;

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, 1.f, 1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point1 = c3ga::point(1., 1., 1.);

    m_Points.push_back(point1);

  // BOTTOM LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, -1.f, 1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point2 = c3ga::point(1., 1., -1.);

    m_Points.push_back(point2);

    c3ga::Mvec<double> line1 = point1 ^ point2 ^ c3ga::ei<double>();

    m_Lines.push_back(line1);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, -1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point3 = c3ga::point(1., -1., -1.);

    m_Points.push_back(point3);

    c3ga::Mvec<double> line2 = point2 ^ point3 ^ c3ga::ei<double>();

    m_Lines.push_back(line2);

  // Triangle 2
  // TOP RIGHT CORNER

  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, 1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point4 = c3ga::point(1., -1., 1.);

    m_Points.push_back(point4);

    c3ga::Mvec<double> line3 = point3 ^ point4 ^ c3ga::ei<double>();

    m_Lines.push_back(line3);

    c3ga::Mvec<double> line4 = point4 ^ point1 ^ c3ga::ei<double>();

    m_Lines.push_back(line4);

    c3ga::Mvec<double> circle = point1 ^ point2 ^ point3;

    m_Circles.push_back(circle);

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, 1.f, 1.f);
  m_Vertices.push_back(vertex);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 1.f;
  vertex.normal.y = 0.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, -1.f, -1.f);

  m_Vertices.push_back(vertex);
}

void Cube::generateTopFace() {
  // FACE 1 (FRONT) (4 vertices (SQUARE) --> 6 vertices (2 TRIANGLES)

  // Triangle 1
  ShapeVertex vertex;
  // TOP LEFT CORNER

  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, 1.f, -1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point1 = c3ga::point(-1., -1., 1.);

    m_Points.push_back(point1);

  // BOTTOM LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, 1.f, 1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point2 = c3ga::point(-1., 1., 1.);

    m_Points.push_back(point2);

    c3ga::Mvec<double> line1 = point1 ^ point2 ^ c3ga::ei<double>();

    m_Lines.push_back(line1);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, 1.f, 1.f);

  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point3 = c3ga::point(1., 1., 1.);

    m_Points.push_back(point3);

    c3ga::Mvec<double> line2 = point2 ^ point3 ^ c3ga::ei<double>();

    m_Lines.push_back(line2);

  // Triangle 2
  // TOP RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, 1.f, -1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point4 = c3ga::point(1., -1., 1.);

    m_Points.push_back(point4);

    c3ga::Mvec<double> line3 = point3 ^ point4 ^ c3ga::ei<double>();

    m_Lines.push_back(line3);

    c3ga::Mvec<double> line4 = point4 ^ point1 ^ c3ga::ei<double>();

    m_Lines.push_back(line4);

    c3ga::Mvec<double> circle = point1 ^ point2 ^ point3;

    m_Circles.push_back(circle);

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, 1.f, -1.f);
  m_Vertices.push_back(vertex);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = 1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, 1.f, 1.f);

  m_Vertices.push_back(vertex);
}

void Cube::generateBottomFace() {
  // FACE 1 (FRONT) (4 vertices (SQUARE) --> 6 vertices (2 TRIANGLES)
  // Triangle 1
  ShapeVertex vertex;

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = -1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, -1.f, 1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point1 = c3ga::point(-1., 1., -1.);

    m_Points.push_back(point1);

  // BOTTOM LEFT CORNER

  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = -1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, -1.f, -1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point2 = c3ga::point(-1., -1., -1.);

    m_Points.push_back(point2);

    c3ga::Mvec<double> line1 = point1 ^ point2 ^ c3ga::ei<double>();

    m_Lines.push_back(line1);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = -1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, -1.f, -1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point3 = c3ga::point(1., -1., -1.);

    m_Points.push_back(point3);

    c3ga::Mvec<double> line2 = point2 ^ point3 ^ c3ga::ei<double>();

    m_Lines.push_back(line2);

  // Triangle 2

  // TOP RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = -1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, -1.f, 1.f);
  m_Vertices.push_back(vertex);

    c3ga::Mvec<double> point4 = c3ga::point(1., 1., -1.);

    m_Points.push_back(point4);

    c3ga::Mvec<double> line3 = point3 ^ point4 ^ c3ga::ei<double>();

    m_Lines.push_back(line3);

    c3ga::Mvec<double> line4 = point4 ^ point1 ^ c3ga::ei<double>();

    m_Lines.push_back(line4);

    c3ga::Mvec<double> circle = point1 ^ point2 ^ point3;

    m_Circles.push_back(circle);

  // TOP LEFT CORNER
  vertex.texCoords.x = 0.f;
  vertex.texCoords.y = 0.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = -1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(-1.f, -1.f, 1.f);
  m_Vertices.push_back(vertex);

  // BOTTOM RIGHT CORNER
  vertex.texCoords.x = 1.f;
  vertex.texCoords.y = 1.f;

  vertex.normal.x = 0.f;
  vertex.normal.y = -1.f;
  vertex.normal.z = 0.f;

  vertex.position = glm::vec3(1.f, -1.f, -1.f);
  m_Vertices.push_back(vertex);
}

GLsizei Cube::getVertexCount() const { return m_nVertexCount; }

const ShapeVertex *Cube::getDataPointer() const {
  return &m_Vertices[0];
}

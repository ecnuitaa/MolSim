/*
 * Particle.cpp
 *
 *  Created on: 23.02.2010
 *      Author: eckhardw
 */

#include "Particle.h"

#include <iostream>
#include <sstream>

Particle::Particle(int type_arg) {
  type = type_arg;
  std::cout << "Particle generated!" << std::endl;
  f = 0.0;
  old_f = 0.0;
}

Particle::Particle(const Particle &other) {
  x = other.x;
  v = other.v;
  f = other.f;
  old_f = other.old_f;
  m = other.m;
  type = other.type;
  std::cout << "Particle generated by copy!" << std::endl;
  ;
}

// Todo: maybe use initializater list instead of copy?
Particle::Particle(utils::Vector<double, 3> x_arg,
                   utils::Vector<double, 3> v_arg, double m_arg, int type_arg) {
  x = x_arg;
  v = v_arg;
  m = m_arg;
  type = type_arg;
  f = 0.0;
  old_f = 0.0;
  std::cout << "Particle generated!" << std::endl;
}

Particle::~Particle() { std::cout << "Particle destructed!" << std::endl; }

utils::Vector<double, 3> &Particle::getX() { return x; }

utils::Vector<double, 3> &Particle::getV() { return v; }

utils::Vector<double, 3> &Particle::getF() { return f; }

utils::Vector<double, 3> &Particle::getOldF() { return old_f; }

double Particle::getM() { return m; }

int Particle::getType() { return type; }

std::string Particle::toString() {
  std::stringstream stream;
  stream << "Particle: X:" << x << " v: " << v << " f: " << f
         << " old_f: " << old_f << " type: " << type;
  return stream.str();
}

bool Particle::operator==(Particle &other) {
  if ((x == other.x) && (v == other.v) && (f == other.f) &&
      (type == other.type) & (m == other.m) && (old_f == other.old_f)) {
    return true;
  }

  return false;
}

std::ostream &operator<<(std::ostream &stream, Particle &p) {
  stream << p.toString();
  return stream;
}

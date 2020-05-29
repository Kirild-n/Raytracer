#ifndef PPM_WRITER_H
#define PPM_WRITER_H

#include "Vec3.h"
#include <vector>
#include <string>

class PpmWriter {
public:
	void write(const std::vector<Vec3f> &points, const std::string& path, int width, int height) const;
};

#endif
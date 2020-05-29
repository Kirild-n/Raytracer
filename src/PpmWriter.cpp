#include "PpmWriter.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

void PpmWriter::write(const std::vector<Vec3f> &points, const std::string& path, int width, int height) const
{
	std::ofstream out(path, std::ios::binary);
	out << "P6\n" << width << " " << height << "\n255\n";
	for (size_t i = 0; i < height * width; ++i)
	{
		for (size_t j = 0; j < 3; j++)
		{
			auto component = std::clamp(points[i][j], 0.f, 1.f);
			out << (char)(255 * component);
		}
	}
}
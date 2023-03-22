#pragma once
#include <algorithm>
class AABB
{
private:
	float calculateSurfaceArea() const { return 2.0f * (getWidth() * getHeight() + getWidth() * getDepth() + getHeight() * getDepth()); }

public:
	float minX,minY,minZ,maxX,maxY,maxZ,surfaceArea;

	AABB() : minX(0.0f), minY(0.0f), minZ(0.0f), maxX(0.0f), maxY(0.0f), maxZ(0.0f), surfaceArea(0.0f) { }
	AABB(unsigned minX,
		unsigned minY,
		unsigned minZ, 
		unsigned maxX, 
		unsigned maxY, 
		unsigned maxZ) :
		AABB(static_cast<float>(minX),
			static_cast<float>(minY), 
			static_cast<float>(minZ), 
			static_cast<float>(maxX),
			static_cast<float>(maxY), 
			static_cast<float>(maxZ)) { }
	AABB(float minX, float minY, float minZ, float maxX, float maxY, float maxZ) :
		minX(minX), minY(minY), minZ(minZ), maxX(maxX), maxY(maxY), maxZ(maxZ)
	{
		surfaceArea = calculateSurfaceArea();
	}

	bool Overlaps(const AABB& other) const
	{
		return maxX > other.minX &&
			minX < other.maxX &&
			maxY > other.minY &&
			minY < other.maxY &&
			maxZ > other.minZ &&
			minZ < other.maxZ;
	}

	bool Contains(const AABB& other) const
	{
		return other.minX >= minX &&
			other.maxX <= maxX &&
			other.minY >= minY &&
			other.maxY <= maxY &&
			other.minZ >= minZ &&
			other.maxZ <= maxZ;
	}

	AABB Merge(const AABB& other) const
	{
		return AABB(
			std::min(minX, other.minX), std::min(minY, other.minY), std::min(minZ, other.minZ),
			std::max(maxX, other.maxX), std::max(maxY, other.maxY), std::max(maxZ, other.maxZ)
		);
	}

	AABB Intersection(const AABB& other) const
	{
		return AABB(
			std::max(minX, other.minX), std::max(minY, other.minY), std::max(minZ, other.minZ),
			std::min(maxX, other.maxX), std::min(maxY, other.maxY), std::min(maxZ, other.maxZ)
		);
	}

	float getWidth() const { return maxX - minX; }
	float getHeight() const { return maxY - minY; }
	float getDepth() const { return maxZ - minZ; }
};


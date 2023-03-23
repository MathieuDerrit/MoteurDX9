#pragma once


class Collider : public Component
{
public:
	Collider();
	~Collider();

	void Init();
	void Update();

	AABB aabb;
	Transform colliderTransform;

	bool CheckSphereIntersect(float XCentre1, float YCentre1, float ZCentre1, float Radius1, float XCentre2, float YCentre2, float ZCentre2, float Radius2) {
		float XDiff, YDiff, ZDiff, Distance;
		XDiff = (float)fabs(XCentre2 - XCentre1);	
		YDiff = (float)fabs(YCentre2 - YCentre1);	
		ZDiff = (float)fabs(ZCentre2 - ZCentre1);	
		Distance = (float)sqrt(XDiff * XDiff + YDiff * YDiff + ZDiff * ZDiff);	// Return TRUE with intersecting spheres	
		if( Distance <= (Radius1+Radius2) ) {		
			return TRUE;	
		}	
		return FALSE;}

};
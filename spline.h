#pragma once
#include"arg_parser.h"
#include"triangle_mesh.h"
#include<vector>

class Spline
{

public:
	Spline();
	// ���ڻ�ͼ��FOR VISUALIZATION
	virtual void Spline::Paint(ArgParser *args);

	// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void Spline::OutputBezier(FILE *file);
	virtual void Spline::OutputBSpline(FILE *file);

	// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING
	virtual int Spline::getNumVertices();
	virtual Vec3f Spline::getVertex(int i);

	// ���ڱ༭������FOR EDITING OPERATIONS
	virtual void Spline::moveControlPoint(int selectedPoint, float x, float y);
	virtual void Spline::addControlPoint(int selectedPoint, float x, float y);
	virtual void Spline::deleteControlPoint(int selectedPoint);

	// ���ڲ��������ε�FOR GENERATING TRIANGLES
	virtual TriangleMesh* Spline::OutputTriangles(ArgParser *args);
	void set(int i, Vec3f v);
protected:
	vector<Vec3f>point;//��ŵ�
	int points=0;//��ŵ���
};

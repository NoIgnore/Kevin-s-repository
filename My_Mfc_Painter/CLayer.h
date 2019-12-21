#pragma once
using namespace std;
#include <fstream>
#include <iostream>
#include <string> 
//struct Mypointlist
//{
//	CPoint my__point = (0, 0);
//	Mypointlist* next = nullptr;
//};
class CLayer
{
public:

	enum EType
	{
		drawing, selecting, normal
	};
	EType m_type = normal;
	CPoint my_point_selected;
	//Mypointlist* from_layer_head_point;
	//Mypointlist* from_layer_tail_point;
	CPoint from_layer_startpoint;
	CPoint from_layer_endpoint;
	CPoint from_layer_middlepoint = (0, 0);
	CString buffer;

	int m_shape = 0;
	int read_file_o = 0;
	int layer_click = 0;
	int layer_n = 0;
	string layer_string;

	CPoint setEndPoint(CPoint point) { return from_layer_endpoint = point; }
	CPoint setMiddlePoint(CPoint point) { return from_layer_middlepoint = point; }

	CLayer();
	virtual ~CLayer();
	CLayer(CPoint p_startPoint, CPoint p_endPoint);
	virtual void OnDraw(CDC* pDC) = 0;
	virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
	virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
	virtual void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC) = 0;
	virtual void SelectLayer(UINT nFlags, CPoint point) = 0;
	virtual void Offset(CPoint ptoffset) = 0;
	virtual void OnFileSave() = 0;
	virtual void OnFileOpen(CString pathName) = 0;
};


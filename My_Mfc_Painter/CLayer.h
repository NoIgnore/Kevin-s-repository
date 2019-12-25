#pragma once
#include "pch.h"
using namespace std;
#include <fstream>
#include <iostream>
#include <string>

class CLayer
{
public:
	enum EType
	{
		drawing, selecting, normal
	};
	EType m_type = normal;
	CPoint my_point_selected;

	CString buffer;

	int m_shape = 0;
	int read_file_o = 0;
	int layer_click = 0;
	int layer_n = 0;
	string layer_string;

	CLayer();
	virtual ~CLayer();
	virtual void OnDraw(CDC* pDC) = 0;
	virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
	virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
	virtual void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC) = 0;
	virtual void SelectLayer(UINT nFlags, CPoint point) = 0;
	virtual void Offset(CPoint ptoffset) = 0;
	virtual void OnFileSave() = 0;
	virtual void OnFileOpen(CString pathName) = 0;
	virtual const char* getName() = 0;
};

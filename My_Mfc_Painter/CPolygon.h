#pragma once
#include "CLayer.h"
class CPolygon :
	public CLayer
{
	/*struct My_list
	{
		CPoint a;
		CPoint* next;
	};
	My_list head, tail;*/
	CPoint m_start, m_end, m_middle1,m_middle2;
	void OnDraw(CDC* pDC);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC);
	void SelectLayer(UINT nFlags, CPoint point);
	void Offset(CPoint ptoffset);
	void OnFileSave();
	void OnFileOpen(CString pathName);
public:
	CPolygon();
	~CPolygon();
};


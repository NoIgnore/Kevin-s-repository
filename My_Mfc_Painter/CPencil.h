#pragma once
#include "CLayer.h"
class CPencil :public CLayer
{
	CArray<CPoint> m_pencil;
	void OnDraw(CDC* pDC);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC);
	void SelectLayer(UINT nFlags, CPoint point);
	void Offset(CPoint ptoffset);
	void OnFileSave();
	void OnFileOpen(CString pathName);
public:
	CPencil();
	~CPencil();
};


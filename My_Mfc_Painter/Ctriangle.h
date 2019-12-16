#pragma once
#include "CLayer.h"
class Ctriangle :
	public CLayer
{
	CPoint m_start, m_end, m_middle;
	void OnDraw(CDC* pDC);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC);
	void SelectLayer(UINT nFlags, CPoint point);
	void Offset(CPoint ptoffset);
	int click = 1;
public:
	Ctriangle();
	~Ctriangle();
};


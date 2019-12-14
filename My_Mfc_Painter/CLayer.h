#pragma once
class CLayer
{
public:
	enum EType
	{
		drawing, selecting, normal
	};
	EType m_type = normal;
	CPoint my_point_selected;
	CLayer();
	virtual ~CLayer();
	virtual void OnDraw(CDC* pDC) = 0;
	virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
	virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
	virtual void OnMouseMove(UINT nFlags, CPoint point, CDC* pDC) = 0;
	virtual void SelectLayer(UINT nFlags, CPoint point) = 0;
	virtual void Offset(CPoint ptoffset) = 0;
};


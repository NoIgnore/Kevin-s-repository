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

	CPoint from_layer_startpoint;
	CPoint from_layer_endpoint;
	CPoint from_layer_middlepoint = (0, 0);

	int m_shape = 2;
	int read_file_o = 0;
	int layer_click = 0;

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
};


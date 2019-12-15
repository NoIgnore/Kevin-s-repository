#include "pch.h"
#include "CRectangle.h"

void CRectangle::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_rect.TopLeft() = point;
	m_shape = 2;
	from_layer_startpoint = point;
}

void CRectangle::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_rect.BottomRight() = point;
	m_rect.NormalizeRect();
	from_layer_endpoint = point;
	m_type = normal;
}

void CRectangle::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	if (nFlags & MK_LBUTTON)
	{
		/*HBRUSH hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
		pDC->SelectObject(hbr);*/
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->SetROP2(R2_NOT);

		if (m_rect.right != MAXLONG)
		{
			pDC->Rectangle(m_rect);
		}
		m_rect.BottomRight() = point;
		pDC->Rectangle(m_rect);
	}
}

void CRectangle::SelectLayer(UINT nFlags, CPoint point)
{
	m_type = m_rect.PtInRect(point) ? selecting : normal;
	my_point_selected = point;
}

void CRectangle::Offset(CPoint ptoffset)
{
	m_rect.OffsetRect(ptoffset);
}

void CRectangle::OnDraw(CDC* pDC)
{
	if (read_file_o == 1)
	{
		m_rect.TopLeft() = from_layer_startpoint;
		m_rect.BottomRight() = from_layer_endpoint;
		//m_rect.NormalizeRect();
		read_file_o = 0;
	}
	pDC->Rectangle(m_rect);
	if (m_type == selecting) {
		CPoint& p1 = m_rect.TopLeft();
		pDC->FillSolidRect(p1.x - 3, p1.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		CPoint& p2 = m_rect.BottomRight();
		pDC->FillSolidRect(p2.x - 3, p2.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		CPoint p3(m_rect.right, m_rect.top);
		pDC->FillSolidRect(p3.x - 3, p3.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
		CPoint p4(m_rect.left, m_rect.bottom);
		pDC->FillSolidRect(p4.x - 3, p4.y - 3, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
	}
}

CRectangle::CRectangle():m_rect(MAXLONG, MAXLONG, MAXLONG, MAXLONG)
{
}

CRectangle::~CRectangle()
{
}

#include "pch.h"
#include "CEllipse.h"

void CEllipse::OnDraw(CDC* pDC)
{
	if (read_file_o == 1)
	{
		m_rect.TopLeft() = from_layer_startpoint;
		m_rect.BottomRight() = from_layer_endpoint;
		//m_rect.NormalizeRect();
		read_file_o = 0;
	}
	pDC->Ellipse(m_rect);
	if (m_type == selecting) {
		CPoint& p1 = m_rect.TopLeft();
		CPoint& p2 = m_rect.BottomRight();
		int a = (p2.x + p1.x) / 2;
		int b = (p2.y + p1.y) / 2;
		pDC->FillSolidRect(a, b, 6, 6, GetSysColor(COLOR_HIGHLIGHT));
	}
}

void CEllipse::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_rect.BottomRight() = point;
	m_rect.NormalizeRect();
	from_layer_endpoint = point;
	m_type = normal;
}

void CEllipse::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_rect.TopLeft() = point;
	from_layer_startpoint = point;
	m_shape = 3;
}

void CEllipse::OnMouseMove(UINT nFlags, CPoint point, CDC* pDC)
{
	if (nFlags & MK_LBUTTON)
	{
		HBRUSH hbr = (HBRUSH)GetStockObject(NULL_BRUSH);
		pDC->SelectObject(hbr);
		pDC->SetROP2(R2_NOT);

		if (m_rect.right != MAXLONG)
		{
			pDC->Ellipse(m_rect);
		}
		m_rect.BottomRight() = point;
		pDC->Ellipse(m_rect);
	}
}

void CEllipse::SelectLayer(UINT nFlags, CPoint point)
{
	m_type = m_rect.PtInRect(point) ? selecting : normal;
	my_point_selected = point;

}

void CEllipse::Offset(CPoint ptoffset)
{
	m_rect.OffsetRect(ptoffset);
	from_layer_startpoint = m_rect.TopLeft();
	from_layer_endpoint = m_rect.BottomRight();
}

void CEllipse::OnFileSave()
{
	buffer.Format(_T("%d %d %d %d %d %d %d"),
		m_shape,
		from_layer_startpoint.x,
		from_layer_startpoint.y,
		from_layer_middlepoint.x,
		from_layer_middlepoint.y,
		from_layer_endpoint.x,
		from_layer_endpoint.y
	);
	buffer += "\n";
}

void CEllipse::OnFileOpen(CString pathName)
{
	if (layer_n >= 2)
	{
		ifstream fin2;
		fin2.open(pathName);
		for (int i = 1; i < layer_n; i++)
		{
			getline(fin2, layer_string);
		}
		fin2 >> m_shape
			>> from_layer_startpoint.x
			>> from_layer_startpoint.y
			>> from_layer_middlepoint.x
			>> from_layer_middlepoint.y
			>> from_layer_endpoint.x
			>> from_layer_endpoint.y;
		fin2.close();
	}
	else {
		ifstream fin2;
		fin2.open(pathName);
		fin2 >> m_shape
			>> from_layer_startpoint.x
			>> from_layer_startpoint.y
			>> from_layer_middlepoint.x
			>> from_layer_middlepoint.y
			>> from_layer_endpoint.x
			>> from_layer_endpoint.y;
		fin2.close();
	}
	read_file_o = 1;
}


CEllipse::CEllipse():m_rect(MAXLONG, MAXLONG, MAXLONG, MAXLONG)
{
}

CEllipse::~CEllipse()
{
}

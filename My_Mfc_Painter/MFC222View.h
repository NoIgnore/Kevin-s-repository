
// MFC222View.h: CMFC222View 类的接口
//

#pragma once
#include"CLayer.h"

class CMFC222View : public CView
{

protected: // 仅从序列化创建
	CArray<CLayer*> m_ls;
	CMFC222View();// noexcept;
	DECLARE_DYNCREATE(CMFC222View)
	UINT m_nIndex;
	void SelectLayer(UINT nFlags, CPoint point);
	void SelectEnd(UINT nFlags, CPoint point);
// 特性
public:
	CMFC222Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFC222View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDrawArrow();
	afx_msg void OnUpdateDrawArrow(CCmdUI* pCmdUI);
	afx_msg void OnDrawEllipse();
	afx_msg void OnUpdateDrawEllipse(CCmdUI* pCmdUI);
	afx_msg void OnDrawLine();
	afx_msg void OnUpdateDrawLine(CCmdUI* pCmdUI);
	afx_msg void OnDrawRect();
	afx_msg void OnUpdateDrawRect(CCmdUI* pCmdUI);
	afx_msg void OnDrawPencil();
	afx_msg void OnUpdateDrawPencil(CCmdUI* pCmdUI);

	int get_status_from_doc = 0;
	int if_move_and_save = 0;

	afx_msg void OnDrawTriangle();
	afx_msg void OnUpdateDrawTriangle(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // MFC222View.cpp 中的调试版本
inline CMFC222Doc* CMFC222View::GetDocument() const
   { return reinterpret_cast<CMFC222Doc*>(m_pDocument); }
#endif

